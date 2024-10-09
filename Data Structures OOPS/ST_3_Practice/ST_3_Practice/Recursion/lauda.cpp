#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int max=-1;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                max=a[j];
            }
        }
        cout<<max<<" ";
    }
    int max=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[n-1])
        {
            max=a[i];
        }
    }
    cout<<max;


    return 0;
}