/*
 * Q7: Diagnose, Redesign and Validate (selected program: Q5 prime check)
 *
 * Bottleneck : the original tests every divisor 2..sqrt(n), including even
 *              ones that can never divide an odd number.
 * Redesign   : handle 2 separately, then test only odd divisors 3, 5, 7, ...
 *              and stop when i > n / i (avoids i * i overflow).
 * Still O(sqrt(n)) time, O(1) space, with about half the divisions.
 */

#include <stdio.h>

unsigned long checks = 0;

/* Original design */
int is_prime_original(unsigned long n)
{
    checks = 0;
    if (n < 2)
        return 0;
    for (unsigned long i = 2; i * i <= n; i++)
    {
        checks++;
        if (n % i == 0)
            return 0;
    }
    return 1;
}

/* Redesigned version */
int is_prime(unsigned long n)
{
    checks = 0;
    if (n < 2)
        return 0;
    checks++;
    if (n % 2 == 0)
        return n == 2;
    for (unsigned long i = 3; i <= n / i; i += 2)
    {
        checks++;
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    for (int i = 0; i < 4; i++)
    {
        int result = is_prime(numbers[i]);
        printf("%lu : %s : Checks = %lu\n",
               numbers[i],
               result ? "Prime" : "Not Prime",
               checks);
    }

    printf("\nOriginal vs Redesigned:\n");
    printf("%-10s %-16s %-16s\n", "Number", "Original Checks", "Improved Checks");
    for (int i = 0; i < 4; i++)
    {
        int r1 = is_prime_original(numbers[i]);  unsigned long c1 = checks;
        int r2 = is_prime(numbers[i]);           unsigned long c2 = checks;
        printf("%-10lu %-16lu %-16lu %s\n", numbers[i], c1, c2,
               (r1 == r2) ? "(same result)" : "(MISMATCH)");
    }

    /* Extra validation: both versions must agree on every n up to 10000 */
    int mismatches = 0;
    for (unsigned long n = 0; n <= 10000; n++)
        if (is_prime_original(n) != is_prime(n))
            mismatches++;
    printf("\nMismatches for n = 0..10000: %d\n", mismatches);

    return 0;
}
