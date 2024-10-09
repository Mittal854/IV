#include<iostream>
#include<vector>
using namespace std;

unsigned long getUgly(int n)
{
    vector<unsigned long> ugly(n);

    ugly[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;

    unsigned long next_multiple_of_2 = 2;
    unsigned long next_multiple_of_3 = 3;
    unsigned long next_multiple_of_5 = 5;

    unsigned long next_ugly_number;

    for(int i = 1; i < n; i++)
    {
        next_ugly_number = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        ugly[i] = next_ugly_number;

        if (next_ugly_number == next_multiple_of_2)
        {
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if (next_ugly_number == next_multiple_of_3)
        {
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if (next_ugly_number == next_multiple_of_5)
        {
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }
    return next_ugly_number;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;
    unsigned long nthUgly;
    nthUgly = getUgly(n);
    cout << nthUgly << endl;
    return 0;
}