# Goldbach Conjecture Explorer

A visual and computational exploration of the **Goldbach Conjecture** using a deterministic **Miller–Rabin primality test** and a **center-expansion search algorithm**.

The project demonstrates how every tested even integer greater than 2 can be expressed as the sum of two prime numbers.

---

# The Goldbach Conjecture

The conjecture states:

> Every even integer greater than 2 can be expressed as the sum of two prime numbers.

Formally:

[
\forall n \in \mathbb{Z}, \quad n > 2,\ n \text{ even} \Rightarrow \exists\ p_1, p_2 \text{ primes such that } n = p_1 + p_2
]

Example:

```
100 = 47 + 53
28  = 11 + 17
4   = 2 + 2
```

---

# Core Mathematical Intuitions

## 1. Even numbers as multiples of two

Every even number can be written as

[
n = 2k
]

If a prime number is (p), then

[
2p = p + p
]

Example:

```
2 × 5 = 10
10 = 5 + 5
```

So **even numbers that are twice a prime already satisfy the conjecture trivially.**

---

## 2. All primes except 2 are odd

Prime numbers:

```
2, 3, 5, 7, 11, 13, ...
```

Except for **2**, every prime is odd.

Therefore:

```
odd + odd = even
```

Example:

```
3 + 5 = 8
11 + 17 = 28
47 + 53 = 100
```

This means **two odd primes naturally produce an even number**, making Goldbach decompositions possible.

---

# Algorithmic Idea

Instead of searching from the beginning of the number line, the algorithm starts from the **center of the number**.

For an even number (n):

[
node_1 = \frac{n}{2}, \quad node_2 = \frac{n}{2}
]

Then the algorithm expands outward symmetrically.

If the center is even (and not 2):

```
node1 = node1 - 1
node2 = node2 + 1
```

Then iterate:

[
node_1 = node_1 - 2
]
[
node_2 = node_2 + 2
]

At each step we test:

[
isPrime(node_1) \land isPrime(node_2)
]

When both are prime:

[
n = node_1 + node_2
]

The search stops.

---

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
