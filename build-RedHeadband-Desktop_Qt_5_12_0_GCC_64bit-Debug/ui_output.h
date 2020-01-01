/********************************************************************************
** Form generated from reading UI file 'output.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_H
#define UI_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Console
{
public:
    QGridLayout *gridLayout;
    QLabel *ConsoleOutput;

    void setupUi(QWidget *Console)
    {
        if (Console->objectName().isEmpty())
            Console->setObjectName(QString::fromUtf8("Console"));
        Console->resize(640, 308);
        gridLayout = new QGridLayout(Console);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ConsoleOutput = new QLabel(Console);
        ConsoleOutput->setObjectName(QString::fromUtf8("ConsoleOutput"));
        ConsoleOutput->setWordWrap(true);

        gridLayout->addWidget(ConsoleOutput, 0, 0, 1, 1);


        retranslateUi(Console);

        QMetaObject::connectSlotsByName(Console);
    } // setupUi

    void retranslateUi(QWidget *Console)
    {
        Console->setWindowTitle(QApplication::translate("Console", "Form", nullptr));
        ConsoleOutput->setText(QApplication::translate("Console", "Some stuff", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Console: public Ui_Console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
