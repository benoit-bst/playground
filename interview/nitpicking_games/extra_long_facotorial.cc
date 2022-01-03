//https://www.hackerrank.com/challenges/extra-long-factorials

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, i, j;
    int carry = 0;
    int digits = 0; //number of digits in factorial

    vector<int> fact;
    fact.resize(n);
    fact[0] = 1; //0! = 1 anyways, so start multiplication from there

    scanf("%d",&n);
    for(i = 1; i <= n; i++){

        // for each digit processed completly
        for(j = 0; j <= digits; j++) {
            fact[j] = (fact[j] * i) + carry;
            carry = fact[j] / 10;
            fact[j] %= 10;
        }

        // we impact the result with the carry
        while(carry > 0 && digits < 200){
            digits++;
            fact[digits] = carry % 10;
            carry /= 10;
        }
    }

    //print factorial
    for(i = digits; i >= 0; i--)
        cout << fact[i];
    cout << endl;

    return 0;
}
