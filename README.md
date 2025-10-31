# progintro-hw0-MarVardoul
# Aliquot Sequence Calculator

This program computes **aliquot sequences** for a given positive integer.
An aliquot sequence is formed by repeatedly replacing a number `n` with the sum
of its **proper divisors** (all positive divisors smaller than `n`).
The sequence terminates when it reaches `0` or may fall into a repeating cycle.

---

## �� Mathematical background

For a number `n`, the sum of its proper divisors is defined as:

\[
s(n) = \sum_{\substack{d \mid n \\ d < n}} d
\]

For example:
- `s(6) = 1 + 2 + 3 = 6` → perfect number  
- `s(12) = 1 + 2 + 3 + 4 + 6 = 16`

The program uses this function to generate the aliquot sequence:
\[
n, s(n), s(s(n)), s(s(s(n))), \dots
\]
until it reaches `0` or exceeds the limit `10^{15}`.

---

## ⚙️ Implementation details

### 1. Divisor sum computation

The function `sum_of_perfect_divisors()` calculates the sum of all proper divisors of a number `n`.  
Instead of checking all numbers from `1` to `n/2`, which is **O(n)** and inefficient for large `n`,  
the algorithm checks divisors only up to `√n`, which makes it **O(√n)**.

This optimization works because:
> For every divisor `i` smaller than `√n`, there exists a corresponding divisor `n / i` greater than `√n`.  

So both divisors can be added at once, avoiding redundant checks.

Example for `n = 36`:  
- When `i = 2`, `n / i = 18` → divisor pair `(2, 18)`  
- When `i = 3`, `n / i = 12` → divisor pair `(3, 12)`  
- When `i = 6`, `n / i = 6` → perfect square → add only once.

This approach avoids double-counting and eliminates the need for the `sqrt()` library.

```c
for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
        if (i * i == n)
            sum += i;          // perfect square — add only once
        else
            sum += i + n / i;  // add both divisors
    }
}
