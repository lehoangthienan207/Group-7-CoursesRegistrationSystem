#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

//fstream input, output;
//Hải: nếu không nhất thiết phải dùng thì đừng dùng biến toàn cục

struct SignIn {
	int ID{};
	string Password{};
	SignIn* pNext{};
};
struct DoB {
	int day{};
	int month{};
	int year{};
};
struct Students
{
	int No{};
	int StudentID{};
	string classID{};
	int SocialID{};
	string Name{};
	int Gender;
	DoB DateOfBirth{};
	Students* pNext{};
};
struct Classes {
	string Name{};
	int NumberOfStudents{};
	Students* pHead{};
	Classes* pNext{};
};

struct ScoreBoardOfCourse {
	string CourseID{};
	string CourseName{};
	int No{};
	int StudentID{};
	string StudentName;
	float Midterm{};
	float Finalterm{};
	float OtherScore{};
	float Overall{};
	int Semester{};
	int Year{};
	ScoreBoardOfCourse* pNext{};
};
struct ScoreBoardOfStudent {
	string StudentName{};
	ScoreBoardOfCourse* pHead{};
	ScoreBoardOfStudent* pNext{};
};
struct Courses {
	string CourseID{};
	string CourseName{};
	char session[4];
	int Maximum{};
	int Credits{};
	string TeacherName{};
	char Day[3];
	Courses* pNext{};
};

// General
void ChooseTypeOfUser(int& type);
void SignUp(SignIn*& pHead);
void LogIn(SignIn*& pHead);
void LogInCredentials(fstream& input);
void ChangePassword(string& Password);

// Staff
void CreateSchoolYear(int& Year);
void CreateSemester(int& Semester);
void CreateClasses(Classes* pHead);

// Newly added function
//void CreateCourses(Courses*& pHead);
void CreateCourses(Courses*& pHead, Courses *&pCurr);
void UpdateCourses(Courses*& pHead);
void RemoveCourses(Courses*& pHead);
void PrintCoursesList(Courses* pHead);
void PrintClassesList(Classes* pHead);

void InputStudent(Classes*& pHead);
void PrintStudentsListInClass(Students* pHead);
void PrintStudentListInCourse(Students* pHead, Courses*pH);
void InputScoreBoard(ScoreBoardOfCourse*& pHead);
void PrintScoreBoard(ScoreBoardOfCourse* pHead);

// Thư: sao có nhiều hàm student ở đây bị mất vậy mọi người? tui nhớ là lần trước mới add vô :<
// Student // tui add lại ở đây, đừng xóa nữa nhen :<
void EnrollCourses(Courses*& pHead, Courses*& pStudents);
void PrintEnrolledCourses(Courses* pHead);
void RemoveEnrolledCourses(Courses*& pHead);
void PrintScoreBoardOfStudents(ScoreBoardOfStudent*& pHead);