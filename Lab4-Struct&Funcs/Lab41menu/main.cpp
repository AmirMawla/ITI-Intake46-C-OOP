#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Employee {
    int id;
    char name[10];
    int age;
    bool filled;
};

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// NEW EMPLOYEE
void addEmployee(Employee arr[], int size) {
    system("cls");
    int index;
    cout << "Enter index (0 - " << size - 1 << ") to insert new employee: ";
    cin >> index;

    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        cout << "\nPress any key to continue...";
        _getch();
        return;
    }

    if (arr[index].filled) {
        cout << "This position already has data for employee:\n"
             << "ID: " << arr[index].id
             << " | Name: " << arr[index].name
             << " | Age: " << arr[index].age << endl;
        cout << "\nPress any key to continue...";
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
    cout << "\nPress any key to continue...";
    _getch();
}

// DISPLAY EMPLOYEES
void displayEmployees(Employee arr[], int size) {
    system("cls");
    cout << "=== Employee List ===\n\n";
    bool empty = true;

    for (int i = 0; i < size; i++) {
        if (arr[i].filled) {
            cout << "[" << i << "] ID: " << arr[i].id
                 << " | Name: " << arr[i].name
                 << " | Age: " << arr[i].age << endl;
            empty = false;
        }
    }

    if (empty) cout << "(No employees to display)\n";
    cout << "\nPress any key to continue...";
    _getch();
}

int main() {
    char menu[3][8] = {"New", "Display", "Exit"};
    int numItems = sizeof(menu) / sizeof(menu[0]);
    int selected = 0;
    bool running = true;

    const int SIZE = 5;
    Employee employees[SIZE];

    for (int i = 0; i < SIZE; i++) employees[i].filled = false;

    while (running) {
        system("cls");
        cout << "=== Menu ===\n\n";

        for (int i = 0; i < numItems; i++) {
            if (i == selected) {
                setColor(10);
                cout << " > " << menu[i] << endl;
                setColor(7);
            } else {
                cout << "   " << menu[i] << endl;
            }
        }

        int key = _getch();
        switch (key) {
            case 224: {
                key = _getch();
                switch (key) {
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
                switch (selected) {
                    case 0:
                        addEmployee(employees, SIZE);
                        break;
                    case 1:
                        displayEmployees(employees, SIZE);
                        break;
                    case 2:
                        running = false;
                        break;
                }
                break;

            case 27: // ESC
                running = false;
                break;
        }
    }

    system("cls");
    cout << "Exiting app... Goodbye!" << endl;
    return 0;
}

