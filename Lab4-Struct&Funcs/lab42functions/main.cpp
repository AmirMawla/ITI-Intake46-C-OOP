#include <iostream>
using namespace std;

 long factorial(int n) {
     long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

 long power(int b, int e) {
     long result = 1;

    for (int i = 1; i <= e; i++) {
        result *= b;
    }

    return result;
}


int reverseNumber(int n) {
    int reversed = 0;

    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return reversed;
}


int main() {
    int num;
    int num1;
    int base ;
    int e;
    cout << "Enter a number: "<<endl;
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " = " << factorial(num) << endl;
    }

        cout << "Enter a number To Reverse: ";
    cin >> num1;

        cout << "The Reverse Of :" << num1 << " = " << reverseNumber(num1) << endl;

          cout << "Power: "<<endl;
          cout << "Enter Base : ";
    cin >> base;
          cout << "Enter Exponent : ";
    cin >> e;
        cout << "The Result  :"  <<power(base,e) << endl;


    return 0;
}
