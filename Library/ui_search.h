/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QPushButton *name;
    QLineEdit *search;
    QPushButton *author;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(610, 500);
        name = new QPushButton(Search);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(300, 160, 101, 31));
        search = new QLineEdit(Search);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(60, 160, 231, 31));
        author = new QPushButton(Search);
        author->setObjectName(QStringLiteral("author"));
        author->setGeometry(QRect(410, 160, 111, 31));
        label = new QLabel(Search);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 110, 211, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(24);
        label->setFont(font);
        tableWidget = new QTableWidget(Search);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 210, 471, 192));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Dialog", Q_NULLPTR));
        name->setText(QApplication::translate("Search", "Search by Name", Q_NULLPTR));
        author->setText(QApplication::translate("Search", "Search by Author", Q_NULLPTR));
        label->setText(QApplication::translate("Search", "Search", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
