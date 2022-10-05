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
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����

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
    
    /* birth year */
    token = false;
    while (1) {
        if (token) break;
        string input_birthyear_string;
        cout << "Birth Year (4 digits)? ";
        getline(cin, input_birthyear_string);// �����ڴ� ���ͷ� �ڵ� ����

        if (input_birthyear_string != "") { // �Է��� �ִ� ��쿡
            if (input_birthyear_string.size() != 4) { // ��Ȯ�� 4���ڰ� �ƴ� ���
                cout << "birth year is 4 digits.\n"; // �����޼��� ����
            }
            else { // �Էµ� �ְ� ���ڼ��� 4������ ��쿡
                for (int i = 0; i < 4; i++)
                {
                    if (isdigit(input_birthyear_string[i])) { //���� ���ڰ� ������
                        if (i == 3) {
                            set_input_birth_year(input_birthyear_string);
                            token = true; //���� �ݺ��� ������ 
                            break;
                        }
                    }
                    else { //���� 4���� �ƴ϶� �ٸ� ���� ���̸�
                        cout << "birth year is 4 digits.\n";
                        break;
                    }
                }
            }
        }
        else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
            set_input_birth_year("~");
            break;
        }
    }
    

    /* dept */
    string input_dept_string;
    cout << "Department ? ";
    getline(cin, input_dept_string);// �����ڴ� ���ͷ� �ڵ� ����

    if (input_dept_string != "") { // �Է��� �ִ� ��쿡       
        set_input_dept(input_dept_string); // �Է¹��� ������ �־��ֱ�      
    }
    else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
        set_input_dept("~");
    }


    /* tel */
    token = false;
    while (1) {
        if (token) break;
        string input_tel_string;
        cout << "Tel ? ";
        getline(cin, input_tel_string);// �����ڴ� ���ͷ� �ڵ� ����

        if (input_tel_string != "") { // �Է��� �ִ� ��쿡
            if (input_tel_string.size() > 12) { // 12���ڱ�����
                cout << "tel is up to 12 digits.\n"; // �����޼��� ����
            }
            else { // �Էµ� �ְ� 12�ڿ� ���ų� ���� �ùٸ� �Է��� ��쿡
                for (int i = 0; i < input_tel_string.size(); i++)
                {
                    if (isdigit(input_tel_string[i])) { //���� ���ڰ� ������
                        if (i == input_tel_string.size() - 1) {
                            set_input_tel(input_tel_string);
                            token = true; //���� �ݺ��� ������ 
                            break;
                        }
                    }
                    else { //���ڰ� �ƴ� �ٸ� ���� ���̸�
                        cout << "Tel is up to 12 digits.\n"; //�������� �������
                        break;
                    }
                }
            }
        }
        else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
            set_input_tel("~");
            break;
        }
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