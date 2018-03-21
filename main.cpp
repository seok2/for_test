#include <iostream>

using namespace std;

int main()
{
    int random_countnum, random_num, store;
    int random_sum=0;
    cout << "random arange num = ";
    cin >> random_countnum;

    for(store=0; store<random_countnum; store++)
    {
        cin >> random_num;
        random_sum += random_num;
    }

    cout << random_sum << endl;;

    return 0;

}
