#include "student_info_management.h"

Student::Student(string name, string student_id, string dept, string birth_year, string tel) {
    // 입력 받았을 때 생성자
    this->name = name;
    this->student_id = student_id;
    this->dept = dept;
    this->birth_year = birth_year;
    this->tel = tel;
}