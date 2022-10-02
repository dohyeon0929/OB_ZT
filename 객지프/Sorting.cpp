#include "student_info_management.h"

bool CompareName(Student a, Student b) { return a.get_name() < b.get_name(); } //Sorting에서 필요한 함수들
bool CompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); }
bool CompareDept(Student a, Student b) { return a.get_dept() < b.get_dept(); }

Sorting::Sorting(vector<Student>& _student_list) { //student_list 받아 오기 
    student_list = _student_list;
}

void Sorting::set_mode(int _sort_mode) {
    //예외처리 안 함
    sort_mode_ = _sort_mode;
    return;
}

void Sorting::Display() { //정렬 선택 시 첫 화면 
    cout << "\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n> ";
}

int Sorting::Input() { //정렬 모드 입력 받기 
    int _sort_mode;
    cin >> _sort_mode;
    return _sort_mode;
}

string Sorting::FilterNull(string s) {
    if (s == "~")s = "NULL";
    return s;
}

void Sorting::Sort() {
    fstream file;
    switch (sort_mode_) { //입력받은 기준에 따라 정렬하기
    case 1:
        sort(student_list.begin(), student_list.end(), CompareName); //sort 함수안에 인자가 세개있는데 comparename이 잇을것이다. 이게 해더파일에 잇다.여튼 저게 comparename이 정의되어있는부분과 이 줄을 가져오면 적용할수있다.
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
    for (int i = 0; i < student_list.size(); i++) {
        file << student_list[i].get_name() << ' ';
        file << student_list[i].get_student_id() << ' ';
        file << student_list[i].get_dept() << ' ';
        file << student_list[i].get_birth_year() << ' ';
        file << student_list[i].get_tel() << ' ';
        file << '\n';
    }
    file.close();
    return;

}
void Sorting::Print() { //정렬 결과 출력하기 
    int blank_space[] = { 16,12,30,12,12 };
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };
    for (int i = 0; i < 5; i++) {
        cout << left << setw(blank_space[i]) << col_name[i];
    }
    cout << '\n';
    for (int i = 0; i < student_list.size(); i++) {
        cout << left << setw(blank_space[0]) << FilterNull(student_list[i].get_name());
        cout << left << setw(blank_space[1]) << FilterNull(student_list[i].get_student_id());
        cout << left << setw(blank_space[2]) << FilterNull(student_list[i].get_dept());
        cout << left << setw(blank_space[3]) << FilterNull(student_list[i].get_birth_year());
        cout << left << setw(blank_space[4]) << FilterNull(student_list[i].get_tel());
        cout << '\n';
    }
    cout << '\n';
}