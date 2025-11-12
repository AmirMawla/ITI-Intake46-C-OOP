#include <iostream>
#include <string.h>
#include<conio.h>
using namespace std;
class Stack
{
    int top;
    int size;
    int* arr ;
public :
    ~Stack()
    {
        cout<<"Object destructed";
        delete[] arr;
    }


    Stack(int _size = 5)
    {
        top = -1 ;
        size = _size;
        arr = new int [size];
    }


    Stack(Stack& s)
    {
        cout<<"copy constructor"<<endl;
        top = s.top;
        size = s.size;
        for(int i=0; i<=top; i++)
        {
            arr[i]=s.arr[i];
        }
    }



    void Push (int x )
    {
        if (top < size - 1)
        {
            top ++;
            arr[top] = x ;
            cout<<"Number :"<<x<<"Pushed Successfuly"<<endl;
        }
        else
        {
            cout<< "The Stack Is Full" <<endl;
        }
    }



    int pop(int* data)
    {
        if(top>=0)
        {
            *data = arr[top];
            top--;
            return 1;
        }
        else
        {
            return 0;
        }
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

void DeleteAll(Stack* s)
{
    int x ;
    cout<<endl;
    while(s->pop(&x) == 1)
    {
        cout<<x<<endl;

    }
    cout<<"The Stack Is Deleted"<<endl;

}


int main()
{
    cout << "Enter Size Of Stack :" << endl;
    int Size;
    bool Running = true ;
    cin>>Size;
    Stack s1(Size);
    _getch();
    while(Running)
    {
        cout << "Do You Want To Push Or Pop Or Print Or Exit Or DeleteAll   1/2/3/4/5 :" << endl;
        int num ;
        cin>> num ;
        _getch();
        switch(num)
        {
        case 1 :
            cout<<"Enter Number To Push :"<<endl;
            int data;
            cin>>data;
            s1.Push(data);
            break;
        case 2 :
            int d,ret;
            ret = s1.pop(&d);
            if(ret == 1)
            {
                cout<<"The Number Poped : "<<d<<endl;
            }
            else
            {
                cout << "The Stack Is Empty"<<endl;
            }

            break;
        case 3:
            s1.Print();
            break;

        case 4:
            Running = false;
            break;
        case 5:
            DeleteAll(&s1);
            break;
        }

    }
    return 0;



}
