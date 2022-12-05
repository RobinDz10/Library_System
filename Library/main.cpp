#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QStringList>
#include <QString>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}

