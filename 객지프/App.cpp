#include "student_info_management.h"

int main() {
    // 테스트용 
    vector<Student> v = { {"Chris Brown", "20191234", "Math", "2000","01012345678"},//실제로는 StudentList에서 받아 올 예정. 
    {"Jarvan 4","20221758", "~", "~", "~"},
    {"Kimdohyeon", "20213428","Capstone Design 2", "2002", "01042770929" } };

    MainMenu m;
    m.Search(v);
    return 0;
}

// 여기다가는 무엇을 하면 될까요?
// main menu class 여기서
// 스튜던트 클래스 마무리, 스튜던트 리스트, 메인메뉴 클래스, 앱 메인 프로그램  