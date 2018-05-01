class Course{
	public:
		Course();
		bool setCourseName();
		string getCourseName();
		string getClassID();
		students[*] getStudents();
		instructor[*] getInstructors():
	private:
		string ID;
		string name;
		student[*] students;
		instructor[*] instructors;
}

class Student{
public:
	Student();
	bool setStudentName();
	double gpa();
	string getStudentID();
private:
	string ID;
	string name;
	double gpa();
	Course[*] courses();
}	

class Instructor{
public:
	Instructor();
	bool setInstructorName();
	string getInstructorName():
	bool newCourse(const& Course c);
	bool assignGrade(Student S, char grade);
	bool modifyGrade(Student s, char grade);
private:
	string ID;
	string name;
	Course[*] courses;
	Student[*] students;
}