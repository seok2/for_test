#include <iostream>

using namespace std;

int main()
{
    int star, enter, space;

    for(enter=1; enter<5; enter++)
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

    for(enter=1; enter<4; enter++)
    {
        for(space=0; space<enter; space++)
        {
            cout << " ";
        }
        for(star=7; star>enter*2; star--)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;

}
