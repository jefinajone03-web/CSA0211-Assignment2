# Assignment 2 – C Programs

| File | Task | Topic |
|------|------|-------|
| `q1_precedence_discount.c` | Q1 | Operator precedence, integer division, GST/discount billing |
| `q2_short_circuit.c` | Q2 | `&&` / `||` short-circuit vs `&` / `|` (railway concession) |
| `q3_bitwise_register.c` | Q3 | Device-status register using bitwise operators |
| `q4_grade_switch.c` | Q4 | Grade classification: switch, else-if ladder, lookup table |
| `q5_prime_loops.c` | Q5 | Prime check with `for`, `while`, `do-while` and division counts |
| `q6_loan_repayment.c` | Q6 | Loan repayment simulation with a `while` loop |
| `q7_prime_redesign.c` | Q7 | Prime check redesign (odd divisors only) with comparison |

## Build and run
```bash
gcc -Wall -Wextra -std=c99 q1_precedence_discount.c -o q1 && ./q1
# repeat for q2 ... q7
```
Q1 and Q2 ask for input. Sample inputs:
- Q1: `100 2 1`, `250 3 0`, `500 2 1` (price, quantity, senior)
- Q2: `0 1` (senior, eligible)

## Key results
- Q1: Totals 178.50, 787.50, 892.50
- Q2: 900 verification calls with `&&`/`||`, 1000 with `&`/`|`
- Q3: `00000101`, `00000110`, AC is ON, PUMP is OFF
- Q4: `100:S 95:S 83:A 50:D 49:F -5:?`
- Q5: divisions = 8, 1, 87, 999
- Q6: 6 months, total interest 645.38
- Q7: checks = 5, 1, 44, 500 (vs 8, 1, 87, 999 originally)
