/********************************************************************************
** Form generated from reading UI file 'reader.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READER_H
#define UI_READER_H

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

class Ui_Reader
{
public:
    QPushButton *Borrow;
    QLineEdit *author;
    QPushButton *Search;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *Return;
    QLabel *label;
    QLineEdit *name;
    QLineEdit *ISN;
    QLabel *label_3;
    QPushButton *Help;
    QLineEdit *quantity;
    QLabel *label_5;
    QLineEdit *status;
    QLabel *label_6;

    void setupUi(QDialog *Reader)
    {
        if (Reader->objectName().isEmpty())
            Reader->setObjectName(QStringLiteral("Reader"));
        Reader->resize(610, 500);
        Borrow = new QPushButton(Reader);
        Borrow->setObjectName(QStringLiteral("Borrow"));
        Borrow->setGeometry(QRect(220, 370, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(12);
        Borrow->setFont(font);
        author = new QLineEdit(Reader);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(210, 170, 281, 31));
        Search = new QPushButton(Reader);
        Search->setObjectName(QStringLiteral("Search"));
        Search->setGeometry(QRect(70, 370, 131, 31));
        Search->setFont(font);
        label_4 = new QLabel(Reader);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 270, 111, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(18);
        label_4->setFont(font1);
        label_2 = new QLabel(Reader);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 170, 71, 31));
        label_2->setFont(font1);
        Return = new QPushButton(Reader);
        Return->setObjectName(QStringLiteral("Return"));
        Return->setGeometry(QRect(370, 370, 131, 31));
        Return->setFont(font);
        label = new QLabel(Reader);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 120, 54, 31));
        label->setFont(font1);
        name = new QLineEdit(Reader);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(210, 120, 281, 31));
        ISN = new QLineEdit(Reader);
        ISN->setObjectName(QStringLiteral("ISN"));
        ISN->setGeometry(QRect(210, 220, 281, 31));
        label_3 = new QLabel(Reader);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 230, 54, 21));
        label_3->setFont(font1);
        Help = new QPushButton(Reader);
        Help->setObjectName(QStringLiteral("Help"));
        Help->setGeometry(QRect(70, 420, 441, 31));
        Help->setFont(font);
        quantity = new QLineEdit(Reader);
        quantity->setObjectName(QStringLiteral("quantity"));
        quantity->setGeometry(QRect(210, 270, 281, 31));
        label_5 = new QLabel(Reader);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 320, 81, 31));
        label_5->setFont(font1);
        status = new QLineEdit(Reader);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(210, 320, 281, 31));
        label_6 = new QLabel(Reader);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 40, 261, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font2.setPointSize(24);
        label_6->setFont(font2);

        retranslateUi(Reader);

        QMetaObject::connectSlotsByName(Reader);
    } // setupUi

    void retranslateUi(QDialog *Reader)
    {
        Reader->setWindowTitle(QApplication::translate("Reader", "Dialog", Q_NULLPTR));
        Borrow->setText(QApplication::translate("Reader", "Borrow", Q_NULLPTR));
        Search->setText(QApplication::translate("Reader", "Search", Q_NULLPTR));
        label_4->setText(QApplication::translate("Reader", "quantity", Q_NULLPTR));
        label_2->setText(QApplication::translate("Reader", "author", Q_NULLPTR));
        Return->setText(QApplication::translate("Reader", "Return", Q_NULLPTR));
        label->setText(QApplication::translate("Reader", "name", Q_NULLPTR));
        label_3->setText(QApplication::translate("Reader", "ISN", Q_NULLPTR));
        Help->setText(QApplication::translate("Reader", "Help", Q_NULLPTR));
        label_5->setText(QApplication::translate("Reader", "status", Q_NULLPTR));
        label_6->setText(QApplication::translate("Reader", "Reader", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reader: public Ui_Reader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READER_H
