#include "homepage.h"
#include "ui_homepage.h"
#include <QMessageBox>
#include <login.h>

HOMEPAGE::HOMEPAGE(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HOMEPAGE)
{
    ui->setupUi(this);

    QPixmap school_logo(":/icons/Technical-University-of-Kenya-TUK-logo.png");
    int logo_width = ui->tuk_logo->width();
    int logo_height = ui->tuk_logo->height();

    ui->tuk_logo->setPixmap(school_logo.scaled(logo_width,logo_height,Qt::KeepAspectRatio));
}

HOMEPAGE::~HOMEPAGE()
{
    delete ui;
}

void HOMEPAGE::on_pushButton_add_new_student_clicked()
{
    new_student_page = new NEW_STUDENT(this);
    new_student_page->setModal(true);
    new_student_page->show();
}

void HOMEPAGE::on_pushButton_search_student_details_clicked()
{
    search_student_page = new SEARCH_STUDENT(this);
    search_student_page->setModal(true);
    search_student_page->show();
}

void HOMEPAGE::on_pushButton_delete_student_details_clicked()
{
    QMessageBox::warning(this,
                         tr("UNAVAILABLE"),
                         tr("Sorry, this functionality is not available at the moment"),
                         QMessageBox::Cancel);
}

void HOMEPAGE::on_actionHOME_triggered()
{


}

void HOMEPAGE::on_actionBACK_triggered()
{
    LOGIN *login_page;
    login_page = new LOGIN(this);
    hide();
    login_page->show();
}

void HOMEPAGE::on_actionQUIT_triggered()
{
    QApplication::instance()->quit();
}
