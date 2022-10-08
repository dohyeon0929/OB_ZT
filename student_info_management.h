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
    std::string name_;
    std::string student_id_;
    std::string dept_;
    std::string birth_year_;
    std::string tel_;
public:
    Student(); //생성자 1
    Student(string name_, string student_id_, string dept_, string birth_year_, string tel_); //생성자 2

    string get_name() { return name_; }
    string get_student_id() { return student_id_; }
    string get_dept() { return dept_; }
    string get_birth_year() { return birth_year_; }
    string get_tel() { return tel_; }
};

class StudentList {
private:
    bool is_sorted_; //Sorting으로 정렬했는지 여부 체크
    vector<Student> student_info_list_; //student 객체를 담을 리스트(vector)
public:
    StudentList(); // 생성자 1	
    StudentList(vector<Student> student_info_list); // 생성자 2
    vector<string> StudentListSplit(string str, char delimiter); //파일 파싱하는 메소드
    void StudentAdd(string name, string student_id, string dept, string birth_year, string tel); // 한 명의 학생 정보 추가
    void SaveListInFile(vector<Student>student_list); // 파일에 저장

    bool get_is_sorted_() { return is_sorted_; } //is_sorted_ 접근자
    void set_is_sorted_(bool is_sorted) { this->is_sorted_ = is_sorted; };
    vector<Student>get_student_list() { return student_info_list_; };// student_info_list 접근자 
};

class MainMenu {
private:
    int mode_; //사용자가 선택한 메뉴
public:
    MainMenu();
    void Start(); //시작 화면
    void MainInsert(StudentList& student_list); //insert 기능 수행
    void MainSearch(StudentList& student_list); //search 기능 수행
    void MainSort(StudentList& student_list); //sort 기능 수행
    void Exit(); //프로그램 종료

    int get_mode_() { return mode_; }
    void set_mode_(string mode_); //mode_ 변경자 
};

class Insertion {
private: 
    StudentList student_list_; //MainMenu의 student_list를 받아 온다. 
    string input_name_; //입력받는 항목들을 저장한다. 
    string input_student_id_;
    string input_dept_;
    string input_birth_year_;
    string input_tel_;
public:
    Insertion(StudentList& student_list_); // 생성자                 
    void Input(); //정보 입력 받기
    bool NoSameId(); //student_list에서 받아온 ID와 중복되는지 검사
    void InsertIn();//삽입

    bool set_input_name_(string s);
    bool set_input_student_id_(string s);
    bool set_input_dept_(string s);
    bool set_input_birth_year_(string s);
    bool set_input_tel_(string s);
};

class Sorting {
private:
    int sort_mode_=0; //정렬 모드 변수 
    StudentList student_list_; //MainMenu의 학생 정보 리스트를 받아올 멤버 변수 
    vector<Student> tmp_vector_; //student_list_에서 vector부분을 저장할 멤버 변수 
public:
    Sorting(StudentList& student_list);
    void SortingDisplay(); //sort 선택 시 첫 화면 
    void SortingInput(); //sort 모드 입력 받기 
    vector<Student> Sort(int sort_mode, vector<Student> tmp_vector); //학생 정보 정렬하기 
    void EnterToFile(); //정렬한 정보를 파일에 저장하기 
    void Print(vector<Student> tmp_vector);//정렬 결과 출력
    string Filter(string s); //파일 내에 저장돼있는 내용 중 일부를 사용자가 이해하기 쉽게 각색해서 출력하게끔 함

    int get_sort_mode_() { return sort_mode_; } //소트 모드 접근자
    vector<Student> get_sorting_tmp_vector_() { return tmp_vector_; }//tmp_vector_ 접근자
    bool set_sort_mode_(string sort_mode_);//소트 모드 변경자 
};

class Searching : public Sorting{
private:
    int search_mode_; // 서치 모드 변수
    StudentList student_list_;    //탐색할 student_list , 즉 현재까지 누적된 list를 뜻함
    vector<Student> tmp_vector_;
public:
    Searching(StudentList& student_list); //생성자
    void SearchingDisplay(); //서치 선택시 첫 화면
    void SearchingInput();  // 서치모드 입력받기
    void Search(); //서치
    void SearchingPrint(); //searchingprint

    int get_search_mode_() { return search_mode_; }; //서치 모드 접근자
    vector<Student> get_searching_tmp_vector_() { return tmp_vector_; }//tmp_vector_ 접근자
    bool set_search_mode_(string search_mode_); //서치 모드 변경자 
};



#endif

