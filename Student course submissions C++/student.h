//
// Created by nick on 2/28/2023.
//

#ifndef INC_2_2_STUDENT_H
#define INC_2_2_STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student{
    public:
        //default constructor
        Student()
        {
            name = "";
            numCourses = 0;
            courseListSize = 1;
            courseList = new string[courseListSize];
        }

        //Copy Constructor
        Student(const Student& studentToCopy)
        {
            cout << "Using copy constructor." << endl;
            name = studentToCopy.name;
            numCourses = studentToCopy.numCourses;
            courseListSize = studentToCopy.courseListSize;

            //We need to make a new array for the student so that it is not sharing a pointer with
            //the previous array.
            courseList = new string [courseListSize];
            for (int courseIndex = 0; courseIndex < numCourses; courseIndex++)
            {
                courseList[courseIndex] = studentToCopy.courseList[courseIndex];
            }
        }

        //Destructor
        ~Student()
        {
            cout << "Using destructor." << endl;

            if (courseList != nullptr)
            {
                //We only need to manually destroy the dynamic array because, other member variables are automatically destroyed.
                courseList = nullptr;
            }

        }

        //Assignment Operator declaration
        Student& operator=(const Student &otherStudent)
        {
            cout << "Using assignment operator." << endl;

            //if the object is trying to run the function on its self just return without copying
            if (this != &otherStudent) {
                //clear any lists the object was using
                delete[] courseList;

                //Copy the properties of the other student.
                this->courseListSize = otherStudent.courseListSize;
                this->courseList = otherStudent.courseList;
                this->numCourses = otherStudent.numCourses;
            }

            //return a pointer to the new object.
            return *this;
        }


        //Methods
        void addCourse();
        void printCourses();
        void resizeCourseList();
        void resetCourseList();
        bool addCoursePrompt();

        //getters and setters
        const string &getName() const {return name;}

        void setName(const string &name) {Student::name = name;}

        int getNumCourses() const {return numCourses;}

        void setNumCourses(int numCourses) {Student::numCourses = numCourses;}

        string *getCourseList() const {return courseList;}

        void setCourseList(string *courseList) {Student::courseList = courseList;}

        int getCourseListSize() const {return courseListSize;}

        void setCourseListSize(int courseListSize) {Student::courseListSize = courseListSize;}


    private:
        string name;
        int numCourses;
        string *courseList;
        int courseListSize;
    };//End student class


#endif //INC_2_2_STUDENT_H

