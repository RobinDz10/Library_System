#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginadmin.h"
#include "loginreader.h"
#include "admin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase  db = QSqlDatabase::addDatabase( "QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("library");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok = db.open();
    if (ok){
        QMessageBox::information(this, "infor", "success");
    }
    else {
        QMessageBox::information(this, "infor", "open failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Administrator_clicked()
{
    LoginAdmin *admin = new LoginAdmin;
    admin->show();
    this->close();

}

void MainWindow::on_Reader_clicked()
{
    loginReader *reader = new loginReader;
    reader->show();
    this->close();
}
