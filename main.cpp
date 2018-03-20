#include <iostream>

using namespace std;

int main()
{
    int star, space;

    for(int enter=1; enter<5; enter++)
    {
        for(space=1; space<5-enter; space++)
        {
            cout << " ";
        }
        for(star=1; star<enter*2; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

