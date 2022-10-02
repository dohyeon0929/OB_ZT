#ifndef __STUDENT_INFO_MANAGEMENT_H__
#define __STUDENT_INFO_MANAGEMENT_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class Student {
private:
    string name;
    string student_id;
    string dept;
    string birth_year;
    string tel;
public:
    Student();
    Student(string name, string student_id, string dept, string birth_year, string tel);
    string get_name() { return name; }
    string get_student_id() { return student_id; }
    string get_dept() { return dept; }
    string get_birth_year() { return birth_year; }
    string get_tel() { return tel; }
};

class Sorting {
private:
    int sort_mode; //정렬 모드 변수 
    vector<Student> student_list; // = student_list
public:
    Sorting(vector<Student>& _student_list);
    void set_mode(int _sort_mode);
    void Display();
    int Input();
    string FilterNull(string s);
    void Sort();
    void Print();
};
#endif
