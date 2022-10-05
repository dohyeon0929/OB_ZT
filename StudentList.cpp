#include"student_info_management.h"
bool DefaultCompare(Student a, Student b) { //정렬 1순위 : 이름, 정렬 2순위 : 학번 
    if (a.get_name() != b.get_name()) return a.get_name() < b.get_name();
    else return a.get_student_id() < b.get_student_id();
}
//1. 문자열 파싱
vector<string> StudentList::Split(string str, char Delimiter) {
	istringstream iss(str);             // istringstream에 str 담기
	string buffer;                      // 구분자를 기준, 절삭된 문자열 담는 버퍼

	vector<string> readline;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		readline.push_back(buffer);               // 절삭된 문자열을 vector에 저장
	}
	return readline; //절삭된 문자열 리턴
}
//2. 학생 추가
void StudentList::StudentAdd(string name, string studentID,
	string dept, string birthYear, string tel, vector<Student>student_list)
{
	Student new_student(name, studentID, dept, birthYear, tel);
	student_list.push_back(new_student);  //vector의 맨 마지막에 student 객체 추가
	//sort(student_list.begin(), student_list.end(), DefaultCompare); // 기본 설정으로 정렬
	SaveList(student_list); //파일에 저장
}


//3. 파일 저장
void StudentList::SaveList(vector<Student>student_list)
{
	fstream file;
	file.open("file1.txt", ios::out | ios::trunc);
	for (int i = 0; i < student_list.size(); i++) //vector에 저장된 student 객체 값 입력
	{
		file << student_list[i].get_name() << ";" << student_list[i].get_student_id() << ";" << student_list[i].get_dept() << ";"
			<< student_list[i].get_birth_year() << ";" << student_list[i].get_tel();
		file << "\n";
	}
	file.close();
}



StudentList::StudentList()
{
	string info[5]; //student 객체의 각 속성
	fstream file;
	string line; //파일의 한 줄 저장
	file.open("file1.txt", ios::in);
	if (file.is_open())
	{
		while (getline(file, line))//파일에서 한 줄 씩 읽어올 떄마다
		{
			vector<string> readline = Split(line, ';'); //readline에 문장 파싱 값 저장
			for (int i = 0; i < readline.size(); i++)//readline의 원소 개수만큼
			{
				if (readline[i] == "")
				{
					readline[i] = "~";
				}
				info[i] = readline[i]; //student 객체 파라미터에 들어갈 값 배열에 저장
			}
			Student result(info[0], info[1], info[2], info[3], info[4]); //객체 생성

			this->student_info_list_.push_back(result); //vector에 넣어주기
		}
		sort(this->student_info_list_.begin(), this->student_info_list_.end(), DefaultCompare);
		file.close();
	}
	else //파일 없으면
	{
		ofstream open("file1.txt"); //파일 생성
		cout << "file created" << "\n";
	}

	SaveList(student_info_list_); //생성된 객체 벡터 값 파일에 저장
	return;
}