#include <iostream>
#include<string.h>
using namespace std;
class String
{
    char* arr ;
public :
     String()
    {
        arr = new char[100];
    }



    ~String()
    {
        delete[] arr;
    }



         String(int x)
    {
        int size = snprintf(nullptr, 0, "%d", x);
        arr = new char[size + 1];
        sprintf(arr, "%d", x);

    }


         String(char* chars)
    {
        arr = new char[strlen(chars)+1];

        for (int i = 0; i < strlen(chars); i++) {
                arr[i] = chars[i];
                     }
           arr[strlen(chars)] = '\0';
    }


    void print()
    {
        for(int i= 0;i<strlen(arr);i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }


    String operator+(String& s)
    {
        String s3;
        s3.arr = new char[strlen(arr)+strlen(s.arr)+1] ;
        for(int i = 0;i<strlen(arr);i++)
        {
            s3.arr[i] = arr[i];
        }
        for(int i=strlen(arr);i<strlen(arr)+strlen(s.arr);i++)
        {
            s3.arr[i] = s.arr[i-strlen(arr)];
        }
        s3.arr[strlen(arr)+strlen(s.arr)] = '\0';
        return s3 ;
    }

    int operator> (String& s)
    {
        return strlen(arr) > strlen(s.arr) ;
    }

    int operator< (String& s)
    {
        return strlen(arr) < strlen(s.arr) ;
    }

    int operator== (String& s)
    {
        if(*this > s || *this < s) return 0 ;
        else{
            for(int i=0;i<strlen(arr);i++)
            {
                if(arr[i]==s.arr[i]) continue ;
                else return 0 ;
            }
            return 1;
        }
    }

 void ToUpper() {
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] >= 'a' && arr[i] <= 'z') {
                arr[i] -= 32;
            }
        }
    }

    void ToLower() {
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] >= 'A' && arr[i] <= 'Z') {
                arr[i] += 32;
            }
        }
    }

};


int main()
{
    cout << "Hello world!" << endl;
    String s1("amir#S");
    s1.ToUpper();
    String s2("mawla");
    s1.print();
    s2.print();

    if(s1==s2) cout<<"s1 == s2"<<endl;
    else if(s1>s2) cout<<"s1 > s2"<<endl;
    else if(s1< s2) cout<<"s1 < s2"<<endl;
    else cout<<" s1 equal s2 in size but not in value"<<endl;

    String s3 = s1+s2;
    s3.print();

    String s4(1234);
    s4.print();
    return 0;
}

