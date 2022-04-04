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
	string FirstName{};
	string LastName{};
	string Gender{};
	DoB DateOfBirth{};
	int SocialID{}; 
	Students* pNext{};
};
struct Classes{
	int No{};
	string Name{};
	int NumberOfStudents{};
	Students* pStudent{};
	Classes* pNext{};
};

struct ScoreBoardOfCourse {
	int No{};
	string CourseID{};
	string CourseName{};
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
	int No{};
	DoB startDate{};
	DoB endDate{};
	string CourseID{};
	string CourseName{};
	//
	char time1[5];
	int Maximum{};
	int Credits{};
	string TeacherName{};
	char Day[3];
	Courses* pNext{};
};
struct Semester
{
	int No{};
	DoB startDate{};
	DoB endDate{};
	Semester *pNext;
};
struct SchoolYear{
	string years{};
	Classes *pClass{};
	Semester *pSemester{};
	SchoolYear *pNext{};
};
// General
void ChooseTypeOfUser(int& type);
void SignUp(SignIn*& pHead);
void LogIn(SignIn*& pHead);
void LogInCredentials(fstream& input);
void ChangePassword(string& Password);
void LogOut();

// Staff
void CreateSchoolYear(int& Year);
void CreateSchoolYear(SchoolYear *&pHead, SchoolYear *&pCurr);
void CreateClasses(Classes* pHead);

// Newly added function
//void CreateCourses(Courses*& pHead);
void CreateCourses(Courses*& pHead, Courses *&pCurr);
void UpdateCourses(Courses*& pHead);
void RemoveCourses(Courses*& pHead);
void PrintCoursesList(Courses* pHead);
void PrintClassesList(Classes* pHead);

void InputStudent(Students *& pHead, ifstream &studentInput);
void PrintStudentsListInClass(Students* pHead);
void PrintStudentListInCourse(Students* pHead, Courses*pH);
//Input scoreboard này tui thấy mình input trong hàm main cũng được nha
void InputScoreBoard(ScoreBoardOfCourse*& pHead);
void PrintScoreBoard(ScoreBoardOfCourse* pHead);

// Thư: sao có nhiều hàm student ở đây bị mất vậy mọi người? tui nhớ là lần trước mới add vô :<
// Student // tui add lại ở đây, đừng xóa nữa nhen :<
void EnrollCourses(Courses*& pHead, Courses*& pStudents);
void PrintEnrolledCourses(Courses* pHead);
void RemoveEnrolledCourses(Courses*& pHead);
void PrintScoreBoardOfStudents(ScoreBoardOfStudent*& pHead);
int MenuOfStudent();

// clear screen
void clrscr();

// delete function
void deleteClasses(Classes *&pHead);
void deleteStudents(Students *&pHead);
void deleteSignIn(SignIn *&pHead);
void deleteCourses(Courses *&pHead);
void deleteScoreBoardOfCourse(ScoreBoardOfCourse *&pHead);
void deleteScoreBoardOfStudent(ScoreBoardOfStudent *&pHead);
