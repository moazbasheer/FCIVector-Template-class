#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include<iostream>
#include"Course.h"
#include"FciVector.h"
using namespace std;
class Student{
public:
    string sname;
    int sid;
    string sdepartment;
    FciVector<Course> course;
    Student(){
        sname="";
        sid=0;
    }
    ~Student(){

    }
    friend istream& operator >>(istream& in,Student& s);
    friend ostream& operator <<(ostream& out,Student& s);
    void operator=(Student& s);
};
istream& operator >>(istream& in,Student& s){ /// Storing data of student
    cout<<"Enter Elements: \n";
    cout<<"Student name: \n";
    in>>s.sname;
    cout<<"Student ID\n";
    in>>s.sid;
    cout<<"Student Department: \n";
    in>>s.sdepartment;
    int NumberOfCourses;
    cout<<"Number of Courses: \n";
    in>>NumberOfCourses;

    for(int i=0;i<NumberOfCourses;i++){
        Course crs;
        cout<<"Enter Course #"<<i+1<<" info:\n";
        cout<<"Course Name: "; in>>crs.courseName;
        cout<<"Course Code: "; in>>crs.courseCode;
        cout<<"Course Grade: "; in>>crs.courseGrade;
        cout<<"Course point: "; in>>crs.coursePoint;
        cout<<"Course year: "; in>>crs.courseYear;
        cout<<"Course Semester: "; in>>crs.courseSemester;
        s.course.PushBack(crs);
    }
    return in;
}
ostream& operator <<(ostream& out,Student& s){ /// print data of student
    out<<"Student name: \n";
    out<<s.sname<<"\n";
    out<<"Student ID\n";
    out<<s.sid<<"\n";
    out<<"Student Department: \n";
    out<<s.sdepartment<<"\n";
    out<<"Number of Courses: \n";
    out<<s.course.Size()<<"\n";

    for(int i=0;i<s.course.Size();i++){
        out<<"Enter Course #"<<i+1<<" info:\n";
        out<<"Course Name: "<<s.course[i].courseName<<"\n";
        out<<"Course Code: "<<s.course[i].courseCode<<"\n";
        out<<"Course Grade: "<<s.course[i].courseGrade<<"\n";
        out<<"Course point: "<<s.course[i].coursePoint<<"\n";
        out<<"Course year: "<<s.course[i].courseYear<<"\n";
        out<<"Course Semester: "<<s.course[i].courseSemester<<"\n";
    }
    return out;
}
void Student::operator=(Student& s){ /// transfer data of student
    sname=s.sname;
    sid=s.sid;
    sdepartment=s.sdepartment;
    if(s.course.Size())
        course.Resize(s.course.Size());
    else return ;
    for(int i=0;i<course.Size();i++){

        course[i]=s.course[i];

    }
}
#endif // STUDENT_H_INCLUDED
