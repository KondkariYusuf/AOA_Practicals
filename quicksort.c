#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int lb, int ub)
{
    int down = lb;
    int up = ub;
    int x = a[lb];
    while (down < up)
    {
        while (a[down] <= x && down < up)
        {
            down = down + 1;
        }
        while (a[up] > x)
        {
            up = up - 1;
        }
        if (down < up)
        {
            swap(&a[down], &a[up]);
        }
    }
    swap(&a[lb],&a[up]);
    return up;
}

void quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int j = partition(a, lb, ub);
        quick_sort(a, lb, j - 1);
        quick_sort(a, j + 1, ub);
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
    quick_sort(a, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
