#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = 0);
    ~LoginAdmin();

private slots:
    void on_Login_clicked();

    void on_Sign_up_clicked();

private:
    Ui::LoginAdmin *ui;
    QSqlDatabase myDatabase;
};

#endif // LOGINADMIN_H
