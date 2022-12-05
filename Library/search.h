#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QSqlDatabase>
#include "trie.h"
namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT
public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    void buildTrie();
    Trie *nameRoot;
    Trie *authorRoot;

private slots:
    void on_name_clicked();

    void on_author_clicked();

private:
    Ui::Search *ui;
    QSqlDatabase myDatabase;
};

#endif // SEARCH_H
