#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int simulate(int n, double q) {
    int heads = 0;
    for (int i = 0; i < n; i++)
        heads += ((double)rand() / RAND_MAX) < q;
    return heads;
}

double binom_pmf(int k, int n, double p) {
    double log_comb = 0;
    for (int i = 1; i <= k; i++)
        log_comb += log(n - k + i) - log(i);
    return exp(log_comb + k * log(p) + (n - k) * log(1 - p));
}

double binom_test(int k, int n, double p) {
    double p_val = 0, obs = binom_pmf(k, n, p);
    for (int x = 0; x <= n; x++) {
        double prob = binom_pmf(x, n, p);
        if (prob <= obs) p_val += prob;
    }
    return p_val;
}

int main() {
    srand(time(NULL));
    int n; double q;
    printf("Enter number of tosses: "); scanf("%d", &n);
    printf("Enter probability of heads (q): "); scanf("%lf", &q);

    int heads = simulate(n, q);
    double p_val = binom_test(heads, n, 0.5);

    printf("\nHeads: %d, Tails: %d\n", heads, n - heads);
    printf("Observed proportion: %.4f\n", (double)heads / n);
    printf("p-value: %.6f\n", p_val);

    printf("Conclusion: ");
    printf(p_val < 0.05 ? "Reject H0. Coin is biased.\n" : "Fail to reject H0. No evidence of bias.\n");
    return 0;
}
