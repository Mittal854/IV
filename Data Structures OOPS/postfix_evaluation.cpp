#include <iostream>
#include <stack>
#include <string>
using namespace std;

int postfix(string s)
{
    stack<int> no;
    for (int i = 0; i < s.size(); i++)
    {
        char a = s[i];
        if (a >= '0' && a <= '9')
        {
            int np = a - '0';
            no.push(np);
        }
        else
        {
            int no2 = no.top();
            no.pop();
            int no1 = no.top();
            no.pop();
            if (a == '+')
            {
                int res = no1 + no2;
                no.push(res);
            }
            else if (a == '-')
            {
                int res = no1 - no2;
                no.push(res);
            }
            else if (a == '*')
            {
                int res = no1 * no2;
                no.push(res);
            }
            else if (a == '/')
            {
                int res = no1 / no2;
                no.push(res);
            }
        }
    }

    int ans = no.top();
    no.pop();
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    int ans = postfix(s);
    cout << ans;
}