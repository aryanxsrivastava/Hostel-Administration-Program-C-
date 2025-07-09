
# 🏨 Hostel Administration Program (C)

A console-based C application to manage hostel operations—student registration, room allotment, fee tracking, and record management—built for educational purposes and lightweight use.

> ⚠️ **Disclaimer:** This project is intended for learning and practice only. It is not recommended for production use without additional security and error handling.

---

## 🚀 Features

- 🌟 Student registration and details maintenance  
- 🛏️ Room allocation & deallocation  
- 💲 Fee payment and tracking  
- 🔍 Search & view student and room records  
- 🧹 Delete or update existing entries  
- 💾 Data persistence using binary file I/O  
- ✔️ Menu-driven interface, easy to navigate

---

## 🗂️ Project Structure

```
Hostel-Administration-Program-C
├── main.c
├── hostel.h
├── hostel.c
├── data/
│   ├── students.dat
│   └── rooms.dat
└── README.md
```

---

## 🛠️ Requirements

- C compiler (like `gcc` or `clang`)
- Compatible on Windows, Linux, and macOS

---

## 🎯 Build & Run

1. **Clone the Repo**
   ```bash
   git clone https://github.com/aryanxsrivastava/Hostel-Administration-Program-C-.git
   cd Hostel-Administration-Program-C-
   ```

2. **Compile**
   ```bash
   gcc main.c hostel.c -o hostel-admin
   ```

3. **Run**
   ```bash
   ./hostel-admin
   ```

---

## 📋 Menu Overview

```text
================ Hostel Administration ================
1. Add New Student
2. Allocate Room
3. Record Fee Payment
4. View Student Record
5. View Room Status
6. Update Student Details
7. Delete Student Record
0. Exit
Enter your choice:
```

Choose a number to access functionality. Input prompts will guide through details.

---

## 🧪 Demo Session

```text
Enter your choice: 1
Enter student name: John Doe
Enter age: 20
Enter course: B.Tech
...
[+] Student added (ID: 101)

Enter your choice: 2
Enter student ID: 101
Enter room number: 203
[+] Room 203 allotted to student 101

Enter your choice: 3
Enter student ID: 101
Enter amount paid: 1500
[+] Fee recorded

Enter your choice: 4
Enter student ID: 101
Student: John Doe | Room: 203 | Fee paid: 1500
```

---

## 🧠 How It Works

- **Data Models**: Defined in `hostel.h` (`Student`, `Room`)
- **Operations**: Implemented in `hostel.c`—handles CRUD and file operations
- **Persistence**: Student and room data stored in `students.dat` and `rooms.dat`
- **Error Handling**: Input validation and basic checks (e.g. room availability)

---

## 🧩 Future Improvements

- ✅ Input validation (e.g. duplicate IDs)
- ✅ Fee status reports (e.g. pending dues)
- 🔄 Backup and restore data
- 🔐 User authentication for admin
- 🗃️ CSV export/import for records

---


## 🙋 Author

**Aryan Srivastava**  
[GitHub](https://github.com/aryanxsrivastava)

---

> ⭐ If you find this useful, please ★ the repo!
