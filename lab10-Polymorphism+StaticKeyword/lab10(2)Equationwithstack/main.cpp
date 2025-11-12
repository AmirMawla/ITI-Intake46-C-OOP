#include <iostream>
#include <cctype>
#include <cstring>
#include <string.h>
#include<conio.h>
using namespace std;

template <class T>
class Stack1
{
    int top;
    int size;
    T* arr ;

public :
    ~Stack1()
    {
//        cout<<"Object destructed"<<endl;;
        delete[] arr;
    }


    Stack1(int _size = 5)
    {
        top = -1 ;
        size = _size;
        arr = new T [size];
    }


    int gettop()
    {
        return top;
    }

    void settop(int _top)
    {
        if(top > size || top <0 )
        {
            cout<<"Invalid Top "<<endl;
        }
        top = _top;
    }



    void Push (T x )
    {
        if (top < size - 1)
        {
            top ++;
            arr[top] = x ;
//            cout<<"char :"<<x<<"Pushed Successfuly"<<endl;
        }
        else
        {
            cout<< "The Stack Is Full" <<endl;
        }
    }



    void pop()
    {
        if(top>=0)
        {
            top--;
        }
    }

    char peak()
    {
        return arr[top] ;
    }


    void Print()
    {
        if(top<0)
            cout<<"The Stack Is Empty"<<endl;
        else
        {
            cout<<endl;
            for(int i= top ; i>=0; i--)
                cout<<arr[i]<<endl;
        }
    }

};


double calc(double num1, double num2, char op)
{
    switch(op)
    {
    case '+' :
        return num1 + num2 ;

    case '-' :
        return num1 - num2 ;

    case '*' :
        return num1 * num2 ;

    case '/' :
        return num1 / num2 ;

    }
    return 0 ;

}


double Solve(char* equ)
{
    Stack1<double> values(20);
    Stack1<char> chars(20);
    for ( int i =0 ; equ[i] != '\0' ; i++)
    {
        if(equ[i] == ' ')
            continue;


        if(isdigit(equ[i]))
        {
            double val = 0 ;
            while(i < strlen(equ) && isdigit(equ[i]))
            {
                val = (val * 10) + (equ[i] - '0') ;
                      i++ ;
            }
            values.Push(val);
            i-- ;
        }



        else if(equ[i] == '(')
        {
            chars.Push(equ[i]);
        }



        else if (equ[i] == ')')
        {
            while(chars.gettop()>= 0 && chars.peak() !='(' )
            {
                double val2 = values.peak();
                values.pop();
                double val1 = values.peak();
                values.pop();
                char op = chars.peak();
                chars.pop();
                values.Push(calc(val1,val2,op));
            }
            chars.pop();
        }


        else
        {

            while (chars.gettop() >= 0 &&  (
                    (chars.peak() == '*' || chars.peak() == '/') ||
                    (  (equ[i] == '+' || equ[i] == '-')  &&   (chars.peak() == '+' || chars.peak() == '-') )))
            {
                double val2 = values.peak(); values.pop();
                double val1 = values.peak(); values.pop();
                char op = chars.peak(); chars.pop();
                values.Push(calc(val1, val2, op));
            }
            chars.Push(equ[i]);

        }

    }

    while(chars.gettop()>=0)
    {
        double val2 = values.peak();
        values.pop();
        double val1 = values.peak();
        values.pop();
        char op = chars.peak();
        chars.pop();
        values.Push(calc(val1,val2,op));
    }

    return values.peak();
}


int main()
{
    char index[50];
    cout << "Enter equation: ";
    cin>>index ;
    cout << "Result = " << Solve(index) << endl;
    return 0;
}
