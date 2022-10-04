#include "student_info_management.h"

//Sorting���� �ʿ��� �Լ���
bool SortingCompareName(Student a, Student b) { //���� 1���� : �л� �̸�, ���� 2���� : �й� 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name(); //1���� : �л� �̸�
    else return a.get_student_id() < b.get_student_id(); //2���� : �й�
} 

bool SortingCompareId(Student a, Student b) { return a.get_student_id() < b.get_student_id(); };//�й����� ���� 

bool SortingCompareDept(Student a, Student b) { //���� 1���� : �а� �̸�, ���� 2���� : �й� 
    if (a.get_dept() != b.get_dept()) return a.get_dept() < b.get_dept(); //1���� : �а� �̸�
    else return a.get_student_id() < b.get_student_id(); //2���� : �й�
}

Sorting::Sorting(StudentList student_list) { //������. �л� ���� list �޾� ���� 
    this->student_list_ = student_list; //MainMenu�� Student list �޾� ����
    this->tmp_vector_ = student_list_.get_student_list(); //StudentList�� vector�κ� ���� ���� 
}

bool Sorting::set_sort_mode_(string sort_mode) { //sort_mode_ ������
    try { //�߸��� �Է� ����ó�� 
        if (sort_mode.size() == 1 && isdigit(sort_mode[0])) { //�Է¹��� �� 1�����̰� �����ΰ�? 
            if ((1 <= sort_mode[0] - '0') && (sort_mode[0] - '0' <= 5)) { //1�̻� 5�����ΰ�?
                this->sort_mode_ = sort_mode[0] - '0'; //��� ���� sort_mode_ �� ����
                return true; //����� �Էµ����� �˸��� ���� true ��ȯ
            }
            else throw sort_mode; //���� �߻� 
        }
        else throw sort_mode; //���� �߻� 
    }
    catch (string exception) {//���ܰ� �߻����� ��, �� �߸��� �Է��� �޾��� �� 
        cout << "Error : Invalid input\n";
        this->sort_mode_ = 0;//MainMenu���� �ٽ� ����� �� ���� �Է¹ްԲ� sort_mode_�� 0���� ����� 
        return false; //�߸��� �Է��� �������� �˸��� ���� false ��ȯ
    }
}

void Sorting::SortingDisplay() { //���� ���� �� ù ȭ�� ���
    cout << "\n- Sorting Option\n1. Sort by Name\n2. Sort by Student ID\n3. Sort by Admission Year\n4. Sort by Department name\n5. Go back\n> ";
}

bool Sorting::SortingInput() { //���� ��� �Է� �ޱ�. ����ó�� ���� 
    string sort_mode; //��������� �Է� ���� string ���� 
    cin >> sort_mode; //��������� �Է� �ޱ� 
    cin.ignore(); //����ڰ� ���鹮�ڿ� �Բ� ���� ���ڸ� �Է����� �� ���� ����� ���� ���� 
    if (set_sort_mode_(sort_mode))return true; //���� ����� �� �Է��� �޾Ҵٸ� true ��ȯ
    else return false; //�߸��� �Է��� �޾Ҵٸ� false ��ȯ 
}

string Sorting::FilterNull(string tmp_string) { //���� ������ ~�� ǥ�õ��ִ� �κ��� ����� ������ NULL�� ǥ���ϱ� ���� �ʿ��� �޼���
    if (tmp_string == "~")tmp_string = "NULL"; //���� �ش� string�� "~"�� �̸� NULL�� ��ȯ
    return tmp_string; //��ȯ�� string�� ��ȯ
}

void Sorting::Sort() {
    switch (this->sort_mode_) { //�Է¹��� ���ؿ� ���� �����ϱ�
    case 1:
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareName); //�л� �̸� ������ ���� (2���� ���� ������ �л� ID)
        break;
    case 2:
    case 3: //��� �⵵ ������ �����ϳ� �л� ID ������ �����ϳ� ��� �л� ID �������� ������ �����ϸ� �Ǳ⿡ �ϳ��� ��ħ. 
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareId); //�л� ID ������ ����. 
        break;
    case 4:
        sort(tmp_vector_.begin(), tmp_vector_.end(), SortingCompareDept); //�а� �̸� ������ ���� (2���� ���ı����� �л� ID)
        break;
    default: //sort_mode_�� 1~4 �̿��� ���� ���޵� ��� �ƹ��� �߰� ���� ���� ���� �޴��� �̵�
        break;
    }

    fstream file; //������ �ٷ�� ���� fstream ���� ���� 
    file.open("file1.txt", ios::out | ios::trunc); //���� �� ��, ���� ���� �� ����� ������ ������� ä���ֱ� 
    for (int i = 0; i < tmp_vector_.size(); i++) { //�л� ������ ������ ������� �ٽ� ���Ͽ� ���� 
        file << tmp_vector_[i].get_name() << ';'; //���� �Ľ��� �� �����ϱ� ���� �� �� �� �� �����ݷ��� �߰��� �ٿ��� ����
        file << tmp_vector_[i].get_student_id() << ';';
        file << tmp_vector_[i].get_dept() << ';';
        file << tmp_vector_[i].get_birth_year() << ';';
        file << tmp_vector_[i].get_tel() ; //�� �л��� ������ ���� ������ �����ݷ� ���̱⸦ ����
        file << '\n';
    }
    file.close(); //���� �ݱ� 
    return;

}
void Sorting::SortingPrint() { //���� ��� ����ϱ� 
    int blank_space[5] = { 14,10,20,10,12 }; //������� �� �� ���� �Ҵ�� ĭ �� ����
    for (auto student : this->tmp_vector_) {
        blank_space[0] = max(blank_space[0], (int)student.get_name().size());
        blank_space[1] = max(blank_space[1], (int)student.get_student_id().size());
        blank_space[2] = max(blank_space[2], (int)student.get_dept().size());
        blank_space[3] = max(blank_space[3], (int)student.get_birth_year().size());
        blank_space[4] = max(blank_space[4], (int)student.get_tel().size());
    }
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" }; //������� �� �� ���� �̸�
    cout << "+"; //ǥ �������� ��Ÿ���� ���� �ڵ�
    for (int i = 0; i < 5; i++) { //col �̸� �ٷ� �� ������
        for (int j = 0; j < blank_space[i]; j++) { //�� �� �� �Ҵ�� ĭ �� ����ϸ� ��� 
            cout << '-';
        }
        cout << '+'; //col �ٲ� �� + ����ؼ� �����ٰ��� �̾��ֱ� 
    }
    cout << '\n';
    cout << '|'; //col �̸��� ��µǴ� �� �� �տ� | ���
    for (int i = 0; i < 5; i++) { //Student Ŭ������ ���� �ִ� ��� �л� ������ ��� 
        cout << left << setw(blank_space[i]) << col_name[i]; // �� ������ �Ҵ�� ĭ ����ŭ ������ Ȯ�� �� ���� ���ķ� ���
        cout << '|'; //col �̸��� ��µǴ� �� �� �������� | ���
    }
    cout << '\n';
    cout << "+"; //ǥ �������� ��Ÿ���� ���� �ʿ��� �ڵ� 
    for (int i = 0; i < 5; i++) { //col �̸� �ٷ� �Ʒ� ������
        for (int j = 0; j < blank_space[i]; j++) { //�� �� �� �Ҵ�� ĭ �� ����ϸ� ���
            cout << '-';
        }
        cout << '+'; //col �ٲ� �� + ����ؼ� �����ٰ��� �̾��ֱ� 
    }
    cout << '\n';
    for (int i = 0; i < this->tmp_vector_.size(); i++) { //������ �ִ� ��� �л� ������ ��ȸ�ϸ� ����ϱ�
        cout << '|'; //�� �л����� ������ �Ҵ�� ������ŭ Ȯ���ϰ� ���� �����Ͽ� ǥ �������� ���
        cout << left << setw(blank_space[0]) << FilterNull(this->tmp_vector_[i].get_name())<<'|';
        cout << left << setw(blank_space[1]) << FilterNull(this->tmp_vector_[i].get_student_id()) << '|';
        cout << left << setw(blank_space[2]) << FilterNull(this->tmp_vector_[i].get_dept())<< '|';
        cout << right << setw(blank_space[3]) << FilterNull(this->tmp_vector_[i].get_birth_year())<< '|';
        cout << left << setw(blank_space[4]) << FilterNull(this->tmp_vector_[i].get_tel())<< '|';
        cout << '\n';
    }
    cout << "+"; //ǥ �������� ��Ÿ���� ���� �ʿ��� �ڵ� 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
}