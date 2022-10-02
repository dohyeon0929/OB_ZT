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
    vector<Student> student_list;
public:
    Sorting(vector<Student>& _student_list);
    void set_mode(int _sort_mode);
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
