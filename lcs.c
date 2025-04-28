#include <stdio.h>
#include <string.h>

int c[20][20];
char d[20][20]; // Variable for direction

void display(char d[][20], char x[], int i, int j) {
    if (i == 0 || j == 0)
        return;
    else {
        if (d[i][j] == 'd') {
            display(d, x, i - 1, j - 1);
            printf("%c", x[i - 1]);
        } else if (d[i][j] == 'u') {
            display(d, x, i - 1, j);
        } else {
            display(d, x, i, j - 1);
        }
    }
}

void lcs(char x[], char y[]) {
    int m, n, i, j;
    m = strlen(x);
    n = strlen(y); // Using 'n' instead of 'n_len'

    printf("Length of first string: %d", m);
    printf("Length of second string: %d", n);

    // Initialize LCS table
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    // Fill LCS table
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = 'd';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                d[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                d[i][j] = 'l';
            }
        }
    }

    printf("Longest Common Subsequence: ");
    display(d, x, m, n);
    printf("");
}

void main() {  // Changed to void main()
    char x[10], y[10];
    
    printf("Enter first string:");
    gets(x);
    puts(x);
    
    printf("Enter second string:");
    gets(y);
    puts(y);
    
    lcs(x, y);
}