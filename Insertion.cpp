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
Insertion::Insertion(StudentList& student_list_) { //student_list �޾� ���� 
    this->student_list_ = student_list_;
}
bool Insertion::Input() {
    //�Է� ���� ������ ����. �׸��� �ǹ� �ƴѰ� ������ ~ ó��, 
    char tmp; //_getch() �Է� �޴� �� 
     //_getch() ���� �Է¹޴� ��
    string input_string;
  
    /* Name */
    while (1) {

        //cout << "in while";
        cout << "Name ? ";
        cin.ignore();
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
    
    while (1) {
        //cout << "in while";
        cout << "Student ID (10 digits)? ";
        cin.ignore();
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����

        if (input_string != "") { // �Է��� �ִ� ��쿡
            cout << "normal input"; // Ȯ�ο�
            try {  // �Է��� ���ڿ��� 10�ڸ� 
                if (input_studentID_.size() == 10) //10�����ΰ�?
                {
                    for (int i = 0; i < 10; i++) 
                    {
                        if (isdigit(input_studentID_[i])) { //10���� ���ڰ� ������
                            if (i == 9) {
                                cout << "jjjjj";
                                set_input_student_id(input_string); // input_name�� input_string
                                input_string = ""; // �й��� �־�� �ϴϱ� �ʱ�ȭ
                                break;
                            }
                            else 
                                continue;
                        }
                        else throw input_studentID_; //10�����ε� ���ڰ� �ƴϸ� �Է��϶�� �ϱ�

                        
                    }
                }
                else throw input_studentID_; // �翬�� 10���ڰ� �ƴϾ �Է��϶�� �ϱ�
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
    cin >> input_birthYear_;
    try {  // �Է��� ���ڿ��� 4�ڸ� 
        if (input_birthYear_.size() == 4)
        {
            for (int i = 0; i < 4; i++)
            {
                if (isdigit(input_birthYear_[i])) continue; //�Է¹��� ���ڿ��� �������� Ȯ��
                else throw input_birthYear_;
            }
        }
        else throw input_birthYear_;
    }
    catch (string execption)
    {
        cout << "Error : Invaild input , input 4 digits numbers\n"; //Birth Year�� 4�ڸ��� �ƴҰ��, ���ڰ� �ƴҰ�� ����ó��
        return false;
    }

    cout << "Department? ";
    cin >> input_dept_;


    cout << "Tel? ";
    cin >> input_tel_;
    try {  // �Է��� ���ڿ��� 10�ڸ� 
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
        cout << "Error : Invaild input , input correct tel numbers\n"; //��ȭ��ȣ�� 10�ڸ��� �Ѿ��� ��� ���� ó��
        return false;
    }
}

bool Insertion::CheckError() {

    for (int i = 0; i < student_list_.get_student_list().size(); i++) {
        if (input_studentID_ == student_list_.get_student_list()[i].get_student_id()) //���� �ߺ��� ID�� ���
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
        student_list_.StudentAdd(input_name_, input_studentID_, input_dept_, input_birthYear_, input_tel_, this->student_list_.get_student_list()); //Student list�� �л� ������ �߰��ϰ�, ������ ����
    }
    else //�ߺ��� ID�̹Ƿ� 
    {
        cout << "Error : Already inserted\n";
    }
}


void Insertion::GoToMain() {
    //���� ����
}