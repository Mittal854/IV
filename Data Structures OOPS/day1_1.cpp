#include <iostream>
using namespace std;

int main()
{
    int n, k;
    int arr[100];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int q = arr[i] / k;
        sum += q;
    }
    cout << sum;
    return 0;
}