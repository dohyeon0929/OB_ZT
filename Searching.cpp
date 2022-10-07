#include "student_info_management.h"

// search ���� ���� :display-> input ->search�� list �޾ƿ���-> search(case������ ���ǿ��´�student���ο�Ϳ����,�̸������ı����Ϸ�)-> print

bool SearchingCompareName(Student a, Student b) { //���� 1���� : �̸�, ���� 2���� : �й� 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
    else return a.get_student_id() < b.get_student_id();
}
vector<string> SearchingSplit(string str, char delimeter) { //���ڿ��� Ư�� ���� �������� ���� �� �ʿ��� �Լ� 
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimeter)) {
        answer.push_back(temp);
    }

    return answer;
}
string Searching::Filter(string s) { //����Ʈ�Ҷ��ʿ���
    if (s == "~")s = "NULL";
    else if (s[0] == '|')s = s.substr(1);
    return s;
}  


void Searching::SearchingDisplay() { // ��ġ ù ȭ�� ���÷���
	std::cout << "- Search -" << std::endl; //- Search -�� ��µ˴ϴ�.
	std::cout << "1. Search by name" << std::endl;//"1. Search by name"�� ��µ˴ϴ�.
	std::cout << "2. Search by student ID (10 numbers)" << std::endl;//"2. Search by student ID (10 numbers)"�� ��µ˴ϴ�.
	std::cout << "3. Search by admission year (4 numbers)" << std::endl;//3. Search by admission year (4 numbers)�� ��µ˴ϴ�.
	std::cout << "4. Search by department name" << std::endl;//"4. Search by department name"�� ��µ˴ϴ�.
	std::cout << "5. List All" << std::endl;//"5. List All" �� ��µ˴ϴ�.
    std::cout << "6. Go back" << std::endl;//"6. Go back"�� ��µ˴ϴ�.
    std::cout << "> ";
}

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
    catch (string exception) {
        cout << "Error :" << "'" << exception << "'" << "is Invalid input\n";
        this->search_mode_ = 0;
        return false;
    }
}


bool Searching::SearchingInput() { //  ��ġ ��� �Է� �ޱ� 
	string search_mode; 
    getline(cin, search_mode);  //_search_mode�� �Է��� �޽��ϴ�. 1�� search by name, 2�� search by Student Id, 3�� search by admission year, 4�� search by department name, 5�� list all, 6�� go back�Դϴ�.
    if (set_search_mode_(search_mode)) return true;  //set_search_mode: 1~6�� ������ �ٸ� �Է°��� ��� ����ó�� 
    else return false;  
}
Searching::Searching(StudentList student_list) { //student_list �޾� ���� 
    this->student_list_ = student_list;
    this->tmp_vector_ = student_list.get_student_list();
}

void Searching::Search() {
    string search_keyword;
    string input_dept_string_in; //dept �˻��� �� �� ��Ʈ��1
    string input_dept_string_out = ""; //dept �˻��� �� �� ��Ʈ��2
    vector<string> temp_string;
   /* cin.ignore();
    getline(cin, search_keyword);*/
    switch (search_mode_) { //�Է¹��� ���ؿ� ���� search �ϱ�
        case 1: //search by name
            std::cout << "name keyword ? ";    //name keyword? ����Ͽ���
            getline(cin, search_keyword);  //getline �Լ��� ���� �Է¹ޱ�
            if ('a' <= search_keyword[0] && search_keyword[0] <= 'z') {
                search_keyword[0] -= 32;
            }
            cout << search_keyword << '\n';
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_name() == search_keyword) {
                    student_search_list_.push_back(tmp_vector_[i]);  
                }
            }
            break;
        case 2:  //search by student id
            std::cout << "student id keyword ? ";  //student id keyword? ����Ͽ���
            getline(cin, search_keyword);  //getline �Լ��� ���� �Է¹ޱ�
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_student_id() == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 3:  //search by admission year
            std::cout << "admission year keyword ? ";  //admission year keyword ? ����Ͽ���
            getline(cin, search_keyword); //getline �Լ��� ���� �Է¹ޱ�
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����. 
                if (tmp_vector_[i].get_student_id().substr(0,4) == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 4: //search by department name
            
            std::cout << "department name keyword ? "; //admission year keyword ? ����Ͽ���
            getline(cin, input_dept_string_in); //getline �Լ��� ���� �Է¹ޱ�

            temp_string = SearchingSplit(input_dept_string_in, ' '); // ���� �������� �а��̸� �ڸ���
            for (int i = 0; i < temp_string.size(); i++) { // �߶��� ������ ù���� �빮�ڷ� �ٲٱ�
                string temp_vector_string = temp_string[i];
                temp_vector_string[0] = toupper(temp_vector_string[0]);
                input_dept_string_out += temp_vector_string;
                input_dept_string_out += " ";
            }
            input_dept_string_out.pop_back(); // �� ���� �ִ� ���� ���ֱ�
            search_keyword = input_dept_string_out;
            for (int i = 0; i < tmp_vector_.size ();i++) {   //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ��� ����.
                if (tmp_vector_[i].get_dept() == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 5: //list all
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size �޼ҵ�� ũ�� Ȯ��, for������ ���ǹ��� �ش��ϴ� student_list�� ���Ҹ� student_search_list��� �� list�� pushback�Լ���  ����.
                student_search_list_.push_back(tmp_vector_[i]);
            }
            sort(student_search_list_.begin(), student_search_list_.end(), SearchingCompareName);
            break;

        default:
            break;
    }
}
void Searching::SearchingPrint() { //���� ��� ����ϱ� 
    int blank_space[5] = { 5,11,10,10,11 }; //������� �� �� ���� �Ҵ�� ĭ �� ����
    for (auto student : this->student_search_list_) {
        blank_space[0] = max(blank_space[0], (int)student.get_name().size()+1);
        blank_space[2] = max(blank_space[2], (int)student.get_dept().size());
        blank_space[4] = max(blank_space[4], (int)student.get_tel().size());
    }
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };   //column �� 
    cout << "+";    //���� ù���� ������ +, �� ���̴� -�� ����Ͽ� ǥ ���·� ���̵��� �Ͽ���.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
    cout << '|';
    for (int i = 0; i < 5; i++) {
        cout << left << setw(blank_space[i]) << col_name[i];
        cout << '|';
    }
    cout << '\n';
    cout << "+";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
    for (int i = 0; i < student_search_list_.size(); i++) {  //
        cout << '|';
        cout << left << setw(blank_space[0]) << Filter(student_search_list_[i].get_name())  << '|';
        cout << left << setw(blank_space[1]) << Filter(student_search_list_[i].get_student_id()) << '|';
        cout << left << setw(blank_space[2]) << Filter(student_search_list_[i].get_dept()) << '|';
        cout << left << setw(blank_space[3]) << Filter(student_search_list_[i].get_birth_year()) << '|';
        cout << left << setw(blank_space[4]) << Filter(student_search_list_[i].get_tel()) << '|';
        cout << '\n';
    }
    
    cout << "+";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < blank_space[i]; j++) {
            cout << '-';
        }
        cout << '+';
    }
    cout << '\n';
}
