#include <cstdio>
#include <cmath>

#define N 6

int main() {
    // Input data
    double X[N] = {1, 2, 3, 4, 5, 6};
    double Y[N] = {2.1, 3.9, 5.8, 8.2, 10.1, 12.2};

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    double m, c;

    // 1. Calculate sums for linear regression
    for (int i = 0; i < N; i++) {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xy += X[i] * Y[i];
        sum_x2 += X[i] * X[i];
    }

    // 2. Apply formulas for slope (m) and intercept (c)
    m = (N * sum_xy - sum_x * sum_y) / (N * sum_x2 - sum_x * sum_x);
    c = (sum_y - m * sum_x) / N;

    // 3. Show best-fit line
    // printf("Best fit line: Y = %.2f X + %.2f\n", m, c);
    printf("Best fit line: Y = %0.2f X + %0.2f\n", m,c);

    // 4. Calculate correlation coefficient (r)
    double ss_xy = 0, ss_xx = 0, ss_yy = 0;
    double x_mean = sum_x / N;
    double y_mean = sum_y / N;

    for (int i = 0; i < N; i++) {
        ss_xy += (X[i] - x_mean) * (Y[i] - y_mean);
        ss_xx += (X[i] - x_mean) * (X[i] - x_mean);
        ss_yy += (Y[i] - y_mean) * (Y[i] - y_mean);
    }

    double r = ss_xy / sqrt(ss_xx * ss_yy);
    printf("Correlation coefficient r = %.4f\n", r);

    return 0;
}
