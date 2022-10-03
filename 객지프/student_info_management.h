#ifndef __STUDENT_INFO_MANAGEMENT_H__
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
    std::string name_;
    std::string student_id_;
    std::string dept_;
    std::string birth_year_;
    std::string tel_;
public:
    Student();
    Student(string name_, string student_id_, string dept_, string birth_year_, string tel_);
    string get_name() { return name_; }
    string get_student_id() { return student_id_; }
    string get_dept() { return dept_; }
    string get_birth_year() { return birth_year_; }
    string get_tel() { return tel_; }
};

class StudentList {
private:
    vector<Student>student_info_list_; //student 객체를 담을 리스트(vector)
public:
    StudentList(); // 기본 생성자	
    vector<string> Split(string str, char Delimiter); //문자열 파싱
    void StudentAdd(string name, string studentID,
        string dept, string birthYear, string tel, vector<Student>student_list); //학생 추가
    void SaveList(vector<Student>student_list); // 파일에 저장
    vector<Student>get_student_list() { return student_info_list_; };// student_list 
    //bool DefaultCompare(Student a, Student b) { return a.get_name() > b.get_name(); };; // 기본 sorting 기능
};

class Insertion {
private: // 입력받는 항목을 private에 저장
    string input_name;
    string input_studentID;
    string input_dept;
    string input_birthYear;
    string input_tel;
    StudentList student_list_; // = student_list
public:
    Insertion(StudentList student_list_); // 생성자                 
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
    int get_mode() { return search_mode_; }; //서치 모드 접근자
    bool set_mode(string search_mode_); //서치 모드 변경자 
    bool Input();  // 서치모드 입력받기
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
    int get_mode() { return sort_mode_; } //소트 모드 접근자
    bool set_mode(string sort_mode_);//소트 모드 변경자 
    void Display(); //sort 선택 시 첫 화면 
    bool Input(); //sort 모드 입력 받기 
    string FilterNull(string s); //Print할 때 필요한 함수 
    void Sort(); //sort 프로세스 
    void Print();//정렬 결과 출력 (최종 제출할 때에는 없어도 됨)
};

class MainMenu
{
private:
    int mode_;
public:
    void Start();
    void set_mode(string mode_); //mode_ 변경자 
    void Insert(StudentList student_list);
    void Sort(vector<Student>student_list);
    void Search(vector<Student>student_list);
    void Exit();
};

#endif

