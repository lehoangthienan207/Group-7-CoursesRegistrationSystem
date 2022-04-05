#include "PROJECT.h"
//#include <string>





void CreateCourses(Courses*& pHead, Courses*& pCurr, int &i)
{
    if (pHead == nullptr)
    {
        pHead = new Courses;
        pHead->No = i;
        cout << "Input course's ID: ";
        cin >> pHead->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pHead->CourseName);
        cout << "Input session: ";
        cin.ignore();
        cin.getline(pHead->time1,5);
        cout << "Input maximum number of students (Default: 50): "; //maximum?? // Thư: là số lượng học sinh tối đa có thể đăng ký (default là 50)
        string maximum="";
        cin.ignore();
        getline(cin,maximum);
        if (!maximum.empty())
            pHead->Maximum = stoi(maximum);
        else pHead->Maximum = 50;
        cout << "Input Number of credits: ";
        cin >> pHead->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pHead->TeacherName);
        cout << "Input number of days: ";
        cin >> pHead->Day;
        ++i;
        pCurr = pHead; //Needed a variable to store the pTail of the linked list
    }
    else
    {
        pCurr->pNext = new Courses;
        pCurr = pCurr->pNext;
        pCurr->No = i;
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pCurr->CourseName);
        cout << "Input session: ";
        cin.ignore();
        cin.getline(pCurr->time1,5);
        cout << "Input maximum number of students (Default: 50): ";
        string maximum ="";
        cin.ignore();
        getline(cin,maximum);
        if (!maximum.empty())
            pCurr->Maximum = stoi(maximum);
        else pCurr->Maximum = 50;
        cout << "Input Number of credits: ";
        cin >> pCurr->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pCurr->TeacherName);
        cout << "Input number of days: ";
        cin >> pCurr->Day;
        ++i;
        pCurr->pNext = nullptr;
    }
}
void PrintCoursesList(Courses* pHead)
{
    Courses* pCurr = pHead;
    while (pCurr != nullptr)
    {
        cout << pCurr->No << "         ";
        cout << pCurr->CourseID << "         ";
        cout << pCurr->CourseName << "         ";
        cout << pCurr->time1 << "         ";
        cout << pCurr->Maximum << "         ";
        cout << pCurr->Credits << "         ";

        
        //cout << pCurr->startDate.day << "         ";
        //cout << pCurr->endDate << "         ";
        cout << pCurr->TeacherName << "         ";
        cout << pCurr->Day << "         ";
        pCurr = pCurr->pNext;
        cout << "\n";
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
        cin.getline(pCurr->time1,5);
        cout << "Input maximum number of students (Default: 50): ";
        string maximum ="";
        cin.ignore();
        getline(cin,maximum);
        if (!maximum.empty())
            pCurr->Maximum = stoi(maximum);
        else pCurr->Maximum = 50;
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


//Long: thêm giúp mình cái pTail trong thông tin đăng nhập nha
//để chương trình biết khi nào phải dừng í
void LogIn(SignIn*& pHead, SignIn*& pTail)
{
    bool status = true;
    int id_input;
    string psw_input;
    while (status)
    {
        cout << "Input ID: "; cin >> id_input;
        cout << "Input password: "; cin >> psw_input;
        SignIn* pCurr = pHead;
        while (pCurr != pTail)
        {
            if (id_input == pCurr -> ID && psw_input == pCurr -> Password)
            {
                cout << "Sign-in successful" << endl;
                status = false;
                continue;
            }
            else
            {
                pCurr = pCurr -> pNext;
                continue;
            }
        }
        if (status)
            cout << "Login failed" << endl;
    }
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
    //logout thì quay về login chứ đâu có exit
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
void PrintClassesList(Classes* pHead)
{
    Classes* pCurr = pHead;
    while (pCurr != pHead)
    {
        cout << pCurr->No << setw(10);
        cout << pCurr->Name << setw(10);
        cout << pCurr->NumberOfStudents << setw(10);
        cout << "\n";
        pCurr = pCurr->pNext;
    }
}
void CreateSchoolYear(SchoolYear *&pHead, SchoolYear *&pCurr)
{
    if (pHead == nullptr)
    {
        pHead = new SchoolYear;
        cout << "Input school year (example: 2020-2021): ";
        cin >> pHead->years;
        Classes *pCurrY = pHead->pClass;
        int i = 1;
        while (true)
        {
            CreateClasses(pHead->pClass,pCurrY,i);
            cout << "Continue? (Yes: y, No: n): ";
            char check;
            cin >> check;
            if (check != 'y')
                break;
        } 
        //pCurrY = pHead->pClass;
        cout << "Input classID you want to add student: ";
        PrintClassesList(pHead->pClass);
        while (true)
        {
            int x;
            cin >> x;
            Classes *pTemp = pHead->pClass;
            while (pTemp != nullptr && pTemp->No != x) pTemp = pTemp->pNext;
            if (pTemp != nullptr)
            {
                ifstream studentInClass(pTemp->Name + "." + "csv");
                InputStudent(pTemp->pStudent,studentInClass);
            }
            else
                cout << "No class found.";
            cout << "Continue? (Yes: y, No: n): ";
            char check;
            cin >> check;
            if (check != 'y')
                break;
        }
        pHead->pNext = nullptr;
        pCurr = pHead;
    }
    else
    {
        pCurr->pNext = new SchoolYear;
        pCurr = pCurr->pNext;
        cout << "Input school year (example: 2020-2021): ";
        cin >> pCurr->years;
        Classes *pCurrY = pCurr->pClass;
        int i = 1;
        while (true)
        {
            CreateClasses(pCurr->pClass,pCurrY,i);
            cout << "Continue? (Yes: y, No: n): ";
            char check;
            cin >> check;
            if (check != 'y')
                break;
        } 
        //pCurrY = pCurr->pClass;
        cout << "Input classID you want to add student: ";
        PrintClassesList(pCurr->pClass);
        while (true)
        {
            int x;
            cin >> x;
            Classes *pTemp = pCurr->pClass;
            while (pTemp != nullptr && pTemp->No != x) pTemp = pTemp->pNext;
            if (pTemp != nullptr)
            {
                ifstream studentInClass(pTemp->Name + "." + "csv");
                InputStudent(pTemp->pStudent,studentInClass);
            }
            else
                cout << "No class found.";
            cout << "Continue? (Yes: y, No: n): ";
            char check;
            cin >> check;
            if (check != 'y')
                break;
        }
        pCurr->pNext = nullptr;
    }
}
//Long: Có vẻ như là cần thêm biến Semester vào struct ScoreBoardOfCourse //Thư: Okay tui thêm nha
void CreateSemester(SchoolYear *pHead)
{
    int x;
    cout << "Input semester number: ";
    cin >> x;
    
    SchoolYear *pCurr = pHead;
    char check = 'n';
    while (true)
    {
        cout << "Input school year this semester belong to (Example: 2020-2021): ";
        string s;
        cin >> s;
        while (pCurr != nullptr && pCurr->years != s) pCurr=pCurr->pNext;
        if (pCurr != nullptr)
        {
            pCurr->pSemester->No = x;
            break;
        }
        else
        {
            cout << "No school year found.";
            cout << "\nTry Again? (Yes: y, No: n): ";
            cin >> check;
            if (check != 'y')
                break;
        }
    }
    if (check == 'y')
        return;
    
    
}
//Long:tạo lớp học mới bằng stack, khi đó truy cập vào những lớp mới sẽ nhanh hơn. // Thư: theo tui thấy cách mình đang là Stack á.
//Long: chỗ để tên lớp nằm ở đâu nhỉ // Thư: ý Long là sao ha? tui chưa hiểu lắm...
void CreateClasses(Classes*& pHead, Classes*& pCurr, int &i)
{
    if (pHead == nullptr)
    {
        pHead = new Classes;
        pHead->No = i;
        cout << "Input class name: ";
        cin >> pHead->Name;
        cout << "Input the number of students: ";
        cin >> pHead -> NumberOfStudents;
        pHead->pNext = nullptr;
        pCurr = pHead;
        ++i; //Needed a variable to store the pTail of the linked list
    }
    else
    {
        pCurr->pNext = new Classes;
        pCurr = pCurr->pNext;
        pCurr->No = i;
        cout << "Input class name: ";
        cin >> pCurr->Name;
        cout << "Input the number of : ";
        cin >> pCurr -> NumberOfStudents;
        pCurr->pNext = nullptr;
        ++i;
    }
}

void InputStudent(Students *& pHead, ifstream &studentInput)
{
    Students *pCurr = pHead;
    if (pHead == nullptr)
    {
        pHead = new Students;
        studentInput >> pHead->No >> pHead->StudentID;
        studentInput.ignore();
        getline(studentInput,pHead->FirstName);
        studentInput.ignore();
        getline(studentInput,pHead->LastName);
        studentInput.ignore();
        getline(studentInput,pHead->Gender);
        studentInput >> pHead->DateOfBirth.day >> pHead->DateOfBirth.month >>pHead->DateOfBirth.year;
        studentInput >> pHead->SocialID;
        pHead->pNext = nullptr;
        pCurr = pHead;
    }
    else
    {
        pCurr->pNext = new Students;
        pCurr = pCurr->pNext;
        studentInput >> pCurr->No >> pCurr->StudentID;
        studentInput.ignore();
        getline(studentInput,pCurr->FirstName);
        studentInput.ignore();
        getline(studentInput,pCurr->LastName);
        studentInput.ignore();
        getline(studentInput,pCurr->Gender);
        studentInput >> pCurr->DateOfBirth.day >> pCurr->DateOfBirth.month >>pCurr->DateOfBirth.year;
        studentInput >> pCurr->SocialID;
        pCurr->pNext = nullptr;
    }
}

void PrintStudentsListInClass(Students* pHead)
{
    string name;
    cout << "Enter name of class: ";
    cin.ignore();
    getline(cin, name);
    ifstream input;
    input.open(name.c_str());
    while (!input.eof()) {
        input >> pHead->No >> pHead->StudentID >> pHead->SocialID >> pHead->FirstName >> pHead->LastName >> pHead->Gender >> pHead->DateOfBirth.day >> pHead->DateOfBirth.month >> pHead->DateOfBirth.year;
    }
    Students* pCur = pHead;
    cout << "\n\t\t--------------------------LIST OF STUDENTS IN ClASS " << name << "--------------------------\n\n";
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "StudentID";
    cout << setw(17) << left << "SocialID";
    cout << setw(25) << left << "LastName";
    cout << setw(20) << left << "FirstName";
    cout << setw(15) << left << "Gender";
    cout << setw(15) << left << "DateofBirth";
    cout << endl;
    while (pCur)
    {
        cout << setw(5) << left << pCur->No;
        cout << setw(15) << left << pCur->StudentID;
        cout << setw(17) << left << pCur->SocialID;
        cout << setw(25) << left << pCur->LastName;
        cout << setw(20) << left << pCur->FirstName;
        cout << setw(15) << left << pCur->Gender;
        cout << setw(0) << left << pCur->DateOfBirth.day << "/" << pCur->DateOfBirth.month << "/" << pCur->DateOfBirth.year;
        cout << endl;
        pCur = pCur->pNext;
    }

}

void PrintStudentListInCourse(Students* pHead, Courses* pH) {
    string Coursesname = "";
    cout << "Enter the name of courses: ";
    cin.ignore();
    getline(cin, Coursesname);
    Students* pCur = pHead;
    cout << "\n\t\t--------------------------LIST OF STUDENTS IN COURSE--------------------------\n\n";
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "StudentID";
    cout << setw(17) << left << "SocialID";
    cout << setw(25) << left << "LastName";
    cout << setw(20) << left << "FirstName";
    cout << setw(15) << left << "Gender";
    cout << setw(15) << left << "DateofBirth";
    cout << endl;
    while (pCur)
    {
        if (Coursesname == pH->CourseName)
        {
            cout << setw(5) << left << pCur->No;
            cout << setw(15) << left << pCur->StudentID;
            cout << setw(17) << left << pCur->SocialID;
            cout << setw(25) << left << pCur->FirstName;
            cout << setw(20) << left << pCur->LastName;
            cout << setw(15) << left << pCur->Gender;
            cout << setw(0) << left << pCur->DateOfBirth.day << "/" << pCur->DateOfBirth.month << "/" << pCur->DateOfBirth.year;
            cout << endl;
            pCur = pCur->pNext;
        }
        else
        {
            cout << "This course does not exist.\n";
            //cout << "Please re-enter the course name: ";
            //cin.ignore();
            //getline(cin, Coursesname);
        }
    }
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
                cin.ignore();
                getline(cin, pStudents->CourseID);
                cout << "Please input the day of week to study this course (Ex: MON, TUE, WED) " << i + 1 << ": ";
                cin.ignore();
                cin.getline(pStudents->Day, 3);
                cout << "Please input the session of day to study this course (Ex: 07h30, 13h30) " << i + 1 << ": ";
                cin.ignore();
                cin.getline(pStudents->time1, 5);
                pStudents->pNext = nullptr;
                pCur = pStudents;
                Courses* pPrev = pHead;
                while (pCurrent != nullptr)
                {
                    if (pStudents->CourseID == pCurrent->CourseID && pStudents->Day == pCurrent->Day && pStudents->time1 == pCurrent->time1)
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
                cin.getline(pCur->time1, 5);
                pCur->pNext = nullptr;
                Courses* pPrev = pHead;
                while (pCurrent != nullptr)
                {
                    if (pCur->CourseID == pCurrent->CourseID && pCur->Day == pCurrent->Day && pCur->time1 == pCurrent->time1)
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
        cout << setw(15) << right << pCur->time1;
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
void PrintScoreBoard(ScoreBoardOfCourse* pHead)
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
    ScoreBoardOfCourse* pCur = pHead;
    while (pCur != nullptr)
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
            if (pCur->CourseID == ID && pCur->Day == DAY && pCur->time1 == session)
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
int MenuOfStudent()
{
    int n = 0;
    cout << "*************************************" << endl;
    cout << "*        1. Enroll in Courses       *" << endl;
    cout << "*        2. Remove Courses          *" << endl;
    cout << "*        3. View list of Courses    *" << endl;
    cout << "*        4. View Scoreboard         *" << endl;
    cout << "*************************************" << endl;
    cout << endl << "Your choice: "; cin >> n;
    return n;
}
int typeOfUser()
{
    cout << "----------------------------------------\n";
    cout << "----------------LOGIN-------------------\n";
    cout << "      Please choose type of user \n";
    cout << "          1. Staff \n";
    cout << "          2. Student \n";
    cout << "          99. Exit \n";
    cout << "----------------------------------------\n";
    cout << "----------------------------------------\n";
    cout << "          Your input: ";
    int a;
    cin >> a;
    return a;
}


//clear scr function
void clrscr(){
    cout << "\033[2J\033[1;1H";
}

void deleteClasses(Classes *&pHead)
{
    while(pHead != nullptr)
    {
        Classes *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}

void deleteStudents(Students *&pHead)
{
    while(pHead != nullptr)
    {
        Students *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteSignIn(SignIn *&pHead)
{
    while(pHead != nullptr)
    {
        SignIn *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteCourses(Courses *&pHead)
{
    while(pHead != nullptr)
    {
        Courses *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteScoreBoardOfCourse(ScoreBoardOfCourse *&pHead)
{
    while(pHead != nullptr)
    {
        ScoreBoardOfCourse *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteScoreBoardOfStudent(ScoreBoardOfStudent *&pHead)
{
    while(pHead != nullptr)
    {
        ScoreBoardOfStudent *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}

void foutSchoolYear(SchoolYear *pHead)
{
    ofstream fout;
    fout.open("schoolYearList.txt");
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        fout << pCurr->years;
        fout <<"\n";
    }
}
void foutClasses(SchoolYear*pHead)
{
    ofstream fout;
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        fout.open(pCurr->years+ "classes" + ".txt");
        
        Classes *pTemp = pCurr->pClass;
        while (pTemp != nullptr)
        {
            fout << pTemp->Name << " " << pTemp->No << " " << pTemp->NumberOfStudents << " ";
            pTemp = pTemp->pNext;
        }
        //fout << "\n";
        pCurr = pCurr->pNext;
    }
}
//chỗ này cần output ra classes list của từng năm học và cái tên cụ thể để có thể input khi đọc chương trình.
//cần thêm 1 phần output ra semester school year với tên tương tự

void foutSemester(SchoolYear*pHead)
{
    ofstream fout;
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        fout.open(pCurr->years +"semester" + ".txt");
        Semester *pTemp = pCurr->pSemester;
        while (pTemp != nullptr)
        {
            fout << pTemp->No << " " << pTemp->startDate.day <<  pTemp->startDate.month << " " << pTemp->startDate.year << " " << pTemp->endDate.day << " " << pTemp->endDate.month << " " << pTemp->endDate.year;
            fout << '\n';
            pTemp = pTemp->pNext;
        }
        pCurr = pCurr->pNext;
    }
}

void inputSignInStaff(SignIn *&pHead)
{
    ifstream input;
    input.open("staff.csv");
    SignIn *pCurr = pHead;
    while(!input.eof())
    {
        if (pHead == nullptr)
        {
            pHead = new SignIn;
            input >> pHead->ID >> pHead->Password;
            pHead->pNext = nullptr;
            pCurr = pHead;
        }
        else
        {
            pCurr->pNext = new SignIn;
            pCurr = pCurr->pNext;
            input >> pCurr->ID >> pCurr->Password;
            pCurr->pNext = nullptr;
        }   
    }
}
void inputSignInStudent(SignIn *&pHead)
{
    ifstream input;
    input.open("student.csv"); //chỗ này có thể thay đổi : ví dụ là thay bằng 21CLC09.csv
    SignIn *pCurr = pHead;
    while(!input.eof())
    {
        if (pHead == nullptr)
        {
            pHead = new SignIn;
            input >> pHead->ID >> pHead->Password;
            pHead->pNext = nullptr;
            pCurr = pHead;
        }
        else
        {
            pCurr->pNext = new SignIn;
            pCurr = pCurr->pNext;
            input >> pCurr->ID >> pCurr->Password;
            pCurr->pNext = nullptr;
        }   
    }
}

bool isEmpty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}
void readFilesBeforeLogin(Classes *&pHClasses)
{
    //mở file txt chứa tên các lớp
    ifstream classInput("listOfClasses.txt");
    Classes *pCClasses = pHClasses;
    if (!classInput && !isEmpty(classInput))
    {
        while (!classInput.eof())
        {

            if (pHClasses == nullptr)
            {   //tạo các lớp và nhập tên các lớp vào
                pHClasses = new Classes;
                classInput.ignore();
                getline(classInput,pHClasses->Name);
                ifstream studentInput(pHClasses->Name + "." + "csv");

                // nhập số học sinh
                classInput >> pHClasses->NumberOfStudents;
                InputStudent(pHClasses->pStudent,studentInput);
                pHClasses->pNext = nullptr;
                pCClasses = pHClasses;
            }
            else
            {   //tạo các lớp và nhập tên các lớp vào
                pCClasses->pNext = new Classes;
                pCClasses = pCClasses->pNext;
                classInput.ignore();
                getline(classInput,pCClasses->Name);
                ifstream studentInput(pCClasses->Name + "." + "csv");

                // nhập số học sinh
                classInput >> pCClasses->NumberOfStudents;
                InputStudent(pCClasses->pStudent,studentInput);
                pCClasses->pNext = nullptr;
            }
        }
    }
}



void readSchoolYearlist(SchoolYear *&pHead)
{
    ifstream input("schoolYearList.txt");
    if (!input && !isEmpty(input))
    {
        SchoolYear *pCurr = pHead;
        while(!input.eof())
        {
            if(pHead == nullptr)
            {
                pHead = new SchoolYear;
                input >> pHead->years;
                pHead->pClass = nullptr;
                pHead->pSemester = nullptr;
                pHead->pNext = nullptr;
                pCurr = pHead;
            }
            else
            {
                pCurr->pNext = new SchoolYear;
                pCurr = pCurr->pNext;
                input >> pCurr->years;
                pCurr->pClass = nullptr;
                pCurr->pSemester = nullptr;
                pCurr->pNext = nullptr;
            }
        }
    }
}
void readClassListAndStudent(SchoolYear *pHead)
{
    SchoolYear *pCurr = pHead;
    while (pCurr!= nullptr)
    {
        ifstream input;
        input.open(pCurr->years +"classes.txt");
        while (!input.eof())
        {
            Classes* pTemp = pCurr->pClass;
            string a = "";
            input >> a;
            ifstream classInput;
            classInput.open(a+".csv");
            while(!classInput.eof())
            {
                if (pCurr->pClass == nullptr)
                {
                    pCurr->pClass = new Classes;
                    pCurr->pClass->Name = a;
                    input >> pCurr->pClass->No;
                    input >> pCurr->pClass->NumberOfStudents;
                    pCurr->pClass->pStudent = new Students;
                    classInput >> pCurr->pClass->pStudent->No >> pCurr->pClass->pStudent->StudentID >> pCurr->pClass->pStudent->LastName >> pCurr->pClass->pStudent->LastName;
                    //DOB;
                    classInput >> pCurr->pClass->pStudent->SocialID >> pCurr->pClass->pStudent->Gender;
                    pCurr->pClass->pStudent->pNext =nullptr;
                    pCurr->pClass->pNext = nullptr;
                    pTemp = pCurr->pClass;
                }
                else
                {
                    pTemp->pNext = new Classes;
                    pTemp = pTemp->pNext;
                    pTemp->Name = a;
                    input >> pTemp->No;
                    input >> pTemp->NumberOfStudents;
                    pTemp->pStudent = new Students;
                    classInput >> pTemp->pStudent->No >> pTemp->pStudent->StudentID >> pTemp->pStudent->LastName >> pTemp->pStudent->LastName;
                    //DOB;
                    classInput >> pTemp->pStudent->SocialID >> pTemp->pStudent->Gender;
                    pTemp->pStudent->pNext =nullptr;
                    pTemp->pNext = nullptr;
                }
            }
        }
    }
}
//phần bên trên chưa xong
