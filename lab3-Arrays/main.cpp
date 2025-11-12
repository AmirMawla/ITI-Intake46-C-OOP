#include <iostream>
#include <windows.h>
#include <conio.h>

#define size 10

using namespace std;


void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void oneDimentionsArray()
{
    double arr[size] = {0};
    int idx, findFlag = 0, continueFlag = 1;
    char input;
    long double sum = 0, minimum, maximum;
    double avg, f;


    cout << "Input 10 int numbers to be stored in the array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }


    sum = minimum = maximum = avg = arr[0];
    cout << "your array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "index: " << i << "\t" << arr[i] << endl;

        // calculations:
        sum += arr[i];
        if (arr[i] > maximum)
            maximum = arr[i];
        if (arr[i] < minimum)
            minimum = arr[i];
    }
    avg = sum / size;


    cout << "results are" << endl;
    cout << "sum value is : " << sum << endl;
    cout << "min value is : " << minimum << endl;
    cout << "max value is : " << maximum << endl;
    cout << "avg value is : " << avg << endl;

    cout << "Input a number to search for in the array: " << endl;
    while (continueFlag == 1)
    {
        cin >> f;
        for (int i = 0; i < size; i++)
        {
            if (f == arr[i])
                {
                    findFlag = 1;
                    idx = i;
                }
        }
        if (findFlag == 1)
        {

            cout << "we found the value " << f << " in the index " << idx << endl;

        }
        else
        {
            cout << "we could not find your value" << endl;
        }
        cout << "pres [e] to exit or [any other key] to search for another value" << endl;
        input = getch();
        switch (input)
        {
        case 'e':
        case 'E':
            continueFlag = 0;
            break;
        default:
            continueFlag = 1;
            findFlag = 0;
            break;
        }
    }

}

void bigDistance()
{
    double arr[size] = {0};
    int maxDistance = 0, counter = 0, startIdx, endIdx;

    cout << "Input 10 int numbers to find the biggest distance between two similar numbers in it:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i ++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i != j && arr[i] == arr[j] && abs(i - j) > maxDistance)
                {
                    maxDistance = abs(i - j);
                    startIdx = i;
                    endIdx = j;

                }
        }
    }

    cout << "results is: " << maxDistance - 1 << endl;

    cout <<"Start Index :"<<startIdx << " , "<<"End Index : "<<endIdx<<endl;

        cout <<"Value : "<< arr[startIdx];
}

void TwoDimentionsArray()
{
    int students = 3, subs = 5;
    double arr[students][subs] = {0};
    short validFlag = 0;
    double buff, stSum = 0, stAvg = 0;

    for(int i = 0; i < students; i++)
    {
        cout << "input student no " << i + 1 << " grades [0 => 100]" << endl;
        cout << "sub1\tsub2\tsub3\tsub4\tsub5" << endl;
        for(int j = 0; j < subs; j++)
        {
                while (validFlag == 0)
                {
                    cin >>  buff;
                    if (buff > 100 || buff < 0)
                    {
                        cout << "invalid value" << endl;
                    } else
                    {
                        validFlag = 1;
                        arr[i][j] = buff;
                    }
                }
                validFlag = 0;

        }
    }


    cout << "results are:" << endl;
    cout << "sub1\tsub2\tsub3\tsub4\tsub5\t";
    cout << "total\tavg\t" << endl;
    for(int i = 0; i < students; i++)
    {
        for(int j = 0; j < subs + 1; j++)
        {
            if (j == subs)
            {
                cout << stSum << "\t";
            }
            else
            {
                cout << arr[i][j] << "\t";
                stSum += arr[i][j];
            }
        }
        stAvg = stSum / subs;
        stSum = 0;
        cout << stAvg << "\t" << endl;
    }
}

void magicBox(){
    int input, last = 1, flag = 0, c, l;
    cout << "Input an odd number to make a magic box:" << endl;
    while (flag == 0){
        cin >> input;
        if (input % 2 == 0 || input <= 0)
        {
            cout << "Invalid input, choose an odd positive number:" << endl;
        }
        else
            flag = 1;
    }

    system("cls");
    c = input / 2 + 1;
    l = 1;
    gotoxy((c - 1) * 4, l - 1);
    cout << 1;

    for (int i = 2; i <= input * input; i++){
        if (last % input == 0){
            if (l + 1 > input)
                l = 1;
            else
                l += 1;
        } else {
            if (l - 1 < 1)
                l = input;
            else
                l -= 1;
            if (c - 1 < 1)
                c = input;
            else
                c -= 1;
        }
        gotoxy((c - 1) * 4, l - 1);
        cout << i;
        last = i;
    }
}


void bubbleSort(){
    long long int arr[size];
    long long int temp;
    cout << "input 10 int values to sort using bubble sort\n";
    for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

    for (int i = 0; i < size - 1; i++)
    {
       for (int j = 0; j < size - i - 1; j++)
        {
             if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        }
    }

    cout << "sorted array \n";
    for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
}


int main()
{
//    oneDimentionsArray();
//    bigDistance();
//    TwoDimentionsArray();
//    magicBox();
//    bubbleSort();
    return 0;
}
