#include <stdio.h>

void sort(float w[], float p[], int n) {
    float ratio;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float ratio1 = p[i] / w[i];
            float ratio2 = p[j] / w[j];
            if (ratio1 < ratio2) {
                // Swap weights
                float temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                // Swap profits
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

float knapsack(float w[], float p[], float M, int n) {
    float x[10];
    float max = 0;
    int cp, i;

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    cp = M;
    sort(w, p, n);
    i = 0;
    
    while (i < n && w[i] <= cp) {
        x[i] = 1;
        cp = cp - w[i];
        i++;
    }

    if (i < n) {
        x[i] = cp / w[i];
    }

    for (i = 0; i < n; i++) {
        max = max + x[i] * p[i];
    }

    return max;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    float weights[n], profits[n], M;
    
    printf("Enter the weights of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Weight of item %d: ", i + 1);
        scanf("%f", &weights[i]);
    }

    printf("Enter the profits of the %d items:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Profit of item %d: ", i + 1);
        scanf("%f", &profits[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &M);

    float result = knapsack(weights, profits, M, n);
    printf("The maximum profit that can be obtained is: %.2f\n", result);

    return 0;
}