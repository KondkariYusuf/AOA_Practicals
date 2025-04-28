#include <stdio.h>
#include <limits.h>

int INIFINITY = INT_MAX;

int A[100][100];
int cost[100][100];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void all_pair(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            A[i][j] = cost[i][j];
        }
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%3d", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Node count? ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                int temp;
                printf("Cost of edge <%d,%d> (if None, enter -1)? ", i+1, j+1);
                scanf("%d", &temp);
                if (temp == -1)
                {
                    cost[i][j] = INIFINITY;
                }
                else
                {
                    cost[i][j] = temp;
                }
            }
            else
            {
                cost[i][j] = 0;
            }
        }
    }
    printf("Shortest path-\n");
    all_pair(n);
    return 0;
}

// Node count? 4
// Cost of edge <1,2> (if None, enter -1)? 5
// Cost of edge <1,3> (if None, enter -1)? 9
// Cost of edge <1,4> (if None, enter -1)? -1
// Cost of edge <2,1> (if None, enter -1)? -1
// Cost of edge <2,3> (if None, enter -1)? 3
// Cost of edge <2,4> (if None, enter -1)? -1
// Cost of edge <3,1> (if None, enter -1)? -1
// Cost of edge <3,2> (if None, enter -1)? -1
// Cost of edge <3,4> (if None, enter -1)? 1
// Cost of edge <4,1> (if None, enter -1)? 2
// Cost of edge <4,2> (if None, enter -1)? -1
// Cost of edge <4,3> (if None, enter -1)? -1
