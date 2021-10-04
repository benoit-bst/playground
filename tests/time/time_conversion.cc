#include <bits/stdc++.h>

using namespace std;

string timeConversion(string str) {

    string output = "";

    // Get hours
    int h2 = (int)str[0] - '0';
    int h1 = (int)str[1] - '0';
    int hh = (h2 * 10 + h1 % 10);
    cout << "hh " << hh << endl;

    // If time is in "AM"
    if (str[8] == 'A')
    {
        if (hh == 12)
        {
            output = "00";
            for (int i=2; i <= 7; i++)
                output += str[i];
        }
        else
        {
            for (int i=0; i <= 7; i++)
                output += str[i];
        }
    }

    // If time is in "PM"
    else
    {
        if (hh == 12)
        {
            output += "12";
            for (int i=2; i <= 7; i++)
                output += str[i];
        }
        else
        {
            hh = hh + 12;
            output += to_string(hh);
            for (int i=2; i <= 7; i++)
                output += str[i];
        }
    }
    return output;

}

int main()
{
    string str = "07:05:45PM";
    cout << timeConversion(str) << endl;

}
