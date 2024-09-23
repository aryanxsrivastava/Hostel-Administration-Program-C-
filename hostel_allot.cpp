#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "giveroom.cpp"
#include "giveroom_Female.cpp"

using namespace std;

struct Student {
    string name;
    string enrollmentNumber;
    string mobileNumber;
    string preferredState;
    string roomNumber;
    string gender;
};

struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Student& s) : student(s), left(nullptr), right(nullptr) {}
};

void removeStudentRecordFromFile(const string& filename, const Student& student) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open the file for reading.\n";
        return;
    }

    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string name, enrollmentNumber, mobileNumber, preferredState, roomNumber, gender;
        if (iss >> name >> enrollmentNumber >> mobileNumber >> preferredState >> roomNumber >> gender) {
            if (name != student.name || enrollmentNumber != student.enrollmentNumber ||
                mobileNumber != student.mobileNumber || preferredState != student.preferredState ||
                gender != student.gender) {
                lines.push_back(line);
            }
        }
    }

    inFile.close();

    ofstream outFile(filename, ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open the file for writing.\n";
        return;
    }

    for (const string& updatedLine : lines) {
        outFile << updatedLine << '\n';
    }
    outFile.close();
}

bool caseInsensitiveStringCompare(const std::string& str1, const std::string& str2) {
    return str1.size() == str2.size() &&
           std::equal(str1.begin(), str1.end(), str2.begin(), [](char a, char b) {
               return tolower(a) == tolower(b);
           });
}


TreeNode* insertIntoBST(TreeNode* root, const Student& student) {
    if (root == nullptr) {
        return new TreeNode(student);
    }

    if (student.preferredState < root->student.preferredState) {
        root->left = insertIntoBST(root->left, student);
    } else {
        root->right = insertIntoBST(root->right, student);
    }

    return root;
}

TreeNode* buildBSTFromStudents(const vector<Student>& students) {
    TreeNode* root = nullptr;
    for (const Student& student : students) {
        root = insertIntoBST(root, student);
    }
    return root;
}

Student allocateRoomForUser(TreeNode* root, const string& userPreferredState, const string& userGender, const string& userEnrollmentNumber) {
    TreeNode* currentNode = root;
    while (currentNode) {
        if (caseInsensitiveStringCompare(userPreferredState, currentNode->student.preferredState) && caseInsensitiveStringCompare(userGender,currentNode->student.gender)) {
            if (currentNode->student.roomNumber.empty()) {
                // Allocate the room to the user

                string roomCounter = giveroom();
                currentNode->student.roomNumber = (userGender == "M" ? "c1-" : "d1-") + roomCounter;
                removeStudentRecordFromFile("students.txt", currentNode->student);
                return currentNode->student;
            } else if (caseInsensitiveStringCompare(currentNode->student.enrollmentNumber,userEnrollmentNumber)) {
                // A matching student with an already allocated room found
                Student alreadyAllottedStudent = currentNode->student;
                return alreadyAllottedStudent;
            } else {
                // A matching student with a different enrollment number and an allocated room found
                // Allocate the same room to the user
                Student userRoommate = currentNode->student;
                return userRoommate;
            }
        } else if (userPreferredState < currentNode->student.preferredState) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    Student noMatch;
    noMatch.name = "No match found";
    return noMatch;
}

vector<Student> loadStudentsFromFile(const string& filename) {
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open the file.\n";
        return students;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Student student;
        if (iss >> student.name >> student.enrollmentNumber >> student.mobileNumber >> student.preferredState >> student.roomNumber >> student.gender) {
            students.push_back(student);
        }
    }

    file.close();
    return students;
}

void assignRoomNumbers(TreeNode* root, const string& roomPrefix, const string& userGender, int& roomCounter) {
    if (root) {
        assignRoomNumbers(root->left, roomPrefix, userGender, roomCounter);
        if (root->student.name != "No match found" && root->student.gender == userGender) {
            root->student.roomNumber = roomPrefix + to_string(roomCounter);
            roomCounter++;
        }
        assignRoomNumbers(root->right, roomPrefix, userGender, roomCounter);
    }
}
long long int_input() {
    long long user_input;
    while (true) {
        string input;
        cin >> input;
        stringstream stream(input);

        if (stream >> user_input) {
            break;
        } else {
            cout << "Invalid input. Please enter numerical values." << endl;
        }
    }
    return user_input;
}


string hostel_allotment() {
    vector<Student> students = loadStudentsFromFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\room_allocation.txt");

    TreeNode* studentBST = buildBSTFromStudents(students);

    string userPreferredState, userGender, userName, userEnrollmentNumber;
    string userMobileNumber;

    cout << "Enter your name(only first name): ";
    cin >> userName;
    cout << endl;

    cout << "Enter your enrollment number: ";
    cin >> userEnrollmentNumber;
    cout << endl;

    while(true){
        cout << "Enter your mobile number: ";
        userMobileNumber = to_string(int_input());

        if(userMobileNumber.length()!=10){cout<<"Please enter valid mobile number.\n";}
        else{cout << endl;break;}
    }

    cout << "Enter your preferred state: ";
    cin >> userPreferredState;
    cout << endl;

    cout << "Enter your gender (M/F): ";
    cin >> userGender;
    cout << endl;

    Student userStudent;
    userStudent.name = userName;
    userStudent.enrollmentNumber = userEnrollmentNumber;
    userStudent.mobileNumber = userMobileNumber;
    userStudent.preferredState = userPreferredState;
    userStudent.gender = userGender;


    Student userRoommate = allocateRoomForUser(studentBST, userPreferredState, userGender, userEnrollmentNumber);
    if (userRoommate.name != "No match found") {
        ofstream outFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\final_list.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "USER INFORMATION:\n";
            outFile << "Name: " << userStudent.name << "\n";
            outFile << "Enrollment Number: " << userStudent.enrollmentNumber << "\n";
            outFile << "Mobile Number: " << userStudent.mobileNumber << "\n";
            outFile << "Gender: " << userStudent.gender << "\n";
            outFile << "Preferred State: " << userStudent.preferredState << "\n";
            outFile << "________________________________________________________________________" << "\n";
            outFile << "ROOMMATE INFORMATION::\n";
            outFile << "Name: " << userRoommate.name << "\n";
            outFile << "Enrollment Number: " << userRoommate.enrollmentNumber << "\n";
            outFile << "Mobile Number: " << userRoommate.mobileNumber << "\n";
            outFile << "Gender: " << userRoommate.gender << "\n";
            outFile << "Room Number: " << userRoommate.roomNumber << "\n\n";
            outFile << "________________________________________________________________________" << "\n\n";
            outFile << "________________________________________________________________________" << "\n\n";
            outFile.close();
            removeStudentRecordFromFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\room_allocation.txt", userRoommate);
            cout << "You have been allotted Room Number: " << userRoommate.roomNumber << endl;
            return userRoommate.name;
        } else {
            cerr << "Error: Could not open the output file.\n";
            return "Not Found";
        }
    } else {
        if(caseInsensitiveStringCompare(userGender , "M")){

            string roomCounter = giveroom();
            userStudent.roomNumber = "C1-"+roomCounter;
        }else if(caseInsensitiveStringCompare(userGender , "F")){

            string roomCounter = giveroom_female();
            userStudent.roomNumber = "D1-"+roomCounter;
        }

//        userStudent.roomNumber = (caseInsensitiveStringCompare(userGender , "M") ? "c1-" : "d1-") + roomCounter;
        students.push_back(userStudent);
        ofstream studentFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\room_allocation.txt");
        if (studentFile.is_open()) {
            for (const Student& s : students) {
                studentFile << s.name << " " << s.enrollmentNumber << " " << s.mobileNumber
                            << " " << s.preferredState << " " << s.roomNumber << " " << s.gender << "\n";
            }
            studentFile.close();
            cout << "You have been allotted Room Number: " << userStudent.roomNumber << endl;
            return "Not Found";
        } else {
            cerr << "Error: Could not open the output file.\n";
            return "No Found";
        }
    }
}