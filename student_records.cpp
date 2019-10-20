#include "student_records.hpp"

using namespace std;

Student_information::Student_information(std::string student_details_file) : 
                                    student_details_file(student_details_file){

        binary_student_details_file.open(student_details_file,
                            ios::in|ios::out|ios::app|ios::binary);
   
}

bool Student_information::insert(Student_details student_details){

    if(binary_student_details_file.is_open()){
        binary_student_details_file.write(student_details.first_name,
                                            sizeof(student_details.first_name) );
        binary_student_details_file.write(student_details.middle_name,
                                            sizeof(student_details.middle_name));
        binary_student_details_file.write(student_details.sir_name,
                                            sizeof(student_details.sir_name));
        binary_student_details_file.write(student_details.course,
                                            sizeof(student_details.course));
        binary_student_details_file.write(student_details.class_code,
                                            sizeof(student_details.class_code));
        binary_student_details_file.write(student_details.registration_number,
                                            sizeof(student_details.registration_number));

        return true;
    }

    return false;   
}

Student_details Student_information::retreive(std::string registration_number){

    Student_details student_details;


    if(binary_student_details_file.is_open()){
        binary_student_details_file.seekg(0 ,ios::beg);
        while(!binary_student_details_file.eof()){
            binary_student_details_file.read(student_details.first_name,
                                                sizeof(student_details.first_name));

            binary_student_details_file.read(student_details.middle_name,
                                                sizeof(student_details.middle_name));

            binary_student_details_file.read(student_details.sir_name ,
                                                sizeof(student_details.sir_name));

             binary_student_details_file.read(student_details.course ,
                                                sizeof(student_details.course));

             binary_student_details_file.read(student_details.class_code ,
                                                sizeof(student_details.class_code));

             binary_student_details_file.read(student_details.registration_number ,
                                                sizeof(student_details.registration_number));
            
            
            std::string retreived_registration_number = student_details.registration_number;
                if(registration_number == retreived_registration_number){


                    break;
                }
        }
    }
    return student_details;
}

Student_information::~Student_information(){
        binary_student_details_file.close();
    }
