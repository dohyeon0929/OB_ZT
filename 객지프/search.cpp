#include <iostream>
#include "student_info_management.h"


bool CompareName(Student a, Student b) { return a.get_name() < b.get_name(); } //Sorting���� �ʿ��� �Լ���



// search ���� ���� :display-> input ->search�� list �޾ƿ���-> search(case������ ���ǿ��´�student���ο�Ϳ����,�̸������ı����Ϸ�)-> print



string Search::FilterNull(string s) { //����Ʈ�Ҷ��ʿ���
    if (s == "~")s = "NULL";
    return s;
}  


void Search::Display() { // ��ġ ù ȭ�� ���÷���
	std::cout << "- Search -" << std::endl;
	std::cout << "1. Search by name" << std::endl;
	std::cout << "2. Search by student ID (10 numbers)" << std::endl;
	std::cout << "3. Search by admission year (4 numbers)" << std::endl;
	std::cout << "4. Search by department name" << std::endl;
	std::cout << "5. List All" << std::endl;
}


int Search::Input() { //  ��ġ ��� �Է� �ޱ� 
	int _search_mode;
	cin >> _search_mode;
	return _search_mode;
}

Search::Search(vector<Student>& _student_list) { //student_list �޾� ���� 
    student_list = _student_list;
}

void Search::search() {

    switch (search_mode_) { //�Է¹��� ���ؿ� ���� search �ϱ�
        case 1: //search by name
            std::cout << "name keyword?";
            cin >> name;
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_name() == name) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 2:  //search by student id
            std::cout << "student id keyword?";
            cin >> student_id;
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_student_id() == student_id) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 3:  //search by admission year
            std::cout << "admission year keyword?";
            cin >> admission_year;
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_birth_year() == admission_year) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 4: //search by department name
            std::cout << "department name keyword?";
            cin >> department_name;
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_dept() == department_name) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 5: //list all
            for (int i = 0; i < student_list.size(); i++) {
            
                student_search_list.push_back(student_list[i]);
                
            }
            break;

        default:
            //���� ó�� ���� �� ���ְ� �׳� �ƹ��� ��ȭ ���� ��. 
            break;
    }
    sort(student_list.begin(), student_list.end(), CompareName);
    
}

void Search::Print() { //���� ��� ����ϱ� 
    int blank_space[] = { 16,12,30,12,12 };
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };
    for (int i = 0; i < 5; i++) {
        cout << left << setw(blank_space[i]) << col_name[i];
    }
    cout << '\n';
    for (int i = 0; i < student_search_list.size(); i++) {
        cout << left << setw(blank_space[0]) << FilterNull(student_search_list[i].get_name());
        cout << left << setw(blank_space[1]) << FilterNull(student_search_list[i].get_student_id());
        cout << left << setw(blank_space[2]) << FilterNull(student_search_list[i].get_dept());
        cout << left << setw(blank_space[3]) << FilterNull(student_search_list[i].get_birth_year());
        cout << left << setw(blank_space[4]) << FilterNull(student_search_list[i].get_tel());
        cout << '\n';
    }
    cout << '\n';
}