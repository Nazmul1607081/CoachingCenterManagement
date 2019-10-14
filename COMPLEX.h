#ifndef COMPLEX_H
#define COMPLEX_H


#include<iostream>
using namespace std;

class Complex
{

    public:
        double real,imag;
        friend istream& operator>>(istream& in,Complex& c);
        friend ostream& operator<<(ostream& in,Complex& c);
    protected:

    private:
};

#endif // COMPLEX_H
