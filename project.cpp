#include <iostream>
#include <windows.h>
using namespace std;
struct Student
{
    int id;
    string name;
    string password;
    float attendance;
    string grade;
    bool feepaid;
};
struct Teacher 
{
    string name;
    string username;
    string password;
};
Student students[20];
Teacher teachers[10];
int studentCount = 0;
int teacherCount = 0;
string adminUser = "admin";
string adminPass = "1234";
bool passcode(string s)
{
    return s.length() == 8;
}
int main() 
{
int choice;
while (true) 
{
    system("color B");
    cout<<"        |||||||||||||||||||||||||||||||||||||||    "<<endl;
    cout<<"        || Tuition Academy Management System ||    "<<endl;
    cout<<"        |||||||||||||||||||||||||||||||||||||||    "<<endl;
    cout << "1. Admin Login\n2. Teacher Login\n3. Student Login\n4. Exit\n";
    cout<<"Enter your Choice:";
    cin >> choice; 
if (choice == 1) 
{
    string u, p;
    cout << "Admin Username: ";
    cin >> u;
    cout << "Admin Password: ";
    cin >> p;
if (u == adminUser && p == adminPass)
{
int ch;
do {
    system("color D");
    system("cls");
    cout<<"       |||||||||||||||||||||||||| "<<endl;
    cout<<"       ||      Admin Panel     || "<<endl;
    cout<<"       |||||||||||||||||||||||||| "<<endl; 
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Add Teacher\n";
    cout << "6. View Teachers\n";
    cout << "7. Update Teacher\n";
    cout << "8. Delete Teacher\n";
    cout << "9. Update Student Fee\n";
    cout << "10. Logout\n";
    cout<<"Enter your Choice:";
    cin >> ch;
if (ch == 1) 
{
    if(studentCount >= 20)
    {
        cout<<"Student limit reached!\n";
    }
    else
    {
    cout << "Student ID: ";
    cin >> students[studentCount].id;
    cout << "Name: ";
    cin >> students[studentCount].name;
do
{
    cout << "Password (exactly 8 characters): ";
    cin >> students[studentCount].password;
    if (!passcode(students[studentCount].password))
        cout << "Password must be exactly 8 characters!\n";
} while (!passcode(students[studentCount].password));

students[studentCount].attendance = 0;
students[studentCount].grade = "";
students[studentCount].feepaid = false;
studentCount++;
cout << "Student Added Successfully!\n";
system("pause");
    }
}

else if (ch == 2) 
{
    if (studentCount == 0)
    {
        cout << "No students available!\n";
    }
    else
for (int i = 0; i < studentCount; i++) 
{
    cout << " ID: " << students[i].id
    << " Name: " << students[i].name
    << " Attendance: " << students[i].attendance
    << " Grade: " << students[i].grade
    << " Fee: " << (students[i].feepaid ? "Paid" : "Unpaid")
    << endl;
}
system("pause");
}
else if (ch == 3) 
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < studentCount; i++) 
    {
        if (students[i].id == id) 
        {
            cout << "New Name: ";
            cin >> students[i].name;

            do {
                cout << "New Password (min 8 chars): ";
                cin >> students[i].password;
            } while (!passcode(students[i].password));

            cout << "Student Updated!\n";
            found = true;
            break;   
        }
    }

    if (!found)
        cout << "Student not found!\n";

    system("pause");
}
else if (ch == 4) 
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    bool found = false;

    for (int i = 0; i < studentCount; i++) 
    {
        if (students[i].id == id) 
        {
            for (int j = i; j < studentCount - 1; j++) 
                students[j] = students[j + 1];

            studentCount--;
            cout << "Student Deleted!\n";
            found = true;
            break;  
        }
    }

    if (!found)
        cout << "Student not found!\n";

    system("pause");
}
else if (ch == 5) 
{
    if (teacherCount >= 10)
    {
        cout << "Teacher limit reached!\n";
    }
    else
    {
        cout << "Teacher Name: ";
        cin >> teachers[teacherCount].name;
        do
        {
            cout << "Teacher Username (password must be exactly 8 characters): ";
            cin >> teachers[teacherCount].username;
        } while (!passcode(teachers[teacherCount].username));

        do
        {
            cout << "Password (password must be exactly 8 characters): ";
            cin >> teachers[teacherCount].password;
        } while (!passcode(teachers[teacherCount].password));

        teacherCount++;
        cout << "Teacher Added Successfully!\n";
    }
    system("pause");
}

    else if (ch == 6) 
{
    if (teacherCount == 0)
    {
        cout << "No teachers available!\n";
    }
    else
    {
        cout << "List of Teachers:\n";
        for (int i = 0; i < teacherCount; i++) 
        {
            cout << i+1
            << " Name: " << teachers[i].name
            << " Username: " << teachers[i].username
            << endl;
        }
    }
    system("pause"); 
}

    else if (ch == 7) 
{
string user;
cout << "Enter Username: ";
cin >> user;
bool found = false;
for (int i = 0; i < teacherCount; i++) 
{
    if (teachers[i].username == user) 
    {
        cout << "New Name: ";
        cin >> teachers[i].name;
        do
        {
          cout << "New Password (exactly 8 characters): ";
          cin >> teachers[i].password;
        } while (!passcode(teachers[i].password));

        cout << "Teacher Updated Successfully!\n";
        found = true;
        break;
    }
}
    system("pause");
}

    else if (ch == 8) 
{
    string user;
    cout << "Enter Username: ";
    cin >> user;

    bool found = false;

    for (int i = 0; i < teacherCount; i++) 
    {
        if (teachers[i].username == user) 
        {
            for (int j = i; j < teacherCount - 1; j++) 
            {
                teachers[j] = teachers[j + 1];
            }
            teacherCount--;
            cout << "Teacher Deleted Successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Teacher not found!\n";

    system("pause");
}

    else if (ch == 9)
{
    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            found = true;
            int feeChoice;
            cout << "1. Mark Fee Paid\n";
            cout << "2. Mark Fee Unpaid\n";
            cout << "Enter choice: ";
            cin >> feeChoice;
            if (feeChoice == 1)
            students[i].feepaid = true;
            else if (feeChoice == 2)
            students[i].feepaid = false;
            cout << "Fee Status Updated Successfully!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found!\n";
    }
        system("pause");
}

    } while (ch != 10);
      system("color B");
    }
      else 
    {
      cout << "Invalid Admin Login!\n";
    }
    }
      else if (choice == 2) 
{
    string u, p;
    cout << "Teacher Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;
    bool found = false;
    for (int i = 0; i < teacherCount; i++)
    {
    if (teachers[i].username == u && teachers[i].password == p)
    {
        found = true;
        int ch;
        do
        {
            system("color A");
            system("cls");
            cout << "|||||||||||||||||||||||||"<<endl;
            cout << "||   Teacher Panel    |||"<<endl;
            cout << "|||||||||||||||||||||||||"<<endl;
            cout << "1. Update Student Record\n";
            cout << "2. Logout\n";
            cout << "Enter choice: ";
            cin >> ch;
        if (ch == 1)
        {
            int id;
            cout << "Student ID: ";
            cin >> id;
            bool foundStudent = false;
        for (int j = 0; j < studentCount; j++)
        {
            if (students[j].id == id)
        {
            foundStudent = true;
            cout << "Attendance (%): ";
            cin >> students[j].attendance;
            cout << "Grade: ";
            cin >> students[j].grade;
            cout << "Updated Successfully!\n";
            break;
        }
            }

            if (!foundStudent)
            {
                cout << "Student not found!\n";
            }
            }
            } while (ch != 2);  
            system("color B");
            break;
        }
    }

    if (!found)
        cout << "Invalid Teacher Login!\n";
}
        else if (choice == 3) 
        {
            system("color E");
            system("cls");
            int id;
            string p;
            cout <<"        |||||||||||||||||||||||         "<<endl;
            cout <<"        ||   Student Panel   ||         "<<endl;
            cout <<"        |||||||||||||||||||||||         "<<endl;
            cout << "Student ID: ";
            cin >> id;
            cout << "Password: ";
            cin >> p;
            bool found = false;
            for (int i = 0; i < studentCount; i++) 
            {
            if (students[i].id == id && students[i].password == p) 
            {
                found = true;
                cout <<"        |||||||||||||||||||||||||||||||         "<<endl;
                cout <<"        || Student Performance Panel ||         "<<endl;
                cout <<"        |||||||||||||||||||||||||||||||         "<<endl;
                cout << "\nName: " << students[i].name;
                cout << "\nOverall Attendance: " << students[i].attendance<<"%";
                cout << "\nOverall Grade: " << students[i].grade;
                cout << "\nFee Status: "
                << (students[i].feepaid ? "PAID" : "NOT PAID") << endl;
                system("pause");

            }
            
            }
            if (!found)
                cout << "Invalid Student Login!\n";
        }

        else if (choice == 4) 
        {
            system("color 09");
            cout <<"        ||||||||||||||||||||||||||||||||||||||||         "<<endl;
            cout <<"        ||   Thank you for using the system   ||         "<<endl;
            cout <<"        ||||||||||||||||||||||||||||||||||||||||         "<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Choice!";
        }
    }

    return 0;
}
