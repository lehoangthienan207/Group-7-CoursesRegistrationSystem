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
    string name = "";
    cout << "Enter name of class: ";
    getline(cin, name);
    cin.ignore();
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

void PrintStudentListInCourse(Students* pHead, Courses*pH)
{
    string Coursesname = "";
    cout << "Enter the name of courses: ";
    getline(cin, Coursesname);
    cin.ignore();
    Students* pCur = pHead;
    while (pCur)
    {
        if (Coursesname == pH->CourseName)
        {
            cout << pCur->No << "   ";
            cout << pCur->StudentID << "   ";
            cout << pCur->SocialID << "   ";
            cout << pCur->Name << "   ";
            cout << pCur->Gender << "   ";
            cout << pCur->DateOfBirth.day << "/" << pCur->DateOfBirth.month << "/" << pCur->DateOfBirth.year << "\n";
            pCur = pCur->pNext;
        }
        else
        {
            cout << "This course does not exist.\n";
            cout << "Please re-enter the course name: ";
            getline(cin, Coursesname);
            cin.ignore();
        }
    }
    
}

void InputScoreBoard(ScoreBoardOfCourse*& pHead)
{

}
