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
    Student(string name, string student_id,string dept, string birth_year, string tel){// 입력 받았을 때 생성자
        this->name = name;
        this->student_id = student_id;
        this->dept = dept;
        this->birth_year = birth_year;
        this->tel = tel;
    };
    string get_name() { return name; }
    string get_student_id() { return student_id; }
    string get_dept() { return dept; }
    string get_birth_year() { return birth_year; }
    string get_tel() { return tel; } 
};
bool CompareName(Student a, Student b){return a.get_name()<b.get_name();} //Sorting에서 필요한 함수들
bool CompareId(Student a, Student b){return a.get_student_id()<b.get_student_id();}
bool CompareDept(Student a, Student b){return a.get_dept()<b.get_dept();}
class Studentlist : Student {
private:
public:
    Studentlist();
};

class Insertion {
private: 

public:
    Insertion(); 

};

class Search {
private: 

public:
    Search(); 

};

class Sorting {
private:
    int sort_mode; //정렬 모드 변수 
    vector<Student> student_list; // = student_list
public:
    Sorting(vector<Student>& _student_list){ //student_list 받아 오기 
        student_list = _student_list;
        return;
    }
    
    void set_mode(int _sort_mode){
        //예외처리 안 함
        sort_mode = _sort_mode;
        return;
    }

    void Display(){ //정렬 선택 시 첫 화면 
        cout<<"\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n> ";
    }

    int Input(){ //정렬 모드 입력 받기 
        int _sort_mode;
        cin>>_sort_mode;
        return _sort_mode;
    }

    string FilterNull(string s){
        if(s=="~")s="NULL";
        return s;
    }

    vector<Student> Sort(){
        fstream file;
        switch(sort_mode){ //입력받은 기준에 따라 정렬하기
            case 1:
                sort(student_list.begin(), student_list.end(), CompareName);
                break;
            case 2:
            case 3:
                sort(student_list.begin(), student_list.end(), CompareId);
                break;
            case 4:
                sort(student_list.begin(), student_list.end(), CompareDept);
                break;
            default:
                //에러 처리 따로 안 해주고 그냥 아무런 변화 없게 함. 
                break;
        }

        file.open("file1.txt", ios::out | ios::trunc); //파일 내용 다 지우고 정렬한 순서대로 채워넣기 
        for(int i=0; i<student_list.size(); i++){
            file<<student_list[i].get_name()<<' ';
            file<<student_list[i].get_student_id()<<' ';
            file<<student_list[i].get_dept()<<' ';
            file<<student_list[i].get_birth_year()<<' ';
            file<<student_list[i].get_tel()<<' ';
            file<<'\n';
        }
        file.close();
        return student_list;

    }
    void Print(){ //정렬 결과 출력하기 
        int blank_space[]={16,12,30,12,12};
        string col_name[]={"Name","Student ID","Department","Birth Year","Tel"};
        for(int i=0; i<5; i++){
            cout<<left<<setw(blank_space[i])<<col_name[i];
        }
        cout<<'\n';
        for(int i=0; i<student_list.size(); i++){
            cout<<left<<setw(blank_space[0])<<FilterNull(student_list[i].get_name());
            cout<<left<<setw(blank_space[1])<<FilterNull(student_list[i].get_student_id());
            cout<<left<<setw(blank_space[2])<<FilterNull(student_list[i].get_dept());
            cout<<left<<setw(blank_space[3])<<FilterNull(student_list[i].get_birth_year());
            cout<<left<<setw(blank_space[4])<<FilterNull(student_list[i].get_tel());
            cout<<'\n';
        }
        cout<<'\n';
    }
};
class MainMenu {
private:

public:
    MainMenu();
};
