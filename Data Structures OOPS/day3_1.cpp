#include <iostream>

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target = 7;

    int result = binarySearch(sortedArray, size, target);

    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
