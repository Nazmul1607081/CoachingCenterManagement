#include "MatrixFun.h"
#include "RESULT.h"
#include "FIRST_PAGE.h"
#include "STUDENT.h"
#include<bits/stdc++.h>
#include "COMPLEX.h"
#include<iostream>
using namespace std;

istream& operator>> (istream& in,Complex& c)
{
    cout<<"\n\n\t";
    cout<<"Complex number "<<endl;
    cout<<"\n\n\t";
    in>>c.real;
    cout<<"\n\t";
    in>>c.imag;
    return in;

}
ostream& operator<<(ostream& out,Complex& c2)
{
    cout<<"\n\n\t";
    out<<c2.real<<" +i"<<c2.imag;;

    return out;
}













