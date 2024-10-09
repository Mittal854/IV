#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int a;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
    }

    for (int i = 1; i < sum; i++)
    {
        if (i * i * i == sum)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}