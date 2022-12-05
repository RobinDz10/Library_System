/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMIN_H
#define UI_LOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdmin
{
public:
    QLineEdit *Username;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Login;
    QLineEdit *Password;
    QPushButton *Sign_up;
    QLabel *label_3;

    void setupUi(QWidget *LoginAdmin)
    {
        if (LoginAdmin->objectName().isEmpty())
            LoginAdmin->setObjectName(QStringLiteral("LoginAdmin"));
        LoginAdmin->resize(610, 500);
        Username = new QLineEdit(LoginAdmin);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(250, 200, 201, 31));
        label = new QLabel(LoginAdmin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 200, 121, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(18);
        label->setFont(font);
        label_2 = new QLabel(LoginAdmin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 250, 111, 21));
        label_2->setFont(font);
        Login = new QPushButton(LoginAdmin);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setGeometry(QRect(80, 310, 191, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(20);
        Login->setFont(font1);
        Password = new QLineEdit(LoginAdmin);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(250, 250, 201, 31));
        Sign_up = new QPushButton(LoginAdmin);
        Sign_up->setObjectName(QStringLiteral("Sign_up"));
        Sign_up->setGeometry(QRect(300, 310, 181, 41));
        Sign_up->setFont(font1);
        label_3 = new QLabel(LoginAdmin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 90, 211, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font2.setPointSize(24);
        label_3->setFont(font2);

        retranslateUi(LoginAdmin);

        QMetaObject::connectSlotsByName(LoginAdmin);
    } // setupUi

    void retranslateUi(QWidget *LoginAdmin)
    {
        LoginAdmin->setWindowTitle(QApplication::translate("LoginAdmin", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("LoginAdmin", "Username", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginAdmin", "Password", Q_NULLPTR));
        Login->setText(QApplication::translate("LoginAdmin", "Log in", Q_NULLPTR));
        Sign_up->setText(QApplication::translate("LoginAdmin", "Sign up", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginAdmin", "Adiminstrator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginAdmin: public Ui_LoginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
