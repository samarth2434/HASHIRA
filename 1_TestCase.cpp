#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

// Convert string to decimal (cpp_int) from given base
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
    vector<pair<int, string>> inputs = {
        {10, "4"},
        {2, "111"},
        {10, "12"},
        {4, "213"}
    };

    for (int i = 0; i < inputs.size(); i++) {
        cpp_int decimalValue = convertToDecimal(inputs[i].second, inputs[i].first);
        cout << i+1 << ": " << decimalValue << "\n";
    }
    return 0;
}
