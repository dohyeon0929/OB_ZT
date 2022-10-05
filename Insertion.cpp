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
    cin.ignore();
  
    /* Name */
    while (1) {
        //cout << "in while";
        string input_string;
        cout << "Name ? ";
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
    bool token = false; //추후 이중 반복문 나가기 위한 변수 선언 
    while (1) {
        //cout << "in while";
        if (token)break;
        string input_string;
        cout << "Student ID (10 digits)? ";
        getline(cin, input_string);// 제한자는 엔터로 자동 설정

        if (input_string != "") { // 입력이 있는 경우에
            //cout << "normal input"; // 확인용
            try {  // 입력한 문자열이 10자리 
                if (input_string.size() == 10) //10글자인가?
                {
                    for (int i = 0; i < 10; i++) 
                    {
                        if (isdigit(input_string[i])) { //10글자 숫자가 맞으면
                            if (i == 9) {
                                set_input_student_id(input_string); // input_name은 input_string
                                token = true; //이중 반복문 나가기 
                                break;
                                //input_string = ""; // 학번도 넣어야 하니까 초기화
                            }
                        }
                        else throw input_string; //10글자인데 숫자가 아니면 입력하라고 하기
                    }
                }
                else throw input_studentID; // 당연히 10글자가 아니어도 입력하라고 하기
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
    
    /* birth year */
    token = false;
    while (1) {
        if (token) break;
        string input_birthyear_string;
        cout << "Birth Year (4 digits)? ";
        getline(cin, input_birthyear_string);// 제한자는 엔터로 자동 설정

        if (input_birthyear_string != "") { // 입력이 있는 경우에
            if (input_birthyear_string.size() != 4) { // 정확히 4글자가 아닌 경우
                cout << "birth year is 4 digits.\n"; // 오류메세지 띄우기
            }
            else { // 입력도 있고 글자수도 4글자인 경우에
                for (int i = 0; i < 4; i++)
                {
                    if (isdigit(input_birthyear_string[i])) { //글자 숫자가 맞으면
                        if (i == 3) {
                            set_input_birth_year(input_birthyear_string);
                            token = true; //이중 반복문 나가기 
                            break;
                        }
                    }
                    else { //숫자 4개가 아니라 다른 것이 섞이면
                        cout << "birth year is 4 digits.\n";
                        break;
                    }
                }
            }
        }
        else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
            set_input_birth_year("~");
            break;
        }
    }
    

    /* dept */
    string input_dept_string;
    cout << "Department ? ";
    getline(cin, input_dept_string);// 제한자는 엔터로 자동 설정

    if (input_dept_string != "") { // 입력이 있는 경우에       
        set_input_dept(input_dept_string); // 입력받은 것으로 넣어주기      
    }
    else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
        set_input_dept("~");
    }


    /* tel */
    token = false;
    while (1) {
        if (token) break;
        string input_tel_string;
        cout << "Tel ? ";
        getline(cin, input_tel_string);// 제한자는 엔터로 자동 설정

        if (input_tel_string != "") { // 입력이 있는 경우에
            if (input_tel_string.size() > 12) { // 12글자까지임
                cout << "tel is up to 12 digits.\n"; // 오류메세지 띄우고
            }
            else { // 입력도 있고 12자와 같거나 작은 올바른 입력의 경우에
                for (int i = 0; i < input_tel_string.size(); i++)
                {
                    if (isdigit(input_tel_string[i])) { //글자 숫자가 맞으면
                        if (i == input_tel_string.size() - 1) {
                            set_input_tel(input_tel_string);
                            token = true; //이중 반복문 나가기 
                            break;
                        }
                    }
                    else { //숫자가 아닌 다른 것이 섞이면
                        cout << "Tel is up to 12 digits.\n"; //숫자임을 오류출력
                        break;
                    }
                }
            }
        }
        else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
            set_input_tel("~");
            break;
        }
    }
    

}

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