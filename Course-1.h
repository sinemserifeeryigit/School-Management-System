#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

namespace PA3 {

    class Course {
    private:
        std::string name;
        std::string code; 
        int* studentIds;
        int numStudents;
        int capacity;

    public:
        Course();
        Course(const std::string& name, const std::string& code); 
        ~Course();
        Course(const Course& other);
        Course& operator=(const Course& other);

        const std::string& getName() const;
        void setName(const std::string& name);
        std::string getCode() const; 
        void setCode(const std::string& code); 

        void enrollStudent(int studentId);
        void dropStudent(int studentId);
        void display() const;
        void unenrollStudent(int studentId);
    };

} 

#endif 
