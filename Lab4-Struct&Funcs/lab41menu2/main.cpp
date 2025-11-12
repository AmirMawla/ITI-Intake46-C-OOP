#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Employee
{
    int id;
    char name[10];
    int age;
    bool filled;
};


void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void addEmployee(Employee* arr, int size)
{
    system("cls");
    int index;
    cout << "Enter index (0 - " << size - 1 << ") to insert new employee: ";
    cin >> index;

    if (index < 0 || index >= size)
    {
        cout << "Invalid index" << endl;

        _getch();
        return;
    }

    if (arr[index].filled)
    {
        cout << "This position already has data for employee:\n"
             << "ID: " << arr[index].id
             << " | Name: " << arr[index].name
             << " | Age: " << arr[index].age << endl;

        _getch();
        return;
    }

    Employee e;
    cout << "Enter Employee ID: ";
    cin >> e.id;
    cout << "Enter Employee Name: ";
    cin >> e.name;
    cout << "Enter Employee Age: ";
    cin >> e.age;
    e.filled = true;

    arr[index] = e;
    cout << "\nEmployee added successfully!" << endl;

    _getch();
}


void displayEmployees(Employee* arr, int size)
{
    system("cls");
    cout << "=== Employee List ===\n\n";
    bool empty = true;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].filled)
        {
            cout << "[" << i << "] ID: " << arr[i].id
                 << " | Name: " << arr[i].name
                 << " | Age: " << arr[i].age << endl;
            empty = false;
        }
    }

    if (empty)
        cout << "(No employees to display)\n";


    _getch();
}


int main()
{
    char menu[3][8] = {"New", "Display", "Exit"};
    int selected = 0;
    int numItems = 3;
    bool running = true;

    const int SIZE = 5;
    Employee* employees = new Employee[SIZE];
    for (int i = 0; i < SIZE; i++)
        employees[i].filled = false;

    while (running)
    {
        system("cls");
        cout << "=== Menu ===\n\n";

        for (int i = 0; i < 3; i++)
        {
            if (i == selected)
            {
                setColor(10);
                gotoxy(10, 5 + i);
                cout << " > " << menu[i] << endl;
                setColor(7);
            }
            else
            {
                gotoxy(10, 5 + i);
                cout << "   " << menu[i] << endl;
            }
        }

        int key = _getch();
        switch (key)
        {
        case 224:
        {
            key = _getch();
            switch (key)
            {
            case 72:
                selected--;
                if (selected < 0) selected = numItems - 1;
                break;
            case 80:
                selected++;
                if (selected >= numItems) selected = 0;
                break;
            }
            break;
        }

        case 13:
            switch (selected)
            {
            case 0:
                addEmployee(employees, SIZE);
                break;
            case 1:
                displayEmployees(employees, SIZE);
                break;
            case 2:
                running = false;
                delete[] employees;
                break;
            }
            break;

        case 27:
            running = false;
            delete[] employees;
            break;
        }
    }

    system("cls");
    return 0;
}

