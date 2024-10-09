#include<iostream>
#include<stack>
#include<string>
using namespace std;

int prec(char a)
{
    if(a=='*' || a=='/')
    {
        return 2;
    }
    if(a=='+'|| a=='-')
    {
        return 1;
    }
    return 0;
}

string inftopos(string s)
{
    stack<char> op;
    string pos="";
    for(int i=0;i<s.size();i++)
    {
        char a=s[i];
        if((a>='a'&&a<='z')||(a>='A' && a<='Z')||(a>='0'&& a<='9'))
        {
            pos+=a;
        }
        else if(a=='(')
        {
            op.push(a);
        }
        else if(a==')')
        {
            while(op.empty() && op.top()!='(' )
            {
                pos+=op.top();
                op.pop();
            }
            if(!op.empty())
            {
                op.pop();
            }
        }
        else{
            while(!op.empty() && prec(op.top())>=prec(a))
            {
                pos+=op.top();
                op.pop();
            }
            op.push(a);
        }
    }
    while(!op.empty())
    {
        pos+=op.top();
        op.pop();
    }
    return pos;
}




int main()
{
    string s;
    getline(cin,s);
    string in=inftopos(s);
    cout<<in;
}