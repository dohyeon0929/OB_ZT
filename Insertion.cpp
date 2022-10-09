#include "student_info_management.h"

/* ������ �ʿ��� �޼ҵ尡 �ƴ� �Լ��� */

vector<string> InsertionSplit(string str, char delimeter) { //dept �Է¹��� �� �ʿ��� ���ڿ� ������ �Լ�
    vector<string> answer;
    stringstream ss(str); //stringstream���� �Է¹��� str�� �ޱ�
    string temp;
    while (getline(ss, temp, delimeter)) { answer.push_back(temp); } //delimeter �������� stringstream�� �ɰ���, ���� Ƣ��� string�� ���Ϳ� �����ؼ� ����
    return answer;
}

bool IsKorean(string s) { //�ѱ���� �����ϴ��� �ƴ��� Ȯ��
    return !('A' <= s[0] && s[0] <= 'z'); //�ѱ���� ������ �� true ��ȯ
}


/* Ŭ���� ������ �� �޼ҵ� */

Insertion::Insertion(StudentList student_list): Sorting(student_list) { //student_list �޾� ���� ������
    this->student_list_ = student_list_;
    this->tmp_vector_ = student_list_.get_student_list();
}

void Insertion::Input() { 
    //�Է� ���� ������ ����. �׸��� �Է��� ������ ~ ó��, 
    string input_string;

    /* Name */
    while (1) {
        cout << "Name ? ";
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        if (set_input_name_(input_string))break; //����� �� �Է��� ������ ���� �׸� �Է� �ޱ� 
        else continue; //�׷��� ������ �ٽ� �Է��ϵ��� �����ϱ� 
    }

    /* StudentID */
    while (1) {
        cout << "Student ID (10 digits)? ";
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        if (set_input_student_id_(input_string))break; //����� �� �Է��� ������ ���� �׸� �Է� �ޱ� 
        else continue; //�׷��� ������ �ٽ� �Է��ϵ��� �����ϱ� 
    }

    /* birth year */
    while (1) {
        cout << "Birth Year (4 digits)? ";
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        if (set_input_birth_year_(input_string))break; //����� �� �Է��� ������ ���� �׸� �Է� �ޱ� 
        else continue; //�׷��� ������ �ٽ� �Է��ϵ��� �����ϱ� 
    }

    /* dept */
    cout << "Department ? ";
    getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
    set_input_dept_(input_string);

    /* tel */
    while (1) {
        cout << "Tel ? ";
        getline(cin, input_string);// �����ڴ� ���ͷ� �ڵ� ����
        if (set_input_tel_(input_string))break; //����� �� �Է��� ������ ���� �׸� �Է� �ޱ� 
        else continue; //�׷��� ������ �ٽ� �Է��ϵ��� �����ϱ� 
    }
}

bool Insertion::NoSameId() {
    for (auto student : student_list_.get_student_list()) {
        if (input_student_id_ == student.get_student_id()) { return 0; }//���� �ߺ��� ID�� ��� 0�� ��ȯ
    }
    return 1; //�ߺ� ���� ID�� 1�� ��ȯ
}

void Insertion::InsertIn()
{
    if (NoSameId()) //�ߺ��� ID�� �ƴϹǷ� ����
    {
        Student new_student = { input_name_, input_student_id_, input_dept_, input_birth_year_, input_tel_ };
        student_list_.StudentAdd(new_student);
        tmp_vector_.push_back(new_student);
        cout << "Saved successfully" << endl;
    }
    else //�ߺ��� ID�̹Ƿ� 
    {
        cout << "Error : Already inserted\n";
    }
}


/* ���� ����ó���� �ð� �ִ� ������ */

bool Insertion::set_input_name_(string input_string) {
    if (input_string != "") { // �Է��� �ִ� ��쿡
        if (input_string.size() > 15) { // 15���� ����
            cout << "Error : Invaild input , Name is up to 15 chars.\n"; // �����޼��� ����
            return false; // �ٽ� �Է��ϵ��� ����
        }
        else { // �Էµ� �ְ� ���ڼ����ѵ� �� ��Ų ��쿡
            if ('a' <= input_string[0] && input_string[0] <= 'z')
                input_string[0] -= 32; // �̸� ù���� �빮�ڷ� ��ȯ
            if (IsKorean(input_string)) { input_string = "|" + input_string; }//ù ���ڰ� �ѱ�����, �ƽ�Ű�ڵ� ���� �� ���ʿ� ��ġ�� '|'�� �� �տ� �־���
            input_name_ = input_string;
            return true;
        }
    }
    else { // �Է� ���� ����ġ�� �Ѿ ���
        cout << "Error : Name can't be blank.\n"; //���� �޼��� 
        return false; //�ٽ� �Է��ϵ��� ����
    }
}

bool Insertion::set_input_student_id_(string input_string) {
    if (input_string != "") { // �Է��� �ִ� ��쿡
        try {  // �Է��� ���ڿ��� 10�ڸ� 
            if (input_string.size() == 10) //10�����ΰ�?
            {
                for (int i = 0; i < 10; i++)
                {
                    if (isdigit(input_string[i])) { //10���� ���ڰ� ������
                        if (i == 9) {
                            input_student_id_ = input_string;
                            return true; //����� �� �Է� �޾���
                        }
                    }
                    else throw input_string; //10�����ε� ���ڰ� �ƴϸ� �Է��϶�� �ϱ�
                }
            }
            else throw input_string; // �翬�� 10���ڰ� �ƴϾ �Է��϶�� �ϱ�
        }
        catch (string exception)
        {
            cout << "Error : Invaild input , ID should be 10 digit number.\n";
            return false; //�ٽ� �Է��ϵ��� ���� 
        }
    }
    else { // �Է� ���� ����ġ�� �Ѿ ���
        cout << "Error : StudentID can't be blank.\n";
        return false; //�ٽ� �Է��ϵ��� ���� 
    }
}

bool Insertion::set_input_dept_(string input_string) {
    string input_string_out = "";
    if (input_string != "") { // �Է��� �ִ� ��쿡       
        if (IsKorean(input_string)) { input_string = "|" + input_string; } //ù ���ڰ� �ѱ�����, �ƽ�Ű�ڵ� ���� �� ���ʿ� ��ġ�� '|'�� �� �տ� �־���
        vector<string> temp_string = InsertionSplit(input_string, ' '); // ���� �������� �а��̸� �ڸ���
        for (int i = 0; i < temp_string.size(); i++) { // �߶��� ������ ù���� �빮�ڷ� �ٲٱ�
            string temp_vector_string = temp_string[i];
            temp_vector_string[0] = toupper(temp_vector_string[0]);
            input_string_out += temp_vector_string;
            input_string_out += " ";
        }
        input_string_out.pop_back(); // �� ���� �ִ� ���� ���ֱ�
        input_dept_ = input_string_out;
    }
    else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
        input_dept_ = "~";
    }
    return true;
}

bool Insertion::set_input_birth_year_(string input_string) {
    if (input_string != "") { // �Է��� �ִ� ��쿡
        if (input_string.size() != 4) { // ��Ȯ�� 4���ڰ� �ƴ� ���
            cout << "Error : Invaild input , Birth year should be 4 digit number.\n"; // �����޼��� ����
            return false;
        }
        else { // �Էµ� �ְ� ���ڼ��� 4������ ��쿡
            for (int i = 0; i < 4; i++)
            {
                if (isdigit(input_string[i])) { //���� ���ڰ� ������
                    if (i == 3) {
                        input_birth_year_ = input_string;
                        return true; //�ùٸ� �Է� �޾��� 
                    }
                }
                else { //���� 4���� �ƴ϶� �ٸ� ���� ���̸�
                    cout << "Error : Invaild input , Birth year should be 4 digit number.\n";
                    return false;
                }
            }
        }
    }
    else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
        input_birth_year_ = "~";
        return true;
    }
}

bool Insertion::set_input_tel_(string input_string) {
    if (input_string != "") { // �Է��� �ִ� ��쿡
        if (input_string.size() > 12) { // 12���ڱ�����
            cout << "Error : Invaild input , Tel is up to 12 digit number.\n"; // �����޼��� ����
            return false;
        }
        else { // �Էµ� �ְ� 12�ڿ� ���ų� ���� �ùٸ� �Է��� ��쿡
            for (int i = 0; i < input_string.size(); i++)
            {
                if (isdigit(input_string[i])) { //���� ���ڰ� ������
                    if (i == input_string.size() - 1) {
                        input_tel_ = input_string;
                        return true;
                    }
                }
                else { //���ڰ� �ƴ� �ٸ� ���� ���̸�
                    cout << "Error : Invaild input , Tel is up to 12 digit number.\n"; //�������� �������
                    return false;
                }
            }
        }
    }
    else { // ����ġ�� �н��ϰ��� �ϴ� ��� (���ʼ� �Է��̴ϱ�)
        input_tel_ = "~";
        return true;
    }
}

