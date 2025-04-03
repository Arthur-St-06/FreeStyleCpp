#include <iostream>
#include <vector>
using namespace std;


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

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    void setNumerator(int numerator) { this->numerator = numerator; }
    void setDenominator(int denominator) { this->denominator = denominator; }

    bool operator==(const Fraction& other) {
        return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator();
    }

    bool operator!=(const Fraction& other) {
        return !(*this == other);
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

Fraction reduceFraction(const Fraction &fraction) {
    // assert if 0 is denominator

    int divisor = gcd(fraction.getNumerator(), fraction.getDenominator());

    Fraction result(fraction.getNumerator() / divisor, fraction.getDenominator() / divisor);
    return result;
}

template <typename FuncType, typename InputType, typename OutputType>
void test(FuncType func, const vector<InputType>& inputs, const vector<OutputType>& expected) {
   for (int i = 0; i < inputs.size(); i++) {
       if (func(inputs[i]) != expected[i]) {
           cout << "FAIL" << endl;
           return;
       }
   }
   cout << "PASS" << endl;
}

int main() {
   vector<int> isPowerInputs = {2, 3, 4, 5, 10, 15, 16, 17};
   vector<bool> isPowerExpected = {true, false, true, false, false, false, true, false};
   cout << "Testing isPowerOfTwoIteratively" << endl;
   test(isPowerOfTwoIteratively, isPowerInputs, isPowerExpected);
   cout << "Testing isPowerOfTwoBinary" << endl;
   test(isPowerOfTwoBinary, isPowerInputs, isPowerExpected);

   vector<int> isPrimeInputs = {2, 3, 4, 5, 6, 7, 10, 17};
   vector<bool> isPrimeExpected = {true, true, false, true, false, true, false, true};
   cout << "Testing isPrime" << endl;
   test(isPrime, isPrimeInputs, isPrimeExpected);

   vector<Fraction> reduceFractionInputs = {Fraction(2, 3), Fraction(3, 2), Fraction(12, 14), Fraction(12, 18)};
   vector<Fraction> reduceFractionExpected = {Fraction(2, 3), Fraction(3, 2), Fraction(6, 7), Fraction(2, 3)};
   cout << "Testing reduceFraction" << endl;
   test(reduceFraction, reduceFractionInputs, reduceFractionExpected);

   return 0;
}