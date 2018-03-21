#include <iostream>

using namespace std;

int main()
{
    int inputnum, enter, star, space;
    cout << "count num input : ";
    cin >> inputnum;

    for(enter=1; enter<inputnum; enter++)
    {
        for(space=1; space<inputnum-enter; space++)
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
