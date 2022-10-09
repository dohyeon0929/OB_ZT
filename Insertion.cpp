#include "student_info_management.h"

/* 구현에 필요한 메소드가 아닌 함수들 */

vector<string> InsertionSplit(string str, char delimeter) { //dept 입력받을 때 필요한 문자열 나누기 함수
    vector<string> answer;
    stringstream ss(str); //stringstream으로 입력받은 str을 받기
    string temp;
    while (getline(ss, temp, delimeter)) { answer.push_back(temp); } //delimeter 기준으로 stringstream을 쪼개고, 각각 튀어나온 string을 벡터에 구분해서 넣음
    return answer;
}

bool IsKorean(string s) { //한국어로 시작하는지 아닌지 확인
    return !('A' <= s[0] && s[0] <= 'z'); //한국어로 시작할 시 true 반환
}


/* 클래스 생성자 및 메소드 */

Insertion::Insertion(StudentList student_list): Sorting(student_list) { //student_list 받아 오는 생성자
    this->student_list_ = student_list_;
    this->tmp_vector_ = student_list_.get_student_list();
}

void Insertion::Input() { 
    //입력 받은 정보를 저장. 그리고 입력이 없을때 ~ 처리, 
    string input_string;

    /* Name */
    while (1) {
        cout << "Name ? ";
        getline(cin, input_string);// 제한자는 엔터로 자동 설정
        if (set_input_name_(input_string))break; //제대로 된 입력을 받으면 다음 항목 입력 받기 
        else continue; //그렇지 않으면 다시 입력하도록 유도하기 
    }

    /* StudentID */
    while (1) {
        cout << "Student ID (10 digits)? ";
        getline(cin, input_string);// 제한자는 엔터로 자동 설정
        if (set_input_student_id_(input_string))break; //제대로 된 입력을 받으면 다음 항목 입력 받기 
        else continue; //그렇지 않으면 다시 입력하도록 유도하기 
    }

    /* birth year */
    while (1) {
        cout << "Birth Year (4 digits)? ";
        getline(cin, input_string);// 제한자는 엔터로 자동 설정
        if (set_input_birth_year_(input_string))break; //제대로 된 입력을 받으면 다음 항목 입력 받기 
        else continue; //그렇지 않으면 다시 입력하도록 유도하기 
    }

    /* dept */
    cout << "Department ? ";
    getline(cin, input_string);// 제한자는 엔터로 자동 설정
    set_input_dept_(input_string);

    /* tel */
    while (1) {
        cout << "Tel ? ";
        getline(cin, input_string);// 제한자는 엔터로 자동 설정
        if (set_input_tel_(input_string))break; //제대로 된 입력을 받으면 다음 항목 입력 받기 
        else continue; //그렇지 않으면 다시 입력하도록 유도하기 
    }
}

bool Insertion::NoSameId() {
    for (auto student : student_list_.get_student_list()) {
        if (input_student_id_ == student.get_student_id()) { return 0; }//만약 중복된 ID일 경우 0을 반환
    }
    return 1; //중복 없는 ID는 1을 반환
}

void Insertion::InsertIn()
{
    if (NoSameId()) //중복된 ID가 아니므로 삽입
    {
        Student new_student = { input_name_, input_student_id_, input_dept_, input_birth_year_, input_tel_ };
        student_list_.StudentAdd(new_student);
        tmp_vector_.push_back(new_student);
        cout << "Saved successfully" << endl;
    }
    else //중복된 ID이므로 
    {
        cout << "Error : Already inserted\n";
    }
}


/* 각종 예외처리를 맡고 있는 변경자 */

bool Insertion::set_input_name_(string input_string) {
    if (input_string != "") { // 입력이 있는 경우에
        if (input_string.size() > 15) { // 15글자 제한
            cout << "Error : Invaild input , Name is up to 15 chars.\n"; // 오류메세지 띄우고
            return false; // 다시 입력하도록 유도
        }
        else { // 입력도 있고 글자수제한도 잘 지킨 경우에
            if ('a' <= input_string[0] && input_string[0] <= 'z')
                input_string[0] -= 32; // 이름 첫글자 대문자로 변환
            if (IsKorean(input_string)) { input_string = "|" + input_string; }//첫 글자가 한국어라면, 아스키코드 순서 상 앞쪽에 위치한 '|'을 맨 앞에 넣어줌
            input_name_ = input_string;
            return true;
        }
    }
    else { // 입력 없이 엔터치고 넘어간 경우
        cout << "Error : Name can't be blank.\n"; //오류 메세지 
        return false; //다시 입력하도록 유도
    }
}

bool Insertion::set_input_student_id_(string input_string) {
    if (input_string != "") { // 입력이 있는 경우에
        try {  // 입력한 문자열이 10자리 
            if (input_string.size() == 10) //10글자인가?
            {
                for (int i = 0; i < 10; i++)
                {
                    if (isdigit(input_string[i])) { //10글자 숫자가 맞으면
                        if (i == 9) {
                            input_student_id_ = input_string;
                            return true; //제대로 된 입력 받았음
                        }
                    }
                    else throw input_string; //10글자인데 숫자가 아니면 입력하라고 하기
                }
            }
            else throw input_string; // 당연히 10글자가 아니어도 입력하라고 하기
        }
        catch (string exception)
        {
            cout << "Error : Invaild input , ID should be 10 digit number.\n";
            return false; //다시 입력하도록 유도 
        }
    }
    else { // 입력 없이 엔터치고 넘어간 경우
        cout << "Error : StudentID can't be blank.\n";
        return false; //다시 입력하도록 유도 
    }
}

bool Insertion::set_input_dept_(string input_string) {
    string input_string_out = "";
    if (input_string != "") { // 입력이 있는 경우에       
        if (IsKorean(input_string)) { input_string = "|" + input_string; } //첫 글자가 한국어라면, 아스키코드 순서 상 앞쪽에 위치한 '|'을 맨 앞에 넣어줌
        vector<string> temp_string = InsertionSplit(input_string, ' '); // 공백 기준으로 학과이름 자르기
        for (int i = 0; i < temp_string.size(); i++) { // 잘라진 어절의 첫글자 대문자로 바꾸기
            string temp_vector_string = temp_string[i];
            temp_vector_string[0] = toupper(temp_vector_string[0]);
            input_string_out += temp_vector_string;
            input_string_out += " ";
        }
        input_string_out.pop_back(); // 맨 끝에 있는 띄어쓰기 없애기
        input_dept_ = input_string_out;
    }
    else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
        input_dept_ = "~";
    }
    return true;
}

bool Insertion::set_input_birth_year_(string input_string) {
    if (input_string != "") { // 입력이 있는 경우에
        if (input_string.size() != 4) { // 정확히 4글자가 아닌 경우
            cout << "Error : Invaild input , Birth year should be 4 digit number.\n"; // 오류메세지 띄우기
            return false;
        }
        else { // 입력도 있고 글자수도 4글자인 경우에
            for (int i = 0; i < 4; i++)
            {
                if (isdigit(input_string[i])) { //글자 숫자가 맞으면
                    if (i == 3) {
                        input_birth_year_ = input_string;
                        return true; //올바른 입력 받았음 
                    }
                }
                else { //숫자 4개가 아니라 다른 것이 섞이면
                    cout << "Error : Invaild input , Birth year should be 4 digit number.\n";
                    return false;
                }
            }
        }
    }
    else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
        input_birth_year_ = "~";
        return true;
    }
}

bool Insertion::set_input_tel_(string input_string) {
    if (input_string != "") { // 입력이 있는 경우에
        if (input_string.size() > 12) { // 12글자까지임
            cout << "Error : Invaild input , Tel is up to 12 digit number.\n"; // 오류메세지 띄우고
            return false;
        }
        else { // 입력도 있고 12자와 같거나 작은 올바른 입력의 경우에
            for (int i = 0; i < input_string.size(); i++)
            {
                if (isdigit(input_string[i])) { //글자 숫자가 맞으면
                    if (i == input_string.size() - 1) {
                        input_tel_ = input_string;
                        return true;
                    }
                }
                else { //숫자가 아닌 다른 것이 섞이면
                    cout << "Error : Invaild input , Tel is up to 12 digit number.\n"; //숫자임을 오류출력
                    return false;
                }
            }
        }
    }
    else { // 엔터치고 패스하고자 하는 경우 (비필수 입력이니까)
        input_tel_ = "~";
        return true;
    }
}

