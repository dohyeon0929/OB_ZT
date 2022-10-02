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
    int search_mode_; // ��ġ ��� ����
    vector<Student> student_list;    //Ž���� student_list , �� ������� ������ list�� ����
    vector<Student> student_search_list; // ���ǿ� �´� student�� ���� ���ο� list�� ����
    string name;    //�˻� ��� �̸�
    string student_id;  //�˻� ��� id
    string admission_year; // �˻� ��� year
    string department_name; // �˻� ��� dpt name 
   
public:
    Search(vector<Student>& _student_list); //�����ڰ� �� ���̴�.
    int Input();  // ��ġ��� �Է¹ޱ�
    void Display(); //��ġ ���ý� ù ȭ��
    void search(); //��ġ��忡 ���� ��¹��
    void Print(); //������ ���
    string FilterNull(string s); // Print�� �� �ʿ��� �Լ�
};

class Sorting {
private:
    int sort_mode_; //���� ��� ���� 
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
    void Sort(vector<Student> student_list) { //�ӽ� 
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
