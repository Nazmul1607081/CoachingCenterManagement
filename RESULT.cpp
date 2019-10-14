#include "RESULT.h"
#include "FIRST_PAGE.h"
#include "STUDENT.h"
#include<bits/stdc++.h>
#include "COMPLEX.h"
#include<bits/stdc++.h>
using namespace std;
RESULT::RESULT()
{
    mark=0;

}
RESULT::RESULT(const RESULT &source)
{
    mark = source.mark;
    name = source.name;
    roll = source.roll;
    date = source.date;
}

RESULT res;
RESULT *ptr= &res ;
STUDENT s_obj;
 //new RESULT;
//ptr = &res;
vector<RESULT>s_result_vec;
vector<RESULT>s_result_vec1;

///COPY CONSTRUCTOR USE/////////////mark

/// Copy constructor


/// function use for sorting...***
bool X_less(RESULT const &l, RESULT const &r)
{
    return l.mark < r.mark;
}
/// ****FUNCTOR USE**** ///
class comp_number
{
public:
    bool operator()(const RESULT &a,const RESULT &b)
    {
        return a.mark>b.mark;
    }
};
comp_number res_num;


RESULT& RESULT::operator=(const RESULT & source)
{
    // check for self-assignment
    mark = source.mark;
    name = source.name;
    roll = source.roll;
}
namespace ndaily{
void display_final_result()
{
    cout<<"\tS.No."<<setw(5)<<"Roll"<<setw(14)<<"Number\n\n";
    for(int i=0; i<Total_number_of_student(); i++)
    {
        cout<<"\t"<<i+1 <<":";cout<<setw(5)<<s_result_vec[i].get_roll()<<"  "<<setw(15)<<setprecision(1)<<setiosflags(ios::fixed)<<s_result_vec[i].mark<<endl;
    }
    //cout<<"OPPS"<<endl;
}

/// Lambda function use .............
void result_publish()
{
    int flag=0;
    cout<<"\n\n\tPlease enter the exam date to publish :"<<endl;
    string d;
    cin>>d;
    ifstream fin("result.dat",ios::in|ios::binary);
    while(fin.read((char*)&res,sizeof(res)))
    {
        if(d==res.date)
        {
            flag=1;
            //copyresult=res;
            RESULT copyresult(res);///copy constructor used.........
            s_result_vec.push_back(copyresult);
        }

    }
    fin.close();
    getchar();
    /// ******sort function ****
    ///sort(s_result_vec.begin(),s_result_vec.end(),&X_less);
    ///sort(s_result_vec.begin(),s_result_vec.end(),res_num);
    sort(s_result_vec.begin(),s_result_vec.end(),[](const RESULT &a,const RESULT &b)->bool{return a.mark>b.mark;});
    if(flag==1)
    {
        cout<<"\n\n\tDate of exam    :"<<d<<endl;
        display_final_result();
    }

    else
    {
        cout<<"Opps"<<endl;
        getchar();
    }

}
}
namespace nmonthly{
void display_final_result()
{
    cout<<"\tS.No."<<setw(5)<<"Roll"<<setw(14)<<"      Number\n\n";
    for(int i=0; i<Total_number_of_student(); i++)
    {
        cout<<"\t"<<i+1 <<":";cout<<setw(5)<<s_result_vec[i].get_roll()<<"  "<<setw(15)<<setprecision(1)<<setiosflags(ios::fixed)<<s_result_vec[i].mark<<endl;
    }
    //cout<<"OPPS"<<endl;
}
/// sorting ********



void result_publish()
{
    int flag=0;
    cout<<"\n\n\tPlease enter the exam date to publish :"<<endl;
    string d;
    cin>>d;
    ifstream fin("result1.dat",ios::in|ios::binary);
    while(fin.read((char*)&res,sizeof(res)))
    {
        if(d==res.date)
        {
            flag=1;
            //copyresult=res;///copy constructor used.........
            RESULT copyresult=res;
            s_result_vec1.push_back(copyresult);
        }

    }
    fin.close();
    getchar();
    /// ******sort function ****
    ///sort(s_result_vec.begin(),s_result_vec.end(),&X_less);
    sort(s_result_vec1.begin(),s_result_vec1.end(),res_num);
    ///sort(s_result_vec.begin(),s_result_vec.end(),[](const RESULT &a,const RESULT &b)->bool{return a.mark<b.mark;});
    if(flag==1)
    {
        cout<<"\n\n\tMonth of exam    :"<<d<<endl;
        ndaily::display_final_result();
    }

    else
    {
        cout<<"Opps"<<endl;
        getchar();
    }

}
}
/// copy constructor use end ////////////////
void RESULT::inputResult()
{
    ofstream fout("result.dat",ios::out|ios::app|ios::binary);
    ifstream fin("stud.dat",ios::in|ios::binary);
    cout<<"Please enter the exam date";
    string r_date;
    cin>>r_date;
    while(fin.read((char*)&s_obj,sizeof(s_obj)))
    {

        s_obj.show_name_roll();
        res.date=r_date;
        res.set_name(s_obj.get_name());
        res.set_roll(s_obj.get_roll());
        cout<<"Enter the mark of this student "<<endl;
        cin>>res.mark;
        fout.write((char*)&res,sizeof(res));
    }
    fin.close();
}
void RESULT::inputResult1()
{
    ofstream fout("result1.dat",ios::out|ios::app|ios::binary);
    ifstream fin("stud.dat",ios::in|ios::binary);
    cout<<"Please enter the exam date";
    string r_date;
    cin>>r_date;
    while(fin.read((char*)&s_obj,sizeof(s_obj)))
    {

        s_obj.show_name_roll();
        res.date=r_date;
        res.set_name(s_obj.get_name());
        res.set_roll(s_obj.get_roll());
        cout<<"Enter the mark of this student "<<endl;
        cin>>res.mark;
        fout.write((char*)&res,sizeof(res));
    }
    fin.close();
}

void RESULT::outputResult()
{
    // system("cls");
    //char examDate[20];
    // cin>>examDate;
    ifstream fin("result.dat",ios::in|ios::binary);
    while(fin.read((char*)&res,sizeof(res)))
    {
        //if(examDate==res.date)
        //{
        cout<<"DATE : "<<res.date<<endl;
        cout<<"Name : "<<res.name<<"Roll : "<<res.roll<<"Mark : "<<res.mark<<endl;

        // }
    }
    fin.close();
    getchar();
}
void RESULT::outputResult1()
{
    // system("cls");
    //char examDate[20];
    // cin>>examDate;
    ifstream fin("result1.dat",ios::in|ios::binary);
    while(fin.read((char*)&res,sizeof(res)))
    {

        //if(examDate==res.date)
        //{
        cout<<"DATE : "<<res.date<<endl;
        cout<<"Name :"<<res.name<<"Roll :"<<res.roll<<"Mark :"<<res.mark<<endl;

        // }
    }
    fin.close();
    getchar();
}


void daily_exam()
{
    cout<<"\n\n\tPlease enter 1 for entry result and 2 for show result and 3 for result publish \n\t"<<endl;
    char c;
    cin>>c;
    if(c=='1')
        res.inputResult();
    if(c=='2')
        ptr->outputResult();
    if(c=='3')
        ndaily::result_publish();
}
void monthly_exam()
{
    cout<<"\n\n\tPlease enter 1 for entry result and 2 for show result and 3 for result publish "<<endl;
    char c;
    cin>>c;
    if(c=='1')
        res.inputResult1();
    if(c=='2')
        ptr->outputResult1();
    if(c=='3')
        nmonthly::result_publish();
}
void daily_exam_s()
{
    //cout<<"\n\n\tPlease enter 1 for see the published daily result \n\n\t"<<endl;

    ndaily::result_publish();
}
void monthly_exam_s()
{
    //cout<<"\n\n\tPlease enter 1 for see the published monthly result \n\n\t"<<endl;

    nmonthly::result_publish();
}



void choose_exam()
{
    system("cls");
    cout << "\n\n\t  _________________________RESULT MENU_________________________";
    cout << "\n\n\t 1: FOR DAYLY EXAM";
    cout << "\n\n\t 2: FOR WEEKLY EXAM ";
    cout << "\n\n\t 3: FOR MONTHLY EXAM\n\n\t\t";
    char ch;
    cin>>ch;
    if(ch=='1')
    {
        daily_exam();
    }
    else if(ch=='2')
        monthly_exam();



}
void choose_exam_s()
{
    system("cls");
    cout << "\n\n  _________________________RESULT MENU_________________________";
    cout << "\n\n 1: FOR DAYLY EXAM";
    cout << "\n\n 2: FOR MONTHLY EXAM ";
    cout << "\n\n 3: FOR WEEKLY EXAM\n\n\t\t";
    char ch;
    cin>>ch;
    if(ch=='1')
    {
        daily_exam_s();
    }
    else if(ch=='2')
        monthly_exam_s();



}
void Result()
{
    choose_exam();
}
