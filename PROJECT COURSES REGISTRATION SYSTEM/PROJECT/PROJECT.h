#pragma once

#include <string>
#include <iostream>
using namespace std;

struct SignIn {
	int StudentID{};
	string Password{};
	SignIn* pNext{};
};
struct Classes {
	int NumberOfStudents{};
	Students* pHead{};
	Classes* pNext{};
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
	string Name{};
	int Gender;
	DoB DateOfBirth{};
	Students* pNext{};
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
void ChangePassword(string& Password);

// Staff
void CreateSchoolYear(int& Year);
void CreateSemester(int& Semester);
void CreateClasses(Classes* pHead);

