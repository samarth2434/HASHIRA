#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

// Function to convert a string number from any base (2–16) to decimal
cpp_int convertToDecimal(const string &value, int base) {
    cpp_int result = 0;
    for (char ch : value) {
        int digit;
        if (isdigit(ch)) digit = ch - '0';
        else if (isalpha(ch)) digit = 10 + (tolower(ch) - 'a');
        else continue;
        result = result * base + digit;
    }
    return result;
}

int main() {
    // --- 1. Hardcoded JSON-like input (can replace with actual JSON parser) ---
    vector<pair<int, string>> inputs = {
        {10, "4"},
        {2, "111"},
        {10, "12"},
        {4, "213"}
    };

    // --- 2. Decode values ---
    vector<cpp_int> decoded_values;
    for (auto &p : inputs) {
        cpp_int val = convertToDecimal(p.second, p.first);
        decoded_values.push_back(val);
        cout << "Decoded Value: " << val << endl;
    }

    // --- 3. Calculate Secret c (example: sum of all decoded values) ---
    cpp_int c = 0;
    for (auto &v : decoded_values) c += v;

    cout << "Secret (c) = " << c << endl;
    return 0;
}
