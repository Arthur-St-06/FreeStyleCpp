#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    static Fraction reduce(const Fraction& fraction);

    bool operator==(const Fraction& other);
    bool operator!=(const Fraction& other);
};

#endif //FRACTION_H
