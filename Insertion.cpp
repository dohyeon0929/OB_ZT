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
vector<string> split(string str, char delimeter) {
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimeter)) {
        answer.push_back(temp);
    }

    return answer;
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
                cout << "Error : Invaild input , Name is up to 15 chars.\n"; // �����޼��� ����
                continue; // �ٽ� �Է��ϵ��� ����
            }
            else { // �Էµ� �ְ� ���ڼ����ѵ� �� ��Ų ��쿡
                if('a'<=input_string[0] && input_string[0]<='z')
                input_string[0] -= 32; // �̸� ù���� �빮�ڷ� ��ȯ
                set_input_name(input_string); // input_name�� input_string
                break;
            }
        }
        else { // �Է� ���� ����ġ�� �Ѿ ���
            cout << "Error : Name can't be blank.\n";
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
                            }
                        }
                        else throw input_string; //10�����ε� ���ڰ� �ƴϸ� �Է��϶�� �ϱ�
                    }
                }
                else throw input_studentID_; // �翬�� 10���ڰ� �ƴϾ �Է��϶�� �ϱ�
            }
            catch (string exception)
            {
                cout << "Error : Invaild input , ID should be 10 digit number.\n";
                continue;
            }
        }
        else { // �Է� ���� ����ġ�� �Ѿ ���
            cout << "Error : StudentID can't be blank.\n";
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
                cout << "Error : Invaild input , Birth year should be 4 digit number.\n"; // �����޼��� ����
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
                        cout << "Error : Invaild input , Birth year should be 4 digit number.\n";
                        break;
                    }
                }
            }
        }
        else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
            set_input_birth_year("!");
            break;
        }
    }


    /* dept */
    string input_dept_string_in;
    string input_dept_string_out = "";
    cout << "Department ? ";
    getline(cin, input_dept_string_in);// �����ڴ� ���ͷ� �ڵ� ����

    if (input_dept_string_in != "") { // �Է��� �ִ� ��쿡       
        vector<string> temp_string = split(input_dept_string_in, ' '); // ���� �������� �а��̸� �ڸ���
        for (int i = 0; i < temp_string.size(); i++) { // �߶��� ������ ù���� �빮�ڷ� �ٲٱ�
            string temp_vector_string = temp_string[i];
            temp_vector_string[0] = toupper(temp_vector_string[0]);
            input_dept_string_out += temp_vector_string;
            input_dept_string_out += " ";
        }
        input_dept_string_out.pop_back(); // �� ���� �ִ� ���� ���ֱ�
        set_input_dept(input_dept_string_out); // �Է¹��� ������ �־��ֱ�      
    }
    else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
        set_input_dept("!");
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
                cout << "Error : Invaild input , Tell is up to 12 digit number.\n"; // �����޼��� ����
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
                        cout << "Error : Invaild input , Tel is up to 12 digit number.\n"; //�������� �������
                        break;
                    }
                }
            }
        }
        else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
            set_input_tel("!");
            break;
        }
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
        student_list_.StudentAdd(input_name_, input_studentID_, input_dept_, input_birthYear_, input_tel_, this->student_list_.get_student_list());
    }
    else //�ߺ��� ID�̹Ƿ� 
    {
        cout << "Error : Already inserted\n";
    }
}