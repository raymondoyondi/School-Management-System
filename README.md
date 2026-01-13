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

2.  **Navigate to the directory**:
    ```bash
    cd School-Management-System
    ```
3.  **Create a build directory and run CMake**:
    ```
    mkdir build
    cd build
    cmake ..
    ```
4.  **Compile the source code** using the generated build system:
    ```
    make
    ```
    
5.  **Run the executable**:
    ```bash
    ./school_management_system
    ```
    
---
## 👋 Contributing
We welcome contributions to enhance the School Management System! Whether it's bug fixes, new features, or improvements to the documentation, your help is appreciated.

To contribute:
1.  **Fork the repository** on GitHub.
2.  **Create a new branch** for your feature or fix: `git checkout -b feature/AmazingFeature`
3.  **Commit your changes** with descriptive commit messages: `git commit -m 'Add some AmazingFeature'`
4.  **Push to the branch**: `git push origin feature/AmazingFeature`
5.  **Open a Pull Request** against the `main` branch of the original repository, describing your changes and linking any relevant issues.

Please ensure your code adheres to the project's coding standards and includes appropriate comments.
---
## ⚖️ License
Distributed under the [MIT License](github.com). See the `LICENSE` file in the repository root for more information.
