#include<bits/stdc++.h>
#include "otherEssentialMethods.cpp"


using namespace std;



// brief
// return
int main() {
    while (true) {
        cout << "\t\t\tGood Morning!! Welcome to the Bennett University Hostel Administration Program (Bennett-edorm)" << endl;
        mainMenu:
        cout << "\n1. Student \n\n";
        cout<< "2. Administrator  \n\n";
        cout<<"3. Exit\n\n";
        string cho;
        cin >> cho;
          if (cho == "2") {
            cout << "\t\t\tPlease select your choice\n" << endl;
            cout << "\t\t\t1. Administrator login\n" << endl;
              cout << "\t\t\t2. Go Back\n" << endl << "\t\t\t";
            cout << "3. exit\n" << endl << "\t\t\t";

            string choice;
            cin >> choice;

              if (choice == "1") {
                  cout << "\t\t\tYou have selected Administrator Login\n" << endl;
                  admin_login();
                  goto mainMenu;

              }
              else if (choice == "2") {
                  goto mainMenu;

              }
              else if (choice == "3") {
                  cout << "\t\t\tYou have selected exit" << endl;
                  cout << "\nThank you for coming. Hope to see you soon!!" << endl;
                  exit(0);

              } else {
                  cout << "\t\tYou have selected the wrong choice\n" << endl;
                  cout << "\t\tPlease select the correct choice again\n " << endl;
                  cout << endl << endl << endl;
              }

          } else if (cho == "1") {
            cout << "\t\tYou have selected Student Login\n" << endl;

            // Offer options for registration or login
            cout << "\t\t1. Register\n";
            cout << "\t\t2. Login\n";
            cout << "\t\t3. Go Back\n";
            string studentChoice;
            cin >> studentChoice;

            if (studentChoice == "1") {
                registerStudent();  // Register a new student
            } else if (studentChoice == "2") {
                student_login();  // Log in as a student
            } else if (studentChoice == "3"){
                goto mainMenu;
                
            }
            else{
                cout << "\t\tInvalid choice. Please try again." << endl;
            }
        } else if (cho=="3") {
              cout<<"\t\t\t\tHope You Had a Wonderfull Experiece ,See You Soon in Bennett University!!\n"<<endl;
              break;

        }
    }

//    cout<<hostel_allotment()<<endl;
    return 0;
}