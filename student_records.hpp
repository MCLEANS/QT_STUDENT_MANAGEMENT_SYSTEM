#ifndef STUDENT_RECORDS_HPP
#define STUDENT_RECORDS_HPP

#include <string.h>
#include <iostream>
#include <fstream>


    struct Student_details
    {
        char first_name[20];
        char middle_name[20];
        char sir_name[20];
        char course[50];
        char class_code[50];
        char registration_number[50];
        
    };
    

    class Student_information{
        private:
            std::string student_details_file;
            std::fstream binary_student_details_file;
        private:
        public:
        public:
            Student_information(std::string student_details_file);
            bool insert(Student_details student_details);
            Student_details retreive(std::string registration_number);
            ~Student_information();
    };




#endif //_STUDENT_RECORDS_HPP
