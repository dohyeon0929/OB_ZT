#ifndef __STUDENT_INFO_MANAGEMENT_H__
#define __STUDENT_INFO_MANAGEMENT_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include<algorithm>
#include<stdlib.h> 
#include<iostream>
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

class Student_list :Student {
private:
    vector<Student>student_info_list; //student 객체를 담을 리스트(vector)
public:
    Student_list(); // 기본 생성자	
    vector<string>split(string str, char Delimiter); //문자열 파싱
    void student_add(string name, string studentID,
        string dept, string birthYear, string tel, vector<Student>student_list); //학생 추가
    void save_list(vector<Student>student_list); // 파일에 저장
    vector<Student>get_student_list() { return student_info_list; };// student_list 
    bool default_compare(Student a, Student b) { return a.get_name() > b.get_name(); };; // 기본 sorting 기능
};

class Sorting {
private:
    int sort_mode; //
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




class main_menu
{
private:
    int set_mode;
public:
    int select;
    void Start();
    void SetMode(int selection);
    void Insertion(vector<Student>student_list);
    void Sort(vector<Student>student_list);
    void Search(vector<Student>student_list);
    void Exit();
};
#endif
