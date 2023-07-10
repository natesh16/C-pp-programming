#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int rollNumber;
    int marks;
};

std::vector<Student> students;

void addStudent() {
    Student student;
    std::cout << "Enter student name: ";
    std::cin >> student.name;
    std::cout << "Enter roll number: ";
    std::cin >> student.rollNumber;
    std::cout << "Enter marks: ";
    std::cin >> student.marks;
    
    students.push_back(student);
    std::cout << "Student added successfully!\n";
}

void deleteStudent() {
    int rollNumber;
    std::cout << "Enter roll number of the student to delete: ";
    std::cin >> rollNumber;
    
    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            found = true;
            break;
        }
    }
    
    if (found) {
        std::cout << "Student deleted successfully!\n";
    } else {
        std::cout << "Student not found!\n";
    }
}

void displayStudents() {
    if (students.empty()) {
        std::cout << "No students found!\n";
        return;
    }
    
    std::cout << "Student Report:\n";
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << "\n";
        std::cout << "Roll Number: " << student.rollNumber << "\n";
        std::cout << "Marks: " << student.marks << "\n\n";
    }
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "----- Student Report Management -----\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Delete Student\n";
        std::cout << "3. Display Students\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudents();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        
        std::cout << "\n";
    }
}
