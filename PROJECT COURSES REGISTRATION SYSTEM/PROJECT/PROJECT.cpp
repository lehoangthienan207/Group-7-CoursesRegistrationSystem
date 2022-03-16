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