/*
Angry Professor
The main logic of the Angry Professor is :

To count the number of arrivalTime which is less than 1.
Check count is greater than or equal to k and return accordingly.
The time complexity for this is (n). Where n is the size of the array.

This is the main logic of the solution for Angry Professor in C++. Please dry and run the code for a better understanding.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,k=1;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            if(j%2!=0)
            {
              k*=2;
            }
            if(j%2==0)
            {
                k++;
            }
        }
        cout<<k<<"\n";
    }
    return 0;
}


