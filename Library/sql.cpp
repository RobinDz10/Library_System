#ifndef CONNECTION
#define CONNECTION

#include <QtSql/QSqlDatabase>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

static bool createConnection()
{

    QStringList drivers = QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug()<<drivers;

    }

    QSqlDatabase db = QSqlDatabase::addDatabase("localhost_3306");
    db.setHostName("localhost");
    db.setDatabaseName("library")
    db.setUserName("root");
    db.setPassword("123456");
    //db.setPort(3306);

    if(!db.open()){
        qDebug()<<"Failed to connect";
        QMessageBox::critical(0,"无法打开数据库","无法创建",QMessageBox::Yes);
        return false;
    }

    return true;


}

#endif // CONNECTION


