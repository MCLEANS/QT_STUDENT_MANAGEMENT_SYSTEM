#include "search_student.h"
#include "ui_search_student.h"
#include "sstream"
#include <string.h>
#include <QMessageBox>

SEARCH_STUDENT::SEARCH_STUDENT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SEARCH_STUDENT)
{
    ui->setupUi(this);
}

SEARCH_STUDENT::~SEARCH_STUDENT()
{
    delete student_information;
    delete ui;
}



void SEARCH_STUDENT::on_search_button_clicked()
{
    ui->student_details_view->clear();
    student_information = new Student_information("F:\\QT_software\\QT_PROJECTS\\SCHOOL_MANAGEMENT\\bin\\binary_file.bin");
    Student_details student_details;
    if(!ui->registration_number->text().isEmpty()){

        student_details = student_information->retreive((ui->registration_number->text()).toStdString());

        std::stringstream full_name;
        full_name<<"NAME : ";
        full_name<<student_details.first_name;
        full_name<<" ";
        full_name<<student_details.middle_name;
        full_name<<" ";
        full_name<<student_details.sir_name;


        QString student_full_name = QString::fromStdString(full_name.str());


        ui->student_details_view->addItem("NAME : "+ student_full_name);
        ui->student_details_view->addItem("COURSE : " + QString::fromStdString(student_details.course));
        ui->student_details_view->addItem("CLASS_CODE : "+ QString::fromStdString(student_details.class_code));
        ui->student_details_view->addItem("REGISTRATION NUMBER : "+ QString::fromStdString(student_details.registration_number));


        ui->registration_number->clear();
    }
    else {
        QMessageBox::warning(this,
                             tr("NO REGISTRATION NUMBER"),
                             tr("The student registration number was not provided"),
                             QMessageBox::Cancel);
    }
}
