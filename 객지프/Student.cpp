#include "student_info_management.h"

Student::Student(string name, string student_id, string dept, string birth_year, string tel) {
    // �Է� �޾��� �� ������
    this->name = name;
    this->student_id = student_id;
    this->dept = dept;
    this->birth_year = birth_year;
    this->tel = tel;
}