/*
 * Q6: Loan repayment simulation using a while loop.
 * Each month: interest is added to the balance, then the fixed payment is
 * deducted. The last payment is reduced to the remaining balance.
 * The loop stops when balance <= 0.005 or after 360 months (safety limit).
 * If payment <= first month's interest the loan can never be repaid.
 */

#include <stdio.h>

int main(void)
{
    double balance = 10000;
    double rate = 2;          /* percent per month */
    double payment = 2000;
    double interest, totalInterest = 0;
    double actualPayment;
    int month = 0;

    if (payment <= balance * rate / 100)
    {
        printf("Loan cannot be repaid with this amount.\n");
        return 0;
    }

    printf("Month\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.005 && month < 360)
    {
        month++;
        interest = balance * rate / 100;
        totalInterest += interest;
        balance += interest;

        actualPayment = payment;
        if (actualPayment > balance)
            actualPayment = balance;

        balance -= actualPayment;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
               month, interest, actualPayment, balance);
    }

    if (balance <= 0.005)
    {
        printf("\nLoan Completed!\n");
        printf("Total Months = %d\n", month);
        printf("Total Interest = %.2f\n", totalInterest);
    }
    else
    {
        printf("Safety limit reached. Loan is not fully repaid.\n");
    }

    return 0;
}
