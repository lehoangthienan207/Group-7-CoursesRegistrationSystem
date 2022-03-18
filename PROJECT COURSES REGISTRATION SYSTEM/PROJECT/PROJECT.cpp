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
void CreateCourses(Courses*& pHead, Courses *&pCurr)
{
    Courses *pCurr = pHead;
    if (pHead == nullptr)
    {
        pHead = new Courses; 
        cout << "Input course's ID: ";
        cin >> pHead->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin,pHead->CourseName);
        cout << "Input session: ";
        cin.ignore();
        getline(cin,pHead->session);
        cout << "Input maximum: "; //maximum??
        cin >> pHead->Maximum;
        cout << "Input Number of credits: ";
        cin >> pHead->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pHead->TeacherName);
        cout << "Input number of days: ";
        cin >> pHead->Day;
        pCurr = pHead->pNext; //Needed a variable to store the pTail of the linked list
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
