#ifndef NEW_STUDENT_H
#define NEW_STUDENT_H

#include <QDialog>
#include "student_records.hpp"

namespace Ui {
class NEW_STUDENT;
}

class NEW_STUDENT : public QDialog
{
    Q_OBJECT

public:
    explicit NEW_STUDENT(QWidget *parent = nullptr);
    ~NEW_STUDENT();

private slots:
    void on_new_student_fom_status_accepted();

    void on_new_student_fom_status_rejected();

private:
    Ui::NEW_STUDENT *ui;
    Student_information *student_information;
};

#endif // NEW_STUDENT_H
