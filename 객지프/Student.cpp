#include "student_info_management.h"

Student::Student(string name_, string student_id_, string dept_, string birth_year_, string tel_) {
    // 입력 받았을 때 생성자
    this->name_ = name_;
    this->student_id_ = student_id_;
    this->dept_ = dept_;
    this->birth_year_ = birth_year_;
    this->tel_ = tel_;
}
