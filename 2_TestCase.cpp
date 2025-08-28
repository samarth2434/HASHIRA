#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

// Convert string in any base (2–16) to decimal (cpp_int)
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
    // JSON values (manually hardcoded for now)
    vector<pair<int, string>> inputs = {
        {6,  "13444211440455345511"},
        {15, "aed7015a346d63"},
        {15, "6aeeb69631c227c"},
        {16, "e1b5e05623d881f"},
        {8,  "316034514573652620673"},
        {3,  "2122212201122002221120200210011020220200"},
        {3,  "20120221122211000100210021102001201112121"},
        {6,  "20220554335330240002224253"},
        {12, "45153788322a1255483"},
        {7,  "1101613130313526312514143"}
    };

    // Conversion and output
    for (int i = 0; i < inputs.size(); i++) {
        cpp_int decimalValue = convertToDecimal(inputs[i].second, inputs[i].first);
        cout << i+1 << ": " << decimalValue << "\n";
    }
    return 0;
}
