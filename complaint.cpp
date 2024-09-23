#include <bits/stdc++.h>

using namespace std;

class Complaint{
    private:
    int complaint_no;
    string student_name  ;
    string complaint_text  ;

    public:
    Complaint(int complaint_no){
        this->complaint_no = complaint_no;
    }

    ///setter methods---------------------------------------------------------------------------------
    void set_student_name(string student_name){
        this->student_name = student_name ;
    }
    void set_complaint_text(string complaint_text){
        this->complaint_text = complaint_text ;



    }

    ///getter methods---------------------------------------------------------------------------------
    int get_complaint_no(){
        return complaint_no ;
    }
    string get_complaint_text(){
        return complaint_text ;
    }
    string get_student_name(){
        return student_name ;
    }
};
int countLinesInFile(const std::string& filename="E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\complaint.txt") {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return -1;  // Error code
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }

    file.close();  // Close the file when you're done with it

    return lineCount;
}

void write_complaint(Complaint complaint,string enrol){
    string a = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\complaint.txt";
    fstream out ;
    int a1=countLinesInFile();
    out.open(a.c_str(),ios::app);
    out<< a1+1<<" "<<complaint.get_student_name()<<" "<< enrol <<":-> "<<complaint.get_complaint_text()<<endl;
    out.close();

}


void regis_compi(){
    string stu_name;
    string enroll;
    string compi_desc;
    cout<<"Enter the Name :-\n";cin.ignore();
    getline(cin, stu_name);
    cin.unget();
    cout<<endl;
    cout<<"Enter the Enrollment no. :-\n";
    cin>>enroll;
    cout<<endl;
    cout<<"Write a complaint(in brief):-";cin.ignore();
    getline(cin, compi_desc);
    cin.unget();
    Complaint cmp1=*new Complaint(1);
    cmp1.set_student_name(stu_name);
    cmp1.set_complaint_text(compi_desc);
    write_complaint(cmp1,enroll);
    cout<<endl;
    cout<<"Thank you!! Your complaint is registered,soon your issue will be resolved."<<endl;
}









