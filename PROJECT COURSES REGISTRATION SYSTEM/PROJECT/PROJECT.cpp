#include "PROJECT.h"
//#include <string>
using namespace std;




void CreateCourses(Courses*& pHead, int &i)
{
    Courses *pCurr = pHead;
    if (pHead == nullptr)
    {
        pHead = new Courses;
        pHead->No = i;
        cout << "Input course's ID: ";
        cin >> pHead->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pHead->CourseName);
        cout << "Input weekday of session 1: ";
        cin.getline(pHead->weekday1,4);
        cout << "Input time of session 1: ";
        cin.getline(pHead->time1,6);
        cout << "Input weekday of session 2: ";
        cin.getline(pHead->weekday2,4);
        cout << "Input time of session 2: ";
        cin.getline(pHead->time2,6);
        cout << "Input maximum number of students (Default: 50): "; //maximum?? // Thư: là số lượng học sinh tối đa có thể đăng ký (default là 50)
        string input="";
        int maximum = 50;
        getline(cin,input);
        if (!input.empty()){
            istringstream stream(input);
            stream >> maximum;
        }
        pHead->Maximum = maximum;
        cout << "Input Number of credits: ";
        cin >> pHead->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pHead->TeacherName);
        ++i;
        pCurr = pHead;
        return; //Needed a variable to store the pTail of the linked list
    } 
    else
    {
        while (pCurr->pNext != nullptr) pCurr = pCurr->pNext;
        pCurr->pNext = new Courses;
        pCurr = pCurr->pNext;
        pCurr->No = i;
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pCurr->CourseName);
        cout << "Input weekday of session 1: ";
        cin.getline(pCurr->weekday1,4);
        cout << "Input time of session 1: ";
        cin.getline(pCurr->time1,6);
        cout << "Input weekday of session 2: ";
        cin.getline(pCurr->weekday2,4);
        cout << "Input time of session 2: ";
        cin.getline(pCurr->time2,6);
        cout << "Input maximum number of students (Default: 50): ";
        string input="";
        int maximum = 50;
        getline(cin,input);
        if (!input.empty()){
            istringstream stream(input);
            stream >> maximum;
        }
        pCurr->Maximum = maximum;
        cout << "Input Number of credits: ";
        cin >> pCurr->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pCurr->TeacherName);
        ++i;
        pCurr->pNext = nullptr;
    }
}
void PrintCoursesList(Courses* pHead)
{
    cout << setw(10) << left << "No";
    cout << setw(15) << left << "Course ID";
    cout << setw(20) << left << "Course Name";
    cout << setw(10) << left << "Credit";
    cout << setw(6) << right << "Day 1";
    cout << setw(15) << right << "Session 1";
    cout << setw(10) << right << "Day 2";
    cout << setw(15) << right << "Session 2";
    cout << setw(20) << right << "Teacher";
    cout << endl;
    cout << setfill('-') << setw(121) << '-';
    cout << endl;
    cout << setfill(' ');
    Courses* pCur = pHead;
    while (pCur != nullptr)
    {
        cout << setw(10) << left << pCur->No;
        cout << setw(15) << left << pCur->CourseID;
        cout << setw(20) << left << pCur->CourseName;
        cout << setw(12) << left << pCur->Credits;
        cout << setw(0) << right << pCur->weekday1[0] << pCur->weekday1[1] << pCur->weekday1[2];
        cout << setw(10) << right << pCur->time1[0] << pCur->time1[1] << pCur->time1[2] << pCur->time1[3] << pCur->time1[4];
        cout << setw(9) << right << pCur->weekday2[0] << pCur->weekday2[1] << pCur->weekday2[2];
        cout << setw(10) << right << pCur->time2[0] << pCur->time2[1] << pCur->time2[2] << pCur->time2[3] << pCur->time2[4];
        cout << setw(22) << right << pCur->TeacherName;
        cout << endl;
        pCur = pCur->pNext;
    }
}
void UpdateCourses(Courses*& pHead)
{
    
    cout << "Input number of course you want to update: ";
    int a;
    cin >> a;
    Courses* pCurr = pHead;
    while (pCurr != nullptr && pCurr->No != a)
        pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        cout << "Input course's ID: ";
        cin >> pCurr->CourseID;
        cout << "Input name of course: ";
        cin.ignore();
        getline(cin, pHead->CourseName);
        cout << "Input weekday of session 1: ";
        cin.getline(pHead->weekday1,4);
        cout << "Input time of session 1: ";
        cin.getline(pHead->time1,6);
        cout << "Input weekday of session 2: ";
        cin.getline(pHead->weekday2,4);
        cout << "Input time of session 2: ";
        cin.getline(pHead->time2,6);
        cout << "Input maximum number of students (Default: 50): "; //maximum?? // Thư: là số lượng học sinh tối đa có thể đăng ký (default là 50)
        string input="";
        int maximum = 50;
        getline(cin,input);
        if (!input.empty()){
            istringstream stream(input);
            stream >> maximum;
        }
        pHead->Maximum = maximum;
        cout << "Input Number of credits: ";
        cin >> pHead->Credits;
        cout << "Input teacher's name: ";
        cin.ignore();
        getline(cin, pHead->TeacherName);
    }
    else
        cout << "No course found.";
}
void removeACourse(Courses *&pHead)
{
    PrintCoursesList(pHead);
    cout << "\nInput number of course you want to delete: ";
    int a;
    cin >> a;
    Courses* pCurr = pHead;
    if (pHead == nullptr)
    {
        cout << "No course found.\n";
        system("pause");
        return;
    }
    if (pHead->No == a)
    {
        Courses *pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
    }
    else
    {
        while (pCurr->pNext != nullptr && pCurr->pNext->No != a)
            pCurr =pCurr->pNext;
        if (pCurr->pNext != nullptr)
        {
            Courses *pTemp = pCurr->pNext;
            pCurr->pNext = pCurr->pNext->pNext;
            delete pTemp;
        }
        else
        {
            cout << "No course found.\n";
            system("pause");
            return;
        }
    }
    pCurr = pHead;
    int i = 1;
    while (pCurr != nullptr)
    {
        pCurr->No = i;
        pCurr = pCurr->pNext;
        ++i;
    }
    cout << "Delete successfully.\n";
    system("pause");
}
//Idea: check the SignIn linked list until there's is a correct ID - password combination
//else the login process will restart again
void LogIn(SignIn* pHead)
{
    bool status = true;
    string id_input;
    string psw_input;
    while (status)
    {
        cout << "Input ID: "; cin >> id_input;
        cout << "Input password: "; cin >> psw_input;
        SignIn *pCurr = pHead;
        while (pCurr != nullptr)
        {
            if (id_input == pCurr -> ID && psw_input == pCurr -> Password)
            {
                pStudentEnroll = pCurr;
                pCurrentStaff = pCurr;
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

void LogOut(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{ 
    clrscr();
    GeneralMenu(pStaff,pStudent,pHead,pCurr);
}

void GeneralMenu(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{
    cout << "Input Current Date And Time (DD MM YYYY): ";
	cin >> currentDateAndTime.day >> currentDateAndTime.month >> currentDateAndTime.year;
    clrscr();
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
        MenuOfStaff(pStaff,pStudent,pHead,pCurr);
    }
    else if (choice == 2)
    {
        LogIn(pStudent);
        MenuOfStudent(pStaff,pStudent,pHead,pCurr);
    }
    else if (choice == 3)
    {
        foutSignInStudent(pStudent);
        foutSignInStaff(pStaff);
        foutSchoolYear(pHead);
        foutClasses(pHead);
        foutSemester(pHead);
        exit(0);
    }
    else
    {
        cout << "Error, please try again";
        GeneralMenu(pStaff,pStudent,pHead,pCurr);
    }
}

//Long:biến Year này thì sẽ ảnh hưởng gì đến các biến khác?
//Long: Tui coi không thấy khai báo biến "Year" trong file header í
void PrintClassesList(Classes* pHead)
{
    cout << "Classes List: \n";
    cout << "No" << setw(10) << "Name" << setw(30) << "Number of students\n";
    Classes* pCurr = pHead;
    while (pCurr != nullptr)
    {
        cout << pCurr->No << setw(10);
        cout << pCurr->Name << setw(10);
        cout << pCurr->NumberOfStudents << setw(10);
        cout << "\n";
        pCurr = pCurr->pNext;
    }
}
void CreateSchoolYear(SchoolYear *&pHead, SchoolYear *&pCurr) //chỗ này có thể tách riêng (hoặc không)
{
    //cần sửa vì file csv có cách đọc khác
    if (pHead == nullptr)
    {
        pHead = new SchoolYear;
        cout << "Input school year (example: 2021-2022): ";
        cin >> pHead->years;
        Classes *pCurrY = pHead->pClass;
        int i = 1;
        while (true)
        {
            CreateClasses(pHead->pClass,pCurrY,i);
            cout << "Continue adding classes? (Yes: y, No: n): ";
            char check;
            cin >> check;
            if (check != 'y')
                break;
        } 
        //pCurrY = pHead->pClass;
        clrscr();
        while (true)
        {
            PrintClassesList(pHead->pClass);
            cout << "\nInput number of class you want to add student: \n";
            int x;
            cin >> x;
            Classes *pTemp = pHead->pClass;
            while (pTemp != nullptr && pTemp->No != x) pTemp = pTemp->pNext;
            if (pTemp != nullptr)
            {
                ifstream studentInClass(".\\"+pHead->years + "\\" + pTemp->Name+".csv");
                InputStudent(pTemp->pStudent,studentInClass);
            }
            else
            {
                cout << "No class found.\n";
                break;
            }
            cout << "Continue adding student to class? (Yes: y, No: n): ";
            char check;
            cin >> check;
            cin.clear();
            cin.ignore(10000,'\n');
            clrscr();
            if (check != 'y')
                break;
        }
        pHead->pNext = nullptr;
        pCurr = pHead;
    }
    else
    {
        cout << "School Year list: \n";
        SchoolYear *pTemp = pHead;
        while (pTemp != nullptr){
            cout << pTemp->years << " ";
            pTemp = pTemp->pNext;
        }
        cout << "\n";
        cout << "Input school year (example: 2021-2022): ";
        string a ="";
        cin >> a;
        pCurr = pHead;
        while (pCurr->years != a && pCurr->pNext != nullptr) pCurr = pCurr->pNext;
        cout << "\n";
        
        if (pCurr->years == a)
        {
            Classes *pCurrY = pCurr->pClass;
            int i = pCurrY->No +1;
            while (true)
            {
                CreateClasses(pCurr->pClass,pCurrY,i);
                cout << "Continue adding classes? (Yes: y, No: n): ";
                char check;
                cin >> check;
                if (check != 'y')
                    break;
            } 
            //pCurrY = pCurr->pClass;
            clrscr();

            while (true)
            {
                PrintClassesList(pCurr->pClass);
                cout << "Input number of class you want to add student: \n";
                int x;
                cin >> x;
                Classes *pTemp = pCurr->pClass;
                while (pTemp != nullptr && pTemp->No != x) pTemp = pTemp->pNext;
                if (pTemp != nullptr)
                {
                    ifstream studentInClass(".\\"+pCurr->years + "\\" + pTemp->Name+".csv");
                    InputStudent(pTemp->pStudent,studentInClass);
                }
                else
                {
                    cout << "No class found.\n";
                    break;
                }
                cout << "Continue adding students to class? (Yes: y, No: n): ";
                char check;
                cin >> check;
                cin.clear();
                cin.ignore(10000,'\n');
                clrscr();
                if (check != 'y')
                    break;
            }
            while (pCurr->pNext != nullptr) pCurr =pCurr->pNext;
        }
        else 
        {   
            pCurr = pHead;
            while (pCurr->pNext != nullptr) pCurr =pCurr->pNext;
            pCurr->pNext = new SchoolYear;
            pCurr = pCurr->pNext;
            pCurr->years =a;
            Classes *pCurrY = pCurr->pClass;
            int i = pCurr->pClass->No +1;
            while (true)
            {
                CreateClasses(pCurr->pClass,pCurrY,i);
                cout << "Continue adding classes? (Yes: y, No: n): ";
                char check;
                cin >> check;
                if (check != 'y')
                    break;
            } 
            //pCurrY = pCurr->pClass;
            clrscr();
        
            while (true)
            {
            
                PrintClassesList(pCurr->pClass);
                cout << "Input number of class you want to add student: \n";
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
                {
                    cout << "No class found.\n";
                    break;
                }
                cout << "Continue adding students to class? (Yes: y, No: n): ";
                char check;
                cin >> check;
                cin.clear();
                cin.ignore(10000,'\n');
                clrscr();
                if (check != 'y')
                break;    
            }
            pCurr->pNext = nullptr;
        }
    }
}
//Long: Có vẻ như là cần thêm biến Semester vào struct ScoreBoardOfCourse //Thư: Okay tui thêm nha
void CreateSemester(SchoolYear *pHead)
{   
    SchoolYear *pCurr = pHead;
    char check = '\n';
    cout << "Input school year this semester belong to (Example: 2021-2022): ";
    string s = "";
    cin >> s;
    while (pCurr != nullptr && pCurr->years != s) pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        Semester *pTemp = pCurr->pSemester;
            cout << "Semester list: \n";
            if (pTemp != nullptr)
            {
                cout << "No"  << "     Start Date" <<  "      End Date\n";
                while(pTemp != nullptr)
                {
                    cout << pTemp->No <<setw(10) << pTemp->startDate.day<<"/" << pTemp->startDate.month <<"/"<< pTemp->startDate.year<<setw(10) << pTemp->endDate.day<<"/" << pTemp->endDate.month<<"/" << pTemp->endDate.year <<"\n";
                    pTemp = pTemp->pNext;
                }
            }
            else
                cout << "Empty\n";
        int x;
        cout << "Input semester number: ";
        cin >> x;
        while (pCurr->pSemester != nullptr && pCurr->pSemester->No != x) pCurr->pSemester = pCurr->pSemester->pNext;
        if (pCurr->pSemester == nullptr) 
        {
            pCurr->pSemester = new Semester;
            if (pCurr == pHead)
                pHead = pCurr;
            pCurr->pSemester->No = x;
            pCurrentSemester = pCurr->pSemester;
            cout << "Input start date (DD MM YYYY): ";
            cin >> pCurr->pSemester->startDate.day >> pCurr->pSemester->startDate.month >> pCurr->pSemester->startDate.year;
            currentSemesterstart.day = pCurr->pSemester->startDate.day;
            currentSemesterstart.month = pCurr->pSemester->startDate.month;
            currentSemesterstart.year = pCurr->pSemester->startDate.year;
            cout << "Input end date (DD MM YYYY): ";
            cin >> pCurr->pSemester->endDate.day >> pCurr->pSemester->endDate.month >> pCurr->pSemester->endDate.year;
            currentSemesterend.day = pCurr->pSemester->endDate.day;
            currentSemesterend.month = pCurr->pSemester->endDate.month;
            currentSemesterend.year = pCurr->pSemester->endDate.year;
            pCurr->pSemester->pCourse = nullptr;
            pCurr->pSemester->pNext = nullptr;
            int i = 1;
            while(true)
            {
                CreateCourses(pCurr->pSemester->pCourse,i);
                cout << "Continue adding courses? (y = yes, n = no): ";
                char check = 'n';
                cin >> check;
                if (check != 'y')
                    break;
            }
        }
        else
        {
            int i = pCurr->pSemester->No +1;
            while(true)
            {
                CreateCourses(pCurr->pSemester->pCourse,i);
                cout << "Continue adding courses? (y = yes, n = no): ";
                char check = 'n';
                cin >> check;
                if (check != 'y')
                    break;
            }
        }
    }
    else
    {
        cout << "No school year found.\n";
    }
    
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
        PrintClassesList(pHead);
        while (pCurr->pNext != nullptr) pCurr = pCurr->pNext;
        cout << "\n";
        pCurr->pNext = new Classes;
        pCurr = pCurr->pNext;
        pCurr->No = i;
        cout << "Input class name: ";
        cin >> pCurr->Name;
        cout << "Input the number of student: ";
        cin >> pCurr -> NumberOfStudents;
        pCurr->pNext = nullptr;
        ++i;
    }
}

void UpdateStudentResult(ScoreBoardOfCourse*& pHead)
{
    int studentID = 0;
    cout << "Type in the Student ID: "; cin >> studentID;
    ScoreOfStudentInBoard* pCur = pHead->pStudent;
    while (pCur != nullptr)
    {
        int n = 0;
        if (pCur->StudentID == studentID)
        {
            cout << "\t\t\t\t*************************************" << endl;
            cout << "\t\t\t\t*        1. Midterm Score           *" << endl;
            cout << "\t\t\t\t*        2. Finalterm Score         *" << endl;
            cout << "\t\t\t\t*        3. Other Score             *" << endl;
            cout << "\t\t\t\t*************************************" << endl;
            cout << endl << "\t\t\t\t\tYour choice: "; cin >> n;
            switch (n)
            {
            case 1: {
                float MidtermScore = 0;
                cout << "Type in new Midterm Score: "; cin >> MidtermScore;
                pCur->Midterm = MidtermScore;
                break;
            }
            case 2: {
                float FinalScore = 0;
                cout << "Type in new Midterm Score: "; cin >> FinalScore;
                pCur->Midterm = FinalScore;
                break;
            }
            case 3: {
                float OtherScore = 0;
                cout << "Type in new Midterm Score: "; cin >> OtherScore;
                pCur->Midterm = OtherScore;
                break;
            }
            default: cout << "System doesn't understand!" << endl;
            }
        }
    }
}

void InputStudent(Students *& pHead, ifstream &studentInput)
{
    if (!isEmpty(studentInput))
    {string key = "";
    getline(studentInput,key);
    Students *pCurr = pHead;
    while (!studentInput.eof())
    {if (pHead == nullptr)
    {
        pHead = new Students;
        getline(studentInput,key,',');
        pHead->No = atoi(key.c_str());
        getline(studentInput,key,',');
        pHead->StudentID = atoi(key.c_str());
        getline(studentInput,key,',');
        pHead->FirstName = key;
        getline(studentInput,key,',');
        pHead->LastName = key;
        getline(studentInput,key,',');
        pHead->SocialID = atoi(key.c_str());
        getline(studentInput,key,',');
        pHead->DateOfBirth = key;
        getline(studentInput,key);
        pHead->Gender = key;
        pHead->pNext = nullptr;
        pCurr = pHead;
    }
    else
    {
        pCurr->pNext = new Students;
        pCurr = pCurr->pNext;
        getline(studentInput,key,',');
        pCurr->No = atoi(key.c_str());
        getline(studentInput,key,',');
        pCurr->StudentID = atoi(key.c_str());
        getline(studentInput,key,',');
        pCurr->FirstName = key;
        getline(studentInput,key,',');
        pCurr->LastName = key;
        getline(studentInput,key,',');
        pCurr->SocialID = atoi(key.c_str());
        getline(studentInput,key,',');
        pCurr->DateOfBirth = key;
        getline(studentInput,key);
        pCurr->Gender = key;
        pCurr->pNext = nullptr;
    }}
    cout << "\nCreate successfully.\n";}
    else
        cout << "\nFile Not Found.\n";
    system("pause");
}

void PrintStudentsListInClass(Classes* pHead)
{
    cout << "\n\t\t--------------------------LIST OF STUDENTS IN ClASS " << pHead->Name << "--------------------------\n\n";
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "StudentID";
    cout << setw(17) << left << "SocialID";
    cout << setw(25) << left << "LastName";
    cout << setw(20) << left << "FirstName";
    cout << setw(15) << left << "Gender";
    cout << setw(15) << left << "DateofBirth";
    cout << endl;
    Students *pCur = pHead->pStudent;
    while (pCur)
    {
        cout << setw(5) << left << pCur->No;
        cout << setw(15) << left << pCur->StudentID;
        cout << setw(17) << left << pCur->SocialID;
        cout << setw(25) << left << pCur->LastName;
        cout << setw(20) << left << pCur->FirstName;
        cout << setw(15) << left << pCur->Gender;
        cout << setw(0) << left << pCur->DateOfBirth;
        cout << endl;
        pCur = pCur->pNext;
    }
}

void PrintStudentListInCourse(Courses *pHead,SignIn *pStudent) {
    SignIn *pCur = pStudent;
    cout << "\n\t\t--------------------------LIST OF STUDENTS IN COURSE--------------------------\n\n";
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "StudentID";
    cout << setw(17) << left << "SocialID";
    cout << setw(25) << left << "LastName";
    cout << setw(20) << left << "FirstName";
    cout << setw(15) << left << "Gender";
    cout << setw(15) << left << "DateofBirth";
    cout << endl;
    int i =1;
    while (pCur != nullptr)
    {
        //bool check = false;
        if (pCur->pCStudent != nullptr && pCur->pCStudent->CourseID == pHead->CourseID && pCur->pCStudent->CourseName == pHead->CourseName)
        {
            //check = true;
            cout << setw(5) << left << i++;
            cout << setw(15) << left << pCur->ID;
            cout << setw(17) << left << pCur->SocialID;
            cout << setw(25) << left << pCur->LastName;
            cout << setw(20) << left << pCur->FirstName;
            cout << setw(15) << left << pCur->Gender;
            cout << setw(0) << left << pCur->DoB;
            cout << endl;
        }
        pCur = pCur->pNext;
    }
    
}
    // Students


bool MaximumStudentEnrollInCourse(Courses*& pHead, Courses*& pStudents, int& number) // add a variable "number"
{
    Courses* pCur = pStudents;
    Courses* pCurrent = pHead;
    int no = 0;
    cout << endl << "Your choice: "; cin >> no;

    if (pStudents == nullptr)
    {
        pStudents = new Courses;
        pStudents->No = no;
        pStudents->pNext = nullptr;
        pCur = pStudents;
        Courses* pPrev = pHead;
        bool check2 = false;
        while (pCurrent != nullptr)
        {
            if (pStudents->No == pCurrent->No)
            {
                if (pCurrent->Maximum > 1)
                    pCurrent->Maximum--;
                else {
                    cout << "This course cannot be register anymore, please choose another!" << endl;
                    MaximumStudentEnrollInCourse(pHead, pStudents, number);
                    return false;
                }
                pStudents = new Courses;
                pStudents->CourseID = pCurrent->CourseID;
                pStudents->CourseName = pCurrent->CourseName;
                pStudents->Credits = pCurrent->Credits;
                for (int j = 0; j < 3; j++)
                {
                    pStudents->weekday1[j] = pCurrent->weekday1[j];
                    pStudents->weekday2[j] = pCurrent->weekday2[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    pStudents->time1[j] = pCurrent->time1[j];
                    pStudents->time2[j] = pCurrent->time2[j];
                }
                pStudents->TeacherName = pCurrent->TeacherName;
                pStudents->No = number;
                number++;
                //pCur = pStudents
                pPrev = pCurrent;
                pCurrent = pCurrent->pNext;
            }
        }
    }
    else {
        pCur->pNext = new Courses;
        pCur = pCur->pNext;
        pCur->No = no;
        pCur->pNext = nullptr;
        pCurrent = pHead;
        Courses* pPrev = pCurrent;
        // bool check2 = false;
        while (pCurrent != nullptr)
        {
            if (pCur->No == pCurrent->No)
            {

                if (pCurrent->Maximum > 1)
                    pCurrent->Maximum--;
                else {
                    cout << "This course cannot be register anymore, please choose another!" << endl;
                    MaximumStudentEnrollInCourse(pHead, pStudents, number);
                    return false;
                }
                pCur->CourseID = pCurrent->CourseID;
                pCur->CourseName = pCurrent->CourseName;
                pCur->Credits = pCurrent->Credits;
                for (int j = 0; j < 3; j++)
                {
                    pCur->weekday1[j] = pCurrent->weekday1[j];
                    pCur->weekday2[j] = pCurrent->weekday2[j];
                }
                for (int j = 0; j < 5; j++)
                {
                    pCur->time1[j] = pCurrent->time1[j];
                    pCur->time2[j] = pCurrent->time2[j];
                }
                pCur->TeacherName = pCurrent->TeacherName;
                pCur->No = number; number++;
            }
            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
        }

    }

    return true;
}

bool DuplicatedSession(Courses*& pHead, Courses*& pStudents, int& number) // add a variable "number"
{
    Courses* pCur = pStudents;
    Courses* pCurrent = pHead;
    int no = 0;
    cout << "Your choice: "; cin >> no;

    pCur->pNext = new Courses;
    pCur = pCur->pNext;
    pCur->No = no;
    pCur->pNext = nullptr;
    pCurrent = pHead;
    Courses* pPrev = pCurrent;

    while (pCurrent != nullptr)
    {
        if (pCur->No == pCurrent->No)
        {
            Courses* pTmp = pStudents;
            while (pTmp != nullptr)
            {
                if (((pTmp->weekday1[0] == pCurrent->weekday1[0] && pTmp->weekday1[1] == pCurrent->weekday1[1]) || (pTmp->weekday2[0] == pCurrent->weekday2[0] && pTmp->weekday2[1] == pCurrent->weekday2[1]) || (pTmp->weekday1[0] == pCurrent->weekday2[0] && pTmp->weekday1[1] == pCurrent->weekday2[1]) || (pTmp->weekday2[0] == pCurrent->weekday1[0] && pTmp->weekday2[1] == pCurrent->weekday1[1])) && ((pTmp->time1[0] == pCurrent->time1[0] && pTmp->time1[1] == pCurrent->time1[1]) || (pTmp->time2[0] == pCurrent->time2[0] && pTmp->time2[1] == pCurrent->time2[1]) || (pTmp->time1[0] == pCurrent->time2[0] && pTmp->time1[1] == pCurrent->time2[1]) || (pTmp->time2[0] == pCurrent->time1[0] && pTmp->time2[1] == pCurrent->time1[1])))
                {
                    cout << "Your course sessions are conflict, please enroll in another course!" << endl;
                    DuplicatedSession(pHead, pStudents, number);
                    return false;
                }
                pTmp = pTmp->pNext;
            }
            pCur->CourseID = pCurrent->CourseID;
            pCur->CourseName = pCurrent->CourseName;
            pCur->Credits = pCurrent->Credits;
            for (int j = 0; j < 3; j++)
            {
                pCur->weekday1[j] = pCurrent->weekday1[j];
                pCur->weekday2[j] = pCurrent->weekday2[j];
            }
            for (int j = 0; j < 5; j++)
            {
                pCur->time1[j] = pCurrent->time1[j];
                pCur->time2[j] = pCurrent->time2[j];
            }
            pCur->TeacherName = pCurrent->TeacherName;
            pCur->No = number; number++;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }
    return true;
}

/*void EnrollCourses(Courses*& pHead, Courses*& pStudents, int limit, int& number)
{
    int n = 0;
    int opt = 0;
    do {
        PrintEnrolledCourses(pHead);
        cout << endl << "Please input the number of courses that you wanna pick: ";
        cin >> n;
        Courses* pCur = pStudents;
        Courses* pCurrent = pHead;

        if (n <= limit)
        {
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
                    bool check2 = false;
                    while (pCurrent != nullptr)
                    {
                        if (pStudents->No == pCurrent->No)
                        {
                            if (pCurrent->Maximum > 1)
                                pCurrent->Maximum--;
                            else {
                                cout << "This course cannot be register anymore, please choose another!" << endl;
                                MaximumStudentEnrollInCourse(pHead, pStudents, number);
                                check2 = true;
                            }
                            if (check2 == true) break;
                            else {
                                pStudents = new Courses;
                                pStudents->CourseID = pCurrent->CourseID;
                                pStudents->CourseName = pCurrent->CourseName;
                                pStudents->Credits = pCurrent->Credits;
                                for (int j = 0; j < 3; j++)
                                {
                                    pStudents->weekday1[j] = pCurrent->weekday1[j];
                                    pStudents->weekday2[j] = pCurrent->weekday2[j];
                                }
                                for (int j = 0; j < 5; j++)
                                {
                                    pStudents->time1[j] = pCurrent->time1[j];
                                    pStudents->time2[j] = pCurrent->time2[j];
                                }
                                pStudents->TeacherName = pCurrent->TeacherName;
                                pStudents->No = number;
                                number++;
                            }
                            pPrev = pCurrent;
                            pCurrent = pCurrent->pNext;
                        }
                    }
                }
                else {
                    pCur->pNext = new Courses;
                    pCur = pCur->pNext;
                    pCur->No = no;
                    pCur->pNext = nullptr;
                    pCurrent = pHead;
                    Courses* pPrev = pCurrent;
                    bool check1 = false;
                    bool check2 = false;
                    while (pCurrent != nullptr)
                    {
                        if (pCur->No == pCurrent->No)
                        {
                            Courses* pTmp = pStudents;
                            while (pTmp != nullptr)
                            {
                                if (((pTmp->weekday1[0] == pCurrent->weekday1[0] && pTmp->weekday1[1] == pCurrent->weekday1[1]) || (pTmp->weekday2[0] == pCurrent->weekday2[0] && pTmp->weekday2[1] == pCurrent->weekday2[1]) || (pTmp->weekday1[0] == pCurrent->weekday2[0] && pTmp->weekday1[1] == pCurrent->weekday2[1]) || (pTmp->weekday2[0] == pCurrent->weekday1[0] && pTmp->weekday2[1] == pCurrent->weekday1[1])) && ((pTmp->time1[0] == pCurrent->time1[0] && pTmp->time1[1] == pCurrent->time1[1]) || (pTmp->time2[0] == pCurrent->time2[0] && pTmp->time2[1] == pCurrent->time2[1]) || (pTmp->time1[0] == pCurrent->time2[0] && pTmp->time1[1] == pCurrent->time2[1]) || (pTmp->time2[0] == pCurrent->time1[0] && pTmp->time2[1] == pCurrent->time1[1])))
                                {
                                    cout << "Your course sessions are conflict, please enroll in another course!" << endl;
                                    DuplicatedSession(pHead, pStudents, number);
                                    check1 = true;
                                }
                                pTmp = pTmp->pNext;
                            }
                            if (pCurrent->Maximum > 1)
                                pCurrent->Maximum--;
                            else {
                                cout << "This course cannot be register anymore, please choose another!" << endl;
                                MaximumStudentEnrollInCourse(pHead, pStudents, number);
                                check2 = true;
                            }
                            if (check1 == true || check2 == true) break; 
                            else
                            {
                                pCur->CourseID = pCurrent->CourseID;
                                pCur->CourseName = pCurrent->CourseName;
                                pCur->Credits = pCurrent->Credits;
                                for (int j = 0; j < 3; j++)
                                {
                                    pCur->weekday1[j] = pCurrent->weekday1[j];
                                    pCur->weekday2[j] = pCurrent->weekday2[j];
                                }
                                for (int j = 0; j < 5; j++)
                                {
                                    pCur->time1[j] = pCurrent->time1[j];
                                    pCur->time2[j] = pCurrent->time2[j];
                                }
                                pCur->TeacherName = pCurrent->TeacherName;
                                pCur->No = number;
                                number++;
                            }
                        }
                        pPrev = pCurrent;
                        pCurrent = pCurrent->pNext;
                    }
                }

            }
        }
        else {
            cout << "You cannot register more than 5 courses! " << endl;
            cout << "Please register again!" << endl;
            EnrollCourses(pHead, pStudents, limit,number);
        }
        cout << "\t\t\t\t***************************************" << endl;
        cout << "\t\t\t\t*        1. Continue Enrolling        *" << endl;
        cout << "\t\t\t\t*        2. View List of Courses      *" << endl;
        cout << "\t\t\t\t*        3. Back to Menu              *" << endl;
        cout << "\t\t\t\tt***************************************" << endl;
        cout << endl;
        cout << "\t\t\t\t\tYour choice: "; cin >> opt;
        if (opt == 1) limit = limit - n;
    } while (opt == 1);
    if (opt == 2) {
        clrscr();
        PrintCoursesList(pStudents);
    }
    else if (opt == 3) {
        clrscr();
    }
}*/
void EnrollCourses(Courses*& pHead, Courses*& pStudents, int limit, int& number)
{
    while (true)
    { 
    if (number < limit)
    { 
         Courses *pTemp = pStudents;
        PrintCoursesList(pHead);
        cout << "Input number of courses you want to pick: ";
        int a;
        cin >> a;
        Courses *pCurr = pHead;
        
        while (pCurr != nullptr && pCurr->No != a) pCurr = pCurr->pNext;
        if (pCurr != nullptr)
        {
            if (pStudents == nullptr)
            {
                pStudents = new Courses;
                pStudents->No = a;
                pStudents->CourseID = pCurr->CourseID;
                pStudents->CourseName = pCurr->CourseName;
                pStudents->Credits = pCurr->Credits;
                pStudents->Maximum = pCurr->Maximum;
                pStudents->TeacherName = pCurr->TeacherName;
                strcpy(pStudents->time1,pCurr->time1);
                strcpy(pStudents->time2,pCurr->time2);
                strcpy(pStudents->weekday1,pCurr->weekday1);
                strcpy(pStudents->weekday2,pCurr->weekday2);
                ++number;
                pStudents->pNext = nullptr;
                pTemp = pStudents;
            }
            else
            {
                Courses *pTam = pStudents;
                while (pTam != nullptr && pTam->No != a) pTam = pTam->pNext;
                if (pTam != nullptr)
                    {cout << "Already Enrolled.\n";
                    system("pause");}
                else
                {
                    if (checkCourses(pStudents,pCurr))
                    {
                        while (pTemp->pNext != nullptr) pTemp = pTemp->pNext;
                        pTemp->pNext = new Courses;
                        pTemp = pTemp->pNext;
                        pTemp->No = a;
                        pTemp->CourseID = pCurr->CourseID;
                        pTemp->CourseName = pCurr->CourseName;
                        pTemp->Credits = pCurr->Credits;
                        pTemp->Maximum = pCurr->Maximum;
                        pTemp->TeacherName = pCurr->TeacherName;
                        strcpy(pTemp->time1,pCurr->time1);
                        strcpy(pTemp->time2,pCurr->time2);
                        strcpy(pTemp->weekday1,pCurr->weekday1);
                        strcpy(pTemp->weekday2,pCurr->weekday2);
                        pTemp->pNext = nullptr; 
                        ++number;
                   
                    }
                    else
                    {
                        cout << "Time of courses conflicted.\n";
                        system("pause");
                    }   
                }
            }
        }
        else
        {
            cout << "No Courses found.\n";
            system("pause");
        }
        cout << "\n";
        PrintEnrolledCourses(pStudents);
        cout << "Continue enroll? (y = yes, n = no)\n";
        char ch;
        cin >> ch;
        if (ch != 'y')
            return;
    }   
    else
    {
        cout << "Maximum number of courses reached.";
        return;
    }
    }
}
void PrintEnrolledCourses(Courses* pHead)
{
    cout << setw(10) << left << "No";
    cout << setw(15) << left << "Course ID";
    cout << setw(20) << left << "Course Name";
    cout << setw(10) << left << "Credit";
    cout << setw(6) << right << "Day 1";
    cout << setw(15) << right << "Session 1";
    cout << setw(10) << right << "Day 2";
    cout << setw(15) << right << "Session 2";
    cout << setw(20) << right << "Teacher";
    cout << endl;
    cout << setfill('-') << setw(121) << '-';
    cout << endl;
    cout << setfill(' ');
    Courses* pCur = pHead;
    while (pCur != nullptr)
    {
        cout << setw(10) << left << pCur->No;
        cout << setw(15) << left << pCur->CourseID;
        cout << setw(20) << left << pCur->CourseName;
        cout << setw(12) << left << pCur->Credits;
        cout << setw(0) << right << pCur->weekday1[0] << pCur->weekday1[1] << pCur->weekday1[2];
        cout << setw(10) << right << pCur->time1[0] << pCur->time1[1] << pCur->time1[2] << pCur->time1[3] << pCur->time1[4];
        cout << setw(9) << right << pCur->weekday2[0] << pCur->weekday2[1] << pCur->weekday2[2];
        cout << setw(10) << right << pCur->time2[0] << pCur->time2[1] << pCur->time2[2] << pCur->time2[3] << pCur->time2[4];
        cout << setw(22) << right << pCur->TeacherName;
        cout << endl;
        pCur = pCur->pNext;
    }
}

/*void PrintScoreBoardOfStudents(ScoreBoardOfCourse*& pHead)
{

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
    while (pCur != nullptr )
    {
        ScoreOfStudentInBoard *pTemp = pCur->pStudent;
        if (pCur->pStudent->StudentID == atoi(pStudentEnroll->ID.c_str()))
        {
            cout << setw(15) << left << pCur->CourseID;
            cout << setw(20) << left << pCur->CourseName;
            cout << setw(12) << left << pTemp->Midterm;
            cout << setw(12) << right << pTemp->Finalterm;
            cout << setw(12) << right << pTemp->OtherScore;
            cout << setw(12) << right << pTemp->Overall;
            cout << endl;
        }
        pCur = pCur->pNext;
    }
}*/

void PrintScoreBoard(ScoreBoardOfCourse* pHead)
{
    
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
        ScoreOfStudentInBoard *pTemp = pCur->pStudent;
        cout << setw(15) << left << pCur->CourseID;
        cout << setw(20) << left << pCur->CourseName;
        cout << setw(12) << left << pTemp->Midterm;
        cout << setw(12) << right << pTemp->Finalterm;
        cout << setw(12) << right << pTemp->OtherScore;
        cout << setw(12) << right << pTemp->Overall;
        cout << endl;
        pCur = pCur->pNext;
    }
}

void MenuOfStaff(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{
    string choose="";
    int choice1;
    int choice2;
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
    cout << "\t\t      *\t\t    2.My School Year, Classes, Semesters and Courses\t\t *\n";
    cout << "\t\t      *\t\t    3.Scoreboard (Not implemented)\t\t *\n";
    cout << "\t\t      *\t\t    4.Log out\t\t\t *\n";
    cout << "\t\t      *\t\t    5.View profile info \t\t\t *\n";
    cout << "\t\t      ********************************************\n\n";
    cout << "\t\t\t\tYour Choice: "; cin >> choice1;
    clrscr();
    switch (choice1)
    {
    case 1: {
        ChangePassword(pStaff->Password);
        cout << "\n\nPassword change successfully\n\n";
        cout << "\nYou must login again.";
        GeneralMenu(pStaff, pStudent,pHead,pCurr);
        break;
    }
    case 2: {
        backtocase2: //maybe a good way
        cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t  1.Create school year and classes\t *\n";
        cout << "\t\t      *\t  2.Create semesters and courses\t\t *\n";
        cout << "\t\t      *\t  3.View the list of all classes\t *\n";
        cout << "\t\t      *\t  4.View the list of all courses,update and delete courses\t *\n";
        cout << "\t\t      *\t  5.View the list of all student in a class\t *\n";
        cout << "\t\t      *\t  6.View the list of all student in a course\t *\n";
        cout << "\t\t      *\t  7.Back \t\t\t\t *\n";
        cout << "\t\t      ********************************************\n\n";
        cout << "\t\t\t\tYour Choice: "; cin >> choice2;
        switch (choice2)
        {
        case 1:
        {

            CreateSchoolYear(pHead, pCurr);
            //Create schoolyear and semester
            //cout << "\n\nCreate successfully!\n\n";
            system("pause");
            clrscr();
            goto backtocase2;
            break;
        }
        case 2:
        {
            SchoolYear *pTemp = pHead;
            cout << "School Year list: \n";
            if (pTemp != nullptr)
                while(pTemp != nullptr)
                {
                    cout << pTemp->years << "\n";
                    pTemp = pTemp->pNext;
                }
            else
                cout << "Empty\n";
            CreateSemester(pHead);
            //cout << "\n\nCreate successfully!\n\n";
            system("pause");
            clrscr();
            goto backtocase2;
            break;
        }
        case 3:
        {
            SchoolYear *pTempp = pHead;
            while (pTempp != nullptr)
            {
                Classes *pTemp = pTempp->pClass;
                PrintClassesList(pTempp->pClass);
                pTempp = pTempp->pNext;
            }
            //View the list of all classes
            system("pause");
            clrscr();
            goto backtocase2;
            break;
        }
        case 4:
        {
            SchoolYear *pTempp = pHead;
            while (pTempp != nullptr)
            {
                PrintCoursesList(pCurrentSemester->pCourse);
                system("pause");
                cout << "\n1. Update a course";
                cout << "\n2. Delete a course";
                cout << "\n3. Go back\n";
                int choice;
                cout << "Your choice: ";
                cin >> choice;
                if (choice == 1)
                UpdateCourses(pCurrentSemester->pCourse);
                else if (choice == 2)
                removeACourse(pCurrentSemester->pCourse);
                clrscr();
               pTempp = pTempp->pNext;
            }
            goto backtocase2;
            break;
        }
        case 5:
        {
            //cin.clear();
           // cin.ignore(10000,'\n');
            clrscr();
            SchoolYear *pTempp = pHead;
            while (pTempp != nullptr)
            {
                cout << "SCHOOL YEAR: " << pTempp->years <<"\n";
                PrintClassesList(pTempp->pClass);
                pTempp = pTempp->pNext;
            }
            cout << "Input which school year you want to see: ";
            string a ="";
            cin >> a;
            pTempp = pHead;
            while (pTempp != nullptr && pTempp->years != a) pTempp =pTempp->pNext;
            if (pTempp != nullptr)
            {
                cout << "Input number of class you want to see: ";
                int x;
                cin >> x;
                while (pTempp->pClass != nullptr && pTempp->pClass->No != x) pTempp->pClass = pTempp->pClass->pNext;
                if (pTempp->pClass != nullptr)
                {
                    PrintStudentsListInClass(pTempp->pClass);
                    cout << "\n";
                }
                else
                {
                    cout << "No class found.";
                }
            }
            else
                cout << "No school year found.";
            system("pause");
            clrscr();
            pTempp = nullptr;
            goto backtocase2;
            break;
        }
        case 6:
        {
            clrscr();
            PrintCoursesList(pHead->pSemester->pCourse);
            int k;
            cout << "Input number of course you want to see student: ";
            cin >> k;
            Courses *pTemp = pHead->pSemester->pCourse;
            while (pTemp != nullptr && pTemp->No != k) pTemp = pTemp->pNext;
            if (pTemp != nullptr)
            {
                PrintStudentListInCourse(pTemp,pStudent);
                system("pause");
            }
            else
            {
                cout << "No Course found.\n";
                system("pause");
            }
            goto backtocase2;
            break;
        }
        case 7:
        {
            //back
            clrscr();

            goto back1;

            break;
        }
        default:
            cout << "Error.";
            goto backtocase2;
            break;
        }
        break;
    }
    case 3: {
        goto back1;
        break;
        /*cout << "\n\t\t\t*****************STAFF******************\n\n";
        cout << "\t\t      ********************************************\n";
        cout << "\t\t      *\t     1.Update scoreboard\t\t *\n";
        cout << "\t\t      *\t     2.View scoreboard of a course\t *\n";
        cout << "\t\t      *\t     3.View scoreboard of a class\t *\n";
        cout << "\t\t      *\t     4.View scoreboard of a class\t *\n";
        cout << "\t\t      *\t     5.Back \t\t\t\t *\n";
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
            //view scoreboard of a classes
        }
        case 5:
        {
            //back
            clrscr();
            goto back1;
            break;
        }
        default:
            cout << "\n\nError!\n\n";
            break;
        }*/
    }
    case 4: {
        LogOut(pStaff,pStudent,pHead,pCurr);
        break;
    }
    case 5:
    {
        cout << "*******Profile info********\n";
        cout << pCurrentStaff->Name << "\n" << pCurrentStaff->ID << "\n" << pCurrentStaff->Email << "\n";
        cout << "***************************";
        system("pause");
        goto back1;
        break;
    }
    default:
        cout << "\n\nError\n\n";
        goto back1;
        break;
    }
}

/*void PrintScoreBoardOfClass(ScoreBoardOfCourse* pHead)
{
    ScoreBoardOfCourse* pCur = pHead;
    cout << "\n\t\t\t\t\t------------------------   SCOREBOARD OF THE CLASS   -------------------------\n\n";
    cout << setw(5) << left << "No";
    cout << setw(10) << left << "ClassID";
    cout << setw(15) << left << "StudentID";
    cout << setw(28) << left << "FullName";
    while (pCur) {
        cout << setw(13) << left << pCur->CourseName;
        pCur = pCur->pNext;
    }
    cout << setw(20) << left << "SemesterGPA";
    cout << setw(20) << left << "OverallGPA";
    cout << endl;
    ScoreOfStudentInBoard *pTemp = pCur->pStudent;
    while (pCur) {
        cout << setw(5) << left << pCur->No;
        cout << setw(10) << left << pCur->classID;
        cout << setw(15) << left << pCur->StudentID;
        cout << setw(28) << left << pCur->StudentName;
        while (pCur) {
            cout << setw(13) << left << pCur->Finalterm;
        }
        // Nhi: Chỗ này là 1 cái GPA của kì này, 1 cái là overall GPA tính luôn GPA của các kì trước
        // tạm thời mình chưa có thông tin ỏ chỗ này

       /* cout << setw(20) << left << 
        cout << setw(20) << left << */
        //chắc là bỏ chứ giờ k kịp làm
        //cout << endl;
       // pCur = pCur->pNext;
   // }
//} */

void RemoveEnrolledCourses(Courses*& pHead)
{
    int no = 0;
    int opt = 0;
    do {
        PrintCoursesList(pHead);
        cout << endl << "\t\t\t\tYour choice: "; cin >> no;
        Courses* pCur = pHead;
        Courses* pPrev = pCur;
        bool check = false;
        while (pCur != nullptr)
        {
            if (check)
            {
                pCur->No = pCur->No - 1;
            }
            if (pCur->No == no)
            {
                if (pCur == pHead)
                {
                    Courses* pTemp = pHead;
                    pHead = pHead->pNext;
                    delete pTemp;
                    check = true;
                }
                else {
                    pPrev->pNext = pCur->pNext;
                    delete pCur;
                    pCur = pPrev->pNext;
                    check = true;
                }
            }
            else {
                pPrev = pCur;
                pCur = pCur->pNext;
            }
        }
        cout << "\t\t\t\t***************************************" << endl;
        cout << "\t\t\t\t*        1. Continue Cancelling       *" << endl;
        cout << "\t\t\t\t*        2. Back to Menu              *" << endl;
        cout << "\t\t\t\t***************************************" << endl;
        cout << endl;
        cout << "\t\t\t\t\tYour choice: "; cin >> opt;
    } while (opt == 1);
   
    if (opt == 2)
    {
        clrscr;
    }
    else if (opt != 1)
    {
        cout << "Not found" << endl;
    }
}
bool checkCourses(Courses *pStudents, Courses *pC)
{
    for (Courses *pCurr = pStudents; pCurr != nullptr; pCurr = pCurr->pNext)
    {
        if (strcmp(pCurr->time1,pC->time1) == 0 && strcmp(pCurr->weekday1,pC->weekday1) ==0)
            return false;
        if (strcmp(pCurr->time2,pC->time1) == 0&& strcmp(pCurr->weekday2,pC->weekday1)== 0)
            return false;
        if (strcmp(pCurr->time1,pC->time2)== 0 && strcmp(pCurr->weekday1,pC->weekday2)== 0)
            return false;
        if (strcmp(pCurr->time2,pC->time2) == 0&& strcmp(pCurr->weekday2,pC->weekday2)== 0)
            return false;
    }
    return true;
}
void MenuOfStudent(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{
    string choose;
    char choice1;
    string Password;
    Courses* PCCur;
    ScoreBoardOfStudent* pHScoreofStudent;
    int number = 1;

stuback1:
    cout << "\n\t\t\t*****************STUDENT****************\n\n";
    cout << "\t\t      ********************************************\n";
    cout << "\t\t      *\t\t 1.View Profile\t\t\t *\n";
    cout << "\t\t      *\t\t 2.Change Password\t\t *\n";
    cout << "\t\t      *\t\t 3.Register for the course\t *\n";
    cout << "\t\t      *\t\t 4.View enrolled courses\t *\n";
    cout << "\t\t      *\t\t 5.Cancel registered course\t *\n";
    cout << "\t\t      *\t\t 6.View scoreboard (Not implemented)\t\t *\n";
    cout << "\t\t      *\t\t 7.Log out\t\t\t *\n";
    cout << "\t\t      ********************************************\n\n";
    cout << "\t\t\t\tYour Choice: "; cin >> choice1;
    clrscr();
    switch (choice1)
    {
        case '1':
        {
        cout << "******PROFILE INFO**********\n";
        cout << pStudent->LastName << " " << pStudent->FirstName << " " << pStudent->ID << " " << pStudent->SocialID << "\n";
        cout << pStudent->DoB << " " << pStudent->Gender << " " << pStudent->Class;
        cout << "\n***************************\n";
        system("pause");
        clrscr();
        goto stuback1;
        break;
        }
        case '2':
        {
        //change password
        ChangePassword(pStudent->Password);
        clrscr();
        cout << "\n\nPassword change successfully!\n\n";
        cout << "\nYou must login again!\n";
        GeneralMenu(pStaff,pStudent,pHead,pCurr);
        // cho học sinh exist và nhập lại thông tin đăng nhập
        goto stuback1;
        break;
        }
        case '3':
        {
            //while (pStudent != nullptr && pStudent != pStudentEnroll) pStudent = pStudent->pNext;
        EnrollCourses(pHead->pSemester->pCourse,pStudentEnroll->pCStudent,5,pStudentEnroll->numberofCourse);
        //enroll courses
        cout << "\n\nRegistered successfully!\n\n";
        cout << "\n\n\t\tThank you!\n\n";
        goto stuback1;
        break;
        }
        case '4':
        {
        PrintEnrolledCourses(pStudentEnroll->pCStudent);
        system("pause");
        goto stuback1;
        break;
        }
    case '5':
    {
        int i = 1;
        Courses *pCurr = pStudentEnroll->pCStudent;
        while (pCurr != nullptr)
        {
            pCurr->No = i++;
            pCurr = pCurr->pNext;
        }
        removeACourse(pStudentEnroll->pCStudent);
        //remove course
        goto stuback1;
        break;
    }
    case '6':
    {
       // PrintScoreBoardOfStudents(pHScoreofStudent);
        //view scoreboard
        goto stuback1;
        break;
    }
    case '7':
    {
        LogOut(pStaff,pStudent,pHead,pCurr);
        //log out
        break;
    }
    default:
        {cout << "\n\n\tError!\n\n";
        goto stuback1;
        break;}
    }
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
        Courses *pTemp = pHead->pCStudent;
        while (pTemp != nullptr)
        {
            Courses *pT = pTemp;
            pTemp = pTemp->pNext;
            delete pT;
        }
        SignIn *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteCourses(Courses *&pHead)
{

    while(pHead != nullptr)
    {
        Students *pTemp = pHead->pStudent;
        while (pTemp != nullptr)
        {
            Students *pT = pTemp;
            pTemp = pTemp->pNext;
            delete pT;
        }
        Courses *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteSemester(Semester *&pHead){
    while (pHead != nullptr)
    {
        Semester *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void deleteSchoolYear(SchoolYear *&pHead)
{
    while (pHead != nullptr)
    {
        SchoolYear *pCurr = pHead;
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
    ofstream fout("schoolYearList.txt");
    SchoolYear *pCurr = pHead;
    while(pCurr != nullptr)
    {   
        fout << pCurr->years << " ";
        _mkdir(pCurr->years.c_str());
        for (int i = 1; i < 4; ++i)
        {
            string a = ".\\" + pCurr->years + "\\" + "semester "+to_string(i);
            _mkdir(a.c_str());
        }
        pCurr = pCurr->pNext;
    }
}
void foutClasses(SchoolYear*pHead)
{
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        Classes *pTemp = pCurr->pClass;
        ofstream fout;
        fout.open(".\\"+ pCurr->years + "\\" + "classList.txt");
        while (pTemp != nullptr)
        {
            fout << pTemp->Name << " " << pTemp->No << " " << pTemp->NumberOfStudents << "\n";
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
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        Semester *pTemp = pCurr->pSemester;
        while (pTemp != nullptr)
        {
            ofstream fout;
            fout.open(".\\" + pCurr->years + "\\" + "semesterList.txt");
            fout << pTemp->No << " " << pTemp->startDate.day << " " << pTemp->startDate.month << " " << pTemp->startDate.year << " " << pTemp->endDate.day << " " << pTemp->endDate.month << " " << pTemp->endDate.year << "\n";
            pTemp = pTemp->pNext;
        }
        pCurr = pCurr->pNext;
    }
}
void foutCourses(SchoolYear *pHead)
{
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        Semester *pTemp = pCurr->pSemester;
        while (pTemp != nullptr)
        {
            ofstream output(".\\" +pCurr->years + "\\" + "semester " + to_string(pTemp->No) + "\\" + "courselist.txt");
            Courses *pTam = pTemp->pCourse;
            while (pTam != nullptr)
            {
                output << pTam->CourseID << " " << pTam->CourseName << " " << pTam->weekday1 << " " << pTam->time1 << " " << pTam->weekday2 << " " << pTam->time2 << " " << pTam->Maximum << " " << pTam->Credits << " " << pTam->TeacherName << "\n";
                Students *pStu = pTam->pStudent;
                while (pStu != nullptr)
                {
                    output << pStu->No << " " << pStu->StudentID << " " << pStu->FirstName << " "  << pStu->LastName << " " << pStu->SocialID << " " << pStu->DateOfBirth << " " << pStu->Gender << "\n";                
                    pStu = pStu->pNext;
                }
                pTam = pTam->pNext;
            }
            pTemp = pTemp->pNext;
        }
        pCurr = pCurr->pNext;
    }
}
void foutCurrentSemester(SchoolYear *pHead)
{
    SchoolYear *pCurr = pHead;
    if (pCurrentSemester != nullptr)
    { 
        while (pCurr != nullptr && pCurr->pSemester != pCurrentSemester) pCurr = pCurr->pNext;
        if (pCurr != nullptr)
        {
            ofstream output(pCurr->years+ "_" + "currentsemester.txt");
            output << pCurr->pSemester->No;
        }
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
            pHead->LastName = key;
            getline(input,key,',');
            pHead->FirstName = key;
            getline(input,key,',');
            pHead->SocialID = key;
            getline(input,key,',');
            pHead->DoB = key;
            getline(input,key,',');
            pHead->Gender = key;
            getline(input,key);
            pHead->Class = key;
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


//cần đọc lớp,semester trong school year list
//cần đọc danh sách enrolled
//phần bên trên chưa xong

void foutSignInStaff(SignIn *pHead)
{
    remove("staff.csv");
    ofstream fout("staff.csv");
    fout << "ID,Password,Name,Email\n";
    SignIn *pCurr = pHead;
    while (pCurr != nullptr)
    {
        fout << pCurr->ID << "," << pCurr->Password << "," << pCurr->Name << "," << pCurr->Email << "\n";
        pCurr = pCurr->pNext;
    }
} 
void foutSignInStudent(SignIn *pHead)
{
    remove("student.csv");
    ofstream fout("student.csv");
    fout << "Student ID,PassWord,Last Name,First Name,Social ID,Date of Birth,Gender,Class\n";
    SignIn *pCurr = pHead;
    while (pCurr != nullptr)
    {
        fout << pCurr->ID << "," << pCurr->Password << "," << pCurr->LastName<< "," << pCurr->FirstName << "," << pCurr->SocialID << "," << pCurr->DoB <<"," << pCurr->Gender <<"," << pCurr->Class <<"\n"; 
        pCurr = pCurr->pNext;
    }
}     

void ExportStudentInCourse(Students*& pStudent, SchoolYear *pHead)
{ 
    fstream output;
    SchoolYear *pSchoolYear = pHead;
    Semester *pTemp = pHead->pSemester;
    if (pCurrentSemester != nullptr)
        while (pSchoolYear != nullptr)
        {
            bool check = false;
            pTemp = pSchoolYear->pSemester;
            while (pTemp != nullptr)
                if (pTemp != pCurrentSemester)
                    pTemp = pTemp->pNext;
                else
                {
                    check = true;
                    break;
                }
            if (check)
                break;
            pSchoolYear = pSchoolYear->pNext;
        }
    else
    {
        cout << "\nCurrently no Semester available.\n";
        return;
    }
    Courses* pCurr = pCurrentSemester->pCourse;
    int course_choice;
    PrintCoursesList(pCurrentSemester->pCourse);    
    cout << "Input the No of the course you want to export: ";
    cin >> course_choice;
    while (pCurr != nullptr && pCurr->No != course_choice) pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        output.open(".\\" + pSchoolYear->years + "\\" + "semester " + to_string(pCurrentSemester->No) + "\\"+pCurr->CourseName+"_student_list.csv", ios::out);
        output << "No" << ",";
        output << "Student ID" << ",";
        output << "First Name" << ",";
        output << "Last Name" << ",";
        output << "Date Of Birth" << ",";
        output << "Class" << ",";
        output << "Mid Term" <<",";
        output << "Final Term" <<",";
        output << "Other Score" <<",";
        output << "Overall" << "\n";
        Students *pStudent = pCurr->pStudent;
        while (pStudent != nullptr)
        {
            output << pStudent->No <<",";
            output << pStudent->StudentID <<",";
            output << pStudent->FirstName <<",";
            output << pStudent->LastName << ",";
            output << pStudent->DateOfBirth<<"\n";
            pStudent = pStudent->pNext;
        }
        cout << "Export successfully.";
        output.close();
        system("pause");
        clrscr();
    }
    else
    {
        cout << "No Course found.";
    }
}
/*void importScoreBoardCourse(ScoreBoardOfCourse *&pScoreBoardCourse, ScoreBoardOfStudent *&PrintScoreBoardOfStudents, SchoolYear *pSchoolYear)
{   
    bool check = false;
    SchoolYear *pTemp = pSchoolYear;
    while (pTemp != nullptr)
    {
        check = false;
        if (pTemp->pSemester != nullptr && pTemp->pSemester != pCurrentSemester) pTemp->pSemester = pTemp->pSemester->pNext;
        if (pTemp->pSemester != nullptr)
        {
            check = true;
            break;
        }
        if(check)
            break;
        pTemp = pTemp->pNext;
    }
    if (check)
    {
        Courses* pCurr = pCurrentSemester->pCourse;
        int course_choice;
        PrintCoursesList(pCurrentSemester->pCourse);    
        cout << "Input the No of the course you want to import: ";
        cin >> course_choice;
        

        while (pCurr != nullptr && pCurr->No != course_choice) pCurr = pCurr->pNext;
        if (pCurr != nullptr)
        {
            if (pScoreBoardCourse == nullptr)
            {pScoreBoardCourse = new ScoreBoardOfCourse;
            pScoreBoardCourse->CourseName = pCurr->CourseName;
            pScoreBoardCourse->CourseID = pCurr->CourseID; 
            string a = "";
            ifstream input(".\\"+pTemp->years+"\\"+ "semester " + to_string(pCurrentSemester->No) + "\\"+pCurr->CourseName+"_student_list.csv");
            getline(input,a);
            while (!input.eof())
            {
                pScoreBoardCourse->pStudent = new ScoreBoardOfStudent;
                ScoreOfStudentInBoard *pTemp = pScoreBoardCourse->pStudent;
                getline(input,a,',');
                pTemp->No = atoi(a.c_str());
                getline(input,a,',');
                pTemp->FirstName = a;
                getline(input,a,',');
                pTemp->LastName = a;
                getline(input,a,',');
                pTemp->DateOfBirth = a;
                getline(input,a,',');
                pTemp->classID = a;
                getline(input,a,',');
                pTemp->Midterm = atof(a.c_str());
                getline(input,a,',');
                pTemp->Finalterm = atof(a.c_str());
                getline(input,a,',');
                pTemp->OtherScore = atof(a.c_str());
                getline(input,a);
                pTemp->Finalterm = atof(a.c_str());
            }   
            cout << "Import Successfully";
            system("pause");
            pScoreBoardCourse->pNext = nullptr;}
            else
            {
                ScoreBoardOfCourse *pCurrScore = pScoreBoardCourse;
                while (pCurrScore->pNext != nullptr) pCurrScore = pCurrScore->pNext;
                pCurrScore->pNext = new ScoreBoardOfCourse;
                pCurrScore = pCurrScore->pNext;
                pCurrScore->CourseName = pCurr->CourseName;
           pCurrScore->CourseID = pCurr->CourseID; 
            string a = "";
            ifstream input(".\\"+pTemp->years+"\\"+ "semester " + to_string(pCurrentSemester->No) + "\\"+pCurr->CourseName+"_student_list.csv");
            getline(input,a);
            while (!input.eof())
            {
                pCurrScore->pStudent = new ScoreBoardOfStudent;
                ScoreOfStudentInBoard *pTemp = pCurrScore->pStudent;
                getline(input,a,',');
                pTemp->No = atoi(a.c_str());
                getline(input,a,',');
                pTemp->FirstName = a;
                getline(input,a,',');
                pTemp->LastName = a;
                getline(input,a,',');
                pTemp->DateOfBirth = a;
                getline(input,a,',');
                pTemp->classID = a;
                getline(input,a,',');
                pTemp->Midterm = atof(a.c_str());
                getline(input,a,',');
                pTemp->Finalterm = atof(a.c_str());
                getline(input,a,',');
                pTemp->OtherScore = atof(a.c_str());
                getline(input,a);
                pTemp->Finalterm = atof(a.c_str());
            }   
            cout << "Import Successfully";
            system("pause");
            pCurrScore->pNext = nullptr;
            }
        }
        
        else
        {
            cout << "No Course found.";
        }
    }
    else
    {
        cout << "\nCurrently no Semester available.\n";
        return;
    }
}*/
/*void deleteScoreBoard(ScoreBoardOfCourse *&pBoard, ScoreBoardOfStudent *&pStudent)
{
    ScoreOfStudentInBoard *pTemp = pScoreBoardCourse->pStudent;
    while (pTemp != nullptr)
    {
        ScoreOfStudentInBoard *pTempp = pTemp;
        pTemp = pTemp->next;
        delete pTempp;
    }
    while (pStudent != nullptr)
    {
        ScoreBoardOfCourse *pTempp = pStudent;
        pStudent = pStudent->pNext;
        delete pTempp;
    }
    while (pBoard != nullptr)
    {
        ScoreBoardOfCourse *pTempp = pBoard;
        pBoard = pBoard->pNext;
        delete pTempp;
    }
}*/
void readSchoolYearList(SchoolYear *&pHead,SchoolYear *&pCurr)
{
    ifstream input("schoolYearList.txt");
    if (input.good())
    {
        while (!input.eof())
        {
            if (pHead == nullptr)
            {
                pHead = new SchoolYear;
                input >> pHead->years;
                pHead->pNext = nullptr;
                pCurr = pHead;
            }
            else
            {
                pCurr->pNext = new SchoolYear;
                pCurr = pCurr->pNext;
                input >> pCurr->years;
                pCurr->pNext = nullptr;
            }
        }
    }
}
void readClassList(SchoolYear *pHead)
{
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        ifstream input(".\\"+pCurr->years + "\\" +"classList.txt");
        if (input.good())
        {
            while (!input.eof())
            {
                if (pCurr->pClass == nullptr)
                {
                    pCurr->pClass = new Classes;
                    input >> pCurr->pClass->Name >> pCurr->pClass->No >> pCurr->pClass->NumberOfStudents;
                    pCurr->pClass->pNext = nullptr;
                    ifstream readStudent(".\\" +pCurr->years + "\\" +pCurr->pClass->Name +".csv");
                    InputStudent(pCurr->pClass->pStudent,readStudent);
                    pCurr->pClass = pCurr->pClass->pNext;  
                }
            }
        }
        pCurr =pCurr->pNext;
    }
}
void readSemesterList(SchoolYear *pHead)
{
    SchoolYear *pCurr = pHead;
    while (pCurr != nullptr)
    {
        ifstream input(".\\"+pCurr->years + "\\" +"semesterList.txt");

    }
}