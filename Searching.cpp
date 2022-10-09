#include "student_info_management.h"

/* ������ �ʿ��� �޼ҵ尡 �ƴ� �Լ��� */

vector<string> SearchingSplit(string str, char delimeter) { //���ڿ��� Ư�� ���� �������� ���� �� �ʿ��� �Լ� 
    vector<string> answer;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimeter)) {
        answer.push_back(temp);
    }
    return answer;
}


/* Ŭ���� ������ �� �޼ҵ� */

Searching::Searching(StudentList student_list) : Sorting(student_list) { //student_list �޾� ���� 
    this->student_list_ = student_list;
    this->tmp_vector_ = student_list.get_student_list();
}

void Searching::SearchingDisplay() { // ��ġ ù ȭ�� ���÷���
    std::cout << "- Search -" << std::endl; //- Search -�� ��µ˴ϴ�.
    std::cout << "+-----------------------------------------+" << std::endl;
    std::cout << "| 1. Search by name                       |" << std::endl;//"1. Search by name"�� ��µ˴ϴ�.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 2. Search by student ID (10 numbers)    |" << std::endl;//"2. Search by student ID (10 numbers)"�� ��µ˴ϴ�.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 3. Search by admission year (4 numbers) |" << std::endl;//3. Search by admission year (4 numbers)�� ��µ˴ϴ�.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 4. Search by department name            |" << std::endl;//"4. Search by department name"�� ��µ˴ϴ�.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 5. List All                             |" << std::endl;//"5. List All" �� ��µ˴ϴ�.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 6. Go back                              |" << std::endl;//"6. Go back"�� ��µ˴ϴ�.
    std::cout << "+-----------------------------------------+" << std::endl;
}

void Searching::SearchingInput() { //  ��ġ ��� �Է� �ޱ� 
	string input_string; 
    while (1) {
        SearchingDisplay();
        getline(cin, input_string);  //_search_mode�� �Է��� �޽��ϴ�. 1�� search by name, 2�� search by Student Id, 3�� search by admission year, 4�� search by department name, 5�� list all, 6�� go back�Դϴ�.
        if (set_search_mode_(input_string)) break;  //set_search_mode: 1~6�� ������ �ٸ� �Է°��� ��� ����ó�� 
    }
}

void Searching::Search() {
    string search_keyword;
    vector<Student> student_search_list; // ���ǿ� �´� student�� ���� ���ο� list�� ����
    vector<string> temp_splited_string; //dept �Է¹��� �� �ӽ÷� �����͸� ������ ����
    if (!student_list_.get_is_sorted_()) {// �÷��̾ ������ ������ ���� �ʾ��� ���
        tmp_vector_ = Sort(1, tmp_vector_);//Sorting�� ����ؼ� Sorting�� Sort�� �״�� ���
    }

    switch (search_mode_) { //�Է¹��� ���ؿ� ���� search �ϱ�

        case 1: //search by name
            std::cout << "name keyword ? ";    //name keyword? ����Ͽ���
            getline(cin, search_keyword);  //getline �Լ��� ���� �Է¹ޱ�
            if ('a' <= search_keyword[0] && search_keyword[0] <= 'z') { search_keyword[0] -= 32; } //�ҹ��ڷ� �����Ѵٸ� ù ���ڸ� �빮�ڷ� ����
            if (!('A' <= search_keyword[0] && search_keyword[0] <= 'z')) { search_keyword = "|" + search_keyword; } //�ѱ���� �����Ѵٸ� �� �տ� '|' ���̱�
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_name() == search_keyword) {
                    student_search_list.push_back(tmp_vector_[i]);  
                }
            }
            break;

        case 2:  //search by student id
            std::cout << "student id keyword ? ";  //student id keyword? ����Ͽ���
            getline(cin, search_keyword);  //getline �Լ��� ���� �Է¹ޱ�
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_student_id() == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 3:  //search by admission year
            std::cout << "admission year keyword ? ";  //admission year keyword ? ����Ͽ���
            getline(cin, search_keyword); //getline �Լ��� ���� �Է¹ޱ�
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����. 
                if (tmp_vector_[i].get_student_id().substr(0,4) == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 4: //search by department name
            std::cout << "department name keyword ? "; //admission year keyword ? ����Ͽ���
            getline(cin, search_keyword); //getline �Լ��� ���� �Է¹ޱ�

            //���� ���� �� �ܾ��� ù ���ڸ� �빮�ڷ� ������ֱ� 
            temp_splited_string = SearchingSplit(search_keyword, ' '); // ���� �������� �а��̸� �ڸ���
            search_keyword = "";
            for (auto temp_splited_string_slice : temp_splited_string) { // �߶��� ������ ù���� �빮�ڷ� �ٲٱ�
                temp_splited_string_slice[0] = toupper(temp_splited_string_slice[0]);
                search_keyword += temp_splited_string_slice+" ";
            }
            search_keyword.pop_back(); // �� ���� �ִ� ���� ���ֱ�
            if (!('A' <= search_keyword[0] && search_keyword[0] <= 'z')) { search_keyword = "|" + search_keyword; } //�ѱ���� �����Ѵٸ� �� �տ� '|' ���̱�

            for (int i = 0; i < tmp_vector_.size ();i++) {   //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_dept() == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 5: //list all
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ���  ����.
                student_search_list.push_back(tmp_vector_[i]);
            }
            break;

        default:
            break;
    }

    this->tmp_vector_ = student_search_list; //�˻� ���ǿ� �´� �л� ������ ���� �����صα� 
}


/* ���� ����ó���� �ð� �ִ� �����ڵ� */

bool Searching::set_search_mode_(string search_mode_) {   //searchmode �����ϱ�
    try {
        if (search_mode_.size() == 1 && isdigit(search_mode_[0])) {   //�Է°��� 1~6�� �ƴ� ��쿡 ����  ����ó��
            if ((1 <= search_mode_[0] - '0') && (search_mode_[0] - '0' <= 6)) {
                this->search_mode_ = search_mode_[0] - '0';  //search_mode_�� string���̱� ������ '0'�� ���� ���ڰ� �ǵ��� ����Ͽ���
                return true;
            }
            else throw search_mode_;
        }
        else throw search_mode_;
    }
    catch (string exception) { //���� ��Ȳ�� �߻����� �� 
        cout << "Error :" << "'" << exception << "'" << "is Invalid input\n";
        this->search_mode_ = 0; //���α׷��� �ƹ��� ������ ���Բ� 0���� search_mode_�� �ʱ�ȭ���ݴϴ�. 
        return false;
    }
}

