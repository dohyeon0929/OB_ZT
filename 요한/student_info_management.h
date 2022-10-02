#pragma once
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
    int search_mode_; // 서치 모드 변수
    vector<Student> student_list;    //탐색할 student_list , 즉 현재까지 누적된 list를 뜻함
    vector<Student> student_search_list; // 조건에 맞는 student를 담을 새로운 list를 뜻함
    string name;    //검색 대상 이름
    string student_id;  //검색 대상 id
    string admission_year; // 검색 대상 year
    string department_name; // 검색 대상 dpt name 
   
public:
    Search(vector<Student>& _student_list); //생성자가 될 것이다.
    int Input();  // 서치모드 입력받기
    void Display(); //서치 선택시 첫 화면
    void search(); //서치모드에 따른 출력방식
    void Print(); //실제로 출력
    string FilterNull(string s); // Print할 때 필요한 함수
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
