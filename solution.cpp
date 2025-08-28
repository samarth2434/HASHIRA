#include <iostream>
using namespace std;

// Step 1: Compute basic polynomial value
double polynomialValue(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

// Step 2: Linear Interpolation Formula (LIF)
double linearInterpolation(double a, double b, double c, double x0, double x1, double x) {
    double f_x0 = polynomialValue(a, b, c, x0);
    double f_x1 = polynomialValue(a, b, c, x1);
    return f_x0 + ((x - x0) / (x1 - x0)) * (f_x1 - f_x0);
}

int main() {
    double a, b, c, x, x0, x1;

    // Input coefficients
    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;

    // Input x for basic value
    cout << "Enter value of x: ";
    cin >> x;

    // Step 1: Compute basic value
    double basic_val = polynomialValue(a, b, c, x);
    cout << "Basic Value f(" << x << ") = " << basic_val << endl;

    // Step 2: LIF value
    cout << "Enter x0 and x1 for LIF: ";
    cin >> x0 >> x1;

    double lif_val = linearInterpolation(a, b, c, x0, x1, x);
    cout << "LIF Value at x = " << x << " is " << lif_val << endl;

    // Step 3: Print constant c
    cout << "Constant term c = " << c << endl;

    return 0;
}
