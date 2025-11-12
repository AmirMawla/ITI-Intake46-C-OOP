#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    int* ptr = arr ;
    cout<<"The Array :"<<endl;

    for(int i =0 ;i<5 ;i++)
    {

        cout<<arr[i]<<"," ;
    }
    cout <<endl;
        for(int i =0 ;i<5 ;i++)
    {

        cout<<ptr[i]<<"," ;
    }
    cout <<endl;
        for(int i =0 ;i<5 ;i++)
    {

        cout<<*(ptr+i)<<"," ;
    }

    return 0;
}
