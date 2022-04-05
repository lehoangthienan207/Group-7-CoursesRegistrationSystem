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
    void LogIn(SignIn*& pHead)
    {
        bool status = true;
        string id_input;
        string psw_input;
        while (status)
        {
            cout << "Input ID: "; cin >> id_input;
            cout << "Input password: "; cin >> psw_input;
            SignIn* pCurr = pHead;
            while (pCurr != nullptr)
            {
                if (id_input == pCurr -> ID && psw_input == pCurr -> Password)
                {
                    cout << "Sign-in successful" << endl;
                    status = false;
                    break;
                }
                else
                {
                    pCurr = pCurr -> pNext;
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

void LogOut(SignIn *pStaff, SignIn* pStudent)
{ 
    clrscr();
    GeneralMenu(pStaff,pStudent);
}

void GeneralMenu(SignIn *pStaff, SignIn* pStudent)
{
    int choice;
    cout << "\n\t\t\t*****************LOGIN******************\n\n";
    cout << "\t\t      ********************************************\n";
    cout << "\t\t      *\t  1.Academic Staff\t *\n";
    cout << "\t\t      *\t  2.Students\t\t *\n";
    cout << "\t\t      *\t  3.Exit\t *\n";
    cout << "\t\t      ********************************************\n\n";
    cout << "\t\t\t\tYour Choice: "; 
    cin >> choice;
    cin.clear();
    cin.ignore(10000,'\n');
    if (choice == 1)
    {
        LogIn(pStaff);
        MenuOfStaff(pStaff,pStudent);
    }
    else if (choice == 2)
    {
        LogIn(pStudent);
        //MenuOfStudent();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        cout << "Error, please try again";
        GeneralMenu(pStaff,pStudent);
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
    int opt = 0;
    do {
        PrintCoursesList(pHead);
        cout << "Please input the number of courses that you wanna pick: ";
        cin >> n;
        Courses* pCur = pStudents;
        Courses* pCurrent = pHead;
        for (int i = 0; i < n; i++)
        {
            int no = 0;
            cout << "Your choice: "; cin >> no;
            if (pStudents == nullptr)
            {
                pStudents = new Courses;
                pStudents->No = no;
                pStudents->pNext = nullptr;
                pCur = pStudents;
                Courses* pPrev = pHead;
                while (pCurrent != nullptr)
                {
                    if (pStudents->No == pCurrent->No)
                    {
                        pStudents->CourseID = pCurrent->CourseID;
                        pStudents->CourseName = pCurrent->CourseName;
                        pStudents->Credits = pCurrent->Credits;
                        pStudents->Day = pCurrent->Day;
                        pStudents->time1 = pCurrent->time1;
                        pStudents->TeacherName = pCurrent->TeacherName;
                        if (pCurrent->Maximum > 1)
                            pCurrent->Maximum--;
                        else {
                            if (pCurrent == pHead)
                            {
                                pCurrent = pHead->pNext;
                                delete pHead;
                                pHead = pCurrent;
                                pPrev = pHead;
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
                pCur->No = no;
                pCur->pNext = nullptr;
                Courses* pPrev = pHead;
                while (pCurrent != nullptr)
                {
                    if (pCur->No = pCurrent->No)
                    {
                        pCur->CourseID = pCurrent->CourseID;
                        pCur->CourseName = pCurrent->CourseName;
                        pCur->Credits = pCurrent->Credits;
                        pCur->Day = pCurrent->Day;
                        pCur->time1 = pCurrent->time1;
                        pCur->TeacherName = pCurrent->TeacherName;
                        if (pCurrent->Maximum > 1)
                            pCurrent->Maximum--;
                        else {
                            if (pCurrent == pHead)
                            {
                                pCurrent = pHead->pNext;
                                delete pHead;
                                pHead = pCurrent;
                                pPrev = pHead;
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
        cout << "***************************************" << endl;
        cout << "*        1. Continue Enrolling        *" << endl;
        cout << "*        2. View List of Courses      *" << endl;
        cout << "*        3. Back to Menu              *" << endl;
        cout << "***************************************" << endl;
        cout << "Your choice: "; cin >> opt;
    } while (opt == 1);
    if (opt == 2) {
        clrscr();
        PrintCoursesList(pStudents);
    }
    else if (opt == 3) {
        clrscr();
        MenuOfStudent();
    }
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
void MenuOfStaff(SignIn *pStaff, SignIn* pStudent)
{
    
    string choose;

    int choice1;
    int choice2;
    string Password;
    SchoolYear* pHead;
    SchoolYear* pCurr;
    Classes* pClass;
    Courses* pHCourse;
    Courses* pCCourse;
    Students* pHStudent;
    ifstream studentInput;
    ScoreBoardOfCourse* pHScore;
    


back1:
    cout << "\n\t\t\t*****************STAFF******************\n\n";
    cout << "\t\t      ********************************************\n";
    cout << "\t\t      *\t\t    1.Change Password\t\t *\n";
    cout << "\t\t      *\t\t    2.My Classes\t\t *\n";
    cout << "\t\t      *\t\t    3.My Courses\t\t *\n";
    cout << "\t\t      *\t\t    4.About Students\t\t *\n";
    cout << "\t\t      *\t\t    5.Scoreboard\t\t *\n";
    cout << "\t\t      *\t\t    6.Log out\t\t\t *\n";
    cout << "\t\t      *\t\t    7.Back \t\t\t *\n";
    cout << "\t\t      ********************************************\n\n";
    cout << "\t\t\t\tYour Choice: "; cin >> choice1;
    clrscr();
    switch (choice1)
    {
    case 1: {
        ChangePassword(pStaff->Password);
        cout << "\n\nPassword change successfully\n\n";
        cout << "\nYou must login again.";
        GeneralMenu(pStaff, pStudent);
        break;
    }
    case 2: {
        cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t  1.Create schoolyear and semesters\t *\n";
        cout << "\t\t      *\t  2.Create all the classes\t\t *\n";
        cout << "\t\t      *\t  3.View the list of all classes\t *\n";
        cout << "\t\t      *\t  4.Back \t\t\t\t *\n";
        cout << "\t\t      ********************************************\n\n";
        cout << "\t\t\t\tYour Choice: "; cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
           // CreateSchoolYear(pHead, pCurr);
            //Create schoolyear and semester
            cout << "\n\nCreate successfully!\n\n";
            break;
        }
        case 2:
        {
            //CreateClasses(pClass);
            //Create all the classes
            cout << "\n\nCreate successfully!\n\n";
            break;
        }
        case 3:
        {
           // PrintClassesList(pClass);
            //View the list of all classes
            break;
        }
        case 4:
        {
            //back
            clrscr();

            goto back1;

            break;
        }
        default:
            cout << "Error.";
            break;
        }
        break;
    }
    case 3:
    {
    back2:
        cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t     1.Add a course to the list\t\t *\n";
        cout << "\t\t      *\t     2.Remove a course of the list\t *\n";
        cout << "\t\t      *\t     3.View the list of all courses\t *\n";
        cout << "\t\t      *\t     4.Back \t\t\t\t *\n";
        cout << "\t\t      ********************************************\n\n";
        cout << "\t\t\t\tYour choice: "; cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
        backcourse:
           // CreateCourses(pHCourse, pCCourse);
            //add course
            cout << "\nAdd a course successfully!\n";
            cout << "\nDo you want to add another course?(yes/no)\n\n";
            cin.ignore();
            getline(cin, choose);
            if (choose == "yes") {
                goto  backcourse;
            }
            else if (choose == "no") {
                goto back2;
            }
            break;
        }
        case 2:
        {
           // RemoveCourses(pHCourse);
            //remove course
            cout << "\nRemove a course successfully!\n";
            break;
        }
        case 3:
        {
            //PrintCoursesList(pHCourse);
            //View the list of all courses
           
            break;
        }
        case 4:
        {
            //back;
            clrscr();
            goto back1;
            break;
        }

        default:
            cout << "\n\nError!\n\n";
            break;
        }
        break;
    }
    case 4:
    {
        cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t1.Add students to a class\t\t *\n";
        cout << "\t\t      *\t2.View the list of students in a class   *\n";
        cout << "\t\t      *\t3.View the list of students in a courses *\n";
        cout << "\t\t      *\t4.Back \t\t\t\t         *\n";
        cout << "\t\t      ********************************************\n\n";
        cout << "\t\t\t\tYour choice: "; cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
           // InputStudent(pHStudent, studentInput);
            //add student in class
            cout << "\nAdd students successfully!\n";
            break;
        }
        case 2:
        {
           // PrintStudentsListInClass(pHStudent);
            //print student in class
            break;
        }
        case 3:
        {
            //PrintStudentListInCourse(pHStudent, pHCourse);
            //print student in course
            break;
        }
        case 4:
        {
            clrscr();
            goto back1;
            break;
        }
        default:
            cout << "\nError!\n";
            break;
        }
    }
    case 5: {
        cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t     1.Update scoreboard\t\t *\n";
        cout << "\t\t      *\t     2.View scoreboard of a course\t *\n";
        cout << "\t\t      *\t     3.Back \t\t\t\t *\n";
        cout << "\t\t      ********************************************\n\n";
        cout << "\t\t\t\tYour choice: "; cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
            //Nhi: chỗ này kh có hàm update scoreboard , xủ lí chỗ này sao ha?
            //update scoreboard
            cout << "\n\nScoreboard update successfully!\n";
            break;
        }
        case 2:
        {
            //PrintScoreBoard(pHScore);
            //View scoreboard of a course
            break;
        }
        case 3:
        {
            //back
            clrscr();
            goto back1;
            break;
        }
        default:
            cout << "\n\nError!\n\n";
            break;
        }
    }
    case 6: {
        //log out
        LogOut(pStaff,pStudent);
        break;
    }
    case 7:
    {
        // Nhi: chỗ này là back về cái giao diện menu của phần login
        /*goto back1;*/
        //back
        break;
    }
    default:
        cout << "\n\nError\n\n";
        break;
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
    cout << "*****************************************************" << endl;
    cout << "*                                                   *" << endl;
    cout << "*               1. Enroll in Courses                *" << endl;
    cout << "*               2. Remove Courses                   *" << endl;
    cout << "*               3. View list of Courses             *" << endl;
    cout << "*               4. View Scoreboard                  *" << endl;
    cout << "*               5. View Your Profile                *" << endl;
    cout << "*               6. Change Your Password             *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
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
void deleteSignIn(SignIn *&pHead)
{
    while (pHead !=nullptr)
    {
        SignIn *pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
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
    string key = "";
    getline(input,key);
    SignIn *pCurr = pHead;
    while(!input.eof())
    {
        if (pHead == nullptr)
        {
            pHead = new SignIn;
            getline(input,key,',');
            pHead->ID = key;
            getline(input,key,',');
            pHead->Password = key;
            getline(input,key,',');
            pHead->Name = key;
            getline(input,key);
            pHead->Email = key;
            pHead->pNext = nullptr;
            pCurr = pHead;
        }
        else
        {
            pCurr->pNext = new SignIn;
            pCurr = pCurr->pNext;
            getline(input,key,',');
            pCurr->ID = key;
            getline(input,key,',');
            pCurr->Password = key;
            getline(input,key,',');
            pCurr->Name = key;
            getline(input,key);
            pCurr->Email = key;
            pCurr->pNext = nullptr;
        }   
    }
}
void inputSignInStudent(SignIn *&pHead)
{
    ifstream input;
    input.open("student.csv"); //chỗ này có thể thay đổi : ví dụ là thay bằng 21CLC09.csv
    string key = "";
    getline(input,key); 
    SignIn *pCurr = pHead;
    while(!input.eof())
    {
        if (pHead == nullptr)
        {
            pHead = new SignIn;
            getline(input,key,',');
            pHead->ID = key;
            getline(input,key,',');
            pHead->Password = key;
            getline(input,key,',');
            pHead->Name = key;
            getline(input,key,',');
            pHead->SocialID = key;
            getline(input,key,',');
            pHead->DoB = key;
            getline(input,key);
            pHead->Gender = key;
            pHead->pNext = nullptr;
            pCurr = pHead;
            
        }
        else
        {
            pCurr->pNext = new SignIn;
            pCurr = pCurr->pNext;
            getline(input,key,',');
            pCurr->ID = key;
            getline(input,key,',');
            pCurr->Password = key;
            getline(input,key,',');
            pCurr->Name = key;
            getline(input,key,',');
            pCurr->SocialID = key;
            getline(input,key,',');
            pCurr->DoB = key;
            getline(input,key);
            pCurr->Gender = key;
            pCurr->pNext = nullptr;
        }   
    }
}

bool isEmpty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
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
        if(!input && !isEmpty(input))
        {while (!input.eof())
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
                    string DaT = "";
                    classInput >> DaT;
                    pCurr->pClass->pStudent->DateOfBirth.month = stoi(DaT.substr(0,2));
                    pCurr->pClass->pStudent->DateOfBirth.day = stoi(DaT.substr(3,2));
                    pCurr->pClass->pStudent->DateOfBirth.year = stoi(DaT.substr(6,4));
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
                    string DaT = "";
                    classInput >> DaT;
                    pTemp->pStudent->DateOfBirth.month = stoi(DaT.substr(0,2));
                    pTemp->pStudent->DateOfBirth.day = stoi(DaT.substr(3,2));
                    pTemp->pStudent->DateOfBirth.year = stoi(DaT.substr(6,4));
                    classInput >> pTemp->pStudent->SocialID >> pTemp->pStudent->Gender;
                    pTemp->pStudent->pNext =nullptr;
                    pTemp->pNext = nullptr;
                }
            }
            pTemp = pTemp->pNext;}
        }
        pCurr = pCurr->pNext;
    }
}

void readSemesterList(SchoolYear *pHead)
{
    SchoolYear *pCurr =pHead;
    while (pCurr != nullptr)
    {
        ifstream input;
        input.open(pCurr->years+"semester.txt");
        Semester *pTemp = pCurr->pSemester;
        if (!input && !isEmpty(input))
        {while (!input.eof())
        {
            if (pCurr->pSemester == nullptr)
            {
                pCurr->pSemester = new Semester;
                input >> pCurr->pSemester->No;
                input >> pCurr->pSemester->startDate.day;
                input >> pCurr->pSemester->startDate.month;
                input >> pCurr->pSemester->startDate.year;
                input >> pCurr->pSemester->endDate.day;
                input >> pCurr->pSemester->endDate.month;
                input >> pCurr->pSemester->endDate.year;
                pCurr->pSemester->pNext = nullptr;
                pTemp = pCurr->pSemester;
            }
            else
            {
                pTemp->pNext = new Semester;
                pTemp = pTemp->pNext;
                input >> pTemp->No;
                input >> pTemp->startDate.day;
                input >> pTemp->startDate.month;
                input >> pTemp->startDate.year;
                input >> pTemp->endDate.day;
                input >> pTemp->endDate.month;
                input >> pTemp->endDate.year;
                pTemp->pNext = nullptr;
            }
        }}
        pCurr =pCurr->pNext;
    }   
}


//phần bên trên chưa xong
