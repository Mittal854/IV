#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string a="";
    for(int i=0;i<s.length();i=i+2)
    {
        if(s[i]>s[i+1])
        {
            a+=s[i];
        }
        else
        {
            a+=s[i+1];
        }
    }
    cout<<a;
    return 0;
}   