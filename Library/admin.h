#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QSqlDatabase>
#include "trie.h"
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    Trie *nameRoot;
    Trie *authorRoot;
    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:
    void on_Register_clicked();

    void on_Deregister_clicked();

    void on_Status_clicked();

    void on_Help_clicked();

private:
    Ui::Admin *ui;
    QSqlDatabase myDatabase;
};
#endif // ADMIN_H
