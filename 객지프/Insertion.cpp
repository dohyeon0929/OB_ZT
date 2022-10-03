#include "student_info_management.h"

Insertion::Insertion(StudentList student_list_) { //student_list �޾� ���� 
    this->student_list_ = student_list_;
}

void Insertion::Input() {
    //�Է� ���� ������ ����. �׸��� �ǹ� �ƴѰ� ������ ~ ó��, 
    char tmp; //_getch() �Է� �޴� �� 
    string input_string; //_getch() ���� �Է¹޴� ��

    cout << "Name ? ";
    cin >> input_name;

    cout << "Student ID (10 digits)? ";
    cin >> input_studentID;

    cout << "Birth Year (4 digits)? ";
    cin >> input_birthYear;

    cout << "Department? ";
    cin >> input_dept;

    cout << "Tel? ";
    cin >> input_tel;

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

}

bool Insertion::CheckError() {

    for (int i = 0; i < student_list_.get_student_list().size(); i++) {
        if (input_studentID == student_list_.get_student_list()[i].get_student_id()) //���� �ߺ��� ID�� ���
        {
            cout << "Error : Already inserted";
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
        student_list_.StudentAdd(input_name, input_studentID, input_dept, input_birthYear, input_tel, student_list_.get_student_list());
    }
}


void Insertion::GoToMain() {
    //���� ����
}
