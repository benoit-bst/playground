#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>

#include <omp.h>

#define NB_THREADS 4

using namespace std;

using std::chrono::nanoseconds;
using std::chrono::duration_cast;

/*

  ** Sections
  Independent sections of code can execute concurrrently
  une barrier naturelle à la fin des sections.

  On peut fixer le nombre de thread
  Il existe la reduction

  ** Tasks in 3.0
  Are independent units of work
  Tasks might be executed immediately or might be deferred.
  The runtime system decides wich of the above

  ** Barrier
  Implicit barrier in : parallel, for, single
  nowait is applicable to : for, single

  ** Pour les problèmes de race condition :
  utilisation de shared(sum)
  puis #pragma omp critical
  pour l'accès à la donnée

  ** Scheduler :
  Le scheduler par default est static avec chunk size = 16

  ---------------------------------------------------------------
  STATIC
  Chaque * une iteration, chaque row un thread
  Exemple de parallelistation de 64 itérations sur num thread = 4


    thread 1     thread 2     thread 3     thread 4
  ------------|------------|------------|------------
  0           16           32           48          64


  -> schedule(static) Par default le chunk size = 16
  ------------
              ------------
                          ------------
                                      ------------
  -> schedule(static, 4) chunk size = 4
  ---         ---         ---         ---
     ---         ---         ---         ---
        ---         ---         ---         ---
           ---         ---         ---         ---
  -> schedule(static, 8) chunk size = 8
  ------                  ------
        ------                  ------
              ------                  ------
                    ------                  ------

  The static type is appropriate when all iterations have the same computational cost

  ---------------------------------------------------------------
  DYNAMIC

  -> schedule(dynamic) Par default le chunk size = 1
  ------------
              ------------
                          ------------
                                      ------------
  -> schedule(dynamic, 4) chunk size = 4
  ---      ---   ---   ---         ------
     ---      ---         ---               ---
                             ---         ---
        ---         ---         ---         ---
  -> schedule(dynamic, 8) chunk size = 8
  ------                        ------
              ------      ------      ------
                    ------                  ------
        ------

  The dynamic scheduling type is appropriate when the iterations require different computational costs.
  Une surcharge plus élévé quand dynamic à cause de la distribution dynamic

  ---------------------------------------------------------------
  GUIDED Pareil que le dynamic sauf que au départ on part de chunk = 16

  -> schedule(guided) Par default le chunk size = 16
              -------            --  --
                     -----   ----      -
                          ---      -
  ------------                      -
  -> schedule(dynamic, 4) chunk size = 4
  ---      ---   ---   ---         ------
     ---      ---         ---               ---
                             ---         ---
        ---         ---         ---         ---
  -> schedule(dynamic, 8) chunk size = 8
  ------                        ------
              ------      ------      ------
                    ------                  ------
        ------

  Utile pour les calcules qui ont un mauvais équilibrage de charge vers la fin du calcul
*/


// Type and declaration
// compile : g++ -std=c++11 -fopenmp -O0 openMpTest1.cpp
int main()
{


  /**
   *
   * Open MP Reduction
   *
   */
  {
    // Data
    unsigned int counter = 100000000;
    vector<int> v1(counter);
    fill(v1.begin(), v1.begin() + counter, 1);

    // Chrono
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto diff = t2 - t1;
    nanoseconds ns = duration_cast<nanoseconds>(diff);

    int nThreads = 0;
    int threadid = 0;
    #pragma omp parallel private(threadid)
    {
      nThreads = omp_get_num_threads();
      // cout << endl << nThreads << " thread(s) available for computation" << endl;
      threadid = omp_get_thread_num();
      // cout << "Thread " << threadid << " is ready for computation"<< endl;
    }

    int sum = 0;
    int partialSum = 0;
    t1 = std::chrono::high_resolution_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < counter; ++i)
    {
      sum += v1[i];
      // v1[i] = v1[i] + 2;
    }
    t2 = std::chrono::high_resolution_clock::now();
    diff = t2 - t1;
    ns = duration_cast<nanoseconds>(diff);
    std::cout << "Open MP Time : " << ns.count() << " nanos" << std::endl;
    std::cout << "Sum          : " << sum << std::endl;
    int timeOpenMp = ns.count();

    //----------------------------------------------------
    // SIMPLE
    sum = 0;
    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < counter; ++i)
    {
      sum += v1[i];
    }
    t2 = std::chrono::high_resolution_clock::now();
    diff = t2 - t1;
    ns = duration_cast<nanoseconds>(diff);
    std::cout << "Simple Time  : " << ns.count() << " nanos" << std::endl;
    std::cout << "Sum          : " << sum << std::endl;
    int timeSimple = ns.count();

    std::cout << "Ratio        : " << (double)timeSimple/timeOpenMp << std::endl;
  }


  /**
   *
   * Open MP Section
   *
   */
  {
    std::cout << "Test 2 :" << std::endl;
    vector<int> v1(40000000);
    fill(v1.begin(), v1.begin() + 40000000, 1);

    int nbIntPerThread = 10000000;
    int sum  = 0;
    int sum0 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    #pragma omp parallel sections num_threads(NB_THREADS)
    {
      #pragma omp section
      {
        int section = 0;
        vector<int> localVect;
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          localVect.push_back(v1[i + section*nbIntPerThread]);
        }
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          sum0 += localVect[i];
        }
        std::cout << "Sum0 = " << sum0 << std::endl;
      }
      #pragma omp section
      {
        int section = 1;
        vector<int> localVect;
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          localVect.push_back(v1[i + section*nbIntPerThread]);
        }
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          sum1 += localVect[i];
        }
        std::cout << "Sum1 = " << sum1 << std::endl;
      }
      #pragma omp section
      {
        int section = 2;
        vector<int> localVect;
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          localVect.push_back(v1[i + section*nbIntPerThread]);
        }
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          sum2 += localVect[i];
        }
        std::cout << "Sum2 = " << sum2 << std::endl;
      }
      #pragma omp section
      {
        int section = 3;
        vector<int> localVect;
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          localVect.push_back(v1[i + section*nbIntPerThread]);
        }
        for (int i = 0; i < nbIntPerThread; ++i)
        {
          sum3 += localVect[i];
        }
        std::cout << "Sum3 = " << sum3 << std::endl;
      }
    }
    sum = sum0 + sum1 + sum2 + sum3;
    std::cout << "Sum   : " << sum << std::endl;

  }


  /**
   *
   * Open MP Task
   *
   */
  {
    // Création d'une team de thread
    #pragma omp parallel num_threads(NB_THREADS)
    {
      // Création d'un single thread pour executer les différentes tasks (On peut faire une loop de tache par exemple)
      #pragma omp single
      {
        int nbIntPerThread = 10000000;

        #pragma omp task
        {
          std::cout << "Task 1" << std::endl;
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          std::cout << "Task 1 End" << std::endl;
        }
        #pragma omp task
        {
          std::cout << "Task 2" << std::endl;
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          std::cout << "Task 2 End" << std::endl;
        }
        #pragma omp task
        {
          std::cout << "Task 3" << std::endl;
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          std::cout << "Task 3 End" << std::endl;
        }
        #pragma omp task
        {
          std::cout << "Task 4" << std::endl;
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          for (int i = 0; i < nbIntPerThread; ++i)
          {
            int a = 0;
          }
          std::cout << "Task 4 End" << std::endl;
        }

      }
    }

    // Création d'une team de thread
    #pragma omp parallel num_threads(NB_THREADS)
    {
      // Création d'un single thread pour executer les différentes tasks (On peut faire une loop de tache par exemple)
      #pragma omp single
      {
        int nbIntPerThread = 10000000;

        for (int i = 0; i < 10; ++i)
        {

          #pragma omp task
          {
            std::cout << "Task id : " << i <<  std::endl;
            for (int j = 0; j < nbIntPerThread; ++j)
            {
              int a = 0;
            }
            for (int j = 0; j < nbIntPerThread; ++j)
            {
              int a = 0;
            }
            std::cout << "Task id End : " << i << std::endl;
          }

        }

      }
    }
  }

}