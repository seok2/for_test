#include <iostream>

using namespace std;

int main()
{
    int i, j;
    for(i=1; i<5; i++)
    {
        for(j=0; j<5-i; j++)
        {
            cout << " ";
        }
        for(j=0; j<i*2-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

