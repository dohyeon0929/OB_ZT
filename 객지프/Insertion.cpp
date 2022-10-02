#include "student_info_management.h"

Insertion::Insertion(vector<Student>& student_list_) { //student_list �޾� ���� 
    this->student_list_ = student_list_;
}

void Insertion::Input() {
    //�Է� ���� ������ ����. �׸��� �ǹ� �ƴѰ� ������ ~ ó��, 
    cout << "Name ? ";
    cin >> input_name;
    cout << "Student ID (10 digits)? ";
    cin >> input_studentID;
    cout << "Birth Year (4 digits)? ";
    if (_getch() == 32)//���� �����̽� �ٸ� ������ �� ������ '~' ����. ���� �ƽ�Ű�ڵ� ����(��������)
    {
        input_birthYear = '~';
    }
    else
        cin >> input_birthYear;

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
}

bool Insertion::CheckError()
{
    for (int i = 0; i < v.size(); i++) {
        if (input_studentID == v[i].getStudentID()) //���� �ߺ��� ID�� ���
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
        Student_add(input_name, input_studentID, input_dept, input_birthYear, input_tel, student_list_);
    }
}


void Insertion::GoToMain() {
    //���� ����
}
