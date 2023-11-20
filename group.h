#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Keeper.h"
#include "Student.h"

class group {
private:
	int number;
	std::vector<std::string> subjects;
	int GPA;
	std::vector<Student> students;
	//Keeper<Student>* students;
public:
	group();
	~group();
	group(group& g);
	void getData();
	void setData();
	void editStudent(const int index);

	void setNumber(int& a) {
		number = a;
	}

	void setSubjects(std::vector<std::string>& a) {
		subjects = a;
	}

	void setGPA(int& a) {
		GPA = a;
	}

	int& get_numb() {
		return number;
	}

	std::vector<std::string>& getSubjects() {
		return subjects;
	}

	int& getGPA() {
		return GPA;
	}
};
