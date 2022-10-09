#include"student_info_management.h"

/* 구현에 필요한 메소드가 아닌 함수들 */


/* 클래스 내 생성자 및 메소드 */

MainMenu::MainMenu() {

}

void MainMenu::Start() //시작화면, setMode메소드 호출함
{
	bool is_sorted=false; //프로그램 실행 중 정렬을 한 번이라도 했는지 체크
	while (1)
	{
		StudentList list; //Student 정보를 담으르 StudentList 객체
		string input_text; //사용자에게 메뉴 및 모드 입력받을 문자열 
		list.set_is_sorted_(is_sorted); //list에 한 번이라도 정렬됐었는지 여부를 저장해준다

		//타이틀에 뭔가 넣고 싶어서 이것 저것 트라이하는 중
		//const char32_t* s32 = U"⣿⠿⢿⡿⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⡿⣿⣿⡿⣿⣿⣿⡿⣻⣿⣿⣿⣿⠿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿";
		//wcout << s32 << endl;
		//⣿⠿⢿⡿⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⡿⣿⣿⡿⣿⣿⣿⡿⣻⣿⣿⣿⣿⠿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
		//⣿⣬⠻⡅⣽⢹⠉⡏⣭⢸⢉⣋⡏⣭⢹⡅⣽⣿⡇⡏⣽⢹⡅⡝⢩⡍⣿⣿⢰⡹⢱⢸⢝⡉⡏⣭⢹⢝⡉⡏⣭⢹⢉⣋⡏⣭⢩⡍⡏⣋⣹⢩⡍⡇⣭⣿
		//⣿⣶⣾⣷⣾⣶⣶⣷⣶⣾⣷⣶⣷⣿⣾⣷⣾⣿⣷⣷⣿⣾⣷⣿⣶⣾⣿⣿⣾⣷⣿⣾⣶⣶⣷⣿⣾⣶⣶⣗⣒⣸⣶⣶⣷⣿⣾⣷⣷⣶⣿⣾⣷⣷⣶⣿

		cout << "\n-Student Info Management-" << endl;

		cout << "+-----------------------+" << std::endl;
		cout << "| 1. Insertion          |" << endl;
		cout << "|-----------------------|" << std::endl;
		cout << "| 2. Search             |" << endl;
		cout << "|-----------------------|" << std::endl;
		cout << "| 3. Sorting Option     |" << endl;
		cout << "|-----------------------|" << std::endl;
		cout << "| 4. Exit               |" << endl;
		cout << "+-----------------------+" << std::endl;
		getline(cin, input_text); //getline으로 띄어쓰기를 포함한 문장 전체 가지고 오기
		set_mode_(input_text);
		switch (this->mode_)
		{
		case 1:
			MainInsert(list);
			break;
		case 2:
			MainSearch(list);
			break;
		case 3:
			MainSort(list);
			is_sorted = true;
			break;
		case 4:
			Exit();
			break;
		default:
			break;
		}
	}
}

void MainMenu::MainInsert(StudentList& student_list) //inseriton실행
{
	Insertion insertion(student_list); //insertion 객체 생성
	insertion.Input(); 
	insertion.InsertIn();
}

void MainMenu::MainSearch(StudentList& student_list)
{
	Searching searching(student_list);
	searching.SearchingInput();
	if (searching.get_search_mode_() == 6) { return; }// 6. back, 6번을 선택하면 mainmenu의 while문으로 돌아감
	else {
		searching.Search();
		searching.Print(searching.get_searching_tmp_vector_());
		return;
	}
}

void MainMenu::MainSort(StudentList& student_list)
{
	Sorting sorting(student_list);
	sorting.SortingInput();
	if (sorting.get_sort_mode_() == 5) { return; }// 5. back, 5번을 선택하면 mainmenu의 while문으로 돌아감
	else {
		sorting.Sort(sorting.get_sort_mode_(), sorting.get_sorting_tmp_vector_());
		sorting.Print(sorting.get_sorting_tmp_vector_());
		sorting.EnterToFile();
		return;
	}
}

void MainMenu::Exit()
{
	exit(0);
}


/* 각종 예외처리를 맡고 있는 변경자 */

void MainMenu::set_mode_(string mode_) { //set mode
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
		cout << "Error :" << "'" << exception << "'" << "is Invalid input\n"; //예외처리 실행
		this->mode_ = 0; //모드 초기화
	}
}
