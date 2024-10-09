#include<iostream>
#include<vector>
using namespace std;


bool ugly(int n)
{
    if(n<=0)
    {
        return false;
    }
    while(n%2==0)
    {
        n=n/2;
    }
    while(n%3==0)
    {
        n=n/3;
    }
    while(n%5==0)
    {
        n=n/5;
    }
    if(n==1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    int i=1;
    while(a.size()<=n)
    {
        bool t=ugly(i);
        if(t)
        {
            a.push_back(i);
        }
        i++;
    }
    cout<<a[n-1];
    return 0;
}