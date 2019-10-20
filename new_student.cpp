#include "new_student.h"
#include "ui_new_student.h"
#include <string.h>
#include <QMessageBox>


NEW_STUDENT::NEW_STUDENT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NEW_STUDENT)
{
    ui->setupUi(this);
}

NEW_STUDENT::~NEW_STUDENT()
{
    delete  student_information;
    delete ui;
}

void NEW_STUDENT::on_new_student_fom_status_accepted()
{
    if(ui->lineEdit_first_name->text().isEmpty() ||
            ui->lineEdit_middle_name->text().isEmpty() ||
            ui->lineEdit_sir_name->text().isEmpty() ||
            ui->lineEdit_course->text().isEmpty() ||
            ui->lineEdit_class_code->text().isEmpty() ||
            ui->lineEdit_registration_number->text().isEmpty()){
        QMessageBox::warning(this,
                                tr("ERROR"),
                                tr("All fields are required before submission"),
                                QMessageBox::Ok);
        return;
    }
    student_information = new Student_information("F:\\QT_software\\QT_PROJECTS\\SCHOOL_MANAGEMENT\\bin\\binary_file.bin");
    Student_details student_details;

    std::string first_name =( ui->lineEdit_first_name->text()).toStdString();
    strcpy( student_details.first_name,first_name.c_str());

    std::string middle_name = (ui->lineEdit_middle_name->text()).toStdString();
    strcpy(student_details.middle_name,middle_name.c_str());

    std::string sir_name = (ui->lineEdit_sir_name->text()).toStdString();
    strcpy(student_details.sir_name,sir_name.c_str());

    std::string course = (ui->lineEdit_course->text()).toStdString();
    strcpy(student_details.course,course.c_str());

    std::string class_code = (ui->lineEdit_class_code->text()).toStdString();
    strcpy(student_details.class_code,class_code.c_str());

    std::string registration_number = (ui->lineEdit_registration_number->text()).toStdString();
    strcpy(student_details.registration_number,registration_number.c_str());



    bool is_submited  = student_information->insert(student_details);

    if(is_submited) {
        int response = QMessageBox::information(this,
                                                tr("SUCCESS"),
                                                tr("student_details submitted sucessfully"),
                                                QMessageBox::Ok);
        if(response == QMessageBox::Ok) hide();
    }

    if(!is_submited){
    QMessageBox::warning(this,
                            tr("ERROR"),
                            tr("There was an error submitting student details \n please try again"),
                            QMessageBox::Ok);
    }

}

void NEW_STUDENT::on_new_student_fom_status_rejected()
{
    hide();
}
