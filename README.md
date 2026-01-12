# School Management System 📖

A robust, console-based application designed to streamline the administration of educational institutions. Built with **C++** and centered around **Object-Oriented Programming (OOP)** principles, this system handles records for students, teachers, and staff with persistent data storage.

---

## 🚀 Features

* **Student Management**: Add, update, view, and delete student records (IDs, grades, attendance).
* **Teacher Management**: Track faculty details, subjects assigned, and contact information.
* **Administrative Control**: Secure login for administrators to manage school-wide data.
* **Persistent Storage**: Utilizes C++ **File Handling** (`fstream`) to save data in `.txt` or `.dat` files, ensuring information is retained after the program closes.
* **Search Functionality**: Quickly find records using unique IDs or names.
* **Clean Console UI**: Organized menus and input validation for a smooth user experience.

---

## 🛠️ Technical Architecture

The system leverages core OOP concepts to ensure the code is modular and scalable:

* **Encapsulation**: Data members are kept private, accessed through public getter and setter functions.
* **Inheritance**: A base `Person` class is extended by `Student` and `Teacher` classes to reduce code redundancy.
* **Polymorphism**: Overloaded functions and virtual methods for flexible record handling.
* **File I/O**: Efficient reading/writing streams to maintain a local database.



---

## 💻 Getting Started

### Prerequisites
* A C++ compiler (GCC/G++, Clang, or MSVC).
* Code Editor or IDE (VS Code, Code::Blocks, or Dev-C++).

### Installation & Execution
1. **Clone the repository**:
   ```bash
   git clone [https://github.com/raymondoyondi/School-Management-System.git](https://github.com/raymondoyondi/School-Management-System.git)
