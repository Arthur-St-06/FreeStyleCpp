#include "MathUtils.h"

bool isPowerOfTwoIteratively(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

bool isPowerOfTwoBinary(int n) {
    return (n & (n - 1)) == 0;
}

bool isPrime(int n) {
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