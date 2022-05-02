#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	//vì chỗ này yêu cầu kiểm tra 1 session có active hay không
	//nên để cho người dùng nhập thời gian để dễ demo hơn
	//để đổi thời gian thì quay về login
	

	SignIn *pStaff = nullptr;
	SignIn *pStaffCurr = nullptr;
	inputSignInStaff(pStaff);
	SignIn *pStudent = nullptr;
	SignIn *pStudentCurr = nullptr;
	SchoolYear *pHead = nullptr;
	SchoolYear *pCurr = pHead;
	ScoreBoardOfStudent *pScoreBoardStudent = nullptr;	
	ScoreBoardOfCourse *pScoreBoardCourse = nullptr;
	inputSignInStudent(pStudent);
	if (readfile())
	{
		readSchoolYearList(pHead,pCurr);
		readClassList(pHead);
		readSemesterList(pHead);
		readCourses(pHead);
		readCurrentSemester(pHead);
		//cout << "pCurrentSemester->No: " << pCurrentSemester->No << "\n";
		readEnrolled(pHead,pStudent);
	}
	GeneralMenu(pStaff,pStudent,pHead,pCurr);
	


	
	delete pCurrentSemester;
	delete pCurrentStaff;
	deleteScoreOfStudentInBoard(pHead);
	deleteCourses(pHead->pSemester->pCourse);
	deleteClasses(pHead->pClass);
	deleteSemester(pHead->pSemester);
	deleteSchoolYear(pHead);
	deleteSignIn(pStaff);
	deleteSignIn(pStudent);
	//deleteScoreBoard(pScoreBoardCourse,pScoreBoardStudent);
	return 0;
}