/*
 * Q1: Precedence, Associativity and the Discount Bug
 *
 * Pharmacy billing: gross -> senior discount (15%) -> GST (5%) on the
 * DISCOUNTED amount -> Rs 50 off if the total exceeds Rs 1000.
 *
 * Notes:
 *  - float is used so integer division cannot drop the fractional part.
 *  - Intermediate variables (gross, discount, tax) keep every step readable
 *    and make the precedence explicit.
 *  - The statement  count = count++ + 1;  is undefined behaviour (count is
 *    modified twice with no sequencing). The correct form is
 *    count = count + 1;  (see the demo at the end of main).
 */

#include <stdio.h>

int main(void)
{
    float price, gross, discount, tax, total, net;
    int qty, senior;

    printf("Enter price: ");
    if (scanf("%f", &price) != 1) return 1;
    printf("Enter quantity: ");
    if (scanf("%d", &qty) != 1) return 1;
    printf("Senior citizen (1=yes, 0=no): ");
    if (scanf("%d", &senior) != 1) return 1;

    gross    = price * qty;
    discount = senior ? gross * 0.15f : 0;
    tax      = (gross - discount) * 0.05f;      /* GST on discounted amount */
    total    = gross - discount + tax;
    net      = total > 1000 ? total - 50 : total;

    printf("Gross Amount = %.2f\n", gross);
    printf("Discount = %.2f\n", discount);
    printf("GST = %.2f\n", tax);
    printf("Total Amount = %.2f\n", total);
    printf("Net Amount = %.2f\n", net);

    /* Fixing the undefined-behaviour example */
    int count = 5;
    count = count + 1;
    printf("count = %d\n", count);

    return 0;
}
