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
public :
    void Print()
    {
        cout<<id<<" : "<<name << " : " << age <<endl;

    }
};

class Stack
{
    int top;
    int size;
    Employee* arr ;
public :
    ~Stack()
    {
        cout<<"Object destructed";
        delete[] arr;
    }


    Stack(int _size = 5)
    {
        top = -1 ;
        size = _size;
        arr = new Employee [size];
        for (int i = 0; i < size; i++)
            arr[i].filled = false;
    }


    Stack(Stack& s)
    {
        cout<<"copy constructor"<<endl;
        top = s.top;
        size = s.size;
        for(int i=0; i<=top; i++)
        {
            arr[i]=s.arr[i];
        }
    }

    void Setsize(int _size)
    {
        size = _size;
    }

    int Getsize()
    {
        return size;
    }

    void SetEmployeeAtIndex(int _index, int _id,char* _name,int _age)
    {
        arr[_index].id = _id;
        strcpy( arr[_index].name, _name);
        arr[_index].age = _age;
        arr[_index].filled = true ;
    }

    Employee GetEmpAtIndex(int _index)
    {
        return arr[_index] ;
    }

    bool getArrIndfilled(int index)
    {
        return  arr[index].filled ;
    }


    void Push (Employee x )
    {
        if (top < size - 1)
        {
            top ++;
            arr[top].id = x.id ;
            strcpy( arr[top].name, x.name );
            arr[top].age = x.age;
            arr[top].filled = true;
            cout<<"Employee Pushed Successfuly"<<endl;
        }
        else
        {
            cout<< "The Stack Is Full" <<endl;
        }
    }



    int pop(Employee* data)
    {
        if(top>=0)
        {
            (*data).id = arr[top].id;
            strcpy((*data).name,arr[top].name);
            (*data).age = arr[top].age;
            (*data).filled = arr[top].filled;
            top--;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void Peak()
    {

        if(top>=0)
        {

            Employee emp = arr[top];
            emp.Print();
        }
        else
        {
            cout << "The Stack Is Empty: "<<endl;
        }
    }


    void Print()
    {
        if(top<0)
            cout<<"The Stack Is Empty"<<endl;
        else
        {
            cout<<endl;
            for(int i= top ; i>=0; i--)
                cout<<arr[i].id<<" : "<<arr[i].name << " : " << arr[i].age <<endl;
        }
    }

};

//void DeleteAll(Stack* s)
//{
//    int x ;
//    cout<<endl;
//    while(s->pop(&x) == 1)
//    {
//        cout<<x<<endl;
//
//    }
//    cout<<"The Stack Is Deleted"<<endl;
//
//}



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


void addEmployee(Stack& s)
{
    system("cls");
    int index;
    cout << "Enter index (0 - " << s.Getsize() - 1 << ") to insert new employee: ";
    cin >> index;

    if (index < 0 || index >= s.Getsize())
    {
        cout << "Invalid index" << endl;

        _getch();
        return;
    }

    if (s.getArrIndfilled(index))
    {
        cout << "This position already has data for employee:\n"
             << "ID: " << s.GetEmpAtIndex(index).id
             << " | Name: " << s.GetEmpAtIndex(index).name
             << " | Age: " << s.GetEmpAtIndex(index).age << endl;

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
    s.Push(e);

    _getch();
}


void displayEmployees(Stack& s)
{
    system("cls");
    cout << "=== Employee List ===\n\n";

    s.Print();
    _getch();
}


int main()
{
    char menu[5][8] = {"New", "Display","Pop", "peak", "Exit"};
    int selected = 0;
    int numItems = 5;
    bool running = true;
    const int SIZE = 5;
    Stack s1(SIZE) ;

    while (running)
    {
        system("cls");
        cout << "=== Menu ===\n\n";
        for (int i = 0; i < 5; i++)
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
                addEmployee(s1);
                break;
            case 1:
                displayEmployees(s1);
                break;
            case 2 :
                system("cls");
                Employee e;
                int a;
                a = s1.pop(&e);
                if(a==1)
                {
                    cout<<"The Employee Poped :"<<endl;
                    e.Print();
                }
                else
                    cout<<"The Stack Is Empty"<<endl;
                _getch();
                break ;
            case 3 :
                system("cls");
                s1.Peak();
                _getch();
                break;
            case 4:
                running = false;
                break;
            }
            break;
        case 27:
            running = false;
            break;
        }
    }

    system("cls");
    return 0;
}

