#include "Course.h"

namespace PA3 {

        Course::Course() : code(""), studentIds(nullptr), numStudents(0), capacity(10) { // Initialize code as an empty string
        studentIds = new int[capacity];
    }

    Course::Course(const std::string& name, const std::string& code) : name(name), code(code), studentIds(new int[10]), numStudents(0), capacity(10) {}


    Course::~Course() {
        delete[] studentIds;
    }

    Course::Course(const Course& other) : name(other.name), code(other.code), numStudents(other.numStudents), capacity(other.capacity) {
        studentIds = new int[capacity];
        for (int i = 0; i < numStudents; ++i) {
            studentIds[i] = other.studentIds[i];
        }
    }

    Course& Course::operator=(const Course& other) {
        if (this != &other) {
            delete[] studentIds;
            name = other.name;
            code = other.code;
            numStudents = other.numStudents;
            capacity = other.capacity;
            studentIds = new int[capacity];
            for (int i = 0; i < numStudents; ++i) {
                studentIds[i] = other.studentIds[i];
            }
        }
        return *this;
    }

  const std::string& Course::getName() const {
        return name;
    }

    void Course::setName(const std::string& name) {
        this->name = name;
    }

    std::string Course::getCode() const { 
        return code;
    }

    void Course::setCode(const std::string& code) { 
        this->code = code;
    }

    void Course::enrollStudent(int studentId) {
        if (numStudents == capacity) {
            capacity *= 2;
            int* temp = new int[capacity];
            for (int i = 0; i < numStudents; ++i) {
                temp[i] = studentIds[i];
            }
            delete[] studentIds;
            studentIds = temp;
        }
        studentIds[numStudents++] = studentId;
    }

    void Course::dropStudent(int studentId) {
        int index = -1;
        for (int i = 0; i < numStudents; ++i) {
            if (studentIds[i] == studentId) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < numStudents - 1; ++i) {
                studentIds[i] = studentIds[i + 1];
            }
            --numStudents;
        }
    }

  void Course::display() const {
        std::cout << "Course Name: " << name << ", Code: " << code << std::endl;
    }

    void Course::unenrollStudent(int studentId) {
        for (int i = 0; i < this->numStudents; ++i) {
            if (this->studentIds[i] == studentId) {
            
                for (int j = i; j < this->numStudents - 1; ++j) {
                this->studentIds[j] = this->studentIds[j + 1];
            }
            
            this->numStudents--;
            break; 
        }
    }
}



} 
