#include "header.h"

student::student(){
    name = "";
    size = 0;
    progress = new int[size];
    std::cout << "Student parametrs set\n";
}

student::student(std::string name_, int size_, int* progress_){
    name = name_;
    size = size_;
    progress = progress_;
    std::cout << "Student parametrs set\n";
}

student::student(student& obj){
    name = obj.name;
    size = obj.size;
    progress = obj.progress;
    std::cout << "Student parametrs copied";
}

student::~student(){
    delete [] progress;
}

void student::set_name(std::string _name){
    name = _name;
}

void student::set_size(int _size){
    size = _size;
}

void student::set_progress(int* _progress){
    progress = _progress;
}

std::string student::get_name(){
    return name;
}

int student::get_size(){
    return size;
}

int* student::get_progress(){
    return progress;
}

void student::set(){

    std::cout << "Enter values:\n";
    std::cout << "Students name: ";
    std::cin >> name;
    std::cout << "Enter grades: ";
    for (int i = 0; i < size; i++){
        std::cin >> progress[i];
    }
    std::cout << std::endl;
}

void student::get(){
    std::cout << "Student " << name << "\n";
    std::cout << "Grades ";
    for (int i = 0; i < size; i++){
        std::cout << progress[i] << " ";
    }
    std::cout << "\n";
}