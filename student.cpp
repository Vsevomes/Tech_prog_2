#include "student.h"
#include "group.h"

Student::Student() {
#ifdef DEBUG
	std::cout << "Constructor Student\n";
#endif // DEBUG	
	FIO = "";
	assesments;
    GPA_local = 0.0;
}

Student::~Student() {
	assesments.clear();
#ifdef DEBUG
	std::cout << "Destructor Student\n";
#endif // DEBUG	
}

void Student::setData() {
	std::cout << "FIO: ";
	std::cin >> this->FIO;
	std::cout << '\n';

	std::cout << "Assesments: ";
	std::cout << '\n';
	std::cout << "Count of marks to set: ";
	int cnt;
	int val;
	std::cin >> cnt;
	for (int i = 0; i < cnt;i++) {
		std::cout << "assesment #" << i << " = ";
		std::cin >> val;
		assesments.push_back(val);
	}
	std::cout << '\n';

    for(int i = 0; i < assesments.size(); i++){
        GPA_local += assesments[i];
    }
    GPA_local /= assesments.size() * 1.0;

}

void Student::getData() {
	std::cout << "Student\n";
	std::cout << "FIO \t:\t" << FIO << '\n';
	std::cout << "assesments \t:\t";
	int cnt = assesments.size();
	for (int i = 0; i < cnt; i++) {
		std::cout << assesments[i] << ' ';
	}
	std::cout << '\n';
}