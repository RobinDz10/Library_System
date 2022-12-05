#include "reader.h"
#include "ui_reader.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include "search.h"
#include <QSqlRecord>

Reader::Reader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reader)
{
    ui->setupUi(this);

}

Reader::~Reader()
{
    delete ui;
}

void Reader::on_Search_clicked()
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
                    QSqlRecord record = query.record();

                   int num = record.indexOf("quantity");
                   ui->quantity->setText(query.value(num).toString());
                   int quantity = query.value(num).toInt();
                   if(quantity)
                   {
                       ui->status->setText("Available");
                   }else{
                       ui->status->setText("Not Available");
                   }
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

void Reader::on_Borrow_clicked()
{
    QSqlQuery query;
    QString name   = ui->name->text();
    QString author = ui->author->text();
    QString ISN    = ui->ISN->text();

    if(name == "" ||author == "" ||ISN == "" ){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
    }else{
        QString cmd = QString("select quantity from admin where (name =\"%1\" and author = \"%2\" and ISN = \"%3\") ;").arg(name).arg(author).arg(ISN);
        qDebug() << cmd;
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
                QSqlRecord record = query.record();
                QString status = "Not Available";
               int num = record.indexOf("quantity");
               int q = query.value(num).toInt();
               if(q)
               {
                   q -=1;
                   QString quantity = QString::number(q);
                   if(q == 0) {
                       status = "Not Available";
                   } else {
                       status = "Available";
                   }
                   QString cmd = QString("update admin set quantity =\"%1\", status = \"%2\" where name = \"%3\";").arg(quantity).arg(status).arg(name);
                   query.exec(cmd);
                   ui->quantity->setText(quantity);
                   ui->status->setText(status);
                   QMessageBox::information(this,"Notice","Book borrow successfully",QMessageBox::Ok);
               }else{
                   ui->status->setText(status);
                   QMessageBox::information(this,"Notice","Book not available",QMessageBox::Ok);
               }
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

void Reader::on_Return_clicked()
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

               QSqlRecord record = query.record();
               QString status = "Available";
               int num = record.indexOf("quantity");

               int q = query.value(num).toInt();

               q +=1;
               QString quantity = QString::number(q);

               QString cmd = QString("update admin set quantity =\"%1\", status = \"%2\" where name = \"%3\";").arg(quantity).arg(status).arg(name);
               query.exec(cmd);
               QMessageBox::information(this,"Notice","Return book successfully",QMessageBox::Ok);
               ui->quantity->setText(quantity);
               ui->status->setText(status);
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

void Reader::on_Help_clicked()
{
    Search *s = new Search;
    s->nameRoot = new Trie();
    s->authorRoot = new Trie();
    s->show();
}
