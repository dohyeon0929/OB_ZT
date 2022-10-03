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

class StudentList  {
private:
    vector<Student>student_info_list_; //student ��ü�� ���� ����Ʈ(vector)
public:
    StudentList(); // �⺻ ������	
    vector<string> Split(string str, char Delimiter); //���ڿ� �Ľ�
    void StudentAdd(string name, string studentID,
        string dept, string birthYear, string tel, vector<Student>student_list); //�л� �߰�
    void SaveList(vector<Student>student_list); // ���Ͽ� ����
    vector<Student>get_student_list() { return student_info_list_; };// student_list 
    //bool DefaultCompare(Student a, Student b) { return a.get_name() > b.get_name(); };; // �⺻ sorting ���
};

class Insertion {
private: // �Է¹޴� �׸��� private�� ����
    string input_name;
    string input_studentID;
    string input_dept;
    string input_birthYear;
    string input_tel;
    vector<Student> student_list_; // = student_list
public:
    Insertion(vector<Student>& _student_list);
    
    void Input(); //���� �Է� �ޱ�
    bool CheckError(); //student_list���� �޾ƿ� ID�� �ߺ��Ǵ��� �˻�
    void InsertIn();//����
    void GoToMain(); //���� ȭ������ ���ư��� �Լ�(���߿���)

};

class Searching {
private:
    int search_mode_; // ��ġ ��� ����
    vector<Student> student_list;    //Ž���� student_list , �� ������� ������ list�� ����
    vector<Student> student_search_list; // ���ǿ� �´� student�� ���� ���ο� list�� ����
public:
    Searching(vector<Student>& _student_list); //������
    void Display(); //��ġ ���ý� ù ȭ��
    void set_mode(int search_mode_); //��ġ ��� ������ 
    int Input();  // ��ġ��� �Է¹ޱ�
    void Search(); //��ġ
    void Print(); //������ ���
    string FilterNull(string s); // Print�� �� �ʿ��� �Լ�
};

class Sorting {
private:
    int sort_mode_; //���� ��� ���� 
    vector<Student> student_list_;
public:
    Sorting(vector<Student>& student_list_);
    void set_mode(int sort_mode_);
    void Display(); //sort ���� �� ù ȭ�� 
    int Input(); 
    string FilterNull(string s); //Print�� �� �ʿ��� �Լ� 
    void Sort();
    void Print();
};

class MainMenu
{
private:
    int mode_;
public:
    int select;
    void Start();
    void set_mode(int selection); //mode_ ������ 
    void Insertion(vector<Student>student_list);
    void Sort(vector<Student>student_list);
    void Search(vector<Student>student_list);
    void Exit();
};

#endif
