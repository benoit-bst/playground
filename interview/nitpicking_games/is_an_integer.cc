#include <iostream>
#include <string>

using namespace std;

//check if number or string
bool check_number(string str) {

    // erase white space
    string buff = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            buff += str[i];
        }
    }
    str = buff;


    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

//check if number or string
bool check_number2(string str) {

    // erase white space
    string buff = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            buff += str[i];
        }
    }
    str = buff;


    for (int i = 0; i < str.length(); i++)
        if (str[i] <'0' && str[i] > '9')
            return false;
    return true;
}
int main() {

    string str = "sunidhi";
    if (check_number(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;
    if (check_number2(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;


    str= "1234";
    if (check_number(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;
    if (check_number2(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;


    str= " 12 34";
    if (check_number(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;
    if (check_number2(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;
}
