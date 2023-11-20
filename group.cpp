#include "group.h"

group::group() {
#ifdef DEBUG
	std::cout << "Constructor group\n";
#endif // DEBUG	
	number = 0;
	GPA = 0;
	subjects;
	students;
}

group::group(group& g) {
#ifdef DEBUG
	std::cout << "Constructor group\n";
#endif // DEBUG	
	number = g.number;
	GPA = g.GPA;
	subjects = g.subjects;
	students = g.students;
}

group::~group() {
	subjects.clear();
	students.clear();
#ifdef DEBUG
	std::cout << "Destructor \n";
#endif // DEBUG	
}

void group::setData() {

	std::cout << "number: ";
	std::cin >> this->number;
	std::cout << '\n';

	std::cout << "Subjects: ";
	std::cout << '\n';
	std::cout << "Count of subjects to set: ";
	int cnt;
	std::string str;
	std::cin >> cnt;
	for (int i = 0; i < cnt ;i++) {
		std::cout << "subject #" << i << " = ";
		std::cin >> str;
		subjects.push_back(str);
	}
	std::cout << '\n';

	std::cout << "Students: ";
	std::cout << '\n';
	std::cout << "Count of students to set: ";
	Student* st;
	std::cin >> cnt;
	for (int i = 0; i < cnt;i++) {
		st = new Student;
		st->setData();
		students.push_back(*st);
	}
	std::cout << '\n';

	std::cout << "GPA: ";

	std::cout << '\n';
}

void group::getData() {
	std::cout << "\nGroup\n";
	std::cout << "number \t:\t" << number << '\n';
	std::cout << "subjects :\t";
	int cnt = subjects.size();
	for (int i = 0;i < cnt;i++) {
		std::cout << subjects[i] << ' ';
	}
	std::cout << '\n';
	std::cout << "GPA \t:\t" << GPA << '\n';
	std::cout << "\nStudents: ";
	cnt = students.size();
	for (int i = 0;i < cnt;i++) {
		students[i].getData();
	}
	std::cout << '\n';
}