i#ifndef __STUDENT_INFO_MANAGEMENT_H__
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

class StudentList : Student {
private:

public:
    StudentList();
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
