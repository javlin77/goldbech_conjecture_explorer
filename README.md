# Goldbach Conjecture Explorer

A visual and computational exploration of the **Goldbach Conjecture** using a deterministic **Miller–Rabin primality test** and a **center-expansion search algorithm**.

The project demonstrates how every tested even integer greater than 2 can be expressed as the sum of two prime numbers.

---

## Mathematical Foundation

The **Goldbach Conjecture** is one of the oldest unsolved problems in number theory. It proposes that every even integer greater than 2 can be expressed as the sum of two prime numbers.

### Formal Statement

For every integer (n):

```
∀ n ∈ ℤ
n > 2
n is even
```

there exist two prime numbers (p₁) and (p₂) such that

```
p₁ + p₂ = n
```

---

### Visual Interpretation

For an even number (n):

```
      p₁        p₂
       │        │
       ▼        ▼
     prime + prime
          │
          ▼
           n
```

Example:

```
47 + 53 = 100
```

Both **47** and **53** are prime numbers whose sum produces the even integer **100**.

---

### Example Decompositions

```
4   = 2 + 2
6   = 3 + 3
8   = 3 + 5
10  = 5 + 5
28  = 11 + 17
100 = 47 + 53
```

---

### Core Intuitions

Two simple observations motivate why this conjecture appears plausible:

#### 1. Every even number is a multiple of two

```
n = 2k
```

If (p) is a prime number:

```
2p = p + p
```

Example:

```
10 = 5 + 5
```

So even numbers that are twice a prime automatically satisfy the conjecture.

---

#### 2. All primes except 2 are odd

Prime numbers:

```
2, 3, 5, 7, 11, 13, ...
```

Except for **2**, every prime number is odd.

Since

```
odd + odd = even
```

two odd primes naturally combine to produce an even number.

Example:

```
3 + 5  = 8
11 + 17 = 28
47 + 53 = 100
```

---

### Algorithmic Insight Used in This Project

Instead of scanning from small primes upward, this project uses a **symmetric center-expansion search**.

For an even number (n):

```
node1 = n / 2
node2 = n / 2
```

Then expand outward symmetrically:

```
node1 ↓        node2 ↑
49 + 51
47 + 53   ← primes found
```

Formally, the search explores pairs of the form:

```
n/2 ± 1
n/2 ± 3
n/2 ± 5
...
```

until both numbers are prime.

This approach often finds valid decompositions quickly, especially for large values of (n).

---

### Disclaimer

This project **does not prove the Goldbach Conjecture**.
It only verifies the conjecture computationally for the tested values.



# Why Start From the Center?

For large numbers, valid Goldbach pairs often appear **near (n/2)**.

This symmetric search reduces the number of checks compared to scanning from small primes upward.

---

# Primality Testing

The project uses a **deterministic Miller–Rabin primality test** with the bases:

```
2
325
9375
28178
450775
9780504
1795265022
```

This guarantees correctness for all numbers below:

[
3.3 \times 10^{24}
]

---

# Visualization

The interface allows users to:

* Enter an even number
* Observe the Goldbach decomposition
* View the prime pair found
* Track computation time
* Maintain a history of tested numbers

Optional animation shows the symmetric search:

```
node1 ↓        node2 ↑
49 + 51
47 + 53
```

---

# Example Result

```
Input:
1000937382345678188

Output:
500468691172838737 + 500468691172839451
```

---

# Technologies Used

* HTML
* CSS
* JavaScript (BigInt)
* Deterministic Miller–Rabin
* LocalStorage (history)

---

# Future Improvements

* Visual animation of the search process
* Prime distribution statistics
* Graphical number-line visualization
* WebAssembly version using C++ for near-native performance

---

# Disclaimer

This project **does not prove the Goldbach Conjecture**.

It only verifies decompositions computationally for tested values.

The conjecture remains an open problem in number theory.
