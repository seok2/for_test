#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int init_num,Count_num, array[100];

    cout << "Count num :";
    cin >>Count_num;

    cout << "question1 : " << "\t";

    for(init_num=1; init_num<30; init_num++)
    {
        if(init_num%3==1)
            cout << setw(4) << init_num << "  " ;
    }

    cout << endl;

    cout << "question2 : " << "\t";
    for(init_num=99; init_num>80; init_num--)
    {
        if(init_num%2==1)
            cout << setw(4) << init_num << "  ";
    }
    cout << endl;

    cout << "question3 : " << "\t";
    init_num = 98;
    for(int a=0; a<10; a++)
    {
        cout << setw(4) << init_num << "  ";
        init_num = init_num/2*-2;
    }
    cout << endl;

    cout << "question4 : " << "\t";
    init_num = 888;
    for(int a = 0; a < 10; a++)
    {
        cout << setw(4) << init_num << "  ";
        init_num = init_num/2;
    }
    cout << endl;

    cout << "question5 : " << "\t";
    init_num = -1;
    for(int a = 0; a < 10; a++)
    {
        cout << setw(4) << init_num << "  ";
        init_num = init_num*-2;
    }
    cout << endl;

    cout << "question6 : " << "\t";
    for(int a = 0; a < Count_num; a++)
    {
        data[a] = 1;

    }
}
