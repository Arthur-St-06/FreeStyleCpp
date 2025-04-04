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
    vector<int> isPowerInputs = {2, 3, 4, 5, 10, 15, 16, 17};
    vector<bool> isPowerExpected = {true, false, true, false, false, false, true, false};
    cout << "Testing isPowerOfTwoIteratively" << endl;
    compareOutputs(isPowerOfTwoIteratively, isPowerInputs, isPowerExpected);
    cout << "Testing isPowerOfTwoBinary" << endl;
    compareOutputs(isPowerOfTwoBinary, isPowerInputs, isPowerExpected);
}

void testIsPrime() {
    vector<int> isPrimeInputs = {2, 3, 4, 5, 6, 7, 10, 17};
    vector<bool> isPrimeExpected = {true, true, false, true, false, true, false, true};
    cout << "Testing isPrime" << endl;
    compareOutputs(isPrime, isPrimeInputs, isPrimeExpected);
}

void testReduceFraction() {
    vector<Fraction> reduceFractionInputs = {Fraction(2, 3), Fraction(3, 2), Fraction(12, 14), Fraction(12, 18)};
    vector<Fraction> reduceFractionExpected = {Fraction(2, 3), Fraction(3, 2), Fraction(6, 7), Fraction(2, 3)};
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