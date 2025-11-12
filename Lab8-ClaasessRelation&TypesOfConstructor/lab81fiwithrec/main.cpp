#include <iostream>

using namespace std;

int Fib(int x)
{
    if(x<0)
    {
        cout<<"No Fib For Negative Numbers"<<endl;
    }
    else if(x==1 || x==0)
    {
        return 1;
    }
    else
        return x * Fib(x-1);
}
int main()
{
    cout << "Enter Number" << endl;
    int x;
    cin>>x;
    cout<<"Result Of Fib Number "<<x <<" = " <<Fib(x)<<endl;
    return 0;
}
