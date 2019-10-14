#ifndef MATRIXFUN_H
#define MATRIXFUN_H
#include<iostream>
#include"COMPLEX.h"
using namespace std;
template<typename T>

class Matrix
{
public:
    int a,b;
    T *data[100];
    Matrix(int a,int b)
    {
        this->a=a;
        this->b=b;
        //*data[a];
        /*T** data = new T*[a];*/

        for(int i = 0; i < a; ++i)
            data[i] = new T[b];
        for(int i=0 ; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                data[i][j]={0};
            }
        }

    }


    friend istream& operator>> (istream& in,Matrix<T>& m)
    {
        for(int i=0 ; i<m.a; i++)
        {
            for(int j=0; j<m.b; j++)
            {
                cin>>m.data[i][j];
            }
        }

        return in;
    }
    friend ostream& operator<<(ostream& out,Matrix<T>& c2)
    {

        for(int i=0 ; i<c2.a; i++)
        {
            for(int j=0; j<c2.b; j++)
            {
                cout<<c2.data[i][j]<<"  ";
            }
            cout<<endl;
        }

        return out;
    }
    ~Matrix()
    {
        for (int i = 0; i < a; i++)
        {
            delete [] data[i];
        }
        delete [] data;

    }
};





void input_data();
void input_matrix();
void matrix_fun();

#endif // MATRIXFUN_H
