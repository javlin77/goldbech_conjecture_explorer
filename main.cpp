#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Validate input
bool isValid(int n) {
    return (n > 2 && n % 2 == 0);
}

// Build sieve up to n
vector<bool> buildSieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Goldbach using center expansion + sieve
pair<int,int> goldbach(int n, const vector<bool>& prime) {
    int node1 = n / 2;
    int node2 = n / 2;

    // If n/2 is even → adjust once
    if (node1 % 2 == 0) {
        node1--;
        node2++;
    }

    while (node1 >= 2) {
        if (prime[node1] && prime[node2]) {
            return {node1, node2};
        }

        node1 -= 2;
        node2 += 2;
    }

    return {-1, -1};
}

int main() {
    int n;
    cout << "Enter an even number greater than 2: ";
    cin >> n;

    if (!isValid(n)) {
        cout << "Invalid input. Please enter an even number greater than 2.";
        return 0;
    }

    // Build sieve once
    vector<bool> prime = buildSieve(n);

    pair<int,int> result = goldbach(n, prime);

    if (result.first != -1) {
        cout << result.first << " + " << result.second << " = " << n;
    } else {
        cout << "No prime pair found.";
    }

    return 0;
}