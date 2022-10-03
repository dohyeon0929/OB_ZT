#include"student_info_management.h"

using namespace std;

void main_menu::Start() //시작화면, setMode메소드 호출함
{
	Student_list list;
	list.get_student_list();
	while (1)
	{
		cout << "1. Insertion" << endl;
		cout << "2. Search" << endl;
		cout << "3. Sorting Option" << endl;
		cout << "4. Exit" << endl;
		cin >> select;
		SetMode(select);
		switch (set_mode)
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
		}
	}
}

void main_menu::SetMode(int select)
{
	set_mode = select;
	return;
}

void main_menu::Insertion(vector<Student>student_list)
{
	//Insertion();
	return;
}

void main_menu::Sort(vector<Student>student_list)
{
	Sorting s(student_list);
	s.Display();
	s.set_mode(s.Input());
	s.Sort();
	s.Print();
}

void main_menu::Search(vector<Student>student_list)
{

}

void main_menu::Exit()
{
	exit(0);
}

