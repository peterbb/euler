#include <stdio.h>

unsigned long long 
sum_divisors(int n) {
    unsigned long long sum;
    int d;

    sum = 0;
    for (d = 1; d < n; d++) {
        if (n % d == 0) {
            sum += d;
        }
    }
    return sum;
}

int
is_abundant(int n) {
    return sum_divisors(n) > n;
}

#define MAX 28123
static int abundant[MAX + 1];
static int is_sum_of_abundant[MAX + 1];

int 
main(int argc, char** argv)
{
    int i, j;
    unsigned long long sum;

    for  (i = 1; i <= MAX; i++) {
        abundant[i] = is_abundant(i);
    }

    for (i = 1; i <= MAX; i++) {
        if (!abundant[i]) 
            continue;
        for (j = 1; j <= MAX; j++) {
            if (!abundant[j])
                continue;
            if (i + j <= MAX)
                is_sum_of_abundant[i + j] = 1;
        }
    }

    sum = 0;
    for (i = 1; i <= MAX; i++) {
        if (!is_sum_of_abundant[i]) 
            sum += i;
    }

    printf("%llu\n", sum);

    return 0;
}

