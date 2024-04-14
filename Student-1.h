#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

namespace PA3 {

    class Student {
    private:
        std::string name;
        int id;
        std::string* courseIds;
        int numCourses;
        int capacity;
        void resizeCourseArray(int newCapacity) {
            std::string* temp = new std::string[newCapacity];
            for (int i = 0; i < numCourses; ++i) {
                temp[i] = courseIds[i];
            }
            delete[] courseIds;
            courseIds = temp;
            capacity = newCapacity;
        }

    public:
        Student();
        Student(const std::string& name, int id);
        ~Student();
        Student(const Student& other);
        Student& operator=(const Student& other);

        const std::string& getName() const;
        void setName(const std::string& name);
        int getId() const;
        void setId(int id);
        void enrollCourse(const std::string& courseId);
        void dropCourse(const std::string& courseId);
        void display() const;
        void unenrollCourse(const std::string& courseId);

    };

} 

#endif 
