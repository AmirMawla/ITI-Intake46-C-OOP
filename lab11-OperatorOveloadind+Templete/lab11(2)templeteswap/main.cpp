#include <iostream>

using namespace std;
template<class t>
void Swap(t& a , t& b)
{
     t temp = a;
     a=b;
     b= temp ;
}
int main()
{
    double x,y;
    cout << "Enter Two numbers :" << endl;
    cin>>x>>y;
    Swap(x,y);
    cout<<"Numbers After Swap : "<<x<<" , "<<y<<endl;
    return 0;
}
