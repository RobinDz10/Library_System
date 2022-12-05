#include "search.h"
#include "ui_search.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include <QSqlRecord>
#include <QTableWidgetItem>
#include <string>
using namespace std;
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    nameRoot = new Trie();
}

Search::~Search()
{
    delete ui;
}

void Search::buildTrie() {
    if(nameRoot == NULL || authorRoot == NULL) {
        return;
    }
    QString cmd = QString("select name, author from admin");
    QSqlQuery query;
    query.exec(cmd);
    query.first();
    string name = query.value(0).toString().toStdString();
    string author = query.value(1).toString().toStdString();
    while(query.next()) {
        string name = query.value(0).toString().toStdString();
        string author = query.value(1).toString().toStdString();

        nameRoot->insert(name);
        authorRoot->insert(author);
    }
}
void Search::on_name_clicked()
{
    buildTrie();
    ui->tableWidget->clear();
    QSqlQuery query;
    QString name = ui->search->text();
    if(name == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
    } else{
        if(nameRoot != NULL && nameRoot->isEmpty() == false && nameRoot->startsWith(name.toStdString()) == false &&
                nameRoot->search(name.toStdString()) == false) {
            return;
        }
        name = name + "%";

        QString cmd = QString("select name,author,ISN,quantity,status from admin where name like \"%1\";").arg(name);

        if(!query.exec(cmd))
        {
           qDebug() << "Error Select to Database" << myDatabase.lastError();
           return;
        }
        query.first();
        int num1 = 0;
        int num2 = 1;
        int num3 = 2;
        int num4 = 3;
        int num5 = 4;
        int i=0;
        int j=0;


        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(5);
        ui->tableWidget->setColumnCount(5);

        QStringList headerText;
        headerText<<"name"<<"author"<<"ISN"<<"quantity"<<"Status";
        ui->tableWidget->setHorizontalHeaderLabels(headerText);

        ui->tableWidget->setItem(i,j  ,new QTableWidgetItem(query.value(num1).toString()));
        ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(query.value(num2).toString()));
        ui->tableWidget->setItem(i,j+2,new QTableWidgetItem(query.value(num3).toString()));
        ui->tableWidget->setItem(i,j+3,new QTableWidgetItem(query.value(num4).toString()));
        ui->tableWidget->setItem(i,j+4,new QTableWidgetItem(query.value(num5).toString()));

        i++;

        while (query.next())
        {
            ui->tableWidget->setItem(i,j  ,new QTableWidgetItem(query.value(num1).toString()));
            ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(query.value(num2).toString()));
            ui->tableWidget->setItem(i,j+2,new QTableWidgetItem(query.value(num3).toString()));
            ui->tableWidget->setItem(i,j+3,new QTableWidgetItem(query.value(num4).toString()));
            ui->tableWidget->setItem(i,j+4,new QTableWidgetItem(query.value(num5).toString()));
            i++;

        }
    }

}

void Search::on_author_clicked()
{
    buildTrie();
    ui->tableWidget->clear();
    QSqlQuery query;
    QString author = ui->search->text();
    if(author == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
    }else{
        if(authorRoot != NULL && authorRoot->isEmpty() == false && authorRoot->startsWith(author.toStdString()) == false &&
                authorRoot->search(author.toStdString()) == false) {
            return;
        }
        author = author + "%";
        QString cmd = QString("select name,author,ISN,quantity,status from admin where author like \"%1\";").arg(author);
        if(!query.exec(cmd))
        {
           qDebug() << "Error Select to Database" <<myDatabase.lastError();
           return;
        }
        query.first();

        int num1 = 0;
        int num2 = 1;
        int num3 = 2;
        int num4 = 3;
        int num5 = 4;
        int i=0;
        int j=0;


        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget->setRowCount(5);
        ui->tableWidget->setColumnCount(5);
        QStringList headerText;
        headerText<<"name"<<"author"<<"ISN"<<"quantity"<<"Status";
        ui->tableWidget->setHorizontalHeaderLabels(headerText);

        ui->tableWidget->setItem(i,j  ,new QTableWidgetItem(query.value(num1).toString()));
        ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(query.value(num2).toString()));
        ui->tableWidget->setItem(i,j+2,new QTableWidgetItem(query.value(num3).toString()));
        ui->tableWidget->setItem(i,j+3,new QTableWidgetItem(query.value(num4).toString()));
        ui->tableWidget->setItem(i,j+4,new QTableWidgetItem(query.value(num5).toString()));

        i++;

        while (query.next())
        {
            ui->tableWidget->setItem(i,j  ,new QTableWidgetItem(query.value(num1).toString()));
            ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(query.value(num2).toString()));
            ui->tableWidget->setItem(i,j+2,new QTableWidgetItem(query.value(num3).toString()));
            ui->tableWidget->setItem(i,j+3,new QTableWidgetItem(query.value(num4).toString()));
            ui->tableWidget->setItem(i,j+4,new QTableWidgetItem(query.value(num5).toString()));

            i++;

        }
    }

}
