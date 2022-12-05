/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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

class Ui_Admin
{
public:
    QPushButton *Register;
    QPushButton *Deregister;
    QPushButton *Status;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *name;
    QLineEdit *author;
    QLineEdit *ISN;
    QLineEdit *quantity;
    QPushButton *Help;
    QLabel *label_5;

    void setupUi(QDialog *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QStringLiteral("Admin"));
        Admin->resize(610, 500);
        Register = new QPushButton(Admin);
        Register->setObjectName(QStringLiteral("Register"));
        Register->setGeometry(QRect(70, 352, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(12);
        Register->setFont(font);
        Deregister = new QPushButton(Admin);
        Deregister->setObjectName(QStringLiteral("Deregister"));
        Deregister->setGeometry(QRect(230, 350, 131, 31));
        Deregister->setFont(font);
        Status = new QPushButton(Admin);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setGeometry(QRect(380, 350, 131, 31));
        Status->setFont(font);
        label = new QLabel(Admin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 130, 54, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(Admin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 180, 71, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(Admin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 240, 71, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(Admin);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 280, 101, 31));
        label_4->setFont(font1);
        name = new QLineEdit(Admin);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(210, 130, 281, 31));
        author = new QLineEdit(Admin);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(210, 179, 281, 31));
        ISN = new QLineEdit(Admin);
        ISN->setObjectName(QStringLiteral("ISN"));
        ISN->setGeometry(QRect(210, 230, 281, 31));
        quantity = new QLineEdit(Admin);
        quantity->setObjectName(QStringLiteral("quantity"));
        quantity->setGeometry(QRect(210, 280, 281, 31));
        Help = new QPushButton(Admin);
        Help->setObjectName(QStringLiteral("Help"));
        Help->setGeometry(QRect(70, 410, 441, 31));
        Help->setFont(font);
        label_5 = new QLabel(Admin);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 30, 211, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font2.setPointSize(24);
        label_5->setFont(font2);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QDialog *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "Dialog", Q_NULLPTR));
        Register->setText(QApplication::translate("Admin", "Register", Q_NULLPTR));
        Deregister->setText(QApplication::translate("Admin", "Deregister", Q_NULLPTR));
        Status->setText(QApplication::translate("Admin", "Check Book Status", Q_NULLPTR));
        label->setText(QApplication::translate("Admin", "name", Q_NULLPTR));
        label_2->setText(QApplication::translate("Admin", "author", Q_NULLPTR));
        label_3->setText(QApplication::translate("Admin", "ISN", Q_NULLPTR));
        label_4->setText(QApplication::translate("Admin", "quantity", Q_NULLPTR));
        Help->setText(QApplication::translate("Admin", "Help", Q_NULLPTR));
        label_5->setText(QApplication::translate("Admin", "Adiminstrator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
