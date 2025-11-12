#include <iostream>

using namespace std;

int main()
{

    long double num1, num2, num3, num4 ;
    char char1;

    cout << "please input first number: " << endl;
    cin >> num1;

    cout << "please input second number: " << endl;
    cin >> num2;


    while (num2 == 0)
    {
        cout << "division by 0 is not allowed, please input valid number"  << endl;
        cin >> num2;
    }

    cout << "sum is : " << num1 + num2 << endl;
    cout << "subtract is : " << num1 - num2 << endl;
    cout << "multiplication is : " << num1 * num2 << endl;
    cout << "division is : " << num1 / num2 << endl;
    cout << "Hello world!" << endl;


    cout << "input a character to convert to ASCII: " << endl;
    cin >> char1;
    num3 = char1;
    cout << "ASCII number is: " << num3 << endl;


    cout << "input a number to convert to a character" << endl;
    cin >> num4;
    char1 = num4;
    cout << "character is : " << char1 << endl;


    return 0;
}
