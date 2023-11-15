#include "header.h"

group::group(){
    numb = 0;
    gpa = 0;
    count = 0;
    subjects = new std::string[count];
    students = new list<student>();
    std::cout << "Group parametrs set\n";
}

group::group(int numb_, float gpa_, int count_, std::string *subjects_, list<student>* students_){
    numb = numb_;
    count = count_;
    gpa = gpa_;
    subjects = subjects_;
    students = students_;
    std::cout << "Group parametrs set\n";
}

group::group(group& obj){
    numb = obj.numb;
    gpa = obj.gpa;
    count = obj.count;
    subjects = obj.subjects;
    students = obj.students;
    std::cout << "Group parametrs copied\n";
}

group::~group(){
    delete [] subjects;
    delete students;
}

void group::set_numb(int _numb){
    numb = _numb;
}

void group::set_count(int _count){
    count = _count;
}

void group::set_subjects(std::string* _subjects){
    subjects = _subjects;
}

int group::get_numb(){
    return numb;
}

int group::get_count(){
    return count;
}

float group::get_gpa(){
    return gpa;
}

std::string* group::get_subjects(){
    return subjects;
}

void group::set(){
    std::cout << "Enter values:\n";
    std::cout << "Number of group: ";
    std::cin >> numb;
    std::cout << "Number of subjects: ";
    std::cin >> count;
    subjects = new std::string[count];
    std::cout << "Subjects: ";
    for(int i = 0; i < count; i++){
        std::cin >> subjects[i];
    }
    std:: cout << std::endl;
}

void group::get(){
    std::cout << "Group " << numb << "\n";
    std::cout << "Subjects: ";
    for(int i = 0; i < count; i++){
        std::cout << subjects[i] << " ";
    }
    std::cout << "\n";
    std::cout << "GPA: " << gpa << "\n";
    std::cout << "\n";
}