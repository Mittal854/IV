#include <iostream>
using namespace std;

int main()
{
    int arr[] = {8, 22, 7, 9, 31, 19, 5, 13};
    int count=0;
    int n=8;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}