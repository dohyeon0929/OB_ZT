#include "student_info_management.h"

Insertion::Insertion(vector<Student>& student_list_) { //student_list 받아 오기 
    this->student_list_ = student_list_;
}

void Insertion::Input() {
    //입력 받은 정보를 저장. 그리고 의무 아닌거 없을때 ~ 처리, 
    cout << "Name ? ";
    cin >> input_name;
    cout << "Student ID (10 digits)? ";
    cin >> input_studentID;
    cout << "Birth Year (4 digits)? ";
    if (_getch() == 32)//만약 스페이스 바를 눌렀을 때 변수에 '~' 저장. 엔터 아스키코드 보류(수정예정)
    {
        input_birthYear = '~';
    }
    else
        cin >> input_birthYear;

    cout << "Department? ";
    if (_getch() == 32)//엔터 아스키코드 보류 
    {
        input_dept = '~';
    }
    else
        cin >> input_dept;

    cout << "Tel? ";
    if (_getch() == 32)//엔터 아스키코드 보류 
    {
        input_tel = '~';
    }
    else
        cin >> input_tel;
}

bool Insertion::CheckError()
{
    for (int i = 0; i < v.size(); i++) {
        if (input_studentID == v[i].getStudentID()) //만약 중복된 ID일 경우
        {
            cout << "Error : Already inserted";
            return 0; //중복된 ID는 0을 반환
            break;
        }

    }

    return 1; //중복 없는 ID는 1을 반환
}

void Insertion::InsertIn()
{
    if (CheckError() == 1) //중복된 ID가 아니므로 삽입
    {
        Student_add(input_name, input_studentID, input_dept, input_birthYear, input_tel, student_list_);
    }
}


void Insertion::GoToMain() {
    //개발 예정
}
