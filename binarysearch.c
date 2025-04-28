#include <stdio.h>

int a[10], x;

int binsearch(int low, int high)
{
    if (low <= high) 
    {
        int mid = (low + high) / 2;
        if (x == a[mid])
            return mid;
        else if (x < a[mid])
            return binsearch(low, mid - 1);
        else
            return binsearch(mid + 1, high);
    }
    return -1;
}

int main()
{
    int size;
    printf("Enter size of the list: ");
    scanf("%d", &size);
    printf("Enter %d integer values: ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    printf("Enter an Element to be searched: ");
    scanf("%d", &x);
    int k = binsearch(0, size - 1);
    if (k == -1)
        printf("The Element is not found in the list ");
    else
        printf("The Element is found at index %d", k);
    return 0;
}

