#include "student_info_management.h"

// search 동작 순서 :display-> input ->search로 list 받아오기-> search(case에따라 조건에맞는student새로운벡터에담김,이름순정렬까지완료)-> print

bool SearchingCompareName(Student a, Student b) { //정렬 1순위 : 이름, 정렬 2순위 : 학번 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
    else return a.get_student_id() < b.get_student_id();
}
vector<string> SearchingSplit(string str, char delimeter) { //문자열을 특정 공백 기준으로 나눌 때 필요한 함수 
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimeter)) {
        answer.push_back(temp);
    }

    return answer;
}
string Searching::Filter(string s) { //프린트할때필요함
    if (s == "~")s = "NULL";
    else if (s[0] == '|')s = s.substr(1);
    return s;
}  


void Searching::SearchingDisplay() { // 서치 첫 화면 디스플레이
	std::cout << "- Search -" << std::endl; //- Search -가 출력됩니다.
	std::cout << "1. Search by name" << std::endl;//"1. Search by name"가 출력됩니다.
	std::cout << "2. Search by student ID (10 numbers)" << std::endl;//"2. Search by student ID (10 numbers)"가 출력됩니다.
	std::cout << "3. Search by admission year (4 numbers)" << std::endl;//3. Search by admission year (4 numbers)가 출력됩니다.
	std::cout << "4. Search by department name" << std::endl;//"4. Search by department name"가 출력됩니다.
	std::cout << "5. List All" << std::endl;//"5. List All" 가 출력됩니다.
    std::cout << "6. Go back" << std::endl;//"6. Go back"가 출력됩니다.
    std::cout << "> ";
}

bool Searching::set_search_mode_(string search_mode_) {   //searchmode 설정하기
    try {
        if (search_mode_.size() == 1 && isdigit(search_mode_[0])) {   //입력값이 1~6이 아닌 경우에 대해  예외처리
            if ((1 <= search_mode_[0] - '0') && (search_mode_[0] - '0' <= 6)) {
                this->search_mode_ = search_mode_[0] - '0';  //search_mode_는 string값이기 때문에 '0'을 빼서 숫자가 되도록 계산하였음
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


bool Searching::SearchingInput() { //  서치 모드 입력 받기 
	string search_mode; 
    getline(cin, search_mode);  //_search_mode로 입력을 받습니다. 1은 search by name, 2은 search by Student Id, 3은 search by admission year, 4은 search by department name, 5은 list all, 6은 go back입니다.
    if (set_search_mode_(search_mode)) return true;  //set_search_mode: 1~6을 제외한 다른 입력값의 경우 예외처리 
    else return false;  
}
Searching::Searching(StudentList student_list) { //student_list 받아 오기 
    this->student_list_ = student_list;
    this->tmp_vector_ = student_list.get_student_list();
}

void Searching::Search() {
    string search_keyword;
    string input_dept_string_in; //dept 검색할 때 쓸 스트링1
    string input_dept_string_out = ""; //dept 검색할 때 쓸 스트링2
    vector<string> temp_string;
   /* cin.ignore();
    getline(cin, search_keyword);*/
    switch (search_mode_) { //입력받은 기준에 따라 search 하기
        case 1: //search by name
            std::cout << "name keyword ? ";    //name keyword? 출력하였음
            getline(cin, search_keyword);  //getline 함수로 한줄 입력받기
            if ('a' <= search_keyword[0] && search_keyword[0] <= 'z') {
                search_keyword[0] -= 32;
            }
            cout << search_keyword << '\n';
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_name() == search_keyword) {
                    student_search_list_.push_back(tmp_vector_[i]);  
                }
            }
            break;
        case 2:  //search by student id
            std::cout << "student id keyword ? ";  //student id keyword? 출력하였음
            getline(cin, search_keyword);  //getline 함수로 한줄 입력받기
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_student_id() == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 3:  //search by admission year
            std::cout << "admission year keyword ? ";  //admission year keyword ? 출력하였음
            getline(cin, search_keyword); //getline 함수로 한줄 입력받기
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음. 
                if (tmp_vector_[i].get_student_id().substr(0,4) == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 4: //search by department name
            
            std::cout << "department name keyword ? "; //admission year keyword ? 출력하였음
            getline(cin, input_dept_string_in); //getline 함수로 한줄 입력받기

            temp_string = SearchingSplit(input_dept_string_in, ' '); // 공백 기준으로 학과이름 자르기
            for (int i = 0; i < temp_string.size(); i++) { // 잘라진 어절의 첫글자 대문자로 바꾸기
                string temp_vector_string = temp_string[i];
                temp_vector_string[0] = toupper(temp_vector_string[0]);
                input_dept_string_out += temp_vector_string;
                input_dept_string_out += " ";
            }
            input_dept_string_out.pop_back(); // 맨 끝에 있는 띄어쓰기 없애기
            search_keyword = input_dept_string_out;
            for (int i = 0; i < tmp_vector_.size ();i++) {   //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_dept() == search_keyword ) {
                    student_search_list_.push_back(tmp_vector_[i]);
                }
            }
            break;
        case 5: //list all
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로  담음.
                student_search_list_.push_back(tmp_vector_[i]);
            }
            sort(student_search_list_.begin(), student_search_list_.end(), SearchingCompareName);
            break;

        default:
            break;
    }
}
void Searching::SearchingPrint() { //정렬 결과 출력하기 
    int blank_space[5] = { 5,11,10,10,11 }; //출력했을 때 각 열에 할당될 칸 수 지정
    for (auto student : this->student_search_list_) {
        blank_space[0] = max(blank_space[0], (int)student.get_name().size()+1);
        blank_space[2] = max(blank_space[2], (int)student.get_dept().size());
        blank_space[4] = max(blank_space[4], (int)student.get_tel().size());
    }
    string col_name[] = { "Name","Student ID","Department","Birth Year","Tel" };   //column 값 
    cout << "+";    //열의 첫값과 끝값에 +, 그 사이는 -를 출력하여 표 형태로 보이도록 하였음.
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
