#include <iostream>

using namespace std;

int main()
{
    int star, blank, enter;

    for(enter=0; enter<5; enter++)
    {
        for(star=5; star>enter; star--)
        {
            cout << "*";
        }
        for(blank=0; blank<enter*2; blank++)
        {
            cout << " ";
        }
        for(star=5; star>enter; star--)
        {
            cout << "*";
        }
        cout << endl;
    }


    for(enter=1; enter<6; enter++)
    {
        for(star=0; star<enter; star++)
        {
            cout << "*";
        }
        for(blank=10-enter; blank>enter; blank--)
        {
            cout << " ";
        }
        for(star=0; star<enter; star++)
        {
            cout << "*";
        }
    cout << endl;
    }
}
