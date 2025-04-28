#include <stdio.h>
#include <math.h>

void combine(int a[], int down, int mid, int up)
{
    int temp[10];
    // iterate over k
    int k = down;
    // iterate over left-half of a
    int i = down;
    // iterate over right-half of a
    int j = mid + 1;
    while (i <= mid && j <= up)
    {
        if (a[i] < a[j])
        {
            temp[k]= a[i];
            k = k + 1;
            i = i + 1;
        }
        else
        {
            temp[k] = a[j];
            k = k + 1;
            j = j + 1;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k = k + 1;
        i = i + 1;
    }
    while (j <= up)
    {
        temp[k] = a[j];
        k = k + 1;
        j = j + 1;
    }
    for (k = down; k <= up; k++)
    {
        a[k] = temp[k];
    }
}

void merge_sort(int a[], int down, int up)
{
    if (down < up)
    {
        int mid = floor((float)(down + up) / 2);
        merge_sort(a, down, mid);
        merge_sort(a, mid + 1, up);
        combine(a, down, mid, up);
    }
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
