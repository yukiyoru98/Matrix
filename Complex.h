#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    
public:
    Complex(double = 0, double = 0);
    Complex add(Complex);
    Complex multiply(Complex);
    Complex divide(Complex);
    Complex conjugate();
    double getReal();
    double getImag();
    void print();

private:
    double real;
    double imag;
    
};

#endif
