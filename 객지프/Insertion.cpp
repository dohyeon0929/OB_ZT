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
Insertion::Insertion(StudentList& student_list_) { //student_list �޾� ���� 
    this->student_list_ = student_list_;
}
bool Insertion::Input() {
    //�Է� ���� ������ ����. �׸��� �ǹ� �ƴѰ� ������ ~ ó��, 
    char tmp; //_getch() �Է� �޴� �� 
    string input_string; //_getch() ���� �Է¹޴� ��

    cout << "Name ? ";
    cin >> input_name;


    cout << "Student ID (10 digits)? ";
    cin >> input_studentID;
    try {  // �Է��� ���ڿ��� 10�ڸ� 
        if (input_studentID.size() == 10) //10�����ΰ�?
        {
            for (int i = 0; i < 10; i++) //
            {
                if (isdigit(input_studentID[i])) continue;
                else throw input_studentID;
            }
        }
        else throw input_studentID; //�ƴ϶�� ����ó��
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input 10 digits numbers\n";
        return false;
    }




    cout << "Birth Year (4 digits)? ";
    cin >> input_birthYear;
    try {  // �Է��� ���ڿ��� 10�ڸ� 
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
    try {  // �Է��� ���ڿ��� 10�ڸ� 
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
//    //�Է� ���� ������ ����. �׸��� �ǹ� �ƴѰ� ������ ~ ó��, 
//    char tmp; //_getch() �Է� �޴� �� 
//    string input_string; //_getch() ���� �Է¹޴� ��
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
    if (tmp == 32)//���� �����̽� �ٸ� ������ �� ������ '~' ����. ���� �ƽ�Ű�ڵ� ����(��������)
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
    if (_getch() == 32)//���� �ƽ�Ű�ڵ� ����
    {
        input_dept = '~';
    }
    else
        cin >> input_dept;
    cout << "Tel? ";
    if (_getch() == 32)//���� �ƽ�Ű�ڵ� ����
    {
        input_tel = '~';
    }
    else
        cin >> input_tel;
    */

    //}

bool Insertion::CheckError() {

    for (int i = 0; i < student_list_.get_student_list().size(); i++) {
        if (input_studentID == student_list_.get_student_list()[i].get_student_id()) //���� �ߺ��� ID�� ���
        {

            return 0; //�ߺ��� ID�� 0�� ��ȯ
            break;
        }

    }

    return 1; //�ߺ� ���� ID�� 1�� ��ȯ
}

void Insertion::InsertIn()
{
    if (CheckError() == 1) //�ߺ��� ID�� �ƴϹǷ� ����
    {
        // cout << "hey"; // Ȯ�ο�
        student_list_.StudentAdd(input_name, input_studentID, input_dept, input_birthYear, input_tel, this->student_list_.get_student_list());
    }
    else //�ߺ��� ID�̹Ƿ� 
    {
        cout << "Error : Already inserted\n";
    }
}


void Insertion::GoToMain() {
    //���� ����
}