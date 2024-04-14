#include "Student.h"
#include <iostream>

namespace PA3 {

    // default constrctor
    Student::Student() : name(""), id(-1), courseIds(new std::string[1]), numCourses(0), capacity(1) {}

    Student::Student(const std::string& name, int id) : name(name), id(id), courseIds(new std::string[1]), numCourses(0), capacity(1) {}

    // destructor
    Student::~Student() {
        delete[] courseIds;
    }

    // copy Constructor
    Student::Student(const Student& other) : name(other.name), id(other.id), numCourses(other.numCourses), capacity(other.capacity) {
        courseIds = new std::string[capacity];
        for (int i = 0; i < numCourses; ++i) {
            courseIds[i] = other.courseIds[i];
        }
    }

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] courseIds;
            name = other.name;
            id = other.id;
            numCourses = other.numCourses;
            capacity = other.capacity;
            courseIds = new std::string[capacity];
            for (int i = 0; i < numCourses; ++i) {
                courseIds[i] = other.courseIds[i];
            }
        }
        return *this;
    }

    // getter and setter implementation
    const std::string& Student::getName() const { return name; }
    void Student::setName(const std::string& name) { this->name = name; }
    int Student::getId() const { return id; }
    void Student::setId(int id) { this->id = id; }

  
    void Student::enrollCourse(const std::string& courseId) {
    //checking
    for (int i = 0; i < numCourses; i++) {
        if (courseIds[i] == courseId) return; 
    }

  
    if (numCourses == capacity) {
        resizeCourseArray(capacity * 2);
    }
    courseIds[numCourses++] = courseId;
}


  
    void Student::dropCourse(const std::string& courseId) {
    int index = -1;
    for (int i = 0; i < numCourses; i++) {
        if (courseIds[i] == courseId) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < numCourses - 1; i++) {
            courseIds[i] = courseIds[i + 1];
        }
        numCourses--;
    }
}


  
    void Student::display() const {
        std::cout << "Student Name: " << name << ", ID: " << id << ", Enrolled Courses: " << numCourses << std::endl;
    }

    void Student::unenrollCourse(const std::string& courseId) {
    for (int i = 0; i < this->numCourses; ++i) {
        if (this->courseIds[i] == courseId) { 
            for (int j = i; j < this->numCourses - 1; ++j) {
                this->courseIds[j] = this->courseIds[j + 1];
            }
            
            this->numCourses--;
            break; 
        }
    }
}




}
