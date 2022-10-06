#ifndef __STUDENT_INFO_MANAGEMENT_H__
#define __STUDENT_INFO_MANAGEMENT_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <conio.h> //_getch�� ���ԵǾ��ִ� ���
using namespace std; // main ���

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
    vector<Student>student_info_list_; //student ��ü�� ���� ����Ʈ(vector)
public:
    StudentList(); // �⺻ ������	
    vector<string> Split(string str, char delimiter); //���ڿ� �Ľ�
    void StudentAdd(string name, string student_id,
        string dept, string birth_year, string tel, vector<Student>student_list); //�л� �߰�
    void SaveList(vector<Student>student_list); // ���Ͽ� ����
    vector<Student>get_student_list() { return student_info_list_; };// student_list 
    //bool DefaultCompare(Student a, Student b) { return a.get_name() > b.get_name(); };; // �⺻ sorting ���
};

class Insertion {
private: // �Է¹޴� �׸��� private�� ����
    string input_name_;
    string input_studentID_;
    string input_dept_;
    string input_birthYear_;
    string input_tel_;
    StudentList student_list_; // = student_list
public:
    Insertion(StudentList& student_list_); // ������                 
    bool set_input_name(string s);
    bool set_input_student_id(string s);
    bool set_input_dept(string s);
    bool set_input_birth_year(string s);
    bool set_input_tel(string s);
    bool Input(); //���� �Է� �ޱ�
    bool CheckError(); //student_list���� �޾ƿ� ID�� �ߺ��Ǵ��� �˻�
    void InsertIn();//����
};

class Searching {
private:
    int search_mode_; // ��ġ ��� ����
    StudentList student_list_;    //Ž���� student_list , �� ������� ������ list�� ����
    vector<Student> student_search_list_; // ���ǿ� �´� student�� ���� ���ο� list�� ����
    vector<Student> tmp_vector_;
public:
    Searching(StudentList& student_list); //������
    void SearchingDisplay(); //��ġ ���ý� ù ȭ��
    int get_search_mode_() { return search_mode_; }; //��ġ ��� ������
    bool set_search_mode_(string search_mode_); //��ġ ��� ������ 
    bool SearchingInput();  // ��ġ��� �Է¹ޱ�
    void Search(); //��ġ
    void SearchingPrint(); //searchingprint
    string FilterNull(string s); // Print�� �� �ʿ��� �Լ�
};

class Sorting {
private:
    int sort_mode_; //���� ��� ���� 
    StudentList student_list_; //MainMenu�� �л� ���� ����Ʈ�� �޾ƿ� ��� ���� 
    vector<Student> tmp_vector_; //student_list_���� vector�κ��� ������ ��� ���� 
public:
    Sorting(StudentList student_list);
    int get_sort_mode_() { return sort_mode_; } //��Ʈ ��� ������
    bool set_sort_mode_(string sort_mode_);//��Ʈ ��� ������ 
    void SortingDisplay(); //sort ���� �� ù ȭ�� 
    bool SortingInput(); //sort ��� �Է� �ޱ� 
    string FilterNull(string s); //Print�� �� �ʿ��� �Լ� 
    void Sort(); //sort ���μ��� 
    void SortingPrint();//���� ��� ���
};

class MainMenu
{
private:
    int mode_;
public:
    void Start();
    void set_mode(string mode_); //mode_ ������ 
    void Insert(StudentList student_list);
    void Sort(StudentList student_list);
    void Search(StudentList student_list);
    void Exit();
};

#endif

