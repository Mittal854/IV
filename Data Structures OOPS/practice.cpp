#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<string> result1(26, "");
    for (char i : s)
    {
        if (i >= 'A' && i <= 'Z')
        {
            result1[i - 'A'] += i;
        }
        else
        {
            result1[i - 'a'] += i;
        }
    }
    for (string i : result1)
    {
        cout << i << " ";
    }
    deque<string> result;
    for (string i : result1)
    {
        if (!i.empty())
        {
            result.push_back(i);
        }
    }
    cout << endl;
    string final = "";
    while (!result.empty())
    {
        string a = result.front();
        final += a;
        result.pop_front();

        if (!result.empty())
        {
            string b = result.back();
            final += b;
            result.pop_back();
        }
    }
    cout << final;
    return 0;
}