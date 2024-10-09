#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 3, 1, 6, 7};
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int a = i - 1;
        int num = arr[i];
        while (a >= 0 && num < arr[a])
        {
            arr[a + 1] = arr[a];
            a--;
        }
        arr[a + 1] = num;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}