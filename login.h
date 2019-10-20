#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "student_records.hpp"
#include "homepage.h"

namespace Ui {
class LOGIN;
}

class LOGIN : public QMainWindow
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();
    Student_information *student_information;
    HOMEPAGE *homepage;

private slots:

    void on_pushButton_login_clicked();

private:
    Ui::LOGIN *ui;
};

#endif // LOGIN_H
