#include "student_info_management.h"

int main() {
    // �׽�Ʈ�� 
    vector<Student> v = { {"Chris Brown", "20191234", "Math", "2000","01012345678"},//�����δ� StudentList���� �޾� �� ����. 
    {"Jarvan 4","20221758", "~", "~", "~"},
    {"Kimdohyeon", "20213428","Capstone Design 2", "2002", "01042770929" } };

    MainMenu m;
    m.Search(v);
    return 0;
}

// ����ٰ��� ������ �ϸ� �ɱ��?
// main menu class ���⼭
// ��Ʃ��Ʈ Ŭ���� ������, ��Ʃ��Ʈ ����Ʈ, ���θ޴� Ŭ����, �� ���� ���α׷�  