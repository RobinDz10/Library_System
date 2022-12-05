#ifndef READER_H
#define READER_H

#include <QDialog>
#include <QSqlDatabase>
#include "trie.h"
namespace Ui {
class Reader;
}

class Reader : public QDialog
{
    Q_OBJECT

public:
    Trie* nameRoot;
    Trie *authorRoot;
    explicit Reader(QWidget *parent = 0);
    ~Reader();

private slots:
    void on_Search_clicked();

    void on_Borrow_clicked();

    void on_Return_clicked();

    void on_Help_clicked();

private:
    Ui::Reader *ui;
    QSqlDatabase myDatabase;
};

#endif // READER_H
