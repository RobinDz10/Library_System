#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include "search.h"
#include <QSqlRecord>

Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_Register_clicked()
{
    QSqlQuery query;
    QString name   = ui->name->text();
    QString author = ui->author->text();
    QString ISN    = ui->ISN->text();
    QString quantity    = ui->quantity->text();

    if(name == "" ||author == "" ||ISN == "" ||quantity ==""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{

            QString status = "Available";
            QString cmd = QString("insert into admin values(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\");").arg(name).arg(author).arg(ISN).arg(quantity).arg(status);
            nameRoot->insert(name.toStdString());
            authorRoot->insert(author.toStdString());
            if(!query.exec(cmd))
            {
                 qDebug() << "Error to Insert Into Database " << myDatabase.lastError();
                 QMessageBox::information(this,"Notice","Register book unsuccessfully",QMessageBox::Ok);
                 return;
            }else{
                QMessageBox::information(this,"Notice","Register book successfully",QMessageBox::Ok);
            }
            ui->name->clear();
            ui->author->clear();
            ui->ISN->clear();
            ui->quantity->clear();

    }

}

void Admin::on_Deregister_clicked()
{
    QSqlQuery query;
    QString name   = ui->name->text();
    QString author = ui->author->text();
    QString ISN    = ui->ISN->text();

    if(name == "" ||author == "" ||ISN == "" ){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
    }else{
        if(nameRoot->search(name.toStdString()) == true) {
            nameRoot->del(name.toStdString());
            authorRoot->del(author.toStdString());
        }
        QString cmd = QString("delete from admin where name =\"%1\" and author = \"%2\" and ISN = \"%3\" ;").arg(name).arg(author).arg(ISN);
        if(!query.exec(cmd))
        {
             qDebug() << "Error to Delete Into Database " << myDatabase.lastError();
             QMessageBox::information(this,"Notice","Deregister book unsuccessfully",QMessageBox::Ok);
             return;
        }else{
            QMessageBox::information(this,"Notice","Deregister book successfully",QMessageBox::Ok);
        }
        ui->name->clear();
        ui->author->clear();
        ui->ISN->clear();
        ui->quantity->clear();

    }
}

void Admin::on_Status_clicked()
{
    QSqlQuery query;
    QString name   = ui->name->text();
    QString author = ui->author->text();
    QString ISN    = ui->ISN->text();

    if(name == "" ||author == "" ||ISN == "" ){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{

            QString cmd = QString("select quantity from admin where (name =\"%1\" and author = \"%2\" and ISN = \"%3\") ;").arg(name).arg(author).arg(ISN);
            if(!query.exec(cmd))
            {
                 qDebug() << "Error to Select from Database " << myDatabase.lastError();
                 QMessageBox::information(this,"Notice","Please enter correct book name/author/ISN",QMessageBox::Ok);
                 ui->name->clear();
                 ui->author->clear();
                 ui->ISN->clear();
                 ui->quantity->clear();
                 return;
            }else{
                if(query.first()) {
                   QSqlRecord record = query.record();// get current record

                   int num = record.indexOf("quantity");
                   ui->quantity->setText(query.value(num).toString());
                } else {
                    QMessageBox::information(this,"Notice","Please enter correct book name/author/ISN",QMessageBox::Ok);
                    ui->name->clear();
                    ui->author->clear();
                    ui->ISN->clear();
                    ui->quantity->clear();
                }
            }

    }

}

void Admin::on_Help_clicked()
{
    Search *s = new Search;
    s->nameRoot = new Trie();
    s->authorRoot = new Trie();
    s->show();
    //this->close();
}
