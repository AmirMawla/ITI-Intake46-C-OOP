#include <iostream>

using namespace std;
class Queue {
int top;
int bottom;
int* arr;
int size ;
int numofelements;
public :
    Queue(int _size = 5)
    {
     size = _size;
     arr = new int [size];
     top=0;
     bottom=0;
     numofelements = 0;
    }

void Enqueue(int x)
{
    if(numofelements < size)
    {
        arr[top] = x ;
        numofelements ++;
        cout<<"The Value : "<<x<<" Enqueued Successfuly" <<endl;
        top = (top + 1) % size;
    }
    else cout<<"The Queue Is Full"<<endl;
}

int Dequeue()
{
    if (numofelements>0)
    {
        cout<<"The Value : "<< arr[bottom] << " Dequeued Successfuly" <<endl;
        bottom = (bottom+1) % size ;
        numofelements--;
    }
    else
        cout<<"The Queue Is Empty "<<endl;
}


void Print()
{


if (numofelements == 0)
        {
            cout << "The Queue Is Empty" << endl;
            return;
        }

        cout << "Queue Elements: "<<endl;
        for (int i = 0; i < numofelements; i++)
        {
            int index = (bottom + i) % size;
            cout << arr[index] << endl;
        }
        cout << endl;
    }

};
int main()
{
    cout << "Enter Size Of Queue :" << endl;
    int Size;
    cin>> Size;
    Queue q1(Size);
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.Dequeue();

    q1.Print();

    return 0;





}
