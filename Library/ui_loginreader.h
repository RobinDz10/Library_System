/********************************************************************************
** Form generated from reading UI file 'loginreader.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINREADER_H
#define UI_LOGINREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginReader
{
public:
    QLineEdit *Username;
    QLineEdit *Password;
    QPushButton *Login;
    QPushButton *Sign_up;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *loginReader)
    {
        if (loginReader->objectName().isEmpty())
            loginReader->setObjectName(QStringLiteral("loginReader"));
        loginReader->resize(610, 500);
        Username = new QLineEdit(loginReader);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(270, 200, 201, 41));
        Password = new QLineEdit(loginReader);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(270, 270, 201, 41));
        Login = new QPushButton(loginReader);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(89, 350, 191, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(20);
        Login->setFont(font);
        Sign_up = new QPushButton(loginReader);
        Sign_up->setObjectName(QStringLiteral("Sign_up"));
        Sign_up->setGeometry(QRect(300, 349, 191, 41));
        Sign_up->setFont(font);
        label = new QLabel(loginReader);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 210, 111, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(loginReader);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 280, 91, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(loginReader);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 90, 101, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font2.setPointSize(24);
        label_3->setFont(font2);

        retranslateUi(loginReader);

        QMetaObject::connectSlotsByName(loginReader);
    } // setupUi

    void retranslateUi(QDialog *loginReader)
    {
        loginReader->setWindowTitle(QApplication::translate("loginReader", "Dialog", Q_NULLPTR));
        Login->setText(QApplication::translate("loginReader", "Log in", Q_NULLPTR));
        Sign_up->setText(QApplication::translate("loginReader", "Sign up", Q_NULLPTR));
        label->setText(QApplication::translate("loginReader", "Username", Q_NULLPTR));
        label_2->setText(QApplication::translate("loginReader", "Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("loginReader", "Reader", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginReader: public Ui_loginReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINREADER_H
