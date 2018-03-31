#include <iostream>

using namespace std;

int add(int *x, int *y, int z)
{
    *x = *x + z;
    *y = *y + z;
}
int main()
{
    int jumsu1, jumsu2;
    int sum=0;

    cout << "input jumsu " << endl;
    cin >> jumsu1;
    cin >> jumsu2;

    cout << "input add jumsu " << endl;
    cin >> sum;
    add(&jumsu1, &jumsu2, sum);

    cout << sum << "+" << endl;
    cout << "jumsu1 " << "= " << jumsu1 << endl;
    cout << "jumsu2 " << "= " << jumsu2 << endl;
}

