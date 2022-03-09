#include <iostream>
using namespace std; // 102 345 2343 5555 21343
int BinarySearch(int a[], int low, int high, int element)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == element)
        {
            return mid + 1;
        }
        else if (a[mid] >= element)
        {
            return BinarySearch(a, 0, mid - 1, element);
        }
        else
            return BinarySearch(a, mid + 1, high, element);
    }

    return -1;
}
int main()
{
    int num, a[1000], element, i;

    cout << "How many elements you wants to enter : ";
    cin >> num;

    cout << "Enter " << num << " elements...\n";
    for (i = 0; i < num; i++)
    {
        cin >> a[i];
    }

    cout << "Array elements...\n";
    for (i = 0; i < num; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Enter element to search : ";
    cin >> element;

    int ans = BinarySearch(a, 0, num, element);
    if (ans == -1)
    {
        cout << element << " is not present in an array.";
    }
    else
        cout << element << " is present at " << ans << " index.";

    return 0;
}