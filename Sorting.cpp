#include "student_info_management.h"

//Sorting에서 필요한 함수들
bool SortingCompareName(Student a, Student b) { //정렬 1순위 : 학생 이름, 정렬 2순위 : 학번 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name(); //1순위 : 학생 이름
    else return a.get_student_id() < b.get_student_id(); //2순위 : 학번
} 

bool SortingCompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); };//학번으로 정렬 

bool SortingCompareDept(Student a, Student b) { //정렬 1순위 : 학과 이름, 정렬 2순위 : 학번 
    if (a.get_dept() != b.get_dept()) return a.get_dept() < b.get_dept(); //1순위 : 학과 이름
    else return a.get_student_id() < b.get_student_id(); //2순위 : 학번
}

Sorting::Sorting(StudentList student_list) { //생성자. 학생 정보 list 받아 오기 
    this->student_list_ = student_list; //MainMenu의 Student list 받아 오기
    this->tmp_vector_ = student_list_.get_student_list(); //StudentList의 vector부분 따로 저장 
}

bool Sorting::set_sort_mode_(string sort_mode) { //sort_mode_ 변경자
    try { //잘못된 입력 예외처리 
        if (sort_mode.size() == 1 && isdigit(sort_mode[0])) { //입력받은 게 1글자이고 숫자인가? 
            if ((1 <= sort_mode[0] - '0') && (sort_mode[0] - '0' <= 5)) { //1이상 5이하인가?
                this->sort_mode_ = sort_mode[0] - '0'; //멤버 변수 sort_mode_ 값 변경
                return true; //제대로 입력됐음을 알리기 위해 true 반환
            }
            else throw sort_mode; //예외 발생 
        }
        else throw sort_mode; //예외 발생 
    }
    catch (string exception) {//예외가 발생했을 때, 즉 잘못된 입력을 받았을 때 
        cout << "Error : Invalid input\n";
        this->sort_mode_ = 0;//MainMenu에서 다시 제대로 된 값을 입력받게끔 sort_mode_를 0으로 만들기 
        return false; //잘못된 입력이 들어왔음을 알리기 위해 false 반환
    }
}

void Sorting::SortingDisplay() { //정렬 선택 시 첫 화면 출력
    cout << "\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n5. Go back\n> ";
}

bool Sorting::SortingInput() { //정렬 모드 입력 받기. 예외처리 목적 
    string sort_mode; //사용자한테 입력 받을 string 선언 
    cin >> sort_mode; //사용자한테 입력 받기 
    cin.ignore(); //사용자가 공백문자와 함께 여러 문자를 입력했을 때 버퍼 비워서 오류 방지 
    if (set_sort_mode_(sort_mode))return true; //만약 제대로 된 입력을 받았다면 true 반환
    else return false; //잘못된 입력을 받았다면 false 반환 
}

string Sorting::FilterNull(string tmp_string) { //파일 내에서 ~로 표시돼있는 부분을 출력할 때에는 NULL로 표시하기 위해 필요한 메서드
    if (tmp_string == "~")tmp_string = "NULL"; //만약 해당 string이 "~"면 이를 NULL로 변환
    return tmp_string; //변환한 string을 반환
}

void Sorting::Sort() {
    switch (this->sort_mode_) { //입력받은 기준에 따라 정렬하기
    case 1:
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareName); //학생 이름 순으로 정렬 (2순위 정렬 기준은 학생 ID)
        break;
    case 2:
    case 3: //등록 년도 순으로 정렬하나 학생 ID 순으로 정렬하나 모두 학생 ID 기준으로 정렬을 진행하면 되기에 하나로 합침. 
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareId); //학생 ID 순으로 정렬. 
        break;
    case 4:
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareDept); //학과 이름 순으로 정렬 (2순위 정렬기준은 학생 ID)
        break;
    default: //sort_mode_로 1~4 이외의 값이 전달된 경우 아무런 추가 동작 없이 메인 메뉴로 이동
        break;
    }

    fstream file; //파일을 다루기 위해 fstream 변수 선언 
    file.open("file1.txt", ios::out | ios::trunc); //파일 연 후, 파일 내용 다 지우고 정렬한 순서대로 채워넣기 
    for (int i = 0; i < tmp_vector_.size(); i++) { //학생 정보를 정렬한 순서대로 다시 파일에 저장 
        file << tmp_vector_[i].get_name() << ';'; //파일 파싱할 때 구분하기 위해 그 때 그 때 세미콜론을 추가로 붙여서 저장
        file << tmp_vector_[i].get_student_id() << ';';
        file << tmp_vector_[i].get_dept() << ';';
        file << tmp_vector_[i].get_birth_year() << ';';
        file << tmp_vector_[i].get_tel() ; //각 학생의 마지막 정보 끝에는 세미콜론 붙이기를 생략
        file << '\n';
    }
    file.close(); //파일 닫기 
    return;

}
void Sorting::SortingPrint() { //정렬 결과 출력하기 
    int blank_space[5] = { 14,10,20,10,12 }; //출력했을 때 각 열에 할당될 칸 수 지정
    for (auto student : this->tmp_vector_) {
        blank_space[0] = max(blank_space[0], (int)student.get_name().size());
        blank_space[1] = max(blank_space[1], (int)student.get_student_id().size());
        blank_space[2] = max(blank_space[2], (int)student.get_dept().size());
        blank_space[3] = max(blank_space[3], (int)student.get_birth_year().size());
        blank_space[4] = max(blank_space[4], (int)student.get_tel().size());
    }
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" }; //출력했을 때 각 열의 이름
    cout << "+"; //표 형식으로 나타내기 위한 코드
    for (int i = 0; i < 5; i++) { //col 이름 바로 위 가로줄
        for (int j = 0; j < blank_space[i]; j++) { //각 열 별 할당된 칸 수 계산하며 출력 
            cout << '-';
        }
        cout << '+'; //col 바뀔 때 + 출력해서 세로줄과도 이어주기 
    }
    cout << '\n';
    cout << '|'; //col 이름이 출력되는 줄 맨 앞에 | 출력
    for (int i = 0; i < 5; i++) { //Student 클래스가 갖고 있는 모든 학생 정보를 출력 
        cout << left << setw(blank_space[i]) << col_name[i]; // 각 열마다 할당된 칸 수만큼 공간을 확보 후 왼쪽 정렬로 출력
        cout << '|'; //col 이름이 출력되는 줄 맨 마지막에 | 출력
    }
    cout << '\n';
    cout << "+"; //표 형식으로 나타내기 위해 필요한 코드 
    for (int i = 0; i < 5; i++) { //col 이름 바로 아래 가로줄
        for (int j = 0; j < blank_space[i]; j++) { //각 열 별 할당된 칸 수 계산하며 출력
            cout << '-';
        }
        cout << '+'; //col 바뀔 때 + 출력해서 세로줄과도 이어주기 
    }
    cout << '\n';
    for (int i = 0; i < this->tmp_vector_.size(); i++) { //가지고 있는 모든 학생 정보를 순회하며 출력하기
        cout << '|'; //각 학생들의 정보를 할당된 공간만큼 확보하고 왼쪽 정렬하여 표 형식으로 출력
        cout << left << setw(blank_space[0]) << FilterNull(this->tmp_vector_[i].get_name())<<'|';
        cout << left << setw(blank_space[1]) << FilterNull(this->tmp_vector_[i].get_student_id()) << '|';
        cout << left << setw(blank_space[2]) << FilterNull(this->tmp_vector_[i].get_dept())<< '|';
        cout << right << setw(blank_space[3]) << FilterNull(this->tmp_vector_[i].get_birth_year())<< '|';
        cout << left << setw(blank_space[4]) << FilterNull(this->tmp_vector_[i].get_tel())<< '|';
        cout << '\n';
    }
    cout << "+"; //표 형식으로 나타내기 위해 필요한 코드 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
}