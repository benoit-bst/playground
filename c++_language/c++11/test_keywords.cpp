#include <iostream> // remplace cette ligne de code par le code du .h directement au même endroit

using namespace std; // permettent d'utiliser un identificateur d'un espace de nommage de manière simplifiée

// compile : g++ -std=c++11 test_keywords.cpp

extern int a;  // declaration extern

typedef unsigned int UnInt; // definition

// En c+11, on peut typedef en utilisant using
// template <size_t T>
// using vector = Matrix<T,1>;

// utilisation de size_t au lieu de int permet de supprimer le problème de portablilité

//-------------------------------------------------------------------------------------------------------------
// Static const
static const int x = 5; // variable que tu definis à la valeur 5 (plus lent evalué pendant le runtime) par contre peut être mise dans namespace ou classe. plus propre que le define

// Macro
#define VALDEFINE 100              // Macro qui remplace partout dans le code (avant de compiler) le val par 100. Cette definition n'est pas en memoire contrairement au const
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

// Linker des bibliothèques C dans du C++. pas d'incidence en C
extern "C"{ // C'est du C++ - permet de ne pas modifier le nom des fonctions C par le compilo C++ !! name mangling
  #include<math.h>
}

// Fonction constexpr recursive
constexpr size_t factoriel(int i){
  return i > 0 ? i*factoriel(i-1) : 1;
}

// Fonction const
const size_t constFonc(const int b){
  int a = 2*b;
  return a;
}

// Fonction constexpr
constexpr int constexprFonc(int a, int b){
  return a*b;
}

// Nombre d'instance
class A_static{
public:
  explicit A_static(){compteur++;}
  ~A_static(){compteur--;}
  static int nbInstance(){return compteur;}
private:
  static int compteur;
};
int A_static::compteur = 0;


int main()
{
  //-------------------------------------------------------------------------------------------------------------
  // Appel d'une macro
  cout << "Max : "<< MAX(2,5) << endl;

  //-------------------------------------------------------------------------------------------------------------
  // const signifie qu'une expression est constante. Peut être appliqué aux variables
  // constexpr peut être appliqué aux fonctions (recursive mais pas virtuelle) et aux classes C++11
  // cosntexpr fournit une expression constante
  // On doit initialiser le constexpr au moment de l'initialisation
  // interdit : constexpr a = i; car i var
  const int constA = 4;
  const int nums[] {1,2,3,4};
  const int nums2[] = {1,2,3,4};
  constexpr float constExprA = 42.2;

  // pour les fonctions permet de remplacer le résultats de la fonction directement à la compilation
  cout << "constexpr function :"<< endl;
  cout << "factoriel(5) = " << factoriel(5) << endl; // Est remmplacé par le compilo par le résultat
  int res = constFonc(12);
  cout << "constFonc() = " << res << endl;
  res = constexprFonc(2,2);
  cout << "constexprFonc() = " << res << endl << endl;

  // Les methodes const
  class classTestCosnt
  {
    public:
      classTestCosnt():m_a(0) {};
      void const_method() const {int a = 0;}; // On ne peut pas modifier m_a dans la const function
      void method() {m_a = 0;};
    private:
      int m_a;
  };

  const classTestCosnt c1;
  classTestCosnt c2;
  c1.const_method();
  //c1.method(); // No compil
  c2.method();
  c2.const_method();

  //-------------------------------------------------------------------------------------------------------------
  // mutable
  {
    struct mut
    {
      int i;           // Non modifiable si mut est const.
      mutable int j;   // Toujours modifiable.
    };
  }

  //-------------------------------------------------------------------------------------------------------------
  // référence &
  // doit être initialisé directement
  // Dans une classe si une ref est dedans alors il faut l'initialiser avec le preprocesseur
  // class test{
  //   int &t;
  // public:
  //   test(int &x):t(x){]}
  // };
  {
    int b = 2;
    int & a = b;
    // int & a = NULL; // ne compile pas
    // int & b; // ne compile pas
  }

  //-------------------------------------------------------------------------------------------------------------
  // volatile
  // Permet de forcer la non optimisation du compilateur. Peut être utile dans certain cas. La variable n'est
  // jamais stored in a register.
  // Modification de la valeur par un code extérieur.
  {
    // volatile int some_int = 100;
    // while (some_int == 100)      // Compiler may optimize int while(true)
    // {
    //   int a = 0;
    // }
  }

  //-------------------------------------------------------------------------------------------------------------
  // Static
  // Une variable static est accecible partout dans un namespace.
  // C'est utile pour par exemple créer un compteur d'instanciation d'une classe
  // Une fonction static dans une classe est appelable seul sans instanciation de la classe
  {
    A_static a1;
    std::cout << "A_static nb : " << A_static::nbInstance() << std::endl;
    A_static a2, a3;
    std::cout << "A_static nb : " << A_static::nbInstance() << std::endl;
    a1.~A_static();
    std::cout << "A_static nb : " << A_static::nbInstance() << std::endl;
  }

  //-------------------------------------------------------------------------------------------------------------
  // Sizeof
  // y = 20/4 = 5
  int x[x];
  int y = sizeof(x)/sizeof(int);

  //-------------------------------------------------------------------------------------------------------------
  // mots clés Enum
  {
    enum color {RED, GREEN, BLUE};
    cout << "Enum :"<< endl;
    cout << "color::BLUE - pos 2       = " << color::BLUE << endl << endl;

    // C++11 - fortement typée
    enum class colorprime {RED, GREEN, BLUE};
    colorprime coco = colorprime::RED;
    if (coco == colorprime::RED)
      cout << "Enum :"<< endl;
    //cout << "color::BLUE - pos 2       = " << colorprime::BLUE << endl << endl; // ne compile pas

    enum color2
    {
      red,        // = 1
      yellow,     // = 2
      green = 20, // = 20
      blue        // = 21
    };
    cout << "color2::blue - pos 3 (21) = " << color2::blue << endl << endl;

    enum color3: int
    {
      rr, // = 0
      gg  // = 1
    };
    cout << "color3::rr - pos 0        = " << color3::rr << endl << endl;

    enum altitude: char
    {
      high ='h',              // = h
      low ='l',               // = l
      space ='l'              // = l
    };
    cout << "altitude::high - val h    = " << (char)altitude::high << endl;
    cout << "altitude::low - val l     = " << (char)altitude::low << endl;
    cout << "altitude::space - val l   = " << (char)altitude::space << endl << endl;
  }

  //-------------------------------------------------------------------------------------------------------------
  // Union : les données partages la même zones de memoire de la plus grande variable d'ou l'écrasement de entier
  // Se déclare de la même manière qu'une structure
  {
    union unionTest
    {
      int entier;
      short b;
      double reel;
    };
    union unionTest A;

    A.entier = 200;
    A.reel   = 2.2;
    cout << "Union :"<< endl;
    cout << "Union 1 = " << A.entier << endl;
    cout << "Union 2 = " << A.reel << endl;
    cout << "sizof Union = " << sizeof(A) << endl; // 8 la taille du plus grand

    union unionTest1
    {
      double A1;
      double A2;
    };
    union unionTest1 B;
    B.A1 = 10;
    B.A2 = 11;

    cout << "Union :"<< endl;
    cout << "Union 1 = " << B.A1 << endl;
    cout << "Union 2 = " << B.A2 << endl;
  }

  //-------------------------------------------------------------------------------------------------------------
  // Struct
  //
  {
    struct bitfield{
      int a;
    };
    struct bitfield b;
    std::cout << "sizof struct  : " << sizeof(b) << endl;
    std::cout << "struct menber : " << b.a << std::endl;
    b.a = 3;
    std::cout << "sizof struct  : " << sizeof(b) << endl;
    std::cout << "struct menber : " << b.a << std::endl;
  }

  // Complement binaire
  {
    int a = 2;
    std::cout << "a : " << ~a << std::endl;
  }

  return 0;
}
