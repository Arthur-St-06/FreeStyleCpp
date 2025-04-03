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

int gcd(int a, int b) {
   while (b != 0) {
       int tmp = a % b;
       a = b;
       b = tmp;
   }
   return a;
}

vector<int> reduceFraction(const vector<int>& nums) {
   vector<int> result;
   int divisor = gcd(nums[0], nums[1]);
   result.push_back(nums[0] / divisor);
   result.push_back(nums[1] / divisor);
   return result;
}

template <typename FuncType, typename InputType, typename OutputType>
void testFunction(FuncType func, const vector<InputType>& inputs, const vector<OutputType>& expected) {
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
   testFunction(isPowerOfTwoIteratively, isPowerInputs, isPowerExpected);
   cout << "Testing isPowerOfTwoBinary" << endl;
   testFunction(isPowerOfTwoBinary, isPowerInputs, isPowerExpected);

   vector<int> isPrimeInputs = {2, 3, 4, 5, 6, 7, 10, 17};
   vector<bool> isPrimeExpected = {true, true, false, true, false, true, false, true};
   cout << "Testing isPrime" << endl;
   testFunction(isPrime, isPrimeInputs, isPrimeExpected);

   vector<vector<int>> reduceFractionInputs = {{2, 3}, {3, 2}, {12, 14}, {12, 18}};
   vector<vector<int>> reduceFractionExpected = {{2, 3}, {3, 2}, {6, 7}, {2, 3}};
   cout << "Testing reduceFraction" << endl;
   testFunction(reduceFraction, reduceFractionInputs, reduceFractionExpected);

   return 0;
}