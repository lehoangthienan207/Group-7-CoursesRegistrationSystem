#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <direct.h>
#include <cstdio>
#include <windows.h>
#include <stdio.h>
using namespace std;

bool publishcheck = false;
struct SignIn;
struct DoB;
struct Students;
struct Classes;
struct ScoreBoardOfCourse;
struct ScoreBoardOfStudent;
struct Courses;
struct Semester;

struct SignIn {
	string ID{};
	string Password{};
	string Name{};
	string SocialID{};
	string Email{};
	string DoB{};
	string Gender{};
	Courses *pCStudent = nullptr;
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
	string DateOfBirth{};
	int SocialID{}; 
	Students* pNext{};
};
struct Classes{
	int No{};
	string Name{};
	int NumberOfStudents{};
	Students* pStudent= nullptr;
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
	string classID{};
	ScoreBoardOfCourse* pNext{};
};
struct ScoreBoardOfStudent {
	string StudentName{};
	ScoreBoardOfCourse* pHead = nullptr;
	ScoreBoardOfStudent* pNext{};
};

struct Courses {
	int No{};
	string CourseID{};
	string CourseName{};
	char weekday1[4];//cái này là thứ học tiết 1, sửa các cái char[] thành char[+1]vì cần để chứa \0
	char time1[6];//thời gian học tiết 1
	char weekday2[4]; //thứ học tiết 2
	char time2[6]; //thời gian tiết 2
	int Maximum{};
	int Credits{};
	string TeacherName{};
	Students *pStudent = nullptr;
	Courses* pNext{};
};
struct Semester
{
	int No{};
	DoB startDate{};
	DoB endDate{};
	Courses *pCourse = nullptr;
	Semester *pNext;
};
SignIn *pStudentEnroll = nullptr;
Semester *pCurrentSemester = nullptr;
struct SchoolYear{
	string years{};
	Classes *pClass = nullptr;
	Semester *pSemester = nullptr;
	SchoolYear *pNext{};
};
// General
//void ChooseTypeOfUser(int& type);
void GeneralMenu(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
//void SignUp(SignIn*& pHead);
void LogIn(SignIn* pHead);// Nhi: Long ơi chỗ này ông quên thêm biến trong hàm nha.
void ChangePassword(string& Password);
void LogOut(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
void ViewProfie(Students* pHead);// hàm mới để in thông tin học sinh nha.
// Staff
/*void CreateSchoolYear(int& Year);*/ //Nhi: tui comment cái này lại nha, tại nó bị trùng hàm rồi.
void CreateSchoolYear(SchoolYear *&pHead, SchoolYear *&pCurr);
void CreateClasses(Classes*& pHead, Classes*& pCurr, int &i);
void CreateCourses(Courses*& pHead, int &i);

// Newly added function
//void CreateCourses(Courses*& pHead);
void CreateCourses(Courses*& pHead, Courses *&pCurr);
void UpdateCourses(Courses*& pHead);
void removeACourse(Courses *&pHead);
void PrintCoursesList(Courses* pHead);
void PrintClassesList(Classes* pHead);

void InputStudent(Students *& pHead, ifstream &studentInput);
void PrintStudentsListInClass(Students* pHead);
void PrintStudentListInCourse(Students* pHead, Courses*pH);
//Input scoreboard này tui thấy mình input trong hàm main cũng được nha
void InputScoreBoard(ScoreBoardOfCourse*& pHead);
void PrintScoreBoard(ScoreBoardOfCourse* pHead);
void MenuOfStaff(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
void PrintScoreBoardOfClass(ScoreBoardOfCourse* pHead);

// Thư: sao có nhiều hàm student ở đây bị mất vậy mọi người? tui nhớ là lần trước mới add vô :<
// Student // tui add lại ở đây, đừng xóa nữa nhen :<
bool DuplicatedSession(Courses*& pHead, Courses*& pStudents);
void EnrollCourses(Courses*& pHead, Courses*& pStudents, int limit);
void PrintEnrolledCourses(Courses* pHead);
void RemoveEnrolledCourses(Courses*& pHead);
void PrintScoreBoardOfStudents(ScoreBoardOfStudent*& pHead);
void MenuOfStudent(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);

// clear screen
void clrscr();

bool isEmpty(ifstream& pFile);
// delete function
void deleteSemester(Semester *&pHead);
void deleteSchoolYear(SchoolYear *&pHead);
void deleteClasses(Classes *&pHead);
void deleteStudents(Students *&pHead);
void deleteSignIn(SignIn *&pHead);
void deleteCourses(Courses *&pHead);
void deleteScoreBoardOfCourse(ScoreBoardOfCourse *&pHead);
void deleteScoreBoardOfStudent(ScoreBoardOfStudent *&pHead);
// input
void InputStudent(Students *& pHead, ifstream &studentInput);
void inputSignInStaff(SignIn *&pHead);
void inputSignInStudent(SignIn *&pHead);
// output
void foutSignInStudent(SignIn *pHead);
void foutSignInStaff(SignIn *pHead);
void foutSchoolYear(SchoolYear *pHead);
void foutClasses(SchoolYear*pHead);
void foutSemester(SchoolYear*pHead);

//readfile
void readSchoolYearlist(SchoolYear *&pHead);
void readClassListAndStudent(SchoolYear *pHead);
void readSemesterList(SchoolYear *pHead);