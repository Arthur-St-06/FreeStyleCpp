#include "Fraction.h"
#include "MathUtils.h"

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
void Fraction::setDenominator(int denominator) { this->denominator = denominator; }

Fraction Fraction::reduce(const Fraction &fraction) {
    // assert if 0 is denominator

    int divisor = gcd(fraction.getNumerator(), fraction.getDenominator());

    Fraction result(fraction.getNumerator() / divisor, fraction.getDenominator() / divisor);
    return result;
}

bool Fraction::operator==(const Fraction& other) {
    return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator();
}

bool Fraction::operator!=(const Fraction& other) {
    return !(*this == other);
}