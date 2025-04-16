#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to simulate coin tosses
int simulate_coin_tosses(int n, double q) {
    int heads = 0;
    for (int i = 0; i < n; i++) {
        double rand_val = (double)rand() / RAND_MAX;
        if (rand_val < q) {
            heads++;
        }
    }
    return heads;
}

// Function to calculate binomial probability mass function
double binomial_pmf(int k, int n, double p) 
{
    double log_comb = 0.0;  // Calculate log of n choose k to avoid overflow
    for (int i = 1; i <= k; i++) {
        log_comb += log(n - k + i) - log(i);
    }
    
    
    return exp(log_comb + k * log(p) + (n - k) * log(1 - p)); // Calculate the probability
}

double binomial_test(int k, int n, double p) {
    double p_value = 0.0;
    
    // Calculate the probability of getting exactly k heads
    double observed_prob = binomial_pmf(k, n, p);
    
    // Sum probabilities of all outcomes as or more extreme than observed
    for (int x = 0; x <= n; x++) {
        double current_prob = binomial_pmf(x, n, p);
        if (current_prob <= observed_prob) {
            p_value += current_prob;
        }
    }
    
    return p_value;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int n;
    double q;
    
    printf("Enter number of coin tosses (n): ");
    scanf("%d", &n);
    
    printf("Enter true probability of heads (q) for simulation (0 < q < 1): ");
    scanf("%lf", &q);
    

    int heads = simulate_coin_tosses(n, q);      // Simulate coin tosses
    int tails = n - heads;
    
    printf("\nSimulation results:\n");
    printf("Heads: %d, Tails: %d\n", heads, tails);
    printf("Observed proportion of heads: %.4f\n", (double)heads / n);
    
    
    double p_value = binomial_test(heads, n, 0.5);  // Perform binomial test with H0: p = 0.5
    
    printf("\nBinomial test results:\n");
    printf("p-value: %.6f\n", p_value);
    
    // Interpret the result
    double alpha = 0.05;
    printf("\nConclusion at alpha=%.2f: ", alpha);
    if (p_value < alpha) {
        printf("Reject H0. There is significant evidence that the coin is biased.\n");
    } else {
        printf("Fail to reject H0. There is not enough evidence to conclude the coin is biased.\n");
    }
    
    return 0;
}
