#include "student_info_management.h"
int main() {
    // Sorting �׽�Ʈ�� 
    vector<Student> v = { {"Chris Brown", "20191234", "Math", "2000","01012345678"},//�����δ� StudentList���� �޾� �� ����. 
        {"Jarvan 4","20221758", "~", "~", "~"},
        {"Kimdohyeon", "20213428","Capstone Design 2", "2002", "01042770929" } };
    Sorting s(v);
    s.Display();
    s.set_mode(s.Input());
    s.Sort();
    s.Print();
    return 0;
}