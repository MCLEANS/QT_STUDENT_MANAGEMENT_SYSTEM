#ifndef HOMEPAGE_H
#define HOMEPAGE_H


#include <QMainWindow>
#include <new_student.h>
#include <search_student.h>



namespace Ui {
class HOMEPAGE;
}

class HOMEPAGE : public QMainWindow
{
    Q_OBJECT

public:
    explicit HOMEPAGE(QWidget *parent = nullptr);
    ~HOMEPAGE();
    NEW_STUDENT *new_student_page;
    SEARCH_STUDENT *search_student_page;

private slots:
    void on_pushButton_add_new_student_clicked();

    void on_pushButton_search_student_details_clicked();

    void on_pushButton_delete_student_details_clicked();

    void on_actionHOME_triggered();

    void on_actionBACK_triggered();

    void on_actionQUIT_triggered();

private:
    Ui::HOMEPAGE *ui;
};

#endif // HOMEPAGE_H
