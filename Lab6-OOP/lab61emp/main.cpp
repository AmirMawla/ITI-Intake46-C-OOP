#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
    int id;
    char name[50] ;
    int age ;
    double salary;

public:

    Employee ()
    {
        id = 1;
        strcpy(name, "amir");
        age = 30;
        salary = 6000;
    }

    Employee (int _id)
    {
        id = _id;
        strcpy(name, "amir");
        age = 30;
        salary = 6000;
    }

    Employee (int _id,double _salary)
    {
        id = _id;
        strcpy(name, "amir");
        age = 30;
        salary = _salary;
    }


    Employee (int _id, int _age,double _salary)
    {
        id = _id;
        age = _age;
        strcpy(name, "amir");
        salary = _salary;
    }


    Employee (int _id, char* _name, int _age,double _salary)
    {
        id = _id;
        strcpy(name, _name);
        age = _age;
        salary = _salary;
    }


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
            strcpy(name, _name);
    }

    int GetAge()
    {
        return age;
    }

    void SetAge(int _age)
    {
        if(_age < 12 && _age >50)
            cout<<"Invalid Age"<<endl;

        else
            age = _age;
    }

    int GetSalary()
    {
        return salary;
    }

    void SetSalary(double _salary)
    {
        if(_salary < 12000 && _salary >50000)
            cout<<"Invalid Salary"<<endl;

        else
            salary = _salary ;
    }

    void Print()
    {
        cout<<"Employee Details :"<<endl;
        cout<< "[Id]"<<":"<<"[Name]"<<":"<<"[Age]"<<":"<<"[Salary]"<<endl;
        cout<<id<<" : "<<name<<"  :  "<<age<<" :  "<<salary<<endl;
    }

};
int main()
{

    Employee e1,e2(3,24,17000);

    e1.SetId(1);
    e1.SetName("Amir");
    e1.SetAge(23);
    e1.SetSalary(15000);
    e1.Print();
    cout<<endl;
    e2.Print();
    return 0;
}







