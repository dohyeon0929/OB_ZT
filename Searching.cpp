#include "student_info_management.h"

// search ���� ���� :display-> input ->search�� list �޾ƿ���-> search(case������ ���ǿ��´�student���ο�Ϳ����,�̸������ı����Ϸ�)-> print

bool CompareName2(Student a, Student b) { //���� 1���� : �̸�, ���� 2���� : �й� 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
    else return a.get_student_id() < b.get_student_id();
}

string Searching::FilterNull(string s) { //����Ʈ�Ҷ��ʿ���
    if (s == "~")s = "NULL";
    return s;
}  


void Searching::Display() { // ��ġ ù ȭ�� ���÷���
	std::cout << "- Search -" << std::endl;
	std::cout << "1. Search by name" << std::endl;
	std::cout << "2. Search by student ID (10 numbers)" << std::endl;
	std::cout << "3. Search by admission year (4 numbers)" << std::endl;
	std::cout << "4. Search by department name" << std::endl;
	std::cout << "5. List All" << std::endl;
    std::cout << "6. Go back" << std::endl;
    std::cout << "> ";
}

bool Searching::set_mode(string search_mode_) {
    try {
        if (search_mode_.size() == 1 && isdigit(search_mode_[0])) {
            if ((1 <= search_mode_[0] - '0') && (search_mode_[0] - '0' <= 6)) {
                this->search_mode_ = search_mode_[0] - '0';
                return true;
            }
            else throw search_mode_;
        }
        else throw search_mode_;
    }
    catch (string exception) {
        cout << "Error : Invalid input\n";
        this->search_mode_ = 0;
        return false;
    }
}


bool Searching::Input() { //  ��ġ ��� �Է� �ޱ� 
	string _search_mode;
	cin >> _search_mode;
    if (set_mode(_search_mode)) return true;
    else return false;
}

Searching::Searching(vector<Student>& student_list) { //student_list �޾� ���� 
    this->student_list = student_list;
}

void Searching::Search() {
    string search_keyword;
    switch (search_mode_) { //�Է¹��� ���ؿ� ���� search �ϱ�
        case 1: //search by name
            std::cout << "name keyword ? ";
            cin.ignore();
            getline(cin, search_keyword);
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_name() == search_keyword) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 2:  //search by student id
            std::cout << "student id keyword ? ";
            cin.ignore();
            getline(cin, search_keyword);
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_student_id() == search_keyword ) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 3:  //search by admission year
            std::cout << "admission year keyword ? ";
            cin.ignore();
            getline(cin, search_keyword);
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_student_id().substr(0,4) == search_keyword ) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 4: //search by department name
            std::cout << "department name keyword ? ";
            cin.ignore();
            getline(cin, search_keyword);
            for (int i = 0; i < student_list.size(); i++) {
                if (student_list[i].get_dept() == search_keyword ) {
                    student_search_list.push_back(student_list[i]);
                }
            }
            break;
        case 5: //list all
            for (int i = 0; i < student_list.size(); i++) {
                student_search_list.push_back(student_list[i]);
            }
            sort(student_search_list.begin(), student_search_list.end(), CompareName2);
            break;

        default:
            break;
    }
}
void Searching::Print() { //���� ��� ����ϱ� 
    int blank_space[] = { 16,12,30,12,12 };
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };
    cout << "+";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
    cout << '|';
    for (int i = 0; i < 5; i++) {
        cout << left << setw(blank_space[i]) << col_name[i];
        cout << '|';
    }
    cout << '\n';
    cout << "+";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
    for (int i = 0; i < student_search_list.size(); i++) {
        cout << '|';
        cout << left << setw(blank_space[0]) << FilterNull(student_search_list[i].get_name()) << '|';
        cout << left << setw(blank_space[1]) << FilterNull(student_search_list[i].get_student_id()) << '|';
        cout << left << setw(blank_space[2]) << FilterNull(student_search_list[i].get_dept()) << '|';
        cout << left << setw(blank_space[3]) << FilterNull(student_search_list[i].get_birth_year()) << '|';
        cout << left << setw(blank_space[4]) << FilterNull(student_search_list[i].get_tel()) << '|';
        cout << '\n';
    }
    cout << "+";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
}
