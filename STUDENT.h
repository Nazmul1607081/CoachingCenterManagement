#ifndef STUDENT_H
#define STUDENT_H
#include<string>
class STUDENT
{
public:
    //virtual void outputResult(){};
    STUDENT();
    std::string get_name();
    void set_roll(int);
    void set_name(std::string s);
    int get_roll();
    void get_data();
    void show_data();
    void show_data1();
    void show_name_roll();
    ~STUDENT();

protected:
    std::string  name;
    int roll;
private:

    char number[20];
    char exam_name[20];
    std::string father_name;
    std::string mother_name;
    std::string college_name;
    char SSC_gpa[20];
    char batch[20];

};
int Total_number_of_student();
void Entertainment();
void gotoxy(int x,int y);
void update_notice();
void show_previous_notice();






#endif // STUDENT_H
