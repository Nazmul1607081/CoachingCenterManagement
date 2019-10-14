#include "MatrixFun.h"
#include "RESULT.h"
#include "FIRST_PAGE.h"
#include "STUDENT.h"
#include<bits/stdc++.h>
#include "COMPLEX.h"
#include<iostream>
using namespace std;



///
Complex operator+ (Complex& c1,Complex& c2)
{
    Complex c;
    c.real=c1.real+c2.real;
    c.imag=c2.imag+c1.imag;
    return c;
}
Complex operator- (Complex& c1,Complex& c2)
{
    Complex c;
    c.real=c1.real-c2.real;
    c.imag=c2.imag-c1.imag;
    return c;
}
template<typename T>
Matrix<T> operator+(Matrix<T>& c1,Matrix<T>& c2)
{
    Matrix<T> c(c1.a,c1.b);
    for(int i=0; i<c1.a; i++)
    {
        for(int j=0; j<c1.b; j++)
        {
            c.data[i][j]=c1.data[i][j]+c2.data[i][j];
        }
    }
    return c;
}
template<typename T>
Matrix<T> operator-(Matrix<T>& c1,Matrix<T>& c2)
{
    Matrix<T> c(c1.a,c1.b);
    for(int i=0; i<c1.a; i++)
    {
        for(int j=0; j<c1.b; j++)
        {
            c.data[i][j]=c1.data[i][j]-c2.data[i][j];
        }
    }
    return c;
}

void input_matrix()
{

    int a,b;
    cout<<"\n\n\tEnter the dimension     : ";
    cout<<"\n\n\tRow size : ";
    cin>>a;
    cout<<"\n\n\tColumn size : ";
    cin>>b;
    cout<<endl;
    cout<<"\n\n\t1.Complex number matrix";
    cout<<"\n\t2.Integer number matrix";
    cout<<"\n\t3.Double number matrix\n\n\t";
    char c;
    cin>>c;
    if(c=='1')
    {
        Matrix<Complex> m1(a,b),m2(a,b),m3(a,b);
        cout<<"\n\n\tEnter the first matrix :\n\t";
        cin>>m1;
        cout<<"\n\n\tEnter the second matrix :\n\n\t";
        cin>>m2;
        cout<<"\n\n\tThis is first matrix\n\t";
        cout<<m1<<endl;
        cout<<"\n\n\tThis is second matrix\n\t";
        cout<<m2<<endl;
        cout<<"\n\n\tChoose a operation to perform \n\t";
        cout<<"\n\n\tplease press 1 for addition 2 for substitution of two complex number matrix \n\n\n\t";
        char ch ;
        cin>>ch;
        if(ch=='1')
            m3=m1+m2;
        if(ch=='2')
            m3=m1-m2;
        cout<<"\n\n\n\tThis is the result \n\t";
        cout<<m3<<endl;
        getchar();
    }
    else if(c=='2')
    {
        Matrix<int> m1(a,b),m2(a,b),m3(a,b);
        cout<<"\n\n\tEnter the first matrix :\n\t";
        cin>>m1;
        cout<<"\n\n\tEnter the second matrix :\n\n\t";
        cin>>m2;
        cout<<"\n\n\tThis is first matrix\n\t";
        cout<<m1<<endl;
        cout<<"\n\n\tThis is second matrix\n\t";
        cout<<m2<<endl;
        cout<<"\n\n\tChoose a operation to perform \n\t";
        cout<<"\n\n\tplease press 1 for addition 2 for substitution of two complex number matrix \n\n\n\t"<<endl;
        char ch ;
        cin>>ch;
        if(ch=='1')
            m3=m1+m2;
        if(ch=='2')
            m3=m1-m2;
        cout<<"\n\n\n\tThis is the result \n\t";
        cout<<m3<<endl;
        getchar();
    }
    else if(c=='3')
    {
        Matrix<double> m1(a,b),m2(a,b),m3(a,b);
        cout<<"\n\n\tEnter the first matrix :\n\t";
        cin>>m1;
        cout<<"\n\n\tEnter the second matrix :\n\n\t";
        cin>>m2;
        cout<<"\n\n\tThis is first matrix\n\t";
        cout<<m1<<endl;
        cout<<"\n\n\tThis is second matrix\n\t";
        cout<<m2<<endl;
        cout<<"\n\n\tChoose a operation to perform \n\t";
        cout<<"\n\n\tplease press 1 for addition 2 for substitution of two complex number matrix \n\n\n\t"<<endl;
        char ch ;
        cin>>ch;
        if(ch=='1')
            m3=m1+m2;
        if(ch=='2')
            m3=m1-m2;
        cout<<"\n\n\n\tThis is the result \n\t"<<endl;
        cout<<m3<<endl;
        getchar();
    }


}


