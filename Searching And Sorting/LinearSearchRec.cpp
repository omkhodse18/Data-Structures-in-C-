#include <iostream>
using namespace std;

int LinearSearch(int a[], int size, int element)
{
    int ans;
    if (size <= -1)
    {
        return -1;
    }

    if (a[size] == element)
    {
        return size + 1;
    }
    else
        ans = LinearSearch(a, size - 1, element);

    return ans;
}


int main()
{
    int num, a[100], element, i;

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

    int ans = LinearSearch(a, num, element);

    if (ans == -1)
    {
        cout << element << " is not present in an array.";
    }
    else
        cout << element << " is present at " << ans << " index.";

    return 0;
}