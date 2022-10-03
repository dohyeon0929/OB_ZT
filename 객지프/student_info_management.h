i#ifndef __STUDENT_INFO_MANAGEMENT_H__
#define __STUDENT_INFO_MANAGEMENT_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <conio.h> //_getch가 포함되어있는 헤더
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
private: // 입력받는 항목을 private에 저장
    string input_name;
    string input_studentID;
    string input_dept;
    string input_birthYear;
    string input_tel;
    vector<Student> student_list_; // = student_list
public:
    Insertion(vector<Student>& _student_list);
    
    void Input(); //정보 입력 받기
    bool CheckError(); //student_list에서 받아온 ID와 중복되는지 검사
    void InsertIn();//삽입
    void GoToMain(); //메인 화면으로 돌아가는 함수(개발예정)

};

class Searching {
private:
    int search_mode_; // 서치 모드 변수
    vector<Student> student_list;    //탐색할 student_list , 즉 현재까지 누적된 list를 뜻함
    vector<Student> student_search_list; // 조건에 맞는 student를 담을 새로운 list를 뜻함
public:
    Searching(vector<Student>& _student_list); //생성자
    void Display(); //서치 선택시 첫 화면
    void set_mode(int search_mode_); //서치 모드 변경자 
    int Input();  // 서치모드 입력받기
    void Search(); //서치
    void Print(); //실제로 출력
    string FilterNull(string s); // Print할 때 필요한 함수
};

class Sorting {
private:
    int sort_mode_; //정렬 모드 변수 
    vector<Student> student_list_;
public:
    Sorting(vector<Student>& student_list_);
    void set_mode(int sort_mode_);
    void Display(); //sort 선택 시 첫 화면 
    int Input(); 
    string FilterNull(string s); //Print할 때 필요한 함수 
    void Sort();
    void Print();
};

class MainMenu {
private:

public:
    MainMenu();
    void Insert(vector<Student> student_list) {
        Insert i(student_lis);
        i.Input();
        i.CheckError();
        i.InsertIn();
        i.GoToMain();

    }
    void Search(vector<Student> student_list) {
        Searching s(student_list);
        s.Display();
        s.set_mode(s.Input());
        s.Search();
        s.Print();
    }
    void Sort(vector<Student> student_list) {
        Sorting s(student_list);
        s.Display();
        s.set_mode(s.Input());
        s.Sort();
        s.Print();
    }
    void Exit() {
        exit(0);
    }
};
#endif
