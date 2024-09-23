Bennett-e-dorm: Hostel Administration Program
Welcome to Bennett-e-dorm, a C++-based Hostel Administration System that ensures seamless management for students and administrators alike. The system employs a friendly interface, incorporating advanced features to enhance the user experience.

Greetings and Menu Options
Upon execution, Bennett-e-dorm extends a warm welcome, varying its greeting based on the time of the day. Users are presented with three main options: Student, Administrator, and Exit.

Student Zone
Registration: Students can register by providing essential details, such as Enroll No. (College ID), Name, Mobile No., Password, and Confirm Password. Stringent checks ensure password accuracy and validate mobile numbers. Successful registrations are recorded in the registered.txt file.

Login: Enrolled students can access the Student Zone by entering their Enroll No. and Password.

Room Allotment: Students have the option to secure a room based on their gender and preferred state. The system intelligently allocates rooms, saving the information in roomallocation.txt. If a room is full, the data is transferred to finalroomallocation.txt.

Raise a Complaint: Students can log complaints, providing their Enroll No., Name, and a brief description of the issue. Complaints are stored in the complaint.txt file, with a confirmation message provided.

Return to Main Menu and Exit options are available.

Administrator Zone
Administrators access the system by entering their credentials.

Show Allotted Students: This feature displays information from finalroomallocation.txt, showcasing students and their respective allotted rooms.

Show All Complaints: Administrators can view complaints lodged by students, sourced from the complaint.txt file.

Return to Main Menu and Exit options are available for administrators.

Implementation Details
The project leverages data structures, including Binary Search Trees and Vectors, to enhance efficiency in data storage and retrieval. With eight .cpp files, including the central main.cpp, the components seamlessly integrate. Information is systematically managed across eight .txt files.

Conclusion
Bennett-e-dorm offers a user-centric approach to hostel administration. Whether you are a student seeking hassle-free accommodation or an administrator in need of streamlined oversight, this system is tailored to meet your requirements. Your valuable feedback is appreciated, and we hope your experience with Bennett-e-dorm is both pleasant and efficient.

Visit our GitHub repository for further details and updates. Thank you for choosing Bennett-e-dorm!
