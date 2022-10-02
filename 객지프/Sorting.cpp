#include "student_info_management.h"

bool CompareName(Student a, Student b) { return a.get_name() < b.get_name(); } //Sorting���� �ʿ��� �Լ���
bool CompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); }
bool CompareDept(Student a, Student b) { return a.get_dept() < b.get_dept(); }

Sorting::Sorting(vector<Student>& student_list_) { //student_list �޾� ���� 
    this->student_list_ = student_list_;
}

void Sorting::set_mode(int sort_mode_) {
    //����ó�� �� ��
    this->sort_mode_ = sort_mode_;
    return;
}

void Sorting::Display() { //���� ���� �� ù ȭ�� 
    cout << "\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n> ";
}

int Sorting::Input() { //���� ��� �Է� �ޱ� 
    int _sort_mode;
    cin >> _sort_mode;
    return _sort_mode;
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
        //���� ó�� ���� �� ���ְ� �׳� �ƹ��� ��ȭ ���� ��. 
        break;
    }

    file.open("file1.txt", ios::out | ios::trunc); //���� ���� �� ����� ������ ������� ä���ֱ� 
    for (int i = 0; i < student_list_.size(); i++) {
        file << student_list_[i].get_name() << ' ';
        file << student_list_[i].get_student_id() << ' ';
        file << student_list_[i].get_dept() << ' ';
        file << student_list_[i].get_birth_year() << ' ';
        file << student_list_[i].get_tel() << ' ';
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