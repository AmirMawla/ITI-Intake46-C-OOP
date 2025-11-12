#include <iostream>

using namespace std;

int main()
{
    float base, power, sign = 1;
    double result = 1;
    cout << "Calculate Power" << endl;
    cin >> base >> power;

    if (power < 0)
    {
        sign = -1;
    }
    for (int i = 0; i <abs(power) ; i++)
    {
        result *= base;
    }
    if (sign < 0)
        result = 1 / result;
    if (power == 0)
        result = 1;
    cout << "result of " << base << " power " << power << " is " << result;
    return 0;
}
