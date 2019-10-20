#ifndef SEARCH_STUDENT_H
#define SEARCH_STUDENT_H

#include <QDialog>
#include "student_records.hpp"

namespace Ui {
class SEARCH_STUDENT;
}

class SEARCH_STUDENT : public QDialog
{
    Q_OBJECT

public:
    explicit SEARCH_STUDENT(QWidget *parent = nullptr);
    ~SEARCH_STUDENT();

private slots:
    void on_pushButton_clicked();

    void on_search_button_clicked();

private:
    Ui::SEARCH_STUDENT *ui;
    Student_information *student_information;
};

#endif // SEARCH_STUDENT_H
