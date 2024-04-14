#include "SchoolManagementSystem.h"

namespace PA3 {

    SchoolManagementSystem::SchoolManagementSystem() : courses(new Course[10]), numCourses(0), capacity(10), students(new Student[10]), numStudents(0), studentCapacity(10) {}

    SchoolManagementSystem::~SchoolManagementSystem() {
        delete[] courses;
        delete[] students;
    }

    void SchoolManagementSystem::addStudent(const std::string& name, int id) {
        if (numStudents >= studentCapacity) {
            int newCapacity = studentCapacity * 2;
            Student* temp = new Student[newCapacity];
            for (int i = 0; i < numStudents; ++i) {
                temp[i] = students[i];
            }
            delete[] students;
            students = temp;
            studentCapacity = newCapacity;
        }
        students[numStudents++] = Student(name, id);
    }

    void SchoolManagementSystem::deleteStudent(int id) {
        for (int i = 0; i < numStudents; ++i) {
            if (students[i].getId() == id) {
                for (int j = i; j < numStudents - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --numStudents;
                break;
            }
        }
    }

    void SchoolManagementSystem::addCourse(const std::string& name,const std::string& code) {
        if (numCourses >= capacity) {
            int newCapacity = capacity * 2;
            Course* temp = new Course[newCapacity];
            for (int i = 0; i < numCourses; ++i) {
                temp[i] = courses[i];
            }
            delete[] courses;
            courses = temp;
            capacity = newCapacity;
        }
        courses[numCourses++] = Course(name, code);
    }

void SchoolManagementSystem::deleteCourse(const std::string& code) {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].getCode() == code) {
            for (int j = i; j < numCourses - 1; ++j) {
                courses[j] = courses[j + 1];
            }
            --numCourses;
            break;
        }
    }
}


    void SchoolManagementSystem::enrollStudentInCourse(int studentId, const std::string& courseCode) {
    Student* student = nullptr;
    Course* course = nullptr;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].getId() == studentId) {
            student = &students[i];
            break;
        }
    }
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].getCode() == courseCode) {
            course = &courses[i];
            break;
        }
    }
    if (student && course) {
        student->enrollCourse(courseCode);
        course->enrollStudent(studentId);
    }
}


    void SchoolManagementSystem::displayStudents() const {
        if (numStudents > 0) {
            for (int i = 0; i < numStudents; ++i) {
            students[i].display();
        }
    }   else {
           // std::cout << "There are no students to be shown." << std::endl;
    }
}


    void SchoolManagementSystem::displayCourses() const {
        for (int i = 0; i < numCourses; ++i) {
            courses[i].display();
        }
    }

     void SchoolManagementSystem::displayMenu() const {
        
        std::cout << "0: exit\n";
        std::cout << "1: students\n";
        std::cout << "2: courses\n";
        std::cout << "3: list all students\n";
        std::cout << "4: list all courses\n";
    }
    
    void SchoolManagementSystem::displayStudentMenu() {
        std::cout << "Student Menu\n";
        std::cout << "0: up\n";
        std::cout << "1: add_student\n";
        std::cout << "2: select_student\n";
    }

void SchoolManagementSystem::studentChoice(int choice) {
    std::string name;
    int studentID;
    switch(choice) {
        case 0:
            std::cout << "Exiting...\n";
            break;
        case 1: {
            std::string inputLine, name;
            int studentID = -1;
            //std::cout << "Enter student name and ID: ";
            
            // reading entire line
            std::getline(std::cin >> std::ws, inputLine);
            // finding the when name ends id starts
            size_t lastSpace = inputLine.find_last_of(" ");
            if (lastSpace != std::string::npos && lastSpace + 1 < inputLine.size()) {
                name = inputLine.substr(0, lastSpace); 
                std::string idStr = inputLine.substr(lastSpace + 1); 
                studentID = std::stoi(idStr); 
                
                addStudent(name, studentID);
                //std::cout << "Student added successfully.\n";
            } else {
                //std::cerr << "Input format error. Please enter name followed by ID." << std::endl;
            }
            break;
        }
        case 2: {
            std::string inputLine, name;
             int studentID = -1;
            //std::cout << "Enter student name and ID to select: ";


            std::getline(std::cin >> std::ws, inputLine);

            size_t lastSpace = inputLine.find_last_of(" ");
                if (lastSpace != std::string::npos && lastSpace + 1 < inputLine.size()) {
                name = inputLine.substr(0, lastSpace);
                std::string idStr = inputLine.substr(lastSpace + 1);
                studentID = std::stoi(idStr);

                selectedStudentID = studentID; 

                displaySelectiveStudentMenu();
                int subChoice;
                std::cin >> subChoice;
                selectiveStudentLogic(subChoice);
    }           else {
                std::cerr << "wrong input\n" << std::endl;
    }
        break;


        }
        default:
            //std::cout << "invalid choice\n";
    }
}



    void SchoolManagementSystem::displaySelectiveStudentMenu() {
        std::cout << "Selective student menu\n";
        std::cout << "0: up\n" ;
        std::cout << "1: delete student\n";
        std::cout << "2: add selective student to a course\n";
        std::cout << "3: drop selective student from a course\n";
    }

void SchoolManagementSystem::selectiveStudentLogic(int choice) {
    std::string courseCode;
    switch(choice) {
        case 0:
            //std::cout << "Exiting...\n";
            break;
        case 1:
            //std::cout << "Deleting student...\n";
            deleteStudent(selectedStudentID);
            //std::cout << "Student deleted successfully.\n";
            break;
        case 2:
            //std::cout << "Enter course code to add: ";
            std::cin >> courseCode;
            enrollStudentInCourse(selectedStudentID, courseCode);
            //std::cout << "Student added to course successfully.\n";
            break;
        case 3:
            //std::cout << "Enter course code to drop: ";
            std::cin >> courseCode;
            //std::cout << "Student dropped from course successfully.\n";
            break;
        default:
            //std::cout << "Invalid choice. Please try again.\n";
    }
}


    void SchoolManagementSystem::courseSubMenu() {
        std::cout << "Course Sub Menu\n";
        std::cout << "0: Up\n";
        std::cout << "1: Add Course\n";
        std::cout << "2: Select Course\n";
    }

void SchoolManagementSystem::courseLogic(int choice) {
    std::string name;
    int courseCode;
    switch(choice) {
        case 0:
            //std::cout << "Exiting...\n";
            break;
        case 1: {
    std::string inputLine, courseCode, courseName;
    //std::cout << "Enter course code and course name: ";

    
    std::getline(std::cin >> std::ws, inputLine);

    
    size_t firstSpace = inputLine.find(' ');
    if (firstSpace != std::string::npos) {
        courseCode = inputLine.substr(0, firstSpace);
        courseName = inputLine.substr(firstSpace + 1);
    } else {
        //std::cout << "Invalid input format." << std::endl;
        break;
    }

    addCourse(courseName, courseCode);
    break;
}

        case 2: {
    std::string inputLine;
    std::string courseCode;
    //std::cout << "Enter course code and course name: ";


    std::getline(std::cin >> std::ws, inputLine);


    size_t firstSpace = inputLine.find(' ');
    if (firstSpace != std::string::npos) {
        courseCode = inputLine.substr(0, firstSpace);
    } else {
        //std::cout << "Invalid input format." << std::endl;
        break;
    }

    Course* selectedCourse = findCourseByCode(courseCode);
    if (selectedCourse != nullptr) {
        //std::cout << "Course selected: " << selectedCourse->getName() << std::endl;
    } else {
        //std::cout << "Course not found.\n";
    }
    break;
}

        default:
            //std::cout << "Invalid choice. Please try again.\n";
    }
}



   void SchoolManagementSystem::executeChoice(int choice) {
    switch (choice) {
        case 0:
            //std::cout << "Exiting...\n";
            break;
        case 1:
            while (true) {
                displayStudentMenu();
                int studentMenuChoice;
                std::cin >> studentMenuChoice;
                if (studentMenuChoice == 0) {
                    break;  
                }
                studentChoice(studentMenuChoice);
            }
            break;
        case 2:
            while (true) {
                courseSubMenu();
                int courseMenuChoice;
                std::cin >> courseMenuChoice;
                if (courseMenuChoice == 0) {
                    break; 
                }
                courseLogic(courseMenuChoice);
            }
            break;
        case 3:
            displayStudents();
            break;
        case 4:
            displayCourses();
            break;
        default:
            //std::cout << "Invalid choice. Please try again.\n";
    }
}



         Course* SchoolManagementSystem::findCourseByCode(const std::string& code) {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].getCode() == code) {
            return &courses[i];
        }
    }
    return nullptr;  
}
}


       
