#include <iostream>
#include <iomanip>
using namespace std;
//12. x^2+5*cos(x)  a=Ц1	b=4	m=5	
// вадратична€ интерпол€ци€
double f(double x) {
	return x * x + 5 * cos(x);
}
double N1(double* x, double* y, int t) {
	double xt = (x[t+1] + x[t]) / 2.0;
	return y[t] + (xt - x[t]) * (y[t + 1] - y[t]) / 
		(x[t + 1] - x[t]);
}
double N2(double* x, double* y, int t) {
	double xt = (x[t + 1] + x[t]) / 2.0;
	return N1(x, y, t) + (xt - x[t]) *(xt - x[t + 1]) * 
		((y[t] - y[t + 1]) /(x[t] - x[t + 1])
			- (y[t + 1] - y[t + 2]) /
		(x[t + 1] - x[t + 2])) / (x[t] - x[t + 2]);
}
int main() {
	double a = -1.0, b = 4.0;
	size_t m = 5;
	double h = (b - a) / (m-1);
	double* x = new double[m+1];
	double* y = new double[m+1];
	for (int i = 0; i < m + 1; i++) {
		x[i] = a + i * h;
		y[i] = f(x[i]);
		cout << setw(4) << x[i] << setw(8)<< y[i] << endl;
	}
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < m-1; i++) {
		cout << setw(6) << (x[i+1]+x[i])/2.0 <<
			" interpol " << N2(x, y, i) 
			<<" real " << f((x[i+1]+x[i])/2.0) << endl;
	}
	
}