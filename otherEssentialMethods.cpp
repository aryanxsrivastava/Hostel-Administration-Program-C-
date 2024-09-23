#include <bits/stdc++.h>
#include "complaint.cpp"
#include "filemethods.cpp"
#include "hostel_allot.cpp"
using namespace std;

string cmp = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\complaint.txt";
string registrationFile = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\registered.txt"; // Add the registration file

// Define a structure to hold student registration information
struct [[maybe_unused]] StudentRegistration {
    string id;
    string name;
    string password;
};

// Function to check if a student with the given ID already exists
bool isStudentRegistered(const string& id) {
    ifstream file(registrationFile);
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string regId;
        iss >> regId;
        if (regId == id) {
            return true;
        }
    }
    return false;
}bool isStrongPassword(const string& password) {
    // Check if the password meets the specified criteria.
    if (password.length() < 8 || password.length() > 12) {
        return false;
    }

    bool hasDigit = false;
    bool hasAlpha = false;
    bool hasSpecial = false;
    bool hasUppercase = false;

    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
        } else if (isalpha(c)) {
            hasAlpha = true;
            if (isupper(c)) {
                hasUppercase = true;
            }
        } else {
            hasSpecial = true;
        }
    }

    return hasDigit && hasAlpha && hasSpecial && hasUppercase;
}

void registerStudent() {
    string id, name, password, confirmPassword;
    cout << "\t\t\tEnter student ID: ";
    cin >> id;
    cout<<endl;

    if (isStudentRegistered(id)) {
        cout << "\t\t\tStudent with this ID already exists. Registration failed.\n" << endl;
        return ;
    }

    cout << "\t\t\tEnter your first name: ";
    cin.ignore();
    getline(cin, name);
    cin.unget();

    cout<<"\nNote:-your password should have 8-12 characters, at least 1 digit, 1 uppercase letter, 1 special character\n";
    cout << "\t\t\tEnter password: ";
    cin >> password;
    cout<<endl;

    if (!isStrongPassword(password)) {
        cout << "\t\t\tyour password should have 8-12 characters, at least 1 digit, 1 uppercase letter, 1 special character,Password does not meet the specified criteria. Registration failed.\n" << endl;
        return ;
    }

    cout << "\t\t\tConfirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "\t\t\tPassword and confirm password do not match. Registration failed.\n" << endl;
        return ;
    }

    ofstream regFile(registrationFile, ios::app);
    regFile << id << " " << password << " " << name << endl;
    regFile.close();

    cout << "\t\t\tStudent registered successfully.\n" << endl;
}

Complaint create_complaint_obj();
void write_complaint_to_file(Complaint c);
void complain_main();


//admin methods
void admin_login();
void admin_switch_case();

//complaint methods

void dyballa();

Complaint create_complaint_obj(){
    int complaint_no ;
    string student_name;
    string complaint_text;
    complaint_no = get_no_of_lines(cmp) + 1 ;
    Complaint c(complaint_no);
    cout<<"\t\t\t*********Complaint************\n"<<endl;
    cout<<"\t\t\tenter your name and roll no.\n"<<endl<<"\t\t\t\t" ;

    cin.ignore();
    getline(cin,student_name);
    c.set_student_name(student_name+"->");

    cout<<"\t\t\tenter complaint text : \n"<<endl<<"\t\t\t\t";
    //multiple words input
    cin.ignore();
    getline(cin,complaint_text);
    c.set_complaint_text(complaint_text);
    cout<<"complaint added successfully\n"<<endl<<endl <<endl;
    return c ;
}



//complaint methods complete-----------------------------------------------------

void viewAllottedStudents() {
    string filename = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\final_list.txt";
    ifstream in(filename.c_str());

    if (!in) {
        cout << "Error: Unable to open the student information file." << endl;
        return;
    }

    string line;
    cout << "Allotted Hostel Students: " << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();
}

////admin methods --------------------------
void admin_login(){
    string admin_id;
    string admin_password;
    cout<<"\t\t\t\tenter admin id : ";
    cin>>admin_id;
    cout<<endl;
    cout<<"\t\t\t\tenter admin password : ";
    cin>>admin_password;
    cout<<endl;
    if(admin_id == "1" && admin_password == "admin"){
        cout<<"\t\t\t\twelcome to admin's corner\n"<<endl;
        // now the admin login is done decdide how to proceed further **work to be done ** -------------
        admin_switch_case();

    }else{
        cout<<"\t\t\t\tinvalid admin id or password\n"<<endl;


    }
    return ;
}


void admin_switch_case(){
    admin_menu:
    cout<<"\t\t\t\t\t----------Admin Menu----------\n"<<endl;
    cout<<"\t\t\t\t1.See All Complaints given by Students\n"<<endl;
    cout<<"\t\t\t\t2.Preview Alloted Students in Hostel\n"<<endl;
    cout<<"\t\t\t\t3.go to main menu\n"<<endl<<"\t\t\t\t";
    cout<<"4.exit"<<endl;


    int choice;
    cin.ignore();
    cin.clear();
    fflush(stdin);
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"\t\t\t\t----------Preview all the complaints by Students----------\n"<<endl;
            cout<<"no.| Student name and Enrollment no. | Complaint body\n"<<endl;
            printFile(cmp);
            cout<<endl<<endl;
            goto admin_menu;
            break;

        case 2:
            cout<<"\t\t\t\t-----------Students who are Allocated in Hostel Rooms-----------\n"<<endl;
            viewAllottedStudents();
            cout<<endl<<endl;
            goto admin_menu;
            break;
        case 3:
            cout<<"\t\t\t\tyou have selected go to main menu\n"<<endl<<endl;
            break;
        case 4:
            cout<<"\t\t\t\tHope You Had a Wonderfull Experiece ,See You Soon in Bennett University!!\n"<<endl;
            exit(0);
    }
    
}

void student_login() {
    string student_id;
    string student_password;
    cout << "\t\t\tEnter student ID: ";
    cin >> student_id;
    cout << "\t\t\tEnter password: ";
    cin >> student_password;

    // Check if the student is registered and their password matches
    ifstream regFile(registrationFile);
    string line;
    bool loggedIn = false;
    string studentName;

    while (getline(regFile, line)) {
        istringstream iss(line);
        string regId, regName, regPassword;
        iss >> regId >> regPassword >> regName;

        if (regId == student_id && regPassword == student_password) {
            loggedIn = true;
            studentName = regName;
            break;
        }
    }

    regFile.close();

    if (loggedIn) {
        cout << "\t\t\nWelcome to the student's zone, " << studentName << "!" << endl;
        // Now you can proceed with the student's functionality
        dyballa();
    } else {
        cout << "\t\t\t\n\tInvalid student ID or password,Please try again!\n" << endl;
    }
}

// Add a global flag to track if the user has already allocated a room
bool hasAllocatedRoom = false;

// Function to check if a student has already allocated a room
bool checkEnrollmentNumberExists(const string& studentEnrollmentNumber) {
    ifstream inFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\room_allocation.txt"); // Update this with the correct path to your student file

    if (!inFile.is_open()) {
        cerr << "Error: Could not open the file for reading." << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string name, enrollmentNumber, mobileNumber, preferredState, roomNumber, gender;
        if (iss >> name >> enrollmentNumber >> mobileNumber >> preferredState >> roomNumber >> gender) {
            if (enrollmentNumber == studentEnrollmentNumber) {
                // The student is found in the file, indicating they have allocated a room
                inFile.close();
                return true;
            }
        }
    }

    inFile.close();
    // The student is not found in the file, indicating no room allocation
    return false;
}




//void dyballa() {
//    string studentEnrollmentNumber;
//    cout << "Enter your enrollment number: ";
//    cin >> studentEnrollmentNumber;
//
//    if (checkEnrollmentNumberExists(studentEnrollmentNumber)) {
//        cout << "You have already allocated a room. The room allocation feature is not available to you." << endl;
//        cout << "Available options: Raise a complaint, Main menu, and Exit." << endl;
//
//        while (true) {
//            cout << "\n\n\t\t\t----------Student Menu----------\n" << endl;
//            cout << "1. Raise Complaint\n" << endl;
//            cout << "2. Back to Main Menu\n" << endl << "\t\t\t";
//            cout << "3. Exit\n" << endl;
//
//            int choice;
//            cin.ignore();
//            string str;
//            cin.clear();
//            fflush(stdin);
//            cin >> choice;
//
//            switch (choice) {
//                case 1:
//                    cout << "\t\t\tRaise Complaint\n" << endl;
//                    regis_compi();
//                    cout << endl << endl;
//                    break;
//                case 2:
//                    cout << "\t\t\tyou have selected go to the main menu\n" << endl << endl;
//                    return;
//                case 3:
//                    cout << "\t\t\tHope You Had a Wonderful Experience, See You Soon in Bennett University!!\n" << endl;
//                    exit(0);
//                    break;
//                default:
//                    cout << "\t\t\tInvalid choice. Please try again." << endl;
//                    break;
//            }
//        }
//    } else {
//        // Student is allowed to allocate a room
//        student_menu:
//        cout << "\n\n\t\t----------Student Menu----------\n" << endl;
//        cout << "1. Allot/Change Hostel Request\n" << endl;
//        cout << "2. Raise Complaint\n" << endl;
//        cout << "3. Back to Main Menu\n" << endl;
//        cout << "4. Exit\n" << endl;
//
//        int choice;
//        cin.ignore();
//        string str;
//        cin.clear();
//        fflush(stdin);
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                cout << "Welcome to hostel allotment\n\n";
//                cout << endl;
//
//                str = hostel_allotment();
//
//                if (str == "Not Found") {
//                    cout << "You have been allotted your room; your roommate will be allotted soon!!" << endl;
//                    hasAllocatedRoom = true; // Set the flag to indicate room allocation
//                    goto student_menu;
//                } else {
//                    cout << "Your new Roommate is:  " << str << "\nRoom Allocation Completed, Have fun!!" << endl << endl;
//                    hasAllocatedRoom = true; // Set the flag to indicate room allocation
//                    goto student_menu;
//                }
//                break;
//            case 2:
//                cout << "Raise Complaint\n" << endl;
//                regis_compi();
//                cout << endl << endl;
//                goto student_menu;
//                break;
//            case 3:
//                cout << "You have selected go to the main menu\n" << endl << endl;
//                break;
//            case 4:
//                cout << "Hope You Had a Wonderful Experience, See You Soon in Bennett University!!\n" << endl;
//                exit(0);
//                break;
//            default:
//                cout << "Invalid choice. Please try again." << endl;
//                goto student_menu;
//                break;
//        }
//    }
//}



void dyballa() {


    student_menu:
    cout << "\n\n\t\t\t\t----------Student Menu----------\n" << endl;
    cout << "\t\t\t\t1.Book your Hostel Room \n" << endl;
    cout << "\t\t\t\t2.Raise Complaint \n" << endl;
    cout << "\t\t\t\t3.Back to Main Menu\n" << endl;
    cout << "\t\t\t\t4.Exit\n" << endl << "\t\t\t\t";


    int choice;
    cin.ignore();
    string str;
    cin.clear();
    fflush(stdin);
    cin >> choice;
    switch (choice) {
        case 1:

            cout << "\t\t\t\tWelcome to hostel allotment\n\n";
            cout << endl;

            str = hostel_allotment();

            if (str == "Not Found") {
                cout << "\nyou have been Allotted your room , your roommate will be Allotted soon!!" << endl;
            } else {
                cout << "Your new Roommate is:  " << str << "\nRoom Allocation Completed ,Have fun!!" << endl << endl;
                // Depending on the surrounding context, you may need to remove or relocate the 'break' statement.
            }
            goto alloted_menu;

        case 2:
            cout << "\t\t\t\tRaise Complaint\n " << endl;
            regis_compi();
            cout << endl << endl;
            goto student_menu;
        case 3:
            cout << "\t\t\t\tyou have selected go to main menu\n" << endl << endl;
            break;
        case 4:
            cout << "\t\t\t\tHope You Had a Wonderfull Experiece ,See You Soon in Bennett University!!\n" << endl;
            exit(0);
        default:
            cout << "\t\t\t\tinvalid choice Please try again\n" << endl;
            goto student_menu;
    }

    alloted_menu:
    cout << "\n\n\t\t\t\t----------Student Menu----------\n" << endl;
    cout << "\t\t\t\t1.Raise Complaint \n" << endl;
    cout << "\t\t\t\t2.Back to Main Menu\n" << endl;
    cout << "\t\t\t\t3.Exit\n" << endl << "\t\t\t\t";
    int choice1;
    cin.ignore();
    cin.clear();
    fflush(stdin);
    cin >> choice1;
    switch (choice1) {
        case 1:
            cout << "\t\t\t\tRaise Complaint\n " << endl;
            regis_compi();
            cout << endl << endl;
            goto alloted_menu;
        case 2:
            cout << "\t\t\t\tyou have selected go to main menu\n" << endl << endl;
            break;
        case 3:
            cout << "\t\t\nHope You Had a Wonderfull Experiece ,See You Soon in Bennett University!!\n" << endl;
            exit(0);
        default:
            cout << "\t\t\t\tinvalid choice Please try again\n" << endl;
            goto alloted_menu;
    }
}

//int main() {
//    while (true) {
//        cout << "\t\t\tGood Morning!! Welcome to the Bennett University Hostel Administration Program (Bennett-edorm)\n" << endl;
//        mainMenu:
//        cout << "\n1. Student OR 2. Administrator\n";
//        int cho;
//        cin >> cho;
//        if (cho == 2) {
//            cout << "\t\t\tPlease select your choice\n" << endl;
//            cout << "\t\t\t1. Administrator login\n" << endl;
//            cout << "\t\t\t2. exit\n" << endl << "\t\t\t";
//
//            int choice;
//            cin >> choice;
//
//            if (choice == 1) {
//                cout << "\t\t\tYou have selected Administrator Login\n" << endl;
//                admin_login();
//                goto mainMenu;
//            } else if (choice == 2) {
//                cout << "\t\t\tYou have selected exit\n" << endl;
//                exit(0);
//                cout << "Thank you for coming. Hope to see you soon!!" << endl;
//            } else {
//                cout << "\t\tYou have selected the wrong choice\n" << endl;
//                cout << "\t\tPlease select the correct choice again\n " << endl;
//                cout << endl << endl << endl;
//            }
//
//        } else if (cho == 1) {
//            cout << "\t\tYou have selected Student Login\n" << endl;
//
//            // Offer options for registration or login
//            cout << "\t\t1. Register\n";
//            cout << "\t\t2. Login\n";
//            int studentChoice;
//            cin >> studentChoice;
//
//            if (studentChoice == 1) {
//                registerStudent();  // Register a new student
//            } else if (studentChoice == 2) {
//                student_login();  // Log in as a student
//            } else {
//                cout << "\t\tInvalid choice. Please try again." << endl;
//            }
//        } else {
//            break;
//        }
//    }
//
//    string result = hostel_allotment();
//    if (result == "Room Allocation Completed") {
//        cout << "Room allocation completed successfully." << endl;
//    } else if (result == "No match found") {
//        cout << "No students with the same preferred state found for room allocation." << endl;
//    } else if (result == "empty file") {
//        cout << "Error: Student data file is empty or could not be opened." << endl;
//    }
//    return 0;
//}