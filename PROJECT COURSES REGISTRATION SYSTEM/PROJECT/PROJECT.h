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
#include <stdlib.h>
#include <queue>
using namespace std;
bool scoreboardCheck = false;
bool importStudent = false;
bool publishcheck = false;
struct SignIn;
struct DoB;
struct Students;
struct Classes;
struct ScoreBoardOfCourse;
struct ScoreBoardOfStudent;
struct Courses;
struct Semester;
struct ScoreOfStudentInBoard;
struct Score;
struct StudentScoreInClass;
bool checkremove = false;
//int checkImport[100];
struct SignIn {
	string ID{};
	string Password{};
	string Name{};
	string LastName{};
	string FirstName{};
	string SocialID{};
	string Email{};
	string DoB{};
	string Gender{};
	string Class{};
	Courses *pCStudent = nullptr;
	Courses *pCStudent2 = nullptr;
	Courses *pCStudent3 = nullptr;
	SignIn* pNext{};
	int numberofCourse = 0;
	int numberofCourse2= 0;
	int numberofCourse3 =0;
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
	float gpa{};
	Score *point = nullptr;
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
	string CourseID{};
	string CourseName{};
	ScoreOfStudentInBoard *pStudent = nullptr;
	ScoreBoardOfCourse* pNext{};
};

struct ScoreOfStudentInBoard{
	int No{};
	int StudentID{};
	string FirstName;
	string LastName; 
	string DateOfBirth;
	float Midterm{};
	float Finalterm{};
	float OtherScore{};
	float Overall{};
	string classID{};
	ScoreOfStudentInBoard *next = nullptr;
};
struct ScoreBoardOfStudent {
	string StudentName{};
	ScoreBoardOfCourse* pHead = nullptr;
	ScoreBoardOfStudent* pNext{};
};
struct Score{
	string CourseName{};
	float overall{};
	Score *next;
};
struct StudentScoreInClass{
	
	string Class{};
	
	Students *pStudent = nullptr;
	StudentScoreInClass *next;

};
struct Courses {
	int semester;
	int No{};
	string CourseID{};
	string CourseName{};
	char weekday1[4];//c??i n??y l?? th??? h???c ti???t 1, s???a c??c c??i char[] th??nh char[+1]v?? c???n ????? ch???a \0
	char time1[6];//th???i gian h???c ti???t 1
	char weekday2[4]; //th??? h???c ti???t 2
	char time2[6]; //th???i gian ti???t 2
	int Maximum{};
	int Credits{};
	string TeacherName{};
	Students *pStudent = nullptr;
	ScoreOfStudentInBoard *pScore = nullptr;
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

struct SchoolYear{
	string years{};
	Classes *pClass = nullptr;
	Semester *pSemester = nullptr;
	SchoolYear *pNext{};
	StudentScoreInClass *pScore = nullptr;
};
SignIn *pStudentEnroll = nullptr;
SignIn *pStudentTemp = nullptr;
SignIn *pCurrentStaff = nullptr;
Semester *pCurrentSemester = nullptr;
DoB currentDateAndTime;
DoB currentSemesterstart;
DoB currentSemesterend;

// General
//void ChooseTypeOfUser(int& type);
void GeneralMenu(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
//void SignUp(SignIn*& pHead);
void LogInStaff(SignIn* pHead);
void LogInStudent(SignIn* pHead);// Nhi: Long ??i ch??? n??y ??ng qu??n th??m bi???n trong h??m nha.
void ChangePassword(string& Password);
void LogOut(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
//void ViewProfie(Students* pHead);// h??m m???i ????? in th??ng tin h???c sinh nha.
// Staff
/*void CreateSchoolYear(int& Year);*/ //Nhi: tui comment c??i n??y l???i nha, t???i n?? b??? tr??ng h??m r???i.
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
void PrintStudentListInCourse(Courses *pHead,SignIn *pStudent);
//Input scoreboard n??y tui th???y m??nh input trong h??m main c??ng ???????c nha
void InputScoreBoard(ScoreBoardOfCourse*& pHead);
void PrintScoreBoard(ScoreBoardOfCourse* pHead);
void MenuOfStaff(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
void PrintScoreBoardOfClass(ScoreBoardOfCourse* pHead);
void UpdateStudentResult(ScoreBoardOfCourse*& pHead);

// Th??: sao c?? nhi???u h??m student ??? ????y b??? m???t v???y m???i ng?????i? tui nh??? l?? l???n tr?????c m???i add v?? :<
// Student // tui add l???i ??? ????y, ?????ng x??a n???a nhen :<
bool MaximumStudentEnrollInCourse(Courses*& pHead, Courses*& pStudents, int& number);
bool DuplicatedSession(Courses*& pHead, Courses*& pStudents, int& number);
void EnrollCourses(Courses* pHead, Courses*& pStudents, int limit, int& number);
void PrintEnrolledCourses(Courses* pHead);
void RemoveEnrolledCourses(Courses*& pHead);
//void PrintScoreBoardOfStudents(ScoreBoardOfStudent*& pHead);
void MenuOfStudent(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr);
bool checkCourses(Courses *pStudents, Courses *pC);
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
void deleteScoreBoard(ScoreBoardOfCourse *&pBoard, ScoreBoardOfStudent *&pStudent);
// input
void InputStudent(Students *& pHead, ifstream &studentInput);
void inputSignInStaff(SignIn *&pHead);
void inputSignInStudent(SignIn *&pHead);
// output
void foutCourses(SchoolYear *pHead);
void foutSignInStudent(SignIn *pHead);
void foutSignInStaff(SignIn *pHead);
void foutSchoolYear(SchoolYear *pHead);
void foutClasses(SchoolYear*pHead);
void foutSemester(SchoolYear*pHead);
void foutEnrolled(SchoolYear *pHead,SignIn *pStudent);
void foutCurrentSemester(SchoolYear *pHead);

//readfile
void readSchoolYearList(SchoolYear *&pHead,SchoolYear *&pCurr);
//void readClassListAndStudent(SchoolYear *pHead);
void readClassList(SchoolYear *pHead);
void readEnrolled(SchoolYear *pHead,SignIn *pStudent);
bool checkCourses(Courses *pStudents, Courses *pC);
void readSemesterList(SchoolYear *pHead);
void readCurrentSemester(SchoolYear *pHead);
void readCourses(SchoolYear *pHead);
bool readfile();
void checkDate();
void ExportStudentInCourse(SignIn* pStudent, SchoolYear *pHead);
//void importScoreBoardOfACourse(SchoolYear *pHead,Courses *pCourseD);
void importScoreBoardOfCourse(SchoolYear *pHead, Courses*pCourse);
void deleteScoreOfStudentInBoard(SchoolYear*pHead);
void createScoreBoardOfStudentInClass(SchoolYear *pHead);
void printScoreOfStudentInClass(SchoolYear *pHead, Classes *pClass);
void deleteScoreOfStudentInClass(SchoolYear *pHead);
void printScoreBoardStudent(SchoolYear *pHead);