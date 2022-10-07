#include "student_info_management.h"

/* 구현에 필요한 메소드가 아닌 함수들 */

bool SortingCompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); };//학번 순으로 정렬 

bool SortingCompareName(Student a, Student b) { //정렬 1순위 : 학생 이름, 정렬 2순위 : 학번 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name(); //1순위 : 학생 이름
    else return SortingCompareId(a, b); //2순위 학번 
}

bool SortingAdmissionYear(Student a, Student b) { //정렬 1순위 : 등록 년도, 정렬 2순위 : 이름, 정렬 3순위 : 학번 
    if (a.get_student_id().substr(0, 4) != b.get_student_id().substr(0, 4)) return a.get_student_id().substr(0, 4) < b.get_student_id().substr(0, 4); //1순위 : 등록 년도
    else return SortingCompareName(a, b); //2순위 이름, 3순위 학번
}

bool SortingCompareDept(Student a, Student b) { //정렬 1순위 : 학과 이름, 정렬 2순위 : 이름, 정렬 3순위 : 학번 
    if (a.get_dept() != b.get_dept()) return a.get_dept() < b.get_dept(); //1순위 : 학과 이름
    else return SortingCompareName(a, b); //2순위 이름, 3순위 학번
}

void PrintTableLine(int blank_space[]) {//print할 때 table의 가로줄 출력
    cout << "+"; //표 형식으로 나타내기 위한 코드
    for (int i = 0; i < 5; i++) { //col 이름 바로 위 가로줄
        for (int j = 0; j < blank_space[i]; j++) { //각 열 별 할당된 칸 수 계산하며 출력 
            cout << '-';
        }
        cout << '+'; //col 바뀔 때 + 출력해서 세로줄과도 이어주기 
    }
    cout << '\n';
}


/* 클래스 생성자 및 메소드 */

Sorting::Sorting(StudentList& student_list) { //생성자. 학생 정보 list 받아 오기 
    this->student_list_ = student_list; //MainMenu의 Studentlist 받아 오기
    this->tmp_vector_ = student_list_.get_student_list(); //StudentList의 vector부분 따로 저장 
}

void Sorting::SortingDisplay() {//사용자에게 보여지는 출력창
    cout << "- Sorting Option"<<endl;
    cout << "1. Sort by Name" << endl;
    cout << "2. Sort by Student ID" << endl;
    cout << "3. Sort by Admission Year" << endl;
    cout << "4. Sort by Department name" << endl;
    cout << "5. Go back"<<endl;
    cout << "> ";
}

void Sorting::SortingInput() { //정렬 모드 입력 받기. 예외처리 목적 
    string input_string;//사용자한테 입력 받을 string 선언 
    while (1) {
        SortingDisplay();
        getline(cin, input_string);//사용자한테 입력 받기 
        if(set_sort_mode_(input_string)) break; //제대로 된 입력을 받으면 넘어가기
    }
}

string Filter(string s) { //파일 내에서 ~로 표시돼있는 부분을 출력할 때에는 NULL로 표시하기 위해 필요한 메서드
    if (s == "~")s = "NULL"; //만약 해당 string이 "~"면 이를 NULL로 변환
    else if (s[0] == '|')s = s.substr(1);
    return s; //변환한 string을 반환
}

vector<Student> Sorting::Sort(int sort_mode, vector<Student> tmp_vector) {
    switch (sort_mode) { //입력받은 기준에 따라 정렬하기
    case 1:
        sort(tmp_vector.begin(), tmp_vector.end(), SortingCompareName); //학생 이름 순으로 정렬
        break;
    case 2:
        sort(tmp_vector.begin(), tmp_vector.end(), SortingCompareId); //등록 년도 순으로 정렬 
        break;
    case 3:
        sort(tmp_vector.begin(), tmp_vector.end(), SortingAdmissionYear); //학생 ID 순으로 정렬. 
        break;
    case 4:
        sort(tmp_vector.begin(), tmp_vector.end(), SortingCompareDept); //학과 이름 순으로 정렬
        break;
    default: //sort_mode_로 1~4 이외의 값이 전달된 경우 아무런 추가 동작 없이 메인 메뉴로 이동
        break;
    }
    this->tmp_vector_ = tmp_vector;
    return tmp_vector;
}

void Sorting::Print(vector<Student> tmp_vector) { //정렬 결과 출력하기 
    int blank_space[5] = { 5,11,10,10,11 }; //출력했을 때 각 열에 할당될 칸 수 지정
    for (auto student : tmp_vector) {
        blank_space[0] = max(blank_space[0], (int)student.get_name().size()+1);
        blank_space[2] = max(blank_space[2], (int)student.get_dept().size());
        blank_space[4] = max(blank_space[4], (int)student.get_tel().size());
    }
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" }; //출력했을 때 각 열의 이름

    PrintTableLine(blank_space);
    cout << '|'; //col 이름이 출력되는 줄 맨 앞에 | 출력
    for (int i = 0; i < 5; i++) { //Student 클래스가 갖고 있는 모든 학생 정보를 출력 
        cout << left << setw(blank_space[i]) << col_name[i]; // 각 열마다 할당된 칸 수만큼 공간을 확보 후 왼쪽 정렬로 출력
        cout << '|'; //col 이름이 출력되는 줄 맨 마지막에 | 출력
    }
    cout << '\n';
    PrintTableLine(blank_space);
    for (int i = 0; i < tmp_vector.size(); i++) { //가지고 있는 모든 학생 정보를 순회하며 출력하기
        cout << '|'; //각 학생들의 정보를 할당된 공간만큼 확보하고 왼쪽 정렬하여 표 형식으로 출력
        cout << left << setw(blank_space[0]) << Filter(tmp_vector[i].get_name()) << '|';
        cout << left << setw(blank_space[1]) << Filter(tmp_vector[i].get_student_id()) << '|';
        cout << left << setw(blank_space[2]) << Filter(tmp_vector[i].get_dept()) << '|';
        cout << right << setw(blank_space[3]) << Filter(tmp_vector[i].get_birth_year()) << '|';
        cout << left << setw(blank_space[4]) << Filter(tmp_vector[i].get_tel()) << '|';
        cout << '\n';
    }
    PrintTableLine(blank_space);
}

void Sorting::EnterToFile() {
    fstream file; //파일을 다루기 위해 fstream 변수 선언 
    file.open("file1.txt", ios::out | ios::trunc);//파일 연 후, 파일 내용 다 지우고 정렬한 순서대로 채워넣기 
    for (int i = 0; i < tmp_vector_.size(); i++) { //학생 정보를 정렬한 순서대로 다시 파일에 저장 
        file << tmp_vector_[i].get_name() << ';'; //파일 파싱할 때 구분하기 위해 그 때 그 때 세미콜론을 추가로 붙여서 저장
        file << tmp_vector_[i].get_student_id() << ';';
        file << tmp_vector_[i].get_dept() << ';';
        file << tmp_vector_[i].get_birth_year() << ';';
        file << tmp_vector_[i].get_tel(); //각 학생의 마지막 정보 끝에는 세미콜론 붙이기를 생략
        file << '\n';
    }
    file.close(); //파일 닫기 
    return;
}


/* 각종 예외처리를 맡고 있는 변경자들 */

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
        cout << "Error : "<<exception<<" is Invalid input\n";
        this->sort_mode_ = 0;//MainMenu에서 다시 제대로 된 값을 입력받게끔 sort_mode_를 0으로 만들기 
        return false; //잘못된 입력이 들어왔음을 알리기 위해 false 반환
    }
}

