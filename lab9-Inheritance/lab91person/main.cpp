#include <iostream>
#include <string.h>
using namespace std;

class Person{
int id;
char name[30];
int age;
public :
    Person(int _id =0,char* _name = "amir",int _age=13)
    {
        id = _id;
        strcpy(name , _name);
        age = _age;
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

    void Print()
    {
        cout<<id<<" : "<<name<<" : "<<age;
    }
};

class emp : public Person
{
    double salary ;
   public :
       emp(int _id =0,char* _name = "amir",int _age=13, double _salary =15000): Person(_id,_name,_age)
       {
           salary = _salary;
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
        Person::Print();
        cout<<" : "<<salary<<endl;
    }


};

class Student : public Person
{
    double grade ;
   public :
       Student(int _id =0,char* _name = "amir",int _age=13, double _grade =50): Person(_id,_name,_age)
       {
           grade = _grade;
       }

       int GetSgrade()
    {
        return grade;
    }

    void Setgrade(double _grade)
    {
        if(_grade < 0 && _grade >100)
            cout<<"Invalid grade"<<endl;

        else
            grade = _grade ;
    }

    void Print()
    {
        Person::Print();
        cout<<" : "<<grade<<endl;
    }


};


int main()
{

    Person p(1,"amir",23);
    emp e(1,"amir",23,15000);
    Student s(1,"amir",23,100);
    cout << "Person Details :" << endl;
    p.Print();
    cout<<endl<<"------------------------"<<endl;
    cout << "Emp Details :" << endl;
    e.Print();
    cout<<"------------------------"<<endl;
    cout << "Student Details :" << endl;
    s.Print();

    return 0;
}



