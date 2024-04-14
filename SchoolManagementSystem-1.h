#ifndef SCHOOLMANAGEMENTSYSTEM_H
#define SCHOOLMANAGEMENTSYSTEM_H

#include "Student.h"
#include "Course.h"

namespace PA3 {

    class SchoolManagementSystem {
    private:
        Course* courses;
        int numCourses;
        int capacity;
        Student* students;
        int numStudents;
        int studentCapacity;
        int selectedStudentID; 

    public:
        SchoolManagementSystem();
        ~SchoolManagementSystem();
        void addStudent(const std::string& name, int id);
        void deleteStudent(int id);
        void addCourse(const std::string& name, const std::string& code);
        void deleteCourse(const std::string& code) ;
        void enrollStudentInCourse(int studentId, const std::string& courseCode);
        void displayStudents() const;
        void displayCourses() const;
        void displayMenu() const;
        void executeChoice(int choice);
        void displayStudentMenu(); 
        void studentChoice(int choice); 
        void displaySelectiveStudentMenu(); 
        void selectiveStudentLogic(int choice); 
        void courseSubMenu(); 
        void courseLogic(int choice); 
        Course* findCourseByCode(const std::string& code);
        

};
}
#endif

