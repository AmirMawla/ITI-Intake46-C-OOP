#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;
    static int no ;

public:
    Complex(int _real = 0 , int _img = 0){
    real = _real;
    img = _img ;
    no++ ;

    }


//    Complex(Complex& c)
//    {
//        real = c.real ;
//        img = c.img ;
//        no++ ;
//    }


    ~Complex()
    {
        no--;
    }

    static int Getnu()
    {
        return no ;
    }

    void SetReal(int _real)
    {
        real=_real;
    }
    int GetReal()
    {
        return real;
    }

    void SetImg(int _img)
    {
        img = _img ;
    }

    int GetImg()
    {
        return img;
    }



    void Print()
    {
        cout<<"Complex Number  :";
        if(img>0 && real != 0)
        {
            cout<<real<<"+"<<img<<"j"<<endl;
        }
        else if (img<0 && real!=0)
        {
            cout<<real<<img<<"j"<<endl;
        }
        else if (img == 0 && real != 0)
        {
            cout<<real<<endl;
        }
        else if (real==0 && img!=0)
        {
            cout<<img<<"j"<<endl;
        }
        else
        {
            cout<<0;
        }
    }



    Complex Add(Complex c2)
    {
//         cout<<"no during make add function which take one complex parameter and its member function :"<<Complex::Getnu()<<endl;
        Complex res;
        res.real = real + c2.real ;
        res.img = img + c2.img ;
        return res ;
    }

    Complex operator+(Complex& c)
    {
        return Complex(real+c.real , img+c.img);
    }

    Complex operator+(int x)
    {
        return Complex(real+x ,img);
    }

    int operator==(Complex& c)
    {
        return real == c.real && img == c.img ;
    }

    int operator !=(Complex& c)
    {
        return real != c.real || img != c.img ;
    }

    Complex operator++()
    {
        real ++ ;
        return *this ;
    }

    Complex operator++(int)
{
     Complex newcpl(real,img);
        real ++ ;
        return newcpl ;
}

 explicit operator int()
{
    return real ;
}
};




int Complex::no = 0 ;

Complex operator+(int x , Complex& c)
{
    return Complex(x+c.GetReal(),c.GetImg());
}


Complex Substract(Complex c1, Complex c2)
{
//    cout<<"no during make Substract function which take two complex parameter and its standalone function :"<<Complex::Getnu()<<endl;
    Complex res;
    res.SetReal(c1.GetReal()-c2.GetReal());
    res.SetImg(c1.GetImg()-c2.GetImg());
    return res ;
}





void Print(int real, int img)
{
    cout<<"Complex Number  :";
    if(img>0 && real != 0)
    {
        cout<<real<<"+"<<img<<"j"<<endl;
    }
    else if (img<0 && real!=0)
    {
        cout<<real<<img<<"j"<<endl;
    }
    else if (img == 0 && real != 0)
    {
        cout<<real<<endl;
    }
    else if (real==0 && img!=0)
    {
        cout<<img<<"j"<<endl;
    }
    else
    {
        cout<<0;
    }

}




int main()
{
    Complex c1,c2,res,res2;

//    cout<<"no After Creating Four Objects :"<<Complex::Getnu()<<endl;
    int rel1,rel2,img1,img2;


    cout<<"Enter Number 1 :"<<endl;
    cout<<"Enter Real Part :"<<endl;
    cin>>rel1;
    cout<<"Enter Imag Part :"<<endl;
    cin>>img1;
    cout<<endl;
    cout<<"Enter Number 2 :"<<endl;
    cout<<"Enter Real Part :"<<endl;
    cin>>rel2;
    cout<<"Enter Imag Part :"<<endl;
    cin>>img2;



    c1.SetReal(rel1);
    c1.SetImg(img1);
    c2.SetReal(rel2);
    c2.SetImg(img2);
    res =c1.Add(c2);
//    cout<<"no After return from  make add function which take one complex parameter and its member function :"<<Complex::Getnu()<<endl;
    res2 = Substract(c1,c2);
//    cout<<"no After make Substract function which take two complex parameter and its standalone function :"<<Complex::Getnu()<<endl;
cout<<"-------------------------------------"<<endl;
    cout << "The Result Of: "<<endl;
    c1.Print();
    cout << "Add "<<endl;
    c2.Print();
    cout << "Equal "<<endl;
    res.Print();
    cout<<endl;
    cout << "The Result Of: "<<endl;
    c1.Print();
    cout << "Substract "<<endl;
    c2.Print();
    cout << "Equal "<<endl;
    res2.Print();

    cout<<"--------------------------"<<endl;
    Complex c3;
    c3 = c1+ c2 ;
    c3.Print();
    Complex c4;
    c4 = c3 + 2 ;
    c4.Print();
    Complex c5;
    c5 = 2+c4 ;
    c5.Print();

    if(c4==c5)
        cout<<"c4 equal c5"<<endl;
    else cout<< "c4 not equal c5"<<endl;

    if(c4 != c5)
        cout<<"c4 not equal c5"<<endl;
    else cout<< "c4 equal c5"<<endl;


    Complex c6;
    c6 = ++c5;
    c6.Print();
    Complex c7;
    c7 =c6++;
    c7.Print();
    c6.Print();

    int z;
    z = (int) c6;
    cout<<z<<endl;
    Complex c8 ;
    c8 = z;
    c8.Print();


    return 0;
}





