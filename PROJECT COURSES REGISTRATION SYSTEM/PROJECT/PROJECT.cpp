#include "PROJECT.h"
//#include <string>

void CreateCourses(Courses*& pHead, Courses *&pCurr)
{
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
        pCurr = pHead; //Needed a variable to store the pTail of the linked list
    }
    else
    {
        pCurr->pNext = new Courses;
        pCurr = pCurr->pNext;
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin,pCurr->CourseName);
        cout << "Input session: ";
        cin.ignore();
        getline(cin,pCurr->session);
        cout << "Input maximum: "; //maximum??
        cin >> pCurr->Maximum;
        cout << "Input Number of credits: ";
        cin >> pCurr->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pCurr->TeacherName);
        cout << "Input number of days: ";
        cin >> pCurr->Day;
        pCurr->pNext = nullptr;
    }
}
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
        cout << "---------------------------------\n";
    }
}
void UpdateCourses(Courses*& pHead)
{
    cout << "Input courseID you want to update";
    string a;
    cin >> a;
    Courses *pCurr = pHead;
    while (pCurr!= nullptr && pCurr->CourseID != a)
        pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin,pCurr->CourseName);
        cout << "Input session: ";
        cin.ignore();
        getline(cin,pCurr->session);
        cout << "Input maximum: "; //maximum??
        cin >> pCurr->Maximum;
        cout << "Input Number of credits: ";
        cin >> pCurr->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pCurr->TeacherName);
        cout << "Input number of days: ";
        cin >> pCurr->Day;
    }
    else
        cout << "No course found.";
}
void RemoveCourses(Courses*& pHead)
{
    string a;
    cout << "Input courseID you want to remove: ";
    cin >> a;
    if (pHead->CourseID == a)
    {
        Courses *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
        return;
    }
    else
    {
        Courses *pCurr = pHead;
        while (pCurr->pNext != nullptr && pCurr->pNext->CourseID != a)
            pCurr = pCurr->pNext;
        if (pCurr->pNext != nullptr)
        {
            Courses *pTemp = pCurr->pNext;
            pCurr->pNext = pCurr->pNext->pNext;
            delete pTemp;
            return;
        }
    }
    cout << "No course found.";
}
void PrintClassesList(Classes* pHead)
{
    Classes *pCurr = pHead;
    while (pCurr != pHead)
    {
        cout << pCurr->Name << "\n";
        cout << pCurr->NumberOfStudents << "\n";
        cout << "---------------------\n";
        pCurr = pCurr->pNext;
    }
    
}
void LogInCredentials(fstream& input, SignIn)
{
    //this is optional
}

void LogIn(SignIn* &pHead)
{
    
}

void ChangePassword(string& Password)
{
    //Hải: làm giúp luôn tại cái này ez =))
    string newPass = "";
    cout << "Input new password: ";
    cin >> newPass;
    Password = newPass;
}

void LogOut()
{

}
//Long:biến Year này thì sẽ ảnh hưởng gì đến các biến khác?
//Long: Tui coi không thấy khai báo biến "Year" trong file header í
void CreateSchoolYear(int& Year)
{

}
//Long: Có vẻ như là cần thêm biến Semester vào struct ScoreBoardOfCourse
void CreateSemester(int& Semester)
{

}
//Long:tạo lớp học mới bằng stack, khi đó truy cập vào những lớp mới sẽ nhanh hơn. 
//Long: chỗ để tên lớp nằm ở đâu nhỉ
void CreateClasses(Classes*& pHead)
{
    if (pHead == nullptr)
    {
        pHead = new Classes;
    }
    else 
    {

    }
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

int menuOfGeneral(int type)
{
    cout << "1. View profile info\n";
    cout << "2. Change password\n";
    if (type == 1)
    {
        // placeholder for future function
        // each type of user has different function except of general.
    }
    cout << "0. Log out\n";
    cout << "99. Exit the system\n";
  
    int a;
    do{
        cout << "Input what you want to do.\n";
        cin >> a;
        if (a != 1 || a!= 2 || a!= 0 || a != 99)
            cout << "Invalid input. Please try again.\n";
    }while(a != 1 || a!= 2 || a!= 0 || a!= 99);
    return a;
}

void doSomething(int menuOfGeneral, int type, SignIn *&pHead)
{
    if (menuOfGeneral == 1)
    {
        if (type = 1)
        {
           // if type of users is there, this will be implement later 
        }
    }
    else if (menuOfGeneral == 2)
    {
        ChangePassword(pHead->Password);
    }
    else if (true)
    {
        // placeholder for function of each type of users;
    }
}


/////////////////////////////////////////////////////////////
//these functions only exist if user input type of user
void showInformation(int type)
{

}
////////////////////////////////////////////////////////////
