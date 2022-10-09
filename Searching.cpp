#include "student_info_management.h"

/* 구현에 필요한 메소드가 아닌 함수들 */

vector<string> SearchingSplit(string str, char delimeter) { //문자열을 특정 공백 기준으로 나눌 때 필요한 함수 
    vector<string> answer;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimeter)) {
        answer.push_back(temp);
    }
    return answer;
}


/* 클래스 생성자 및 메소드 */

Searching::Searching(StudentList student_list) : Sorting(student_list) { //student_list 받아 오기 
    this->student_list_ = student_list;
    this->tmp_vector_ = student_list.get_student_list();
}

void Searching::SearchingDisplay() { // 서치 첫 화면 디스플레이
    std::cout << "- Search -" << std::endl; //- Search -가 출력됩니다.
    std::cout << "+-----------------------------------------+" << std::endl;
    std::cout << "| 1. Search by name                       |" << std::endl;//"1. Search by name"가 출력됩니다.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 2. Search by student ID (10 numbers)    |" << std::endl;//"2. Search by student ID (10 numbers)"가 출력됩니다.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 3. Search by admission year (4 numbers) |" << std::endl;//3. Search by admission year (4 numbers)가 출력됩니다.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 4. Search by department name            |" << std::endl;//"4. Search by department name"가 출력됩니다.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 5. List All                             |" << std::endl;//"5. List All" 가 출력됩니다.
    std::cout << "|-----------------------------------------+" << std::endl;
    std::cout << "| 6. Go back                              |" << std::endl;//"6. Go back"가 출력됩니다.
    std::cout << "+-----------------------------------------+" << std::endl;
}

void Searching::SearchingInput() { //  서치 모드 입력 받기 
	string input_string; 
    while (1) {
        SearchingDisplay();
        getline(cin, input_string);  //_search_mode로 입력을 받습니다. 1은 search by name, 2은 search by Student Id, 3은 search by admission year, 4은 search by department name, 5은 list all, 6은 go back입니다.
        if (set_search_mode_(input_string)) break;  //set_search_mode: 1~6을 제외한 다른 입력값의 경우 예외처리 
    }
}

void Searching::Search() {
    string search_keyword;
    vector<Student> student_search_list; // 조건에 맞는 student를 담을 새로운 list를 뜻함
    vector<string> temp_splited_string; //dept 입력받을 때 임시로 데이터를 저장할 변수
    if (!student_list_.get_is_sorted_()) {// 플레이어가 이전에 정렬을 하지 않았을 경우
        tmp_vector_ = Sort(1, tmp_vector_);//Sorting을 상속해서 Sorting의 Sort를 그대로 사용
    }

    switch (search_mode_) { //입력받은 기준에 따라 search 하기

        case 1: //search by name
            std::cout << "name keyword ? ";    //name keyword? 출력하였음
            getline(cin, search_keyword);  //getline 함수로 한줄 입력받기
            if ('a' <= search_keyword[0] && search_keyword[0] <= 'z') { search_keyword[0] -= 32; } //소문자로 시작한다면 첫 글자를 대문자로 변경
            if (!('A' <= search_keyword[0] && search_keyword[0] <= 'z')) { search_keyword = "|" + search_keyword; } //한국어로 시작한다면 맨 앞에 '|' 붙이기
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_name() == search_keyword) {
                    student_search_list.push_back(tmp_vector_[i]);  
                }
            }
            break;

        case 2:  //search by student id
            std::cout << "student id keyword ? ";  //student id keyword? 출력하였음
            getline(cin, search_keyword);  //getline 함수로 한줄 입력받기
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_student_id() == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 3:  //search by admission year
            std::cout << "admission year keyword ? ";  //admission year keyword ? 출력하였음
            getline(cin, search_keyword); //getline 함수로 한줄 입력받기
            for (int i = 0; i < tmp_vector_.size(); i++) {  //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음. 
                if (tmp_vector_[i].get_student_id().substr(0,4) == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 4: //search by department name
            std::cout << "department name keyword ? "; //admission year keyword ? 출력하였음
            getline(cin, search_keyword); //getline 함수로 한줄 입력받기

            //띄어쓰기 기준 각 단어의 첫 글자를 대문자로 만들어주기 
            temp_splited_string = SearchingSplit(search_keyword, ' '); // 공백 기준으로 학과이름 자르기
            search_keyword = "";
            for (auto temp_splited_string_slice : temp_splited_string) { // 잘라진 어절의 첫글자 대문자로 바꾸기
                temp_splited_string_slice[0] = toupper(temp_splited_string_slice[0]);
                search_keyword += temp_splited_string_slice+" ";
            }
            search_keyword.pop_back(); // 맨 끝에 있는 띄어쓰기 없애기
            if (!('A' <= search_keyword[0] && search_keyword[0] <= 'z')) { search_keyword = "|" + search_keyword; } //한국어로 시작한다면 맨 앞에 '|' 붙이기

            for (int i = 0; i < tmp_vector_.size ();i++) {   //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로 담음.
                if (tmp_vector_[i].get_dept() == search_keyword ) {
                    student_search_list.push_back(tmp_vector_[i]);
                }
            }
            break;

        case 5: //list all
            for (int i = 0; i < tmp_vector_.size(); i++) {    //student_list_size 메소드로 크기 확인, for문으로 조건문에 해당하는 student_list의 원소를 student_search_list라는 새 list에 pushback함수로  담음.
                student_search_list.push_back(tmp_vector_[i]);
            }
            break;

        default:
            break;
    }

    this->tmp_vector_ = student_search_list; //검색 조건에 맞는 학생 정보만 따로 저장해두기 
}


/* 각종 예외처리를 맡고 있는 변경자들 */

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
    catch (string exception) { //예외 상황이 발생했을 때 
        cout << "Error :" << "'" << exception << "'" << "is Invalid input\n";
        this->search_mode_ = 0; //프로그램에 아무런 지장이 없게끔 0으로 search_mode_를 초기화해줍니다. 
        return false;
    }
}

