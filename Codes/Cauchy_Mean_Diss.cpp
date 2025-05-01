#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define N 1000  // Size of each random sequence
#define M 10000 // Number of sequences
#define M_PI 3.14159265358979323846 // Define PI since some compilers don't include it

// Generate random numbers from a Cauchy-Lorentz distribution
void generate_cauchy_means(double means[], int size) {
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < N; j++) {
            double u = (double)rand() / RAND_MAX;
            double z = tan(M_PI * (u - 0.5)); // Cauchy distribution
            sum += z;
        }
        means[i] = sum / N;
    }
}

// Save distribution to a file for plotting
void plot_distribution(double means[], int size, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%f\n", means[i]);
    }
    fclose(file);
}

int main() {
    double means[M];

    // Seed random number generator
    srand(time(NULL));

    // Show CLT violation for Cauchy distribution
    generate_cauchy_means(means, M);
    plot_distribution(means, M, "cauchy_distribution.txt");

    return 0;
}
