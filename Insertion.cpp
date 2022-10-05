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
    //string input_string;//_getch() ���� �Է¹޴� ��
    cin.ignore();
  
    /* Name */
    while (1) {
        //cout << "in while";
        string input_string;
        cout << "Name ? ";
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        if (input_string != "") { // �Է��� �ִ� ��쿡
            //cout << "normal input"; // Ȯ�ο�
            if (input_string.size() > 15) { // 15���� ����
                cout << "Name is up to 15 chars.\n"; // �����޼��� ����
                continue; // �ٽ� �Է��ϵ��� ����
            }
            else { // �Էµ� �ְ� ���ڼ����ѵ� �� ��Ų ��쿡
                set_input_name(input_string); // input_name�� input_string
                input_string = ""; // �й��� �־�� �ϴϱ� �ʱ�ȭ
                break;
            }
        }
        else { // �Է� ���� ����ġ�� �Ѿ ���
            cout << "You should input your name !\n";
            continue;
        }
    }

    /* StudentID */
    bool token = false; //���� ���� �ݺ��� ������ ���� ���� ���� 
    while (1) {
        //cout << "in while";
        if (token)break;
        string input_string;
        cout << "Student ID (10 digits)? ";
        //cin.ignore();
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        //cin.ignore();
        //cout << input_string;

        if (input_string != "") { // �Է��� �ִ� ��쿡
            //cout << "normal input"; // Ȯ�ο�
            try {  // �Է��� ���ڿ��� 10�ڸ� 
                if (input_string.size() == 10) //10�����ΰ�?
                {
                    for (int i = 0; i < 10; i++) 
                    {
                        if (isdigit(input_string[i])) { //10���� ���ڰ� ������
                            if (i == 9) {
                                set_input_student_id(input_string); // input_name�� input_string
                                token = true; //���� �ݺ��� ������ 
                                break;
                                //input_string = ""; // �й��� �־�� �ϴϱ� �ʱ�ȭ
                            }
                        }
                        else throw input_string; //10�����ε� ���ڰ� �ƴϸ� �Է��϶�� �ϱ�
                    }
                }
                else throw input_studentID; // �翬�� 10���ڰ� �ƴϾ �Է��϶�� �ϱ�
            }
            catch (string exception)
            {
                cout << "Error : Invaild input , input 10 digits numbers\n";
                continue;
            }
        }
        else { // �Է� ���� ����ġ�� �Ѿ ���
            cout << "You should input your StudentID !\n";
            continue;
        }
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