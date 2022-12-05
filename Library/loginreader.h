#ifndef LOGINREADER_H
#define LOGINREADER_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class loginReader;
}

class loginReader : public QDialog
{
    Q_OBJECT

public:
    explicit loginReader(QWidget *parent = 0);
    ~loginReader();

private slots:
    void on_Login_clicked();

    void on_Sign_up_clicked();

private:
    Ui::loginReader *ui;
    QSqlDatabase myDatabase;
};

#endif // LOGINREADER_H
