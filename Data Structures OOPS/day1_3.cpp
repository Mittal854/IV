#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int sum = 0;
    for (char i : s)
    {
        if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')))
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}