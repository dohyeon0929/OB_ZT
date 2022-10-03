#include "student_info_management.h"

//Sorting���� �ʿ��� �Լ���
bool CompareName(Student a, Student b) { //���� 1���� : �̸�, ���� 2���� : �й� 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
    else return a.get_student_id() < b.get_student_id();
} 
bool CompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); };//�й����� ���� 
bool CompareDept(Student a, Student b) { //���� 2���� : �й� 
    if (a.get_dept() != b.get_dept()) return a.get_dept() < b.get_dept();
    else return a.get_student_id() < b.get_student_id(); 
}

Sorting::Sorting(vector<Student>& student_list_) { //������. �л� ���� list �޾� ���� 
    this->student_list_ = student_list_;
}

bool Sorting::set_mode(string sort_mode_) {
    try { //�߸��� �Է� ����ó�� 
        if (sort_mode_.size() == 1 && isdigit(sort_mode_[0])) {
            if ((1 <= sort_mode_[0] - '0') && (sort_mode_[0] - '0' <= 5)) {
                this->sort_mode_ = sort_mode_[0] - '0';
                return true;
            }
            else throw sort_mode_;
        }
        else throw sort_mode_;
    }
    catch (string exception) {
        cout << "Error : Invalid input\n";
        this->sort_mode_ = 0;
        return false;
    }
    return false;
}

void Sorting::Display() { //���� ���� �� ù ȭ�� 
    cout << "\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n5. Go back\n> ";
}

bool Sorting::Input() { //���� ��� �Է� �ޱ� 
    string _sort_mode;
    cin >> _sort_mode;
    if (set_mode(_sort_mode))return true;
    else return false;
}

string Sorting::FilterNull(string tmp_string) {
    if (tmp_string == "~")tmp_string = "NULL";
    return tmp_string;
}

void Sorting::Sort() {
    fstream file;
    switch (sort_mode_) { //�Է¹��� ���ؿ� ���� �����ϱ�
    case 1:
        sort(student_list_.begin(), student_list_.end(), CompareName);
        break;
    case 2:
    case 3:
        sort(student_list_.begin(), student_list_.end(), CompareId);
        break;
    case 4:
        sort(student_list_.begin(), student_list_.end(), CompareDept);
        break;
    default:
        break;
    }

    file.open("file1.txt", ios::out | ios::trunc); //���� ���� �� ����� ������ ������� ä���ֱ� 
    for (int i = 0; i < student_list_.size(); i++) {
        file << student_list_[i].get_name() << ';';
        file << student_list_[i].get_student_id() << ';';
        file << student_list_[i].get_dept() << ';';
        file << student_list_[i].get_birth_year() << ';';
        file << student_list_[i].get_tel() ;
        file << '\n';
    }
    file.close();
    return;

}
void Sorting::Print() { //���� ��� ����ϱ� 
    int blank_space[] = { 16,12,30,12,12 };
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };
    for (int i = 0; i < 5; i++) {
        cout << left << setw(blank_space[i]) << col_name[i];
    }
    cout << '\n';
    for (int i = 0; i < student_list_.size(); i++) {
        cout << left << setw(blank_space[0]) << FilterNull(student_list_[i].get_name());
        cout << left << setw(blank_space[1]) << FilterNull(student_list_[i].get_student_id());
        cout << left << setw(blank_space[2]) << FilterNull(student_list_[i].get_dept());
        cout << left << setw(blank_space[3]) << FilterNull(student_list_[i].get_birth_year());
        cout << left << setw(blank_space[4]) << FilterNull(student_list_[i].get_tel());
        cout << '\n';
    }
    cout << '\n';
}