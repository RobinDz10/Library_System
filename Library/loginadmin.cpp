#include "loginadmin.h"
#include "ui_loginadmin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>
#include "admin.h"

LoginAdmin::LoginAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);

}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}


//login in
void LoginAdmin::on_Login_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();

    if(username == "" ||password == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{
            QSqlQuery query;
            QString cmd = QString("select username,password from loginadmin where (username=\"%1\" and password=\"%2\");").arg(username).arg(password);
            if(!query.exec(cmd))
            {
                qDebug() << "Error to Select from Database " << myDatabase.lastError();
            }
            else
            {
                if(query.first()) {
                    QMessageBox::information(this,"Notice","Login successfully",QMessageBox::Ok);
                    Admin *m = new Admin();
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



void LoginAdmin::on_Sign_up_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();

    if(username == "" ||password == ""){
            QMessageBox::information(this,"Warning","Input cannot be null",QMessageBox::Ok);
        }else{
            QSqlQuery query;
            query.prepare("select username from loginadmin where username=:username");
            query.bindValue(":username", username);
            query.exec();
            if(query.next())
            {
                QMessageBox::information(this,"Warning","Username already existed",QMessageBox::Ok);
            }
            else
            {
                query.prepare("insert into loginadmin(username,password)"
                              "values(:username,:password)");
                query.bindValue(":username",username);
                query.bindValue(":password",password);
                query.exec();
                QMessageBox::information(this,"Notice","Sign up successfully",QMessageBox::Ok);
            }

    }
}
