#include <iostream>

using namespace std;

int main()
{
    int size;
    int* arr = new int[size];
    cout << "Enter Size Of Array :"<<endl;
    cin>>size;
    for(int i=0 ; i<size ;i++)
    {
        cout<<"Enter Number"<<i+1<<":"<<endl;
        cin>>arr[i];
    }
    cout<<"The Array :"<<endl;
        for(int i=0 ; i<size ;i++)
    {
        cout<<arr[i]<<",";
    }
    return 0;
}
