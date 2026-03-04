#include <iostream>
#include <utility>
using namespace std;

using ull = unsigned long long;

// Fast modular multiplication (avoids overflow)
ull modMul(ull a, ull b, ull mod) {
    __uint128_t res = (__uint128_t)a * b;
    return (ull)(res % mod);
}

// Fast modular exponentiation
ull modPow(ull base, ull exp, ull mod) {
    ull result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = modMul(result, base, mod);
        base = modMul(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin test
bool isPrime(ull n) {
    if (n < 2) return false;
    for (ull p : {2, 3, 5, 7, 11, 13, 17}) {
        if (n % p == 0) return n == p;
    }

    ull d = n - 1;
    int r = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    ull testBases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    for (ull a : testBases) {
        if (a % n == 0) continue;
        ull x = modPow(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool composite = true;
        for (int i = 1; i < r; i++) {
            x = modMul(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }

        if (composite) return false;
    }

    return true;
}

// Goldbach using center expansion
pair<ull, ull> goldbach(ull n) {
    ull node1 = n / 2;
    ull node2 = n / 2;

    if (node1 % 2 == 0) {
        node1--;
        node2++;
    }

    while (node1 >= 2) {
        if (isPrime(node1) && isPrime(node2)) {
            return {node1, node2};
        }
        node1 -= 2;
        node2 += 2;
    }

    return {0, 0};
}

int main() {
    ull n;
    cout << "Enter even number > 2: ";
    cin >> n;

    if (n <= 2 || n % 2 != 0) {
        cout << "Invalid input.";
        return 0;
    }

    auto result = goldbach(n);

    if (result.first != 0)
        cout << result.first << " + " << result.second << " = " << n;
    else
        cout << "No pair found.";

    return 0;
}