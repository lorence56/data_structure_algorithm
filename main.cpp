#include <iostream>
#include <string>

// Structure for Course
struct Course {
    std::string course_code;
    std::string course_name;
};

// Structure for Grade
struct Grade {
    int mark;
    char the_grade;
};

// Structure for Student
struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
};

// Function to calculate grade based on the mark
char calculateGrade(int mark) {
    if (mark > 69)
        return 'A';
    else if (mark > 59)
        return 'B';
    else if (mark > 49)
        return 'C';
    else if (mark > 39)
        return 'D';
    else
        return 'E';
}

// Function to add a student
void addStudent(Student students[], int& studentCount) {
    if (studentCount <= 40) {
        Student newStudent;
        std::cout << "Enter registration number: ";
        std::cin >> newStudent.registration_number;
        std::cout << "Enter name: ";
        std::cin >> newStudent.name;
        std::cout << "Enter age: ";
        std::cin >> newStudent.age;
        std::cout << "Enter course code: ";
        std::cin >> newStudent.course.course_code;
        std::cout << "Enter course name: ";
        std::cin >> newStudent.course.course_name;

        students[studentCount++] = newStudent;

        std::cout << "Student added successfully!\n";
    } else {
        std::cout << "Maximum number of students reached!\n";
    }
}

// Function to edit a student's details
void editStudent(Student students[], int studentCount) {
    std::string regNum;
    std::cout << "Enter registration number of the student to edit: ";
    std::cin >> regNum;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].registration_number == regNum) {
            std::cout << "Enter new registration number: ";
            std::cin >> students[i].registration_number;
            std::cout << "Enter new name: ";
            std::cin >> students[i].name;
            std::cout << "Enter new age: ";
            std::cin >> students[i].age;
            std::cout << "Enter new course code: ";
            std::cin >> students[i].course.course_code;
            std::cout << "Enter new course name: ";
            std::cin >> students[i].course.course_name;

            std::cout << "Student details updated successfully!\n";
            return;
        }
    }

    std::cout << "Student not found!\n";
}

// Function to add marks and calculate grades
void addMarks(Student students[], int studentCount) {
    std::string regNum;
    std::cout << "Enter registration number of the student to add marks: ";
    std::cin >> regNum;

    for (int i = 0; i < studentCount; ++i) {
        if (students[i].registration_number == regNum) {
            std::cout << "Enter marks for " << students[i].name << ": ";
            std::cin >> students[i].grades.mark;

            // Calculate grade and store in the_grade
            students[i].grades.the_grade = calculateGrade(students[i].grades.mark);

            std::cout << "Marks and grades added successfully!\n";
            return;
        }
    }

    std::cout << "Student not found!\n";
}

int main() {
    Student students[40];
    int studentCount = 0;
    int choice;

    do {
        std::cout << "\n1. Add a student\n";
        std::cout << "2. Edit a student's details\n";
        std::cout << "3. Add marks and calculate grades\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarks(students, studentCount);
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

