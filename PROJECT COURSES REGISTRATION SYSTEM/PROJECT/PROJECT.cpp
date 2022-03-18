#include "PROJECT.h"
//#include <string>
void PrintCoursesList(Courses* pHead)
{
    Courses *pCurr = pHead;
    while (pCurr != nullptr)
    {
        cout << pCurr->CourseID << "\n";
        cout << pCurr->CourseName << "\n";
        cout << pCurr->session << "\n";
        cout << pCurr->Maximum << "\n";
        cout << pCurr->Credits << "\n";
        cout << pCurr->TeacherName << "\n";
        cout << pCurr->Day << "\n";
        pCurr = pCurr->pNext;
    }
}
void CreateCourses(Courses*& pHead)
{
    Courses *pCurr = pHead;
    while (true)
    {
        if (pHead == nullptr)
        {
            pHead = new Courses;
            
        }
    }
}

void LogInCredentials(fstream& input, SignIn)
{
    
}

void LogIn(SignIn* pHead, fstream& input)
{
    
}

void ChangePassword(string& Password)
{

}

void LogOut()
{

}

void InputStudent(Classes*& pHead)
{
    
}

void PrintStudentsListInClass(Students* pHead)
{
    string name;
    cout << "Enter name of class: "; getline(cin, name);
    ifstream input;
    input.open(name.c_str());
    while (!input.eof()) {
        input >> pHead->No >> pHead->StudentID >> pHead->SocialID >> pHead->Name >> pHead->Gender >> pHead->DateOfBirth.day >> pHead->DateOfBirth.month >> pHead->DateOfBirth.year;
    }
    Students* pCur = pHead;
    cout << "\tTHE LIST OF STUDENTS IN CLASS " << name << "\t";
    while (pCur)
    {
        cout << pCur->No << "   ";
        cout << pCur->StudentID << "   ";
        cout << pCur->SocialID << "   ";
        cout << pCur->Name << "   ";
        cout << pCur->Gender << "   ";
        cout << pCur->DateOfBirth.day << "/" << pCur->DateOfBirth.month << "/" << pCur->DateOfBirth.year << "\n";
        pCur = pCur->pNext;
    }

}


// Students

void EnrollCourses(Courses*& pHead, Courses*& pStudents)
{
	int n = 0;
	char opt = 'Y';
	do {
		PrintCoursesList(pHead);
		cout << "Please input the number of courses that you wanna pick: ";
		cin >> n;
		Courses* pCur = pStudents;
		Courses* pCurrent = pHead;
		for (int i = 0; i < n; i++)
		{
			if (pStudents == nullptr)
			{
				pStudents = new Courses;
				cout << "Please input the Course ID (Ex: MTH00005) " << i + 1 << ": ";
				getline(cin, pStudents->CourseID);
				cout << "Please input the day of week to study this course (Ex: MON, TUE, WED) " << i + 1 << ": ";
				cin.getline(pStudents->Day, 3);
				cout << "Please input the session of day to study this course (Ex: 07h30, 13h30) " << i + 1 << ": ";
				cin.getline(pStudents->session, 4);
				pStudents->pNext = nullptr;
				pCur = pStudents;
				Courses* pPrev = pHead;
				while (pCurrent != nullptr)
				{
					if (pStudents->CourseID == pCurrent->CourseID && pStudents->Day == pCurrent->Day && pStudents->session == pCurrent->session)
					{
						if (pCurrent->Maximum > 1)
							pCurrent->Maximum--;
						else {
							if (pCurrent == pHead)
							{
								pCurrent = pHead->pNext;
								delete pHead;
								pHead = pCurrent;
							}
							else {
								pPrev->pNext = pCurrent->pNext;
								delete pCurrent;
								pCurrent = pPrev->pNext;
							}
						}
					}
					pPrev = pCurrent;
					pCurrent = pCurrent->pNext;
				}
			}
			else {
				pCur->pNext = new Courses;
				pCur = pCur->pNext;
				cout << "Please input the Course ID (Ex: MTH00005) " << i + 1 << ": ";
				getline(cin, pCur->CourseID);
				cout << "Please input the day of week to study this course (Ex: MON, TUE, WED) " << i + 1 << ": ";
				cin.getline(pCur->Day, 3);
				cout << "Please input the session of day to study this course (Ex: 07h30, 13h30) " << i + 1 << ": ";
				cin.getline(pCur->session, 4);
				pCur->pNext = nullptr;
				Courses* pPrev = pHead;
				while (pCurrent != nullptr)
				{
					if (pCur->CourseID == pCurrent->CourseID && pCur->Day == pCurrent->Day && pCur->session == pCurrent->session)
					{
						if (pCurrent->Maximum > 1)
							pCurrent->Maximum--;
						else {
							if (pCurrent == pHead)
							{
								pCurrent = pHead->pNext;
								delete pHead;
								pHead = pCurrent;
							}
							else {
								pPrev->pNext = pCurrent->pNext;
								delete pCurrent;
								pCurrent = pPrev->pNext;
							}
						}
					}
					pPrev = pCurrent;
					pCurrent = pCurrent->pNext;
				}
			}

		}
		cout << "Do you wanna add more courses or view the list of the courses?" << endl;
		cout << "Input 'Y' if you wanna add courses and 'N' if you wanna view the list." << endl;
		cout << "Please choose: "; cin >> opt;
	} while (opt == 'Y' || opt == 'y');
	PrintCoursesList(pStudents);
}
