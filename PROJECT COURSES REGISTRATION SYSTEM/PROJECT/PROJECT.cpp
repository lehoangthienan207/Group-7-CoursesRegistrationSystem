#include "PROJECT.h"
//#include <string>





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
void deleteSignIn(SignIn *&pHead)
{
    while (pHead !=nullptr)
    {
        SignIn *pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
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
void LogIn(SignIn* pHead)
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
int MenuOfStudent()
{
    int n = 0;
    cout << "*****************************************************" << endl;
    cout << "*                                                   *" << endl;
    cout << "*               1. Enroll in Courses                *" << endl;
    cout << "*               2. Remove enrolled Courses          *" << endl;
    cout << "*               3. View list of Courses             *" << endl;
    cout << "*               4. View Scoreboard                  *" << endl;
    cout << "*               5. View Your Profile                *" << endl;
    cout << "*               6. Change Your Password             *" << endl;
    cout << "*                                                   *" << endl;
    cout << "*****************************************************" << endl;
    cout << endl << "Your choice: "; cin >> n;
    return n;
}
void CreateSchoolYear(SchoolYear *&pHead, SchoolYear *&pCurr) //chỗ này có thể tách riêng (hoặc không)
{
    //cần sửa vì file csv có cách đọc khác
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
        clrscr();
        while (true)
        {
            cout << "Input classID you want to add student: \n";
            PrintClassesList(pHead->pClass);
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
        clrscr();
        
        while (true)
        {
            cout << "Input classID you want to add student: ";
            PrintClassesList(pCurr->pClass);
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
            cin.clear();
            cin.ignore(10000,'\n');
            clrscr();
            if (check != 'y')
                break;
        }
        pCurr->pNext = nullptr;
    }
}
void GeneralMenu(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
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
        MenuOfStaff(pStaff,pStudent,pHead,pCurr);


    }
    else if (choice == 2)
    {
        LogIn(pStudent);
        int c = MenuOfStudent();
    }
    else if (choice == 3)
    {
        exit(0);
    }
    else
    {
        cout << "Error, please try again";
        GeneralMenu(pStaff,pStudent,pHead,pCurr);
    }
}
void MenuOfStaff(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{
    string choose;
    int choice1;
    int choice2;
    string Password;
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
    cout << "\t\t      *\t\t    3.Scoreboard\t\t *\n";
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
        cout << "\t\t      *\t  4.View the list of all courses\t *\n";
        cout << "\t\t      *\t  5.Back \t\t\t\t *\n";
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
            CreateSemester(pHead);
            //cout << "\n\nCreate successfully!\n\n";
            system("pause");
            clrscr();
            goto backtocase2;
            break;
        }
        case 3:
        {
            //PrintClassesList(pClass);
            //View the list of all classes
            system("pause");
            clrscr();
            goto backtocase2;
            break;
        }
        case 5:
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
    case 3: {
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
    case 4: {
        LogOut(pStaff,pStudent,pHead,pCurr);
        break;
    }
    case 5:
    {
        cout << "*******Profile info********\n";
        cout << pStaff->Name << "\n" << pStaff->ID << "\n" << pStaff->Email << "\n";
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
void LogOut(SignIn *pStaff, SignIn* pStudent,SchoolYear *&pHead,SchoolYear *&pCurr)
{ 
    clrscr();
    GeneralMenu(pStaff,pStudent,pHead,pCurr);
}
void clrscr(){
    cout << "\033[2J\033[1;1H";
}
void ChangePassword(string& Password)
{
    //Hải: làm giúp luôn tại cái này ez =))
    string newPass = "";
    cout << "Input new password: ";
    cin >> newPass;
    Password = newPass;
}
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
        cout << "Input the number of student: ";
        cin >> pCurr -> NumberOfStudents;
        pCurr->pNext = nullptr;
        ++i;
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
void InputStudent(Students *& pHead, ifstream &studentInput)
{
    string key = "";
    getline(studentInput,key);
    Students *pCurr = pHead;
    if (pHead == nullptr)
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
    }
    cout << "\nCreate successfully.\n";
    system("pause");
}
void PrintClassesList(Classes* pHead)
{
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
void deleteClasses(Classes *&pHead)
{
    while(pHead != nullptr)
    {
        Classes *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}
void CreateSemester(SchoolYear *pHead)
{   
    SchoolYear *pCurr = pHead;
    char check = '\n';
    cout << "Input school year this semester belong to (Example: 2020-2021): ";
    string s = "";
    cin >> s;
    while (pCurr != nullptr && pCurr->years != s) pCurr = pCurr->pNext;
    if (pCurr != nullptr)
    {
        int x;
        cout << "Input semester number: ";
        cin >> x;
        pCurr->pSemester = new Semester;
        pCurr->pSemester->No = x;
        cout << "Input start date (DD MM YYYY): ";
        cin >> pCurr->pSemester->startDate.day >> pCurr->pSemester->startDate.month >> pCurr->pSemester->startDate.year;
        cout << "Input end date (DD MM YYYY)";
        cin >> pCurr->pSemester->endDate.day >> pCurr->pSemester->endDate.month >> pCurr->pSemester->endDate.year;
        pCurr->pSemester->pCourse = nullptr;
        int i = 1;
        while(true)
        {
            CreateCourses(pCurr->pSemester->pCourse,i);
            cout << "Continue adding courses? (y = yes, n = no)";
            char check = 'n';
            cin >> check;
            if (check != 'y')
                break;
        }
    }
    else
    {
        cout << "No school year found.\n";
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
        cin.ignore();
        cin.getline(pHead->weekday1,4);
        cout << "Input time of session 1: ";
        cin.ignore();
        cin.getline(pHead->time1,6);
        cout << "Input weekday of session 2: ";
        cin.ignore();
        cin.getline(pHead->weekday2,4);
        cout << "Input time of session 2: ";
        cin.ignore();
        cin.getline(pHead->time2,6);
        cout << "Input maximum number of students (Default: 50): "; //maximum?? // Thư: là số lượng học sinh tối đa có thể đăng ký (default là 50)
        string maximum="";
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
        cin.ignore();
        cin.getline(pCurr->weekday1,4);
        cout << "Input time of session 1: ";
        cin.ignore();
        cin.getline(pCurr->time1,6);
        cout << "Input weekday of session 2: ";
        cin.ignore();
        cin.getline(pCurr->weekday2,4);
        cout << "Input time of session 2: ";
        cin.ignore();
        cin.getline(pCurr->time2,6);
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
void deleteCourses(Courses *&pHead)
{
    while(pHead != nullptr)
    {
        Courses *pCurr = pHead;
        pHead = pHead->pNext;
        delete pCurr;
    }
}