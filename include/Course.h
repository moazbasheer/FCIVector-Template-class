#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include<iostream>
using namespace std;
class Course{
public:

    string courseName;
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear;
    int courseSemester;
    ~Course(){

    }
    void operator=(Course& s);
};

void Course::operator=(Course& s){ /// transfer data of course
    courseName=s.courseName;
    courseCode=s.courseCode;
    courseGrade=s.courseGrade;
    coursePoint=s.coursePoint;
    courseYear=s.courseYear;
    courseSemester=s.courseSemester;
}
#endif // COURSE_H_INCLUDED
