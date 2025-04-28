#include <stdio.h>
#include <string.h>

int naive(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; ++i)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char text[100];
    printf("Text string? ");
    scanf("%s", text);
    char pattern[100];
    printf("Pattern string? ");
    scanf("%s", pattern);
    int position = naive(text, pattern);
    if (position == -1)
    {
        printf("Not a substring\n");
    }
    else
    {
        printf("Substring starts from index %d\n", position + 1);
    }
    return 0;
}
