#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int x[20];                
int j;                    
int solution_count = 0;    

int place(int k, int i) {
    
    for (j = 1; j < k; j++) {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return 0;   
        }
    }
    return 1;   
}

void Nqueens(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;   
            if (k == n) {
                
                solution_count++;
                for (j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                Nqueens(k + 1, n);   
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    printf("Solutions are:\n");
    Nqueens(1, n);
    printf("Total solutions: %d\n", solution_count);

    return 0;
}
