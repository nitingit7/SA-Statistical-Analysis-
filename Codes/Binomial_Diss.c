#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000      // Size of each random sequence
#define M 10000     // Number of sequences

// Generate random numbers from a Binomial distribution
void generate_binomial_means(double means[], int size, int trials, double probability) {
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            int x = 0;
            for (int t = 0; t < trials; t++) {
                if ((double)rand() / RAND_MAX < probability) {
                    x++;
                }
            }
            sum += x;
        }
        means[i] = sum / N;
    }
}

// Save distribution to a file for plotting
void plot_distribution(double means[], int size, const char* filename) 
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%f\n", means[i]);
    }
    fclose(file);
}

int main()
{
    double means[M];
    
    // Seed random number generator
    srand(time(NULL));

    // Example: Verify CLT for Binomial distribution
    generate_binomial_means(means, M, 20, 0.5);
    plot_distribution(means, M, "binomial_distribution.txt");

}