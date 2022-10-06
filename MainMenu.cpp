#include"student_info_management.h"

using namespace std;

void MainMenu::set_mode(string mode_) { //set mode
	try {
		if (mode_.size() == 1 && isdigit(mode_[0])) { //입력받은 문자열의 길이가 1이고, 정수일 때
			if ((1 <= mode_[0] - '0') && (mode_[0] - '0' <= 4)) {
				this->mode_ = mode_[0] - '0';
			}
			else throw mode_; //입력받은 문자열의 값이 1보다 작거나 4보다 클 때 예외처리
		}
		else throw mode_; //입력받은 문자열의 길이가 1이 아니거나, 정수가 아닐 때 예외처리
	}
	catch (string exception) {
		cout << "Error :" <<"'"<< exception <<"'" << "is Invalid input\n"; //예외처리 실행
		this->mode_ = 0; //모드 초기화
	}
}
void MainMenu::Start() //시작화면, setMode메소드 호출함
{
	while (1)
	{
		StudentList list;
		string input_text;
		cout << "1. Insertion" << endl;
		cout << "2. Search" << endl;
		cout << "3. Sorting Option" << endl;
		cout << "4. Exit" << endl;
		cout << "> ";
		getline(cin, input_text); //getline으로 띄어쓰기를 포함한 문장 전체 가지고 오기
		set_mode(input_text);
		switch (this->mode_)
		{
		case 1:
			Insert(list);
			break;
		case 2:
			Search(list);
			break;
		case 3:
			Sort(list);
			break;
		case 4:
			Exit();
			break;
		default:
			break;
		}
	}
}

void MainMenu::Insert(StudentList student_list) //inseriton실행
{
	Insertion s(student_list); //insertion 객체 생성
	s.Input(); 
	s.CheckError();
	s.InsertIn();
}

void MainMenu::Sort(StudentList student_list)
{
	Sorting s(student_list);
	while (true) {
		s.SortingDisplay();
		if (s.SortingInput()) {
			if (s.get_sort_mode_() == 5) { // 5. back, 5번을 선택하면 mainmenu의 while문으로 돌아감
				break;
			}
			else {
				s.Sort();
				s.SortingPrint();
				break;
			}
		}
	}
}

void MainMenu::Search(StudentList student_list) 
{
	Searching s(student_list);
	while (true) {
		s.SearchingDisplay();
		if (s.SearchingInput()) {
			if (s.get_search_mode_() == 6) { // 6. back, 6번을 선택하면 mainmenu의 while문으로 돌아감
				break;
			}
			else {
				s.Search();
				s.SearchingPrint();
				break;
			}
		}
	}
}

void MainMenu::Exit()
{
	exit(0);
}

