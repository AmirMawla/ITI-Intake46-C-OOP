#include <iostream>

using namespace std;
const double PI = 3.14159265358979323846;
class Shape
{
protected:
    float dim1,dim2;
public :
    Shape()
    {
        dim1 = dim2 = 1;
    }
    Shape(float x )
    {
        dim1=dim2 = x;
    }
    Shape(float _dim1, float _dim2 )
    {
        dim1 = _dim1;
        dim2 = _dim2;
    }

   virtual double CalcArea()=0;
   virtual void print()=0;
};

class Rectangle: public Shape
{

public :

    Rectangle(float _dim1, float _dim2) : Shape(_dim1,_dim2)
    {
    }

    double CalcArea()
    {
        return dim1 * dim2 ;
    }

    void print()
    {
        cout<<"Rectangle Details : "<<endl;
        cout<<"Shape Dimentions : "<< dim1 << " , " <<dim2<<endl;
        cout << "Area = "<<CalcArea()<<endl;
    }

};

class Triangle: public Shape
{

public :

    Triangle(float _dim1, float _dim2 ) : Shape(_dim1,_dim2)
    {
    }

    double CalcArea()
    {
        return  0.5 * dim1 * dim2 ;
    }

    void print()
    {
        cout<<"Triangle Details : "<<endl;
        cout<<"Shape Dimentions : "<< dim1 << " , " <<dim2<<endl;
        cout << "Area = "<<CalcArea()<<endl;
    }

};

class Circle: public Shape
{

public :

    Circle(int dim ) : Shape(dim)
    {
    }

    double CalcArea()
    {
        return PI * dim1 * dim2  ;
    }

    void print()
    {
        cout<<"Circle Details : "<<endl;
        cout<<"Shape Dimentions : "<< dim1 << " , " <<dim2<<endl;
        cout << "Area = "<<CalcArea()<<endl;
    }

};

class Square : public Rectangle
{
    public :
    Square(int dim = 1) : Rectangle(dim , dim){}
     void print()
    {
        cout<<"Square Details : "<<endl;
        cout<<"Shape Dimentions : "<< dim1 << " , " <<dim2<<endl;
        cout << "Area = "<<Rectangle::CalcArea()<<endl;
    }

};
void Myfun(Shape* s)
{
    s->print();
}

int main()
{
    float dim1,dim2;
    int Size = 4;
    Shape* shapes[4];
    cout<<"Enter Dimensions :"<<endl;
    cout<<"Ented Dim1 : "<<endl;
    cin>>dim1;
    cout<<"Ented Dim2 : "<<endl;
    cin>>dim2;


    shapes[0] = new Rectangle(dim1,dim2);
    shapes[1] = new Triangle(dim1,dim2);
    shapes[2] = new Circle(dim1);
    shapes[3] = new Square(dim1);

    for( int i=0 ; i<Size ; i++)
    {
       Myfun( shapes[i] );
    }
//    r1.print();
//    t.print();
//    c.print();
//    s.print();

    return 0;
}
