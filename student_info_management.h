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
    Student(); //������ 1
    Student(string name_, string student_id_, string dept_, string birth_year_, string tel_); //������ 2

    string get_name() { return name_; }
    string get_student_id() { return student_id_; }
    string get_dept() { return dept_; }
    string get_birth_year() { return birth_year_; }
    string get_tel() { return tel_; }
};

class StudentList {
private:
    bool is_sorted_; //Sorting���� �����ߴ��� ���� üũ
    vector<Student> student_info_list_; //student ��ü�� ���� ����Ʈ(vector)
public:
    StudentList(); // ������ 1	
    StudentList(vector<Student> student_info_list); // ������ 2
    vector<string> StudentListSplit(string str, char delimiter); //���� �Ľ��ϴ� �޼ҵ�
    void StudentAdd(string name, string student_id, string dept, string birth_year, string tel); // �� ���� �л� ���� �߰�
    void SaveListInFile(vector<Student>student_list); // ���Ͽ� ����

    bool get_is_sorted_() { return is_sorted_; } //is_sorted_ ������
    void set_is_sorted_(bool is_sorted) { this->is_sorted_ = is_sorted; };
    vector<Student>get_student_list() { return student_info_list_; };// student_info_list ������ 
};

class MainMenu {
private:
    int mode_; //����ڰ� ������ �޴�
public:
    MainMenu();
    void Start(); //���� ȭ��
    void MainInsert(StudentList& student_list); //insert ��� ����
    void MainSearch(StudentList& student_list); //search ��� ����
    void MainSort(StudentList& student_list); //sort ��� ����
    void Exit(); //���α׷� ����

    int get_mode_() { return mode_; }
    void set_mode_(string mode_); //mode_ ������ 
};

class Insertion {
private: 
    StudentList student_list_; //MainMenu�� student_list�� �޾� �´�. 
    string input_name_; //�Է¹޴� �׸���� �����Ѵ�. 
    string input_student_id_;
    string input_dept_;
    string input_birth_year_;
    string input_tel_;
public:
    Insertion(StudentList& student_list_); // ������                 
    void Input(); //���� �Է� �ޱ�
    bool NoSameId(); //student_list���� �޾ƿ� ID�� �ߺ��Ǵ��� �˻�
    void InsertIn();//����

    bool set_input_name_(string s);
    bool set_input_student_id_(string s);
    bool set_input_dept_(string s);
    bool set_input_birth_year_(string s);
    bool set_input_tel_(string s);
};

class Sorting {
private:
    int sort_mode_=0; //���� ��� ���� 
    StudentList student_list_; //MainMenu�� �л� ���� ����Ʈ�� �޾ƿ� ��� ���� 
    vector<Student> tmp_vector_; //student_list_���� vector�κ��� ������ ��� ���� 
public:
    Sorting(StudentList& student_list);
    void SortingDisplay(); //sort ���� �� ù ȭ�� 
    void SortingInput(); //sort ��� �Է� �ޱ� 
    vector<Student> Sort(int sort_mode, vector<Student> tmp_vector); //�л� ���� �����ϱ� 
    void EnterToFile(); //������ ������ ���Ͽ� �����ϱ� 
    void Print(vector<Student> tmp_vector);//���� ��� ���
    string Filter(string s); //���� ���� ������ִ� ���� �� �Ϻθ� ����ڰ� �����ϱ� ���� �����ؼ� ����ϰԲ� ��

    int get_sort_mode_() { return sort_mode_; } //��Ʈ ��� ������
    vector<Student> get_sorting_tmp_vector_() { return tmp_vector_; }//tmp_vector_ ������
    bool set_sort_mode_(string sort_mode_);//��Ʈ ��� ������ 
};

class Searching : public Sorting{
private:
    int search_mode_; // ��ġ ��� ����
    StudentList student_list_;    //Ž���� student_list , �� ������� ������ list�� ����
    vector<Student> tmp_vector_;
public:
    Searching(StudentList& student_list); //������
    void SearchingDisplay(); //��ġ ���ý� ù ȭ��
    void SearchingInput();  // ��ġ��� �Է¹ޱ�
    void Search(); //��ġ
    void SearchingPrint(); //searchingprint

    int get_search_mode_() { return search_mode_; }; //��ġ ��� ������
    vector<Student> get_searching_tmp_vector_() { return tmp_vector_; }//tmp_vector_ ������
    bool set_search_mode_(string search_mode_); //��ġ ��� ������ 
};



#endif

