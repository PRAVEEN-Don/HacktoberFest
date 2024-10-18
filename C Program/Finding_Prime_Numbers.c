#include <stdio.h>

void sieveOfEratosthenes(int n) {
    int prime[n+1];
    for (int i = 0; i <= n; i++) {
        prime[i] = 1; 
    }
    prime[0] = prime[1] = 0; 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = 0;
            }
        }
    }
    printf("Prime numbers up to %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    sieveOfEratosthenes(n);
    return 0;
}
