#include <iostream>

using namespace std;
class Parent
{
    int x,y ;
public :
    Parent(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    virtual int add()
    {
        return x+y;
    }
};

class Child : public Parent
{
    int z;
public :
    Child(int _x = 0  ,int _y = 0,int _z = 0) : Parent(_x,_y)
    {
        z=_z;
    }
    int add()
    {
        return Parent::add() + z ;
    }
};

int main()
{
    int a,b,c;

    cout << "Enter Numbers :" << endl;
    cout << "__________________________" << endl;
        cout<<"Enter number 1 :"<<endl;
        cin>>a;
        cout<<"Enter number 2 :"<<endl;
        cin>>b;
        cout<<"Enter number 3 :"<<endl;
        cin>>c;
        Child ch(a,b,c);
         cout << "__________________________" << endl;
         cout<<"Result :"<<ch.add();
    return 0;
}
