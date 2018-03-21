#include <iostream>

using namespace std;

int main()
{
    int inputnum1, inputnum2;
    cout << "input num1 : ";
    cin >> inputnum1;
    cout << "input num2 : ";
    cin >> inputnum2;

    for(int space=1; space<4; space++)
    {
    for(int enter=0; enter<1; enter++)
    {
        for(int star=0; star<inputnum1; star++)
        {
            cout << "ㅁ ";
        }
        cout << endl;
    }
    for(int enter=0; enter<1; enter++)
    {
        for(int star=0; star<inputnum2; star++)
        {
            cout << " ㅁ";
        }
        cout << endl;
    }
    }
}
