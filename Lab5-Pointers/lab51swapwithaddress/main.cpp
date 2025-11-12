#include <iostream>

using namespace std;

void swap(int* x , int* y)
{
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}
int main()
{
    int x = 5 ;
    int y = 7 ;
    cout << "The Numbers : " << endl;
    cout << x <<":" <<y << endl;
    swap(&x,&y);
    cout << "The Numbers After Swap  : " << endl;
    cout << x <<":" <<y << endl;
    return 0;
}
