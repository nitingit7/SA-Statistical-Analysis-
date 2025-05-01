#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1000      // Size of each random sequence
#define M 10000     // Number of sequences

// Generate random numbers from a Poisson distribution
void generate_poisson_means(double means[], int size, double lambda) {
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++){
            double L = exp(-lambda);
            double p = 1.0;
            int k = 0;
            do {
                k++;
                p *= (double)rand() / RAND_MAX;
            } while (p > L);
            sum += k - 1;
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

    // Example: Verify CLT for Poisson distribution
    generate_poisson_means(means, M, 10.0);
    plot_distribution(means, M, "poisson_distribution.txt");

}