#include "header.h"

group::group(){
    numb = 0;
    gpa = 0;
    count = 0;
    subjects = new std::string[count];
    std::cout << "Group parametrs set\n";
}

group::group(int numb_, float gpa_, int count_, std::string *subjects_){
    numb = numb_;
    count = count_;
    gpa = gpa_;
    subjects = subjects_;
    std::cout << "Group parametrs set\n";
}

group::group(group& obj){
    numb = obj.numb;
    gpa = obj.gpa;
    count = obj.count;
    subjects = obj.subjects;
}

group::~group(){
    delete [] subjects;
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
    std::cout << "Subjects: ";
    for(int i = 0; i < count; i++){
        std::cin >> subjects[i];
    }
    std:: cout << std::endl;
}