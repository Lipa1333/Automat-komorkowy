/********************************************************************************
** Form generated from reading UI file 'Scope.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOPE_H
#define UI_SCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ShowButton;
    QPushButton *CloseButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *ValuesText;
    QPlainTextEdit *xPosText;
    QPlainTextEdit *yPosText;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(412, 491);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ShowButton = new QPushButton(centralwidget);
        ShowButton->setObjectName(QStringLiteral("ShowButton"));
        ShowButton->setGeometry(QRect(190, 10, 75, 23));
        CloseButton = new QPushButton(centralwidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(20, 440, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 47, 13));
        ValuesText = new QPlainTextEdit(centralwidget);
        ValuesText->setObjectName(QStringLiteral("ValuesText"));
        ValuesText->setGeometry(QRect(20, 140, 371, 291));
        xPosText = new QPlainTextEdit(centralwidget);
        xPosText->setObjectName(QStringLiteral("xPosText"));
        xPosText->setGeometry(QRect(70, 10, 104, 31));
        yPosText = new QPlainTextEdit(centralwidget);
        yPosText->setObjectName(QStringLiteral("yPosText"));
        yPosText->setGeometry(QRect(70, 60, 104, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ShowButton->setText(QApplication::translate("MainWindow", "Show", Q_NULLPTR));
        CloseButton->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "X position", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Y position", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Values", Q_NULLPTR));
        xPosText->setPlainText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        yPosText->setPlainText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOPE_H
