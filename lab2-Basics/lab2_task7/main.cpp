#include <iostream>

using namespace std;

int main()
{

    int input, mirror = 0, digit;
    cout << "mirror|rorrim" << endl;
    cout << "enter +ve number" << endl;

    while (true)
    {
        cin >> input;
        if (input < 0)
            cout << "invalid value, try again:" << endl;
        else
            break;
    }


    while (input != 0)
    {
        digit = input % 10 ;
        mirror = (mirror * 10) +  digit;
        input /= 10;
    }

    cout << mirror;


    return 0;
}
