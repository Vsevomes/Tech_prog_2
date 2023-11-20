#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class Student {
private:
	std::string FIO;
	std::vector<int> assesments;
    float GPA_local;
	
public:
	Student();
	~Student();
	void getData();
	void setData();

	void setFIO(std::string& a) {
		FIO = a;
	}

	void setAssesment(std::vector<int>& a) {
		assesments = a;
	}

	std::string& getFIO() {
		return FIO;
	}

	std::vector<int>& getAssesment() {
		return assesments;
	}
};
