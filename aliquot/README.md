# Aliquot Sequence Calculator

## 📘 Description

This program calculates **Aliquot Sequences** for positive integers.  
An *Aliquot Sequence* is a chain of numbers in which each term equals the sum of the *proper divisors* of the previous term. Proper divisors of a number *n* are all positive integers that divide *n* exactly, excluding *n* itself.

For example, the sequence for **12** evolves as follows:  
12 → 16 → 15 → 9 → 4 → 3 → 1 → 0  
and terminates when reaching 0, since the sum of proper divisors of 1 is 0.  
This sequence has a length of **7**.

Some sequences never reach 0 — for instance, **6** is a *perfect number* because:  
s(6) = 1 + 2 + 3 = 6.  
Other numbers (like 220 and 284) form cycles, known as *amicable pairs*.

---

## ⚙️ Program Overview

The program is implemented in **C** and provides two operating modes:
1. **Full Sequence (`f`)** — prints each element of the sequence up to a user-defined limit.
2. **Length Only (`l`)** — prints the number of steps required until the sequence terminates (or until it reaches the limit).

---

## 🧮 Mathematical Method

For any integer `n`, the function `s(n)` computes the sum of its proper divisors.  
This is implemented efficiently by iterating `i` from `2` to `√n` and adding both divisors `i` and `n/i` whenever `i` divides `n`.

If `i * i == n`, the divisor is only added once (to avoid duplication in perfect squares).

Formally:

```
s(n) = 1 + Σ (i + n/i), for all i ∈ [2, √n] such that n mod i == 0
```

The sequence then proceeds iteratively:
```
n₀ = initial number
n₁ = s(n₀)
n₂ = s(n₁)
...
nₖ = 0 or repetition limit
```

The process stops when:
- `sum == 0` (sequence terminates naturally),  
- or the user-defined maximum length is reached,  
- or the result exceeds `10¹⁵` (per assignment constraints).

---

## 🧩 Code Structure

### **Function:** `sum_of_perfect_divisors(long long int n, long long int sum)`
- Calculates and returns the sum of all proper divisors of `n`.
- Uses `sum = 1` as the base case for all `n > 1`.
- Avoids redundant computation for perfect squares.

### **Main Logic**
1. Reads **initial number**, **mode option**, and optionally **maximum length**.
2. Validates input and numerical limits.
3. Depending on the option:
   - Prints the full sequence (`f`), or
   - Outputs only its length (`l`).
4. Terminates with exit code `1` on invalid input or overflow.

---

## 🖥️ Example Executions

**Full Sequence:**
```
enter the initial number to calculate the aliquot sequence:
12
press f for full sequence, l to calculate the length
f
enter the maximum length of the sequence:
0

12
16
15
9
4
3
1
0
```

**Length Only:**
```
enter the initial number to calculate the aliquot sequence:
12
press f for full sequence, l to calculate the length
l

7
```

**Overflow Condition:**
```
enter the initial number to calculate the aliquot sequence:
276
press f for full sequence, l to calculate the length
f

276
396
...
the sum exceeded 10^15
```

---

## 🧠 Mathematical Insight

Aliquot sequences are a long-standing research topic in number theory.  
- They can **terminate** (when reaching 0),  
- **cycle** (as with perfect or amicable numbers), or  
- possibly **diverge** (never proven or disproven — see the *Catalan–Dickson conjecture*).

Each term can be thought of as applying the *sum-of-proper-divisors* function repeatedly:
```
s₁(n) = s(n)
s₂(n) = s(s(n))
...
sₖ(n) = 0
```
The **length** of the sequence is the smallest `k` such that `sₖ(n) = 0`.

---

## 🧾 Notes

- Program adheres strictly to specifications:
  - Input validation,
  - Output format,
  - Overflow and invalid input handling,
  - Exit codes as defined.
- Tested up to the limit of `10^15`.

---

## 🧰 Compilation

To compile in a Linux environment:
```bash
gcc -O0 -m32 -Wall -Wextra -Werror -pedantic -o aliquot aliquot.c
```

To run:
```bash
./aliquot
```

---

## 🧩 Source

Code formatted using:  
👉 [https://formatter.org](https://formatter.org/#:~:text=This%20online%20code%20formatter%20is%20capable%20of%20formatting,this%20tool%2C%20you%20can%20effectively%20beautify%20your%20code.)

Additionally, chatGPT was used in order to write and format the final README file

