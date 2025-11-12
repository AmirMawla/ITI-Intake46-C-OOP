#include <iostream>
#include <string.h>
using namespace std;

class ba
{
    int id;
    char* name ;
    double balance;

public:
    void SetId(int _id)
    {
        id=_id;
    }
    int GetId()
    {
        return id;
    }

    void SetName(char* _name)
    {
        if(strlen(_name)<3 && strlen(_name)>20)
        {
            cout<<"Invalid Num Of Characters"<<endl;
        }
        else
            name = _name;
    }

    char* GetName()
    {
        return name;
    }


    int Getbalance()
    {
        return balance;
    }


    void Print()
    {
        cout<<"Bank Account Details :"<<endl;
        cout<< "[Id]"<<":"<<"[Name]"<<":"<<":"<<"[Balance]"<<endl;
        cout<<id<<" : "<<name<<"  :  "<<" :  "<<balance<<endl;
    }

    void WithDraw(int x)
    {
        if(x >= balance && x<=0)
            cout<<"Invalid number to withdraw!"<<endl;
        else
        {
            balance -= x ;
            cout<<"the proccess completed successfuly you Withdraw :"<<x<<endl;
            cout<<"Your Current Balance = "<<balance<<endl;
        }
    }

    void Deposit(int x)
    {
        if(x>0)
        {
            balance += x ;
            cout<<"the proccess completed successfulyyou Deposit :"<<x<<endl;
            cout<<"Your Current Balance = "<<balance<<endl;
        }
        else
        {
            cout<<"Invalid Number To Deposit"<<endl;
        }

    }

};

int main()
{
    ba b;
    b.SetId(1);
    b.SetName("Amir");
    b.Deposit(500);
    b.Print();
    b.WithDraw(200);
    b.Print();
    return 0;
}













