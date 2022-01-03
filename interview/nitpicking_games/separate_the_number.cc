#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(string str, int ind , long long int prev){

    if(ind == str.size() -1 && prev - (str[ind] -'0') == -1){
        return true;
    }

    else if(ind == str.size() ) return true;
    long long int k = 0;
    int i;

    for(i = ind; i < str.size(); i++){
        k = k * 10 + (str[i] - '0');
        if(prev - k == -1){
             if( i + 1 == str.size()){
              return true;

            }
            return check(str, i + 1, k);
        }
        else if(k - prev > 1) {
            return false;
        }
    }
    return false;
}

void separate_the_number(string& str) {

    // edge cases
    if(str[0] == '0' || str.size() <= 1){
        cout << "NO"<< endl;
    }

    int k;
    long long int j = 0;
    bool f = false;

    for(k = 0; k < str.size() - 1; k++){

        j = j * 10 + str[k] -'0';
        f = check(str, k + 1, j);
        if(f == true){
            //cout << k <<" "<<str <<endl;
            cout << "YES" << " " << j << endl;
            break;
        }
    }
    if(f== false) {
        cout << "NO" << endl;
    }
}

int main() {

    string str = "12345";
    separate_the_number(str); // YES 1 2 3 4 5

    str = "12045";
    separate_the_number(str); // NO

    str = "54321";
    separate_the_number(str); // NO

    str = "99100";
    separate_the_number(str); // YES 99 100

    return 0;
}
