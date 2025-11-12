#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;
public :
    ~Point()
    {
        cout<<"Point Destructed"<<endl;
    }

    Point(int _x = 0,int _y = 0)
    {
        cout<<"Point Constructed"<<endl;
        x=_x;
        y=_y;
    }
    void SetPoint(int _x, int _y)
    {
        x=_x;
        y = _y;
    }

    void Print()
    {
        cout<<"( "<<x<<" , "<<y<<" )"<<endl;
    }


};

class Rectangle
{

    Point* Ul ;
    Point* Lr;

public :
    ~Rectangle()
    {
        delete Ul;
        delete Lr;
        cout<<"Rectangle Destructed"<<endl;
    }
    Rectangle(int _x1=0,int _y1=0,int _x2=0,int _y2 = 0 )
    {
        Ul = new Point(_x1,_y1);
        Lr= new Point(_x2,_y2);
    }

    void print()
    {
        cout<<"Point Of Ul :";
        Ul->Print();
        cout<<"Point Of Lr :";
        Lr->Print();
    }

};

class Triangle
{

    Point* p1 ;
    Point* p2;
    Point* p3;

public :
    ~Triangle()
    {
        delete p1;
        delete p2;
        delete p3;
        cout<<"Triangle Destructed"<<endl;
    }
    Triangle(int _x1=0,int _y1=0,int _x2=0,int _y2 = 0, int _x3=0,int _y3 = 0 )
    {
        p1= new Point(_x1,_y1);
        p2= new Point(_x2,_y2);
        p3= new Point(_x3,_y3);
    }

    void print()
    {
        cout<<"Point Of p1 :";
        p1->Print();
        cout<<"Point Of p2 :";
        p2->Print();
        cout<<"Point Of p3 :";
        p3->Print();
    }

};

class Circle
{

    Point* c ;
    float root ;

public :
    ~Circle()
    {
        delete c;
        cout<<"Circle Destructed"<<endl;
    }

    Circle(int _x1=0,int _y1=0, float _root = 0)
    {
        c= new Point(_x1,_y1);
        root = _root ;
    }

    void print()
    {
        cout<<"Point Of Centre :";
        c->Print();
        cout<<"Root :"<<root<<endl;
    }

};


int main()
{

    Rectangle r1(1,1,1,1),r2;
    Triangle t(1,1,1,1,1,1);
    Circle c(2,2,2.5);
    cout<<"Rectangle 1 :"<<endl;
    r1.print();
    cout<<"Rectangle 2 :"<<endl;
    r2.print();

    cout<<"Triangle :"<<endl;
    t.print();

    cout<<"Circle :"<<endl;
    c.print();


    return 0;
}
