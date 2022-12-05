#include "loginreader.h"
#include "ui_loginreader.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include "reader.h"

loginReader::loginReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginReader)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

loginReader::~loginReader()
{
    delete ui;
}

void loginReader::on_Login_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();

    if(username == "" ||password == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{
            QSqlQuery query;
            QString cmd = QString("select username,password from loginreader where (username=\"%1\" and password=\"%2\");").arg(username).arg(password);
            if(!query.exec(cmd))
            {
                qDebug() << "Error to Select from Database " << myDatabase.lastError();
            }
            else
            {
                if(query.first()) {
                    QMessageBox::information(this,"Notice","Login successfully",QMessageBox::Ok);
                    Reader *m = new Reader;
                    m->nameRoot = new Trie();
                    m->authorRoot = new Trie();
                    m->show();
                    this->close();
                }else{
                    QMessageBox::information(this,"Warning","Wrong username or password",QMessageBox::Ok);
                }
            }
        }
}



void loginReader::on_Sign_up_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    QSqlQuery query;
    if(username == "" ||password == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{
        query.prepare("select username from loginreader where username=:username");
        query.bindValue(":username", username);
        query.exec();
        if(query.next())
        {
            QMessageBox::information(this,"Warning","Username already existed",QMessageBox::Ok);
        }
        else
        {
            query.prepare("insert into loginreader(username,password)"
                          "values(:username,:password)");
            query.bindValue(":username",username);
            query.bindValue(":password",password);
            query.exec();
            QMessageBox::information(this,"Notice","Register successfully",QMessageBox::Ok);
        }
    }
}
