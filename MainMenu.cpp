#include"student_info_management.h"

using namespace std;

void MainMenu::set_mode(string mode_) {
	try {
		if (mode_.size() == 1 && isdigit(mode_[0])) {
			if ((1 <= mode_[0] - '0') && (mode_[0] - '0' <= 4)) {
				this->mode_ = mode_[0] - '0';
			}
			else throw mode_;
		}
		else throw mode_;
	}
	catch (string exception) {
		cout << "Error : Invalid i	nput\n";
		this->mode_ = 0;
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
		cin >> input_text;
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

void MainMenu::Insert(StudentList student_list)
{
	Insertion s(student_list);
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
			if (s.get_sort_mode_() == 5) { // 5. back
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
			if (s.get_search_mode_() == 6) { // 6. back
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

