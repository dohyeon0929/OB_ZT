#include "student_info_management.h"
bool Insertion::set_input_name(string s) {
    input_name = s;
    return true;
}
bool Insertion::set_input_student_id(string s) {
    input_studentID = s;
    return true;

}
bool Insertion::set_input_dept(string s) {
    input_dept = s;
    return true;

}
bool Insertion::set_input_birth_year(string s) {
    input_birthYear = s;
    return true;

}
bool Insertion::set_input_tel(string s) {
    input_tel = s;
    return true;

}
Insertion::Insertion(StudentList& student_list_) { //student_list 받아 오기 
    this->student_list_ = student_list_;
}
bool Insertion::Input() {
    //입력 받은 정보를 저장. 그리고 의무 아닌거 없을때 ~ 처리, 
    char tmp; //_getch() 입력 받는 용 
    string input_string; //_getch() 이후 입력받는 용

    cout << "Name ? ";
    cin >> input_name;


    cout << "Student ID (10 digits)? ";
    cin >> input_studentID;
    try {  // 입력한 문자열이 10자리 
        if (input_studentID.size() == 10) //10글자인가?
        {
            for (int i = 0; i < 10; i++) //
            {
                if (isdigit(input_studentID[i])) continue;
                else throw input_studentID;
            }
        }
        else throw input_studentID; //아니라면 예외처리
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input 10 digits numbers\n";
        return false;
    }




    cout << "Birth Year (4 digits)? ";
    cin >> input_birthYear;
    try {  // 입력한 문자열이 10자리 
        if (input_birthYear.size() == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (isdigit(input_birthYear[i])) continue;
                else throw input_birthYear;
            }
        }
        else throw input_birthYear;
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input 4 digits numbers\n";
        return false;
    }



    cout << "Department? ";
    cin >> input_dept;


    cout << "Tel? ";
    cin >> input_tel;
    try {  // 입력한 문자열이 10자리 
        if (input_tel.size() <= 11)
        {
            for (int i = 0; i < input_tel.size(); i++)
            {
                if (isdigit(input_tel[i])) continue;
                else throw input_tel;
            }
        }
        else throw input_tel;
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input correct tel numbers\n";
        return false;
    }
}
//void Insertion::Input() {
//    //입력 받은 정보를 저장. 그리고 의무 아닌거 없을때 ~ 처리, 
//    char tmp; //_getch() 입력 받는 용 
//    string input_string; //_getch() 이후 입력받는 용
//
//    cout << "Name ? ";
//    cin.ignore();
//    getline(cin, input_string);
//    set_input_name(input_string);
//
//    cout << "Student ID (10 digits)? ";
//    cin.ignore();
//    getline(cin, input_string);
//    set_input_student_id(input_string);
//
//    cout << "Birth Year (4 digits)? ";
//    cin.ignore();
//    getline(cin, input_string);
//    set_input_birth_year(input_string);
//
//    cout << "Department? ";
//    cin.ignore();
//    getline(cin, input_string);
//    set_input_dept(input_string);
//
//    cout << "Tel? ";
//    cin.ignore();
//    getline(cin, input_string);
//    set_input_tel(input_string);

    /*
    cin.ignore();
    tmp = _getch();
    if (tmp == 32)//만약 스페이스 바를 눌렀을 때 변수에 '~' 저장. 엔터 아스키코드 보류(수정예정)
    {
        input_birthYear = "~";
    }
    else {
        cin >> input_string;
        input_birthYear = "";
        input_birthYear += tmp;
        input_birthYear += input_string;
    }
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
    */

    //}

bool Insertion::CheckError() {

    for (int i = 0; i < student_list_.get_student_list().size(); i++) {
        if (input_studentID == student_list_.get_student_list()[i].get_student_id()) //만약 중복된 ID일 경우
        {

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
        // cout << "hey"; // 확인용
        student_list_.StudentAdd(input_name, input_studentID, input_dept, input_birthYear, input_tel, this->student_list_.get_student_list());
    }
    else //중복된 ID이므로 
    {
        cout << "Error : Already inserted\n";
    }
}


void Insertion::GoToMain() {
    //개발 예정
}