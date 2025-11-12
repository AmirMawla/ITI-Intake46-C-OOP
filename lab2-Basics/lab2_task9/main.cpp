#include <iostream>

using namespace std;
int fibonacci(int n) {
    if (n < 0) {
        cout << "Fibonacci not defined for negative numbers." << endl;
        return -1;
    }
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

    int main()
    {
        int input;

        cout << "fibonanci" << endl;
        while(true)
        {
            cin >> input;
            if (input < 0)
                cout << "invalid value, try agian\n";
            else
                break;
        }

            cout << "Fib Of  "<<input <<" =  "<<fibonacci(input)  << endl;

        return 0;
    }
