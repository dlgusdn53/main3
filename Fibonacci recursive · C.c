#include <stdio.h>
#include <time.h>

// 순환적(반복적) 방법으로 피보나치 수열 계산
// F(1) = 1, F(2) = 1, F(3) = 2, ...
long long fibonacci_iterative(int n) {
    if (n == 1 || n == 2) return 1;

    long long prev2 = 1, prev1 = 1, curr = 0;
    for (int i = 3; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(void) {
    int test_cases[] = {1, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("%-5s  %-25s  %-15s\n", "N", "F(N)", "Time (sec)");
    printf("%-5s  %-25s  %-15s\n", "-----", "-------------------------", "---------------");

    for (int i = 0; i < num_cases; i++) {
        int n = test_cases[i];

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);

        long long result = fibonacci_iterative(n);

        clock_gettime(CLOCK_MONOTONIC, &end);
        double elapsed = (end.tv_sec - start.tv_sec)
                       + (end.tv_nsec - start.tv_nsec) / 1e9;

        printf("%-5d  %-25lld  %.9f\n", n, result, elapsed);
    }

    return 0;
}