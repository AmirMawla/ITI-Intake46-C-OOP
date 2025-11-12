#include <iostream>
#include<string.h>
using namespace std;

class Product{
char* name ;
double price ;
int quantity;

void SetName(char* _name)
{
    if(strlen(_name)>= 2)
    {
        name=_name;
    }
    else{
        cout<<"Invalid Num Of Characters"<<endl;
    }
}

char* GetName()
{
    return name;
}



void SetPrice(double _price)
{
    if(_price > 0)
    {
        price=_price;
    }
    else{
        cout<<"Invalid Price"<<endl;
    }
}

double GetPrice()
{
    return price;
}

void SetQuantity(int _quantity)
{
    if(_quantity > 0)
    {
        price=_price;
    }
    else{
        cout<<"Invalid Quantity"<<endl;
    }
}

double GetQuantity()
{
    return quantity;
}


void Print()
{
    cout<<name<<"  :  "<<price<<"  :  "<<"  :  "
}

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
