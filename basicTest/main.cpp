#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int sum(int x, int y)
{
    int z;
    z = x + y;
    return z;
}

int sub(int x, int y)
{
    int z;
    z = x-y;
    return z;
}

int multiple(int x, int y)
{
    int z;
    z = x*y;
    return z;
}

int division(int x, int y)
{
    int z;
    z = x/y;
    return z;
}

int namuji(int x, int y)
{
    int z;
    z = x%y;
    return z;
}

int main()
{
    int value1, value2, year, month, days, tries, var;
    char oper, ch, answer, guess;
    cout << "question 1. case calculate : " << endl;
    while(true)
    {
        cout << ">> input value ? (0 0 0)-> next";
        cin >> value1 >> oper >> value2;

        if(value1 == 0 && oper == '0' && value2 == 0)
            break;
    switch(oper)
    {
    case '+':
        cout << "result : " << value1 << oper << value2 << " = " << value1+value2 << endl;
    break;

    case '-':
        cout << "result : " << value1 << oper << value2 << " = " << value1-value2 << endl;
    break;

    case '*':
        cout << "result : " << value1 << oper << value2 << " = " << value1*value2 << endl;
    break;

    case '/':
        cout << "result : " << value1 << oper << value2 << " = " << value1/value2 << endl;
    break;

    case '%':
        cout << "result : " << value1 << oper << value2 << " = " << value1%value2 << endl;
    break;
    }
    cout << endl;
    }

    cout << "question 2. function calculate : " << endl;

    while(true)
    {
        cout << ">> (fu)input value ? (0 0 0)-> next";
        cin >> value1 >> oper >> value2;
        if(value1 == 0 && oper == '0' && value2 == 0)
            break;

    switch(oper)
    {
    case '+':
        cout << "result : " << value1 << oper << value2 << " = " << sum(value1, value2) << endl;
        break;
    case '-':
        cout << "result : " << value1 << oper << value2 << " = " << sub(value1, value2) << endl;
        break;
    case '*':
        cout << "result : " << value1 << oper << value2 << " = " << multiple(value1, value2) << endl;
        break;
    case '/':
        cout << "result : " << value1 << oper << value2 << " = " << division(value1, value2) << endl;
        break;
    case '%':
        cout << "result : " << value1 << oper << value2 << " = " << namuji(value1, value2) << endl;
        break;
    }
    cout << endl;
    }

    cout << "question 3. judgment (/)-> next" << endl;

    while(true)
    {
        cout << "input anything : ";
        cin >> ch;

        if(ch == '/')
        {
            break;
        }
        if((int)ch >=48 && (int)ch <= 57)
        {
            cout << "number." << endl;
        }
        else if((int)ch >=65 && (int)ch <= 90)
        {
            cout << "Big Alpha." << endl;
        }
        else if((int)ch >=97 && (int)ch <= 122)
        {
            cout << "Small Alpha." << endl;
        }
        else
        {
            cout << "Other Ch." <<endl;
        }
    }
    cout << "question 4. Month and day (0)->next" << endl;

    while(true){

        cout << ">> input month : ";
        cin >> month;
        if(month==0)
        {
            break;
        }
        if(month <1 || month > 12)
        {
            cout << "1~12 input!" << endl;
        }
        else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            cout << "31." << endl;
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            cout << "30." << endl;
        }
        else if(month==2)
        {
            cout << "Input year : ";
            cin >> year;
            if(year%4 == 0 && year%100 != 0 || year%400 == 0)
                cout << "29" <<endl;
            else
                cout << "28" <<endl;
        }

    }
    cout << "question 5. Match char" << endl;

        srand((unsigned)time(NULL));
        answer = (rand()%26)+97;
        tries = 0;

        while(1)
        {
            cout<< tries+1 << ". >> input smallalphabet : ";
            cin >> ch;
            tries++;

            if((int)ch > answer)
            {
                cout << "ch > ascii!" << endl;
            }
            else if((int)ch < answer)
            {
                cout << "ch < ascii!" << endl;
            }
            else if((int)ch == answer)
            {
                cout << "Victory!!" << tries << "time you corret" << endl;
                break;
            }

      }
}

