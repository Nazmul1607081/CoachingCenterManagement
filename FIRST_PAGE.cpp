#include "FIRST_PAGE.h"
#include "STUDENT.h"
#include<bits/stdc++.h>
#include "STUDENT.h"
#include<bits/stdc++.h>
#include "RESULT.h"
#include "MatrixFun.h"
#include "COMPLEX.h"
using namespace std;

#include<windows.h> y
#include <stdio.h>
#include <ctime>


STUDENT student_obj,s;


int Total_number_of_student()
{
    fstream fio("stud.dat",ios::in|ios::out|ios::binary);
    int size=0;
    //int begin,last;
    //begin=fio.tellg();
    while(fio.read((char*)&student_obj,sizeof(student_obj)))
    {
        size++;
    }
    //last=fio.tellg();
    //fio.close();
    return size;

}


COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void time()
{
    //  FOR current time and date
    gotoxy(1,10);
    time_t now;
    time (&now);
    cout << "\n\n\t\t Current Date & Time is: "<<ctime(&now);;         // For Displaying Date and Time
    // Creating Object of Time

}
void  loading()
{
    gotoxy(24,26);
    int i;
    for (i=0; i<5; i++)
    {
        cout << "\xdb\xdb\xdb\xdb\xdb";
        Sleep(100);
    }
    Sleep(500);
    cout << endl << endl;
    gotoxy(24,28);
}
void  mainEntrance()
{
    gotoxy(15,2);
    cout<<"     ллл     ллл       лллллл         лллллл       "<<endl;
    gotoxy(15,3);
    cout<<"     лллл    ллл     ллл            ллл         "<<endl;
    gotoxy(15,4);
    cout<<"     ллллл   ллл    ллл           ллл               "<<endl;
    gotoxy(15,5);
    cout<<"     ллл лл  ллл    ллл           ллл                "<<endl;
    gotoxy(15,6);
    cout<<"     ллл   ллллл    ллл           ллл          "<<endl;
    gotoxy(15,7);
    cout<<"     ллл    лллл     ллл           ллл            "<<endl;
    gotoxy(15,8);
    cout<<"     ллл     ллл       лллллл        лллллл    "<<endl<<endl;
    gotoxy(6,9);
    cout << "     **************************************************************" << endl;
    gotoxy(6,10);
    cout << "                  OBJECT ORIENTED PROGRAMMING PROJECT                     " << endl;
    gotoxy(6,11);
    cout << "     **************************************************************" << endl;
}
void login()
{
    system("cls");

    string username = "";
    string  password = "";
    char retry;
    //int i = 0, j = 0;
    mainEntrance();
    time();
    gotoxy(35,14);
    cout << "(LOGIN)";
    gotoxy(20,16);
    cout << "Enter Username: \n\t\t    Enter Password: ";
    gotoxy(36,16);
    cin>>username;
    gotoxy(36,17);
    cin>>password;


    if (username == "n" && password == "n")
    {
        gotoxy(15,16);
        cout << "\n\n Username & Password Matched !! ";
        cout << "\n\n\t Access Granted...\n\n";
        cout << "\n\n\t\t Now Loading: ";
        loading();
        return;
    }
    else
    {
        system("cls");
        cout << "\n\n You entered Wrong UserName/Password ";
        cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
        cin >> retry;
        if(retry == 'r' || retry == 'R')
        {
            system("cls");
            login();
        }
        else
        {
            exit(0);
        }
    }
}
fstream fio("stud.dat",ios::in|ios::out|ios::binary);

///Admit a student ///

void add_a_student()
{
    system("cls");
    char ch='y';
    ofstream fout("stud.dat",ios::out|ios::app|ios::binary);
    while(ch=='y'||ch=='Y')
    {
        student_obj.get_data();
        //cout<<"\n\n\tDo you want to save this Y/N ";
        //cin>>ch;
        //if(ch=='Y'||ch=='y')
        fout.write((char*)&student_obj,sizeof(student_obj));
        cout<<"\n\n\tDo you want to add another :(y/n) ";
        cin>>ch;

    }
    fout.close();
    cout<<"\nData Appended and Transferred to file...\n";

}

///Show all student details::///

void show_a_student_details()
{
    system("cls");
    ifstream fin("stud.dat",ios::in|ios::binary);
    while(fin.read((char*)&student_obj,sizeof(student_obj)))
    {

        student_obj.show_data();
    }
    fin.close();
    cout<<"\n\nThe total number of student is                   :"<<Total_number_of_student()<<endl;
    getchar();
    //studentMenu();
}
/// Search option ///
bool  comps(string s1,string s2,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(s1.at(i)!=s2.at(i))
            return false;
    }
    return  true;
}

/// ******Searching option***** ///

void search()
{
    int flag = 0;
    ifstream fin("stud.dat",ios::in|ios::binary);
    system("cls");
    gotoxy(8,4);
    cout<<"\tSearch by :";
    char ch;
    cout<<"\n\n\t\t 1. Roll ";
    cout<<"\n\n\t\t 2. Name ";
    cout<<"\n\n\t";
    cin>>ch;
    gotoxy(30,5);
    if(ch=='1')
    {
        system("cls");
        gotoxy(20,5);
        cout<<"Enter a roll to search : ";
        int search_roll;
        cin>>search_roll;
        cout<<endl<<endl;
        while(fin.read((char*)&student_obj,sizeof(student_obj)))
        {
            if(search_roll==student_obj.get_roll())
            {
                flag=1;
                student_obj.show_data();
            }
        }
    }
    else if(ch=='2')
    {
        system("cls");
        gotoxy(20,5);
        int n;
        cout<<"\n\n\t How many character do you want for name search :  ";
        cin>>n;
        cout<<"\n\n\tEnter a name to search : ";
        string search_name;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,search_name);
        cout<<endl<<endl;
        while(fin.read((char*)&student_obj,sizeof(student_obj)))
        {
            if(comps(search_name,student_obj.get_name(),n))
            {
                flag=1;
                student_obj.show_data();
                getchar();
            }
        }
    }

    if(flag==0)
    {
        cout<<"\n\n\n No data found";
    }
    cout<<" \n\n\n\n 1 for try another one and  0 for back to main menu \n"<<endl;

    char c;
    cin>>c;
    if(c=='1')
    {
        search();
    }
    fin.close();
    getchar();
}

//For Displaying the all data of the students.


void Modify()
{
    system("cls");
    cout<<"\n\n\tEnter a roll to search :  ";
    //string search_name;
    int search_roll;
    cin>>search_roll;
    //cin>>search_name;
    fstream fio("stud.dat",ios::in|ios::binary|ios::out);
    int flag = 0;
    while(fio)
    {
        int loc=fio.tellg();
        fio.read((char*)&student_obj,sizeof(student_obj));
        //cout<<student_obj.get_name()<<"  bbb  "<<endl;
        if(search_roll==student_obj.get_roll())
        {
            flag = 1;
            student_obj.show_data1();
            cout<<"\n\n\tPlease modify :"<<endl;
            getchar();
            //student_obj.clear();
            //ofstream fout("stud.txt",ios::out|ios::app|ios::binary);
            student_obj.get_data();
            fio.seekg(loc);
            fio.write((char*)&student_obj,sizeof(student_obj));

        }
    }
    if(flag==0)
        cout<<"\t\tNothing found\n";
    fio.close();
    getchar();
}


void Delete()
{
    system("cls");
    cout<<"\n\n\tEnter a roll to search : "<<endl;
    //string search_name;
    //cin>>search_name;
    int search_roll;
    cin>>search_roll;
    fstream fio("stud.dat",ios::in|ios::binary|ios::out);
    ofstream fio2("stud2.dat",ios::binary|ios::out|ios::app);
    ofstream fio3("stud3.dat",ios::binary|ios::out|ios::app);
    while(fio)
    {
        fio.read((char*)&student_obj,sizeof(student_obj));

        if(search_roll==student_obj.get_roll())
        {
            student_obj.show_data1();
            cout<<"\t\t Do you want to delete this data confirm double enter and y/n ";
            char ch;
            cin>>ch;
            if(ch=='Y'||ch=='y')
            {
                fio3.write((char*)&student_obj,sizeof(student_obj));
            }
            else
            {
                fio2.write((char*)&student_obj,sizeof(student_obj));
            }
        }
        else
        {
            fio2.write((char*)&student_obj,sizeof(student_obj));
        }
    }
    fio.close();
    fio2.close();
    fio3.close();
    if( remove( "stud.dat" ) != 0 )
        cout<< "\n\n\tError deleting file" ;
    else
        cout<< "\n\n\tFile successfully deleted" ;
    rename("stud2.dat","stud.dat");
    getchar();
}

void student_corner()
{
    cout<<"\n\n\t1. TO SEE THE RESULT "<<endl;
    cout<<"\n\n\t2. ENTERTINMENT "<<endl;
    cout<<"\n\t3. Notice Bord \n\n\t\t\t";
    char c;
    cin>>c;
    if(c=='1')
        choose_exam_s();
    if(c=='2')
    {
        Entertainment();
    }
    if(c=='3')
    {
        show_previous_notice();
    }

}
void Entertainment()
{
    cout<<"\n\n\tPress 1 for matrix fun 0 for exit \n\n\t\t\t";
    char ch ;
    cin>>ch;
    if(ch=='1')
        input_matrix();

}
void show_previous_notice()
{
    string text;
    ifstream fin("notice.dat",ios::in|ios::binary);
    while(fin)
    {
        getline(fin,text);
        cout<<"\n\t"<<text;
    }
    getchar();
    getchar();
}
void new_notice()
{
    system("cls");
    remove("notice.dat");
    ofstream fout("notice.dat",ios::out|ios::app|ios::binary);
    string str;
    cout<<"\n\n\tPlease write in two lines\n";
    for(int i=0;i<2;i++)
    {
        cin>>str;
        fout<<str;
    }

}
void update_notice()
{
    cout<<"\n\n\tPress 1 for update 0 for exit \n\n\t\t\t";
    char ch ;
    cin>>ch;
    if(ch=='1')
    {
        system("cls");
        show_previous_notice();
        new_notice();
    }

}
void studentMenu()
{
    system("cls");

    char choice;
    while(true)
    {
        system("cls");
        gotoxy(16,2);
        cout << "  _________________________MAIN MENU_________________________";
        gotoxy(30,5);
        cout << " 1: Admit a student ";
        gotoxy(30,7);
        cout << " 2: See Student Details";
        gotoxy(30,9);
        cout << " 3: To Search a student Details";
        gotoxy(30,11);
        cout << " 4: Modify Result";
        gotoxy(30,13);
        cout << " 5: Delete Record of Student ";
        gotoxy(30,15);
        cout << " 6: Result";
        gotoxy(30,17);
        cout << " 7: Update notice";
        gotoxy(30,19);
        cout << " 8: Student Corner ";
        gotoxy(30,21);
        cout << " 9: Exit ";
        gotoxy(30,25);
        cout << " Enter your Choice: ";


        cin>>choice;
        if(choice=='1')
        {
            add_a_student();
            cout << "\n\n\t";
        }

        if(choice=='2')
        {
            show_a_student_details();
            getchar();
            cout << "\n\n\t";
        }
        if(choice=='3')
        {
            search();
            getchar();
            cout << "\n\n\t";
        }
        if(choice=='4')
        {
            Modify();
            getchar();
            cout << "\n\n\t";
        }
        if(choice=='5')
        {
            Delete();
            getchar();
            cout << "\n\n\t";
        }
        if(choice=='6')
        {
            Result();
            getchar();
            cout << "\n\n\t";
        }
        if(choice=='7')
        {
            update_notice();
            getchar();
        }

        if(choice=='8')
        {
            student_corner();
            getchar();
        }
        if(choice=='9')
        {
            return;
        }
        //studentMenu();


    }
}

void FirstPage::first_page()
{
    system("color 0A");
    login();
    while(true)

    {

        system("cls");
        studentMenu();

    }

}




///
///
///

