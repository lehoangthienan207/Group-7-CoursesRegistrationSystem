#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
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
	int SocialID{};
	string classID{};
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
	string session{};
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
void PrintStudentListInCourse(Students* pHead);
void InputScoreBoard(ScoreBoardOfCourse*& pHead);
void PrintScoreBoard(ScoreBoardOfCourse* pHead);

//Main function (Mostly menu functions)
int menuOfGeneral(int type);


//https://stackoverflow.com/questions/48495724/naming-an-output-file-from-a-user-entered-string
//THe link above contains info about how to output a specific name and file type.

void doSomething(int menuOfGeneral,int type,SignIn *&pHead);

