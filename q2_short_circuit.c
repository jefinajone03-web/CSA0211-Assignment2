/*
 * Q2: When Does Short-Circuit Evaluation Matter?
 *
 * concession = (senior && eligible) || verify_card();
 * verify_card() is the expensive call. With || it runs only when the
 * first part is false. With bitwise | both operands are always evaluated.
 */

#include <stdio.h>

int calls = 0;

int verify_card(void)
{
    calls++;
    return 0;
}

int main(void)
{
    int senior, eligible, concession;

    printf("Enter senior status: ");
    if (scanf("%d", &senior) != 1) return 1;
    printf("Enter ticket eligibility: ");
    if (scanf("%d", &eligible) != 1) return 1;

    concession = (senior && eligible) || verify_card();
    printf("Concession: %s\n", concession ? "YES" : "NO");
    printf("Verification calls: %d\n", calls);

    /* ---- Experiment: 1000 passengers ----
       300 senior, 400 eligible, 100 both. */
    int logical_calls, bitwise_calls;

    calls = 0;
    for (int i = 0; i < 1000; i++) {
        int s = (i < 300);                       /* 0..299   senior   */
        int e = (i < 100) || (i >= 300 && i < 600); /* 0..99 and 300..599 eligible */
        (void)((s && e) || verify_card());
    }
    logical_calls = calls;

    calls = 0;
    for (int i = 0; i < 1000; i++) {
        int s = (i < 300);
        int e = (i < 100) || (i >= 300 && i < 600);
        (void)((s & e) | verify_card());         /* no short-circuit */
    }
    bitwise_calls = calls;

    printf("\n1000 passengers:\n");
    printf("  (&&, ||) verification calls = %d\n", logical_calls);
    printf("  (&,  |)  verification calls = %d\n", bitwise_calls);

    return 0;
}
