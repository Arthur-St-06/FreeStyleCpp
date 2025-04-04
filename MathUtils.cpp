#include "MathUtils.h"
#include <cmath>

bool isPowerOfTwoIteratively(int n) {
    if (n < 1) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

bool isPowerOfTwoIterativelyFloat(float f) {
    if (f <= 0.0f) return false;
    if (f < 1.0f) {
        f = 1.0f / f;
    }
    int n = static_cast<int>(f);
    if (fabsf(f - static_cast<float>(n)) > 1e-6) return false; // Ensure f is an integer, accounting for precision error

    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

bool isPowerOfTwoBinary(int n) {
    return n > 0 && !(n & (n - 1));
}

bool isPowerOfTwoBinaryFloat(float f) {
    if (f <= 0.0f) return false;
    if (f < 1.0f) {
        f = 1.0f / f;
    }
    int n = static_cast<int>(f);
    if (fabsf(f - static_cast<float>(n)) > 1e-6) return false; // Ensure f is an integer, accounting for precision error

    return !(n & (n - 1));
}

bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}