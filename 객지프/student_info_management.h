#ifndef __STUDENT_INFO_MANAGEMENT_H__
#define __STUDENT_INFO_MANAGEMENT_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std; // main 헤더

class Student {
private:
    string name_;
    string student_id_;
    string dept_;
    string birth_year_;
    string tel_;
public:
    Student();
    Student(string name_, string student_id_, string dept_, string birth_year_, string tel_);
    string get_name() { return name_; }
    string get_student_id() { return student_id_; }
    string get_dept() { return dept_; }
    string get_birth_year() { return birth_year_; }
    string get_tel() { return tel_; }
};

class StudentList : Student {
private:

public:
    StudentList();
};

class Insertion {
private:

public:
    Insertion();

};

class Search {
private:

public:
    Search();

};

class Sorting {
private:
    int sort_mode_; //정렬 모드 변수 
    vector<Student> student_list_;
public:
    Sorting(vector<Student>& student_list_);
    void set_mode(int sort_mode_);
    void Display();
    int Input();
    string FilterNull(string s);
    void Sort();
    void Print();
};

class MainMenu {
private:

public:
    MainMenu();
    void Insert() {

    }
    void Search() {

    }
    void Sort(vector<Student> student_list) { //임시 
        Sorting s(student_list);
        s.Display();
        s.set_mode(s.Input());
        s.Sort();
        s.Print();
    }
    void Exit() {

    }
};
#endif
