#include "group.h"

group::group() {
#ifdef DEBUG
	std::cout << "Constructor group\n";
#endif // DEBUG	
	number = 0;
	GPA = 0.0;
	subjects;
	Student* st = new Student;
	students.push_back(*st);
	students.pop_back();
	delete st;
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
		std::cout << "subject #" << i + 1 << " = ";
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
}

void group::getData() {
	std::cout << "\nGroup number \t:\t" << number << '\n';
	std::cout << "subjects :\t";
	int cnt = subjects.size();
	for (int i = 0; i < cnt; i++) {
		std::cout << subjects[i] << ' ';
	}
	std::cout << '\n';
	count_GPA();
	std::cout << "GPA \t:\t" << GPA << '\n';
	std::cout << "\nStudents: ";
	cnt = students.size();
	for (int i = 0; i < cnt; i++) {
		students[i].getData();
	}
	std::cout << '\n';
}

void group::count_GPA(){
	GPA = 0;
	for (int i = 0; i < students.size(); i++){
		GPA += students[i].getGPA_local();
	}
	GPA /= students.size() * 1.0;
}

void group::addStudent(){
	Student* st;
	st = new Student;
	st->setData();
	students.push_back(*st);
}

void group::delStudent(const int ind){
	students.erase(students.begin() + ind - 1);
}

int group::empStudent(){
	return students.size();
}

void group::editStudent(const int index) {
	std::cout << "\nChange Data\n";
	Student* st;
	st = new Student;
	students.erase(students.begin() + index - 1);
	st->setData();
	students.insert(students.begin() + index - 1, *st);
}

int group::bestStud(){
	int flag = 0;
	for (int i = 0; i < students.size(); i++){
		if (students[i].getGPA_local() > 4){
			std::cout << "Group " << this->number << " - " << students[i].getFIO() << std::endl;
			flag = 1;
		}
	}
	return flag;
}