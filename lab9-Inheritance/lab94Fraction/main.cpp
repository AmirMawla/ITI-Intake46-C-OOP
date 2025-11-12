#include <iostream>
#include <numeric>
using namespace std;

int MaxNumToDivide(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
    int num;
    int den;

public:

    Fraction(int _num = 0, int _den = 1) {
        if (_den == 0) {
            cout << "Denominator cannot be zero" << endl;
        } else {
            num = _num;
            den = _den;
            Simplify();
        }
    }


    void Simplify() {
        int g = MaxNumToDivide(num, den);
        num /= g;
        den /= g;


        if (den < 0) {
            num = -num;
            den = -den;
        }
    }


    Fraction Add( Fraction& other)
     {
        int NewDen = den * other.den;
        int NewNum = num * other.den + other.num * den;

        Fraction result(NewNum, NewDen);
        result.Simplify();
        return result;
    }


    void Print() {
        cout << num << "/" << den << endl;
    }

    Fraction operator+(Fraction& c)
    {
        return this->Add(c);
    }

    Fraction operator+(int x)
    {
        Fraction f(x);
        return this->Add(f);
    }

    int operator==(Fraction& c)
    {
        return num == c.num && den == c.den ;
    }

    int operator !=(Fraction& c)
    {
        return num != c.num || den != c.den ;
    }

    Fraction operator++()
    {
        Fraction f(1);
        *this = this->Add(f);
        return *this ;
    }

    Fraction operator++(int)
{
     Fraction newcpl(num,den);
        Fraction f(1);
        *this = this->Add(f);
        return newcpl ;
}


};

Fraction operator+(int x , Fraction& c)
{
    Fraction f(x);
    return c.Add(f);
}


int main() {
    int n1, d1, n2, d2;

    cout << "Enter numerator for first fraction: ";
    cin >> n1 ;
    cout << "Enter denominator for first fraction: ";
    cin >> d1;
    cout << "Enter numerator for second fraction: ";
    cin >> n2 ;
    cout << "Enter denominator for second fraction: ";
    cin >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    cout << "\nFraction 1 simplified: ";
    f1.Print();

    cout << "Fraction 2 simplified: ";
    f2.Print();

    Fraction sum = f1.Add(f2);

    cout << "\nSum of fractions: ";
    sum.Print();

     cout<<"--------------------------"<<endl;
    Fraction c3;
    c3 = f1+ f2 ;
    c3.Print();

    Fraction c4;
    c4 = c3 + 2 ;
    c4.Print();

    Fraction c5;
    c5 = 2+c4 ;
    c5.Print();

    if(c4==c5)
        cout<<"c4 equal c5"<<endl;
    else cout<< "c4 not equal c5"<<endl;

    if(c4 != c5)
        cout<<"c4 not equal c5"<<endl;
    else cout<< "c4 equal c5"<<endl;


    Fraction c6;
    c6 = ++c5;
    c6.Print();

    Fraction c7;
    c7 =c6++;
    c7.Print();

    c6.Print();

    return 0;
}
