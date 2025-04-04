#include <iostream>
#include <vector>
#include "Fraction.h"
#include "MathUtils.h"
using namespace std;

template <typename FuncType, typename InputType, typename OutputType>
void compareOutputs(FuncType func, const vector<InputType>& inputs, const vector<OutputType>& expected) {
   for (int i = 0; i < inputs.size(); i++) {
       if (func(inputs[i]) != expected[i]) {
           cout << "FAIL" << endl;
           return;
       }
   }
   cout << "PASS" << endl;
}

void testIsPowerOfTwo() {
    const vector<int> isPowerInputs = {-5, 0, 2, 3, 4, 5, 10, 15, 16, 17, 1048576, 1048500};
    const vector<bool> isPowerExpected = {false, false, true, false, true, false, false, false, true, false, true, false};
    cout << "Testing isPowerOfTwoIteratively" << endl;
    compareOutputs(isPowerOfTwoIteratively, isPowerInputs, isPowerExpected);
    cout << "Testing isPowerOfTwoBinary" << endl;
    compareOutputs(isPowerOfTwoBinary, isPowerInputs, isPowerExpected);

    const vector<float> isPowerFloatInputs = {-5.0f, 0.25f, 0.5f, 0.6f, 0.0f, 2.0f, 16.0f, 17.0f, 1048576.0f, 1048500.0f};
    const vector<bool> isPowerFLoatExpected = {false, true, true, false, false, true, true, false, true, false};
    cout << "Testing isPowerOfTwoIterativelyFloat" << endl;
    compareOutputs(isPowerOfTwoIterativelyFloat, isPowerFloatInputs, isPowerFLoatExpected);
    cout << "Testing isPowerOfTwoBinaryFloat" << endl;
    compareOutputs(isPowerOfTwoBinaryFloat, isPowerFloatInputs, isPowerFLoatExpected);
}

void testIsPrime() {
    const vector<int> isPrimeInputs = {-5, 0, 1, 2, 3, 4, 5, 6, 7, 10, 17, 997, 1000};
    const vector<bool> isPrimeExpected = {false, false, false, true, true, false, true, false, true, false, true, true, false};
    cout << "Testing isPrime" << endl;
    compareOutputs(isPrime, isPrimeInputs, isPrimeExpected);
}

void testReduceFraction() {
    const vector<Fraction> reduceFractionInputs = {Fraction(2, 3),
                                                   Fraction(-2, 3),
                                                   Fraction(-2, 3),
                                                   Fraction(12, 14),
                                                   Fraction(12, 18),
                                                   Fraction(0, -10)};

    const vector<Fraction> reduceFractionExpected = {Fraction(2, 3),
                                                     Fraction(-2, 3),
                                                     Fraction(2, -3),
                                                     Fraction(6, 7),
                                                     Fraction(2, 3),
                                                     Fraction(0, 1)};
    cout << "Testing reduceFraction" << endl;
    compareOutputs(Fraction::reduce, reduceFractionInputs, reduceFractionExpected);
}

void test() {
    testIsPowerOfTwo();
    testIsPrime();
    testReduceFraction();
}

int main() {
   test();
   return 0;
}