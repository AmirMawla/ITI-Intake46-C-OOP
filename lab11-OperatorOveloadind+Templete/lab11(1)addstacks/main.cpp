#include <iostream>

using namespace std;
template<class T>
class Stack
{
    int top;
    int size;
    T* arr ;

public :
    ~Stack()
    {
//        cout<<"Object destructed"<<endl;;
        delete[] arr;
    }


    Stack(int _size = 10)
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

    Stack operator+(Stack& s2)
    {
        Stack s3(size+s2.size);
        s3.top = top +s2.top +1 ;
//        s3.arr= new T[size+s2.size];
      for(int i = 0;i<=s2.top;i++)
      {
          s3.arr[i]=s2.arr[i];
      }

      for(int i =s2.top +1;i<=s3.top;i++)
      {
          s3.arr[i]=arr[i - (s2.top +1)];
      }
      return s3 ;

    }

};
int main()
{
Stack<int> Stack1(20);
Stack<int> Stack2(20);
Stack1.Push(30);
Stack1.Push(20);
Stack1.Push(10);
Stack2.Push(60);
Stack2.Push(50);
Stack<int> stack3 = Stack1+Stack2 ;
stack3.Print();
return 0;
}
