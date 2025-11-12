#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Employee {
    int id;
    char name[10];
    int age;
};



void displayEmployees(Employee arr[], int size) {
    system("cls");
    cout << "=== Employee List ===\n\n";
    bool empty = true;

    for (int i = 0; i < size; i++) {

            cout << "[" << i << "] ID: " << arr[i].id
                 << " | Name: " << arr[i].name
                 << " | Age: " << arr[i].age << endl;
            empty = false;

    }

    if (empty)
        cout << "(No employees to display)\n";

}


int main()
{
    int size ;
    cout << "Enter Number Of Employees  " << endl;
    cin>> size ;

     Employee Emps[size];

     for(int i=0 ; i<size ;i++)
     {
       cout << "Enter Employee "<< i+1 << " Details " << endl;
        cout<<"Enter Employee Id :";
        cin >> Emps[i].id;
        cout<<"Enter Employee Name :";
        cin >> Emps[i].name ;
        cout<<"Enter Employee Age :";
        cin >> Emps[i].age ;
     }

      displayEmployees(Emps,  size) ;

    return 0;

}
