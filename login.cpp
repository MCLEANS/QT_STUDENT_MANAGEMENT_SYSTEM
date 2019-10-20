#include "login.h"
#include "ui_login.h"
#include <string.h>
#include <QPixmap>
#include <QMessageBox>


LOGIN::LOGIN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    int window_width = 515;
    int window_height = 258;
    setMinimumSize(window_width,window_height);

    student_information = new Student_information("F:\\QT_software\\QT_PROJECTS\\SCHOOL_MANAGEMENT\\bin\\binary_file.bin");
    QPixmap school_logo(":/icons/icons/google.svg");
    int logo_width = ui->label_school_logo->width();
    int logo_height = ui->label_school_logo->height();

    ui->label_school_logo->setPixmap(school_logo.scaled(logo_width,logo_height,Qt::KeepAspectRatio));
}

LOGIN::~LOGIN()
{
    delete student_information;
    delete ui;
}



void LOGIN::on_pushButton_login_clicked()
{
    if(ui->lineEdit_email->text() == "jackagwaya@gmail.com" && ui->lineEdit_password->text() == "agwaya234"){
        homepage = new HOMEPAGE(this);
        hide();
        homepage->show();
    }
    else {
        QMessageBox::warning(this,
                                tr("ERROR"),
                                tr("INVALID email address or password, please try again."),
                                QMessageBox::Cancel);
    }
}
