#include <bits/stdc++.h>

using namespace std;

int howManyGames(int p, int d, int m, int s) {

    // Return the number of games you can buy
    int counter = 0;
    int currentPrice=p;
    while(s >= currentPrice){
        counter++;
        s -= currentPrice;
        currentPrice = (currentPrice - d) >= m ? currentPrice - d : m;
    }
    return counter;

}

// g++ -std=c++11 hallo_price.cc
int main()
{
    cout << howManyGames(20, 3, 6, 85) << endl;


}
