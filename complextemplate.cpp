#include <iostream>
using namespace std;


template <typename T>
class Complex {
private:
    T real, imag;
public: 
    Complex(T r,T i) : real(r), imag(i) {}
    
    Complex friend operator+ (const Complex& a, const Complex& b){
        return Complex(a.real + b.real, a.imag + b.imag);
    }

    friend ostream& operator <<(ostream& s, const Complex& a) {
        s << a.real << " " << a.imag;
        return s;
    }

};



int main() {
	Complex<double> c1(1.5, 2.5);
	Complex<double> c2(2.2, 1.8);
	Complex<double> c3 = c1 + c2;

	
	Complex<float> c4(1.5f, 2.5f);
	Complex<float> c5(2.2f, 1.8f);
	Complex<float> c6 = c4 + c5;

	Complex<long double> c7(1.5L, 2.5L);
	Complex<long double> c8(2.2L, 1.8L);
	Complex<long double> c9 = c7 + c8;

	cout << c3 << '\n';
	cout << c6 << '\n';
	cout << c9 << '\n';
}