#include "student_info_management.h"
bool Insertion::set_input_name(string s) {
    input_name_ = s;
    return true;
}
bool Insertion::set_input_student_id(string s) {
    input_studentID_ = s;
    return true;

}
bool Insertion::set_input_dept(string s) {
    input_dept_ = s;
    return true;

}
bool Insertion::set_input_birth_year(string s) {
    input_birthYear_ = s;
    return true;

}
bool Insertion::set_input_tel(string s) {
    input_tel_ = s;
    return true;

}
Insertion::Insertion(StudentList& student_list_) { //student_list 받아 오기 
    this->student_list_ = student_list_;
}
bool Insertion::Input() {
    //입력 받은 정보를 저장. 그리고 의무 아닌거 없을때 ~ 처리, 
    char tmp; //_getch() 입력 받는 용 
     //_getch() 이후 입력받는 용
    string input_string;
  
    /* Name */
    while (1) {

        //cout << "in while";
        cout << "Name ? ";
        cin.ignore();
        getline(cin, input_string);// 제한자는 엔터로 자동 설정

        if (input_string != "") { // 입력이 있는 경우에
            //cout << "normal input"; // 확인용
            if (input_string.size() > 15) { // 15글자 제한
                cout << "Name is up to 15 chars.\n"; // 오류메세지 띄우고
                continue; // 다시 입력하도록 유도
            }
            else { // 입력도 있고 글자수제한도 잘 지킨 경우에
                set_input_name(input_string); // input_name은 input_string
                input_string = ""; // 학번도 넣어야 하니까 초기화
                break;
            }
        }
        else { // 입력 없이 엔터치고 넘어간 경우
            cout << "You should input your name !\n";
            continue;
        }
    }

    /* StudentID */
    
    while (1) {
        //cout << "in while";
        cout << "Student ID (10 digits)? ";
        cin.ignore();
        getline(cin, input_string);// 제한자는 엔터로 자동 설정

        if (input_string != "") { // 입력이 있는 경우에
            cout << "normal input"; // 확인용
            try {  // 입력한 문자열이 10자리 
                if (input_studentID_.size() == 10) //10글자인가?
                {
                    for (int i = 0; i < 10; i++) 
                    {
                        if (isdigit(input_studentID_[i])) { //10글자 숫자가 맞으면
                            if (i == 9) {
                                cout << "jjjjj";
                                set_input_student_id(input_string); // input_name은 input_string
                                input_string = ""; // 학번도 넣어야 하니까 초기화
                                break;
                            }
                            else 
                                continue;
                        }
                        else throw input_studentID_; //10글자인데 숫자가 아니면 입력하라고 하기

                        
                    }
                }
                else throw input_studentID_; // 당연히 10글자가 아니어도 입력하라고 하기
            }
            catch (string exception)
            {
                cout << "Error : Invaild input , input 10 digits numbers\n";
                continue;
            }
        }
        else { // 입력 없이 엔터치고 넘어간 경우
            cout << "You should input your StudentID !\n";
            continue;
        }
    }
    
    

    cout << "Birth Year (4 digits)? ";
    cin >> input_birthYear_;
    try {  // 입력한 문자열이 4자리 
        if (input_birthYear_.size() == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (isdigit(input_birthYear_[i])) continue; //입력받은 문자열이 숫자인지 확인
                else throw input_birthYear_;
            }
        }
        else throw input_birthYear_;
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input 4 digits numbers\n"; //Birth Year가 4자리가 아닐경우, 숫자가 아닐경우 에러처리
        return false;
    }

    cout << "Department? ";
    cin >> input_dept_;


    cout << "Tel? ";
    cin >> input_tel_;
    try {  // 입력한 문자열이 10자리 
        if (input_tel_.size() <= 11)
        {
            for (int i = 0; i < input_tel_.size(); i++)
            {
                if (isdigit(input_tel_[i])) continue;
                else throw input_tel_;
            }
        }
        else throw input_tel_;
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input correct tel numbers\n"; //전화번호가 10자리를 넘었을 경우 에러 처리
        return false;
    }
}

bool Insertion::CheckError() {

    for (int i = 0; i < student_list_.get_student_list().size(); i++) {
        if (input_studentID_ == student_list_.get_student_list()[i].get_student_id()) //만약 중복된 ID일 경우
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
        student_list_.StudentAdd(input_name_, input_studentID_, input_dept_, input_birthYear_, input_tel_, this->student_list_.get_student_list()); //Student list에 학생 정보를 추가하고, 파일을 저장
    }
    else //중복된 ID이므로 
    {
        cout << "Error : Already inserted\n";
    }
}


void Insertion::GoToMain() {
    //개발 예정
}