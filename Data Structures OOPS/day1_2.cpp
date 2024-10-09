#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int arr[26] = {0};
    for (char i : s)
    {
        int no = i - 'a';
        arr[no]++;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 1)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}