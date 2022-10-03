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
	catch(string exception){
		cout << "Error : Invalid input\n";
		this->mode_ = 0;
	}
}
void MainMenu::Start() //시작화면, setMode메소드 호출함
{
	StudentList list;
	while (1)
	{
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
			Insertion(list.get_student_list());
			break;
		case 2:
			Search(list.get_student_list());
			break;
		case 3:
			Sort(list.get_student_list());
			break;
		case 4:
			Exit();
			break;
		default:
			break;
		}
	}
}

void MainMenu::Insertion(vector<Student>student_list)
{
	//Insertion();
	return;
}

void MainMenu::Sort(vector<Student>student_list)
{
	Sorting s(student_list);
	while (true) {
		s.Display();
		if (s.Input()) {
			if (s.get_mode() == 5) { // 5. back
				break;
			}
			else {
				s.Sort();
				s.Print();
				break;
			}
		}
	}
}

void MainMenu::Search(vector<Student>student_list)
{
	Searching s(student_list);
	while (true) {
		s.Display();
		if (s.Input()) {
			if (s.get_mode() == 6) { // 5. back
				break;
			}
			else {
				s.Search();
				s.Print();
				break;
			}
		}
	}
}

void MainMenu::Exit()
{
	exit(0);
}

