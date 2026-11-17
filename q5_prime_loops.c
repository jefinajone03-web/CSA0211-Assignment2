/*
 * Q5: Count the Work Done by a Loop
 * Prime test using for, while and do-while loops.
 * Only divisors up to sqrt(n) are needed, tested with i * i <= n
 * (no sqrt() call). Time O(sqrt(n)), space O(1).
 */

#include <stdio.h>

unsigned long checks = 0;

/* for loop */
int is_prime(unsigned long n)
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

/* while loop */
int is_prime_while(unsigned long n)
{
    checks = 0;
    if (n < 2)
        return 0;
    unsigned long i = 2;
    while (i * i <= n)
    {
        checks++;
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}

/* do-while loop (the first test i = 2 is guarded so n = 2, 3 are handled) */
int is_prime_do(unsigned long n)
{
    checks = 0;
    if (n < 2)
        return 0;
    unsigned long i = 2;
    if (i * i > n)
        return 1;
    do
    {
        checks++;
        if (n % i == 0)
            return 0;
        i++;
    } while (i * i <= n);
    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};

    for (int k = 0; k < 4; k++)
    {
        int p = is_prime(tickets[k]);
        printf("%8lu  %-9s  divisions = %lu\n",
               tickets[k],
               p ? "prime" : "not prime",
               checks);
    }

    /* The three loop forms must agree */
    printf("\nLoop comparison (result, divisions):\n");
    for (int k = 0; k < 4; k++)
    {
        unsigned long n = tickets[k];
        int a = is_prime(n);       unsigned long ca = checks;
        int b = is_prime_while(n); unsigned long cb = checks;
        int c = is_prime_do(n);    unsigned long cc = checks;
        printf("%8lu  for=%d(%lu)  while=%d(%lu)  do-while=%d(%lu)\n",
               n, a, ca, b, cb, c, cc);
    }

    return 0;
}
