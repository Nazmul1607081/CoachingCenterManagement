#include "FIRST_PAGE.h"
#include "STUDENT.h"
#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include "STUDENT.h"
#include "RESULT.h"
#include "MatrixFun.h"
#include "COMPLEX.h"
#include<windows.h> y
#include <stdio.h>
#include <ctime>
using namespace std;
STUDENT::STUDENT()
{
    roll = 0;
}
STUDENT::~STUDENT()
{
    cout<<"...";
}

void STUDENT:: get_data()
{
    //system("cls");
    //int i =0;int p=Total_number_of_student()+i++;
    //cout<<"\n\n\tPrevious roll no is      :  "<<p<<"\n\n\n\n\n"<<endl;
    cout<<"\n\n\tEnter the roll number      :  ";
    cin>>roll;
    cout<<"\n\n\tEnter student name         :  ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,name);
    cout<<"\n\n\tEnter student father name  :  ";
    getline(cin,father_name);
    cout<<"\n\n\tEnter student mother name  :  ";
    getline(cin,mother_name);
    cout<<"\n\n\tCollege name               :  ";
    getline(cin,college_name);
    cout<<"\n\n\tGPA (SSC)                  :  ";
    cin>>SSC_gpa;
    cout<<"\n\n\tBatch(Morning/Day)         :  ";
    cin>>batch;
    //roll = p;
    cout<<"\n\n\tThe Roll number  of the  student is : "<<roll<<endl;
    getchar();

}
void STUDENT:: show_data()
{
    //gotoxy(12,i++);
    //system("cls");
    cout<<"Student Roll       :  ";
    cout<<roll<<endl;
    //gotoxy(12,i);
    cout<<"Student name       :  ";
    cout<<get_name()<<endl;
    //gotoxy(12,i);
    cout<<"Student father name:  ";
    cout<<father_name<<endl;
    //gotoxy(12,i);
    cout<<"Student mother name:  ";
    cout<<mother_name<<endl;
   // gotoxy(12,i);
    cout<<"College name       :  ";
    cout<<college_name<<endl;
    //gotoxy(12,i);
    cout<<"GPA (SSC)          :  ";
    cout<<SSC_gpa<<endl<<endl<<endl<<endl<<endl;
    //getchar();

}
void STUDENT:: show_data1()
{
    //gotoxy(12,4);
    //system("cls");
    cout<<"Roll               :  ";
    cout<<roll<<endl;
    cout<<"Student name       :  ";
    cout<<name<<endl;
    cout<<"Student father name:  ";
    cout<<father_name<<endl;
    cout<<"Student mother name:  ";
    cout<<mother_name<<endl;
    cout<<"College name       :  ";
    cout<<college_name<<endl;
    cout<<"GPA (SSC)          :  ";
    cout<<SSC_gpa<<endl<<endl<<endl<<endl<<endl;
    getchar();

}
void STUDENT::show_name_roll()
{
    cout<<get_name()<<endl;
    cout<<roll<<endl;
}
string STUDENT::get_name()
{
    return name;
}
void STUDENT::set_name(string s)
{
    name=s;
}
void STUDENT::set_roll(int r)
{
    roll=r;
}
int STUDENT::get_roll()
{
    return roll;
}






/*void STUDENT::add_a_student()
{
    STUDENT student_obj;
    fstream f;
    f.open("stu.txt",ios::in|ios::out|ios::binary);
    student_obj.get_data();
    f.write((char*)&student_obj,sizeof(student_obj));
    studentMenu();
}
void STUDENT::show_a_student_details()
{
    STUDENT student_obj;
    fstream f;
    f.open("stu.txt",ios::in|ios::out|ios::binary);
    f.read((char*)&student_obj,sizeof(student_obj));
    student_obj.show_data();
    studentMenu();
}*/
