#include "PROJECT.h"
//#include <string>

void CreateCourses(Courses*& pHead, Courses*& pCurr)
{
    if (pHead == nullptr)
    {
        pHead = new Courses;
        cout << "Input course's ID: ";
        cin >> pHead->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pHead->CourseName);
        cout << "Input session: ";
        cin.ignore();
        cin.getline(pHead->session,4);
        cout << "Input maximum: "; //maximum?? // Thư: là số lượng học sinh tối đa có thể đăng ký (default là 50)
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
        getline(cin, pCurr->CourseName);
        cout << "Input session: ";
        cin.ignore();
        cin.getline(pCurr->session,4);
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
    Courses* pCurr = pHead;
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
    Courses* pCurr = pHead;
    while (pCurr != nullptr && pCurr->CourseID != a)
        pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pCurr->CourseName);
        cout << "Input session: ";
        cin.ignore();
        cin.getline(pCurr->session,4);
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
        Courses* pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
        return;
    }
    else
    {
        Courses* pCurr = pHead;
        while (pCurr->pNext != nullptr && pCurr->pNext->CourseID != a)
            pCurr = pCurr->pNext;
        if (pCurr->pNext != nullptr)
        {
            Courses* pTemp = pCurr->pNext;
            pCurr->pNext = pCurr->pNext->pNext;
            delete pTemp;
            return;
        }
    }
    cout << "No course found.";
}
void PrintClassesList(Classes* pHead)
{
    Classes* pCurr = pHead;
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

void LogIn(SignIn*& pHead)
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
    int temp;
    bool fact = true;
    while (fact)
    {
        cout << "Are you sure you want to logout?" << endl;
        cout << "If yes, press 1; press 0 to cancel: ";
        cin >> temp; 
        switch(temp)
        {
            case 1:
                exit(0);
            case 0:
                break;
            default:
            {                
                cout << "I don't understand...";
                break;
            }
        }
    }
}
//Long:biến Year này thì sẽ ảnh hưởng gì đến các biến khác?
//Long: Tui coi không thấy khai báo biến "Year" trong file header í
void CreateSchoolYear(int& Year)
{
    
}
//Long: Có vẻ như là cần thêm biến Semester vào struct ScoreBoardOfCourse //Thư: Okay tui thêm nha
void CreateSemester(int& Semester)
{

}
//Long:tạo lớp học mới bằng stack, khi đó truy cập vào những lớp mới sẽ nhanh hơn. // Thư: theo tui thấy cách mình đang là Stack á.
//Long: chỗ để tên lớp nằm ở đâu nhỉ // Thư: ý Long là sao ha? tui chưa hiểu lắm...
void CreateClasses(Classes*& pHead, Classes*& pCurr)
{
    if (pHead == nullptr)
    {
        pHead = new Classes;
        cout << "Input new class name: ";
        cin >> pHead->Name;
        cout << "Input the number of students: ";
        cin >> pHead -> NumberOfStudents;
        pCurr = pHead; //Needed a variable to store the pTail of the linked list
    }
    else
    {
        pCurr->pNext = new Classes;
        pCurr = pCurr->pNext;
        cout << "Input new class name: ";
        cin >> pCurr->Name;
        cout << "Input the number of : ";
        cin >> pCurr -> NumberOfStudents;
        pCurr->pNext = nullptr;
    }
}

void InputStudent(Classes*& pHead)
{

}

void PrintStudentsListInClass(Students* pHead)
{
    // cin.ignore() trước getline nha
    string name;
    cout << "Enter name of class: "; 
    cin.ignore();
    getline(cin, name);
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

void PrintStudentListInCourse(Students* pHead, Courses* pH) {
    string Coursesname = "";
    cout << "Enter the name of courses: ";
    cin.ignore();
    getline(cin, Coursesname);
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
            cin.ignore();
            getline(cin, Coursesname);
        }
    }
}
void PrintScoreBoard(ScoreBoardOfCourse* pHead)
{
    ScoreBoardOfCourse* pCur = pHead;
    while (pCur)
    {
        cout << pCur->CourseID << " ";
        cout << pCur->CourseName << " ";
        cout << pCur->No << " ";
        cout << pCur->StudentID << " ";
        cout << pCur->StudentName << " ";
        cout << pCur->Midterm << " ";
        cout << pCur->Finalterm << " ";
        cout << pCur->OtherScore << " ";
        cout << pCur->Overall << " ";
        cout << pCur->Semester << " ";
        cout << pCur->Year << " ";
    }
    cout << endl;
}
    // Students

void EnrollCourses(Courses * &pHead, Courses * &pStudents)
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
                cin.ignore();
                cin.getline(pCur->Day, 3);
                cout << "Please input the session of day to study this course (Ex: 07h30, 13h30) " << i + 1 << ": ";
                cin.ignore();
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
void PrintEnrolledCourses(Courses* pHead)
{
    cout << setw(15) << left << "Course ID";
    cout << setw(20) << left << "Course Name";
    cout << setw(10) << left << "Credit";
    cout << setw(5) << right << "Day";
    cout << setw(15) << right << "Session";
    cout << setw(20) << right << "Teacher";
    cout << endl;
    cout << setfill('-') << setw(85) << '-';
    cout << endl;
    Courses* pCur = pHead;
    while (pCur != nullptr)
    {
        cout << setw(15) << left << pCur->CourseID;
        cout << setw(20) << left << pCur->CourseName;
        cout << setw(10) << left << pCur->Credits;
        cout << setw(5) << right << pCur->Day;
        cout << setw(15) << right << pCur->session;
        cout << setw(20) << right << pCur->TeacherName;
        cout << endl;
        pCur = pCur->pNext;
    }
}
void PrintScoreBoardOfStudents(ScoreBoardOfStudent*& pHead)
{
    int year;
    int semester;
    cout << "Please enter the Year: "; cin >> year;
    cout << "Please enter the Semester: "; cin >> semester;
    cout << setw(15) << left << "Course ID";
    cout << setw(20) << left << "Course Name";
    cout << setw(12) << left << "Midterm";
    cout << setw(12) << right << "Finalterm";
    cout << setw(12) << right << "Other Score";
    cout << setw(12) << right << "Overall";
    cout << endl;
    cout << setfill('-') << setw(83) << '-';
    cout << endl;
    ScoreBoardOfCourse* pCur = pHead->pHead;
    while (pCur != nullptr )
    {
        if (pCur->Year == year && pCur->Semester == semester)
        {
            cout << setw(15) << left << pCur->CourseID;
            cout << setw(20) << left << pCur->CourseName;
            cout << setw(12) << left << pCur->Midterm;
            cout << setw(12) << right << pCur->Finalterm;
            cout << setw(12) << right << pCur->OtherScore;
            cout << setw(12) << right << pCur->Overall;
            cout << endl;
        }
        pCur = pCur->pNext;
    }
}
void RemoveEnrolledCourses(Courses*& pHead)
{
    string ID;
    char* DAY = new char[3];
    char* session = new char[5];
    char opt = 'N';
    do {
        cout << "Please input the ID of the course that you wanna remove: "; getline(cin, ID);
        cout << "Please input the DAY of the course that you wanna remove: "; cin.getline(DAY, 3);
        cout << "Please input the session of the course that you wanna remove: "; cin.getline(session, 5);
        Courses* pCur = pHead;
        Courses* pPrev = pCur;
        while (pCur != nullptr)
        {
            if (pCur->CourseID == ID && pCur->Day == DAY && pCur->session == session)
            {
                if (pCur == pHead)
                {
                    Courses* pTemp = pHead;
                    pHead = pHead->pNext;
                    delete pTemp;
                }
                else {
                    pPrev->pNext = pCur->pNext;
                    delete pCur;
                    pCur = pPrev->pNext;
                }
            }
            else {
                pPrev = pCur;
                pCur = pCur->pNext;
            }
        }
        cout << "Do you wanna remove more courses or you wanna print your all enrolled courses?" << endl;
        cout << "Please enter 'Y' if you wanna remove more and 'N' if you wanna print courses" << endl;
        cout << "Please enter here: "; cin >> opt;
    } while (opt == 'Y' || opt == 'y');
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
    do {
        cout << "Input what you want to do.\n";
        cin >> a;
        if (a != 1 || a != 2 || a != 0 || a != 99)
            cout << "Invalid input. Please try again.\n";
    } while (a != 1 || a != 2 || a != 0 || a != 99);
    return a;
}

void doSomething(int menuOfGeneral, int type, SignIn*& pHead)
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
