#include "Fraction.h"
#include "MathUtils.h"
#include <cassert>

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
void Fraction::setDenominator(int denominator) { this->denominator = denominator; }

Fraction Fraction::reduce(const Fraction &fraction) {
    assert(fraction.getDenominator() != 0);

    int divisor = gcd(fraction.getNumerator(), fraction.getDenominator());

    Fraction result(fraction.getNumerator() / divisor, fraction.getDenominator() / divisor);
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return this->getNumerator() == other.getNumerator() && this->getDenominator() == other.getDenominator() ||
           -this->getNumerator() == other.getNumerator() && -this->getDenominator() == other.getDenominator(); // Makes -2/3 == 2/-3
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}