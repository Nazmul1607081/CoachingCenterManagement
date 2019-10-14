#ifndef RESULT_H
#define RESULT_H
#include<string>
#include "STUDENT.h"


class RESULT : public STUDENT
{
    public:
        RESULT();
        RESULT(const RESULT &source);///copy constructor
        RESULT& operator=(const RESULT &);
        void inputResult();
        void outputResult();
        void inputResult1();
        void outputResult1();
        std::string date;
        float  mark;

    protected:

    private:
};
void result_publish();
void display_final_result();
void choose_exam();
void choose_exam_s();

void Result();
#endif // RESULT_H
