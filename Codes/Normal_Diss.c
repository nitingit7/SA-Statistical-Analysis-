#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define _USE_MATH_DEFINES
#define N 1000      // Size of each random sequence
#define M 10000     // Number of sequences

// Generate random numbers from a normal distribution
void generate_normal_means(double means[], int size) 
{
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            double u1 = ((double)rand() / RAND_MAX);
            if (u1 == 0) 
            {
                u1 = 1e-10; // Small positive number to avoid log(0)
            }
            double u2 = ((double)rand() / RAND_MAX);
            double z = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2); // Box-Muller transform
            sum += z;
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

    // Example: Verify CLT for normal distribution
    generate_normal_means(means, M);
    plot_distribution(means, M, "normal_distribution.txt");

    return 0;

}