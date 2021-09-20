#include <bits/stdc++.h>

using namespace std;

string kangaroo(int sp1, int v1, int sp2, int v2) {

    while(true)
    {
        if ( sp1 > sp2 && v1 > v2 || sp2 > sp1 && v2 > v1 || (v1 == v2 && sp1 != sp2))
        {
            return "NO";
        }
        if ((sp1 = sp1 + v1) == (sp2 = sp2 + v2))
        {
            return "YES";
        }
    }
}


int main()
{
    cout << kangaroo(3, 2, 4, 3) << endl;

}
