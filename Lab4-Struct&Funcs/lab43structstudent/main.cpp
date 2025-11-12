#include <iostream>
#include <conio.h>
using namespace std;

struct Student{
int Id ;
char Name[10];
int Age ;
};

void PrintStudent(Student Std)
{
 cout <<  " ID: " << Std.Id
                 << " | Name: " << Std.Name
                 << " | Age: " << Std.Age << endl;
}

int main()
{
    Student student ;
    cout << "Enter Student Details " << endl;
    cout<<"Enter Student Id :" << endl;
    cin >> student.Id ;
    cout<<"Enter Student Name :" << endl;
    cin >> student.Name ;
    cout<<"Enter Student Age :" << endl;
    cin >> student.Age ;

    cout << "Student Details :" << endl ;
    PrintStudent(student);
    return 0;
}
