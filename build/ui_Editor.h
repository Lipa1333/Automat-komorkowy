/********************************************************************************
** Form generated from reading UI file 'Editor.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

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

class Ui_EditorWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SaveButton;
    QPushButton *CloseButton;
    QLabel *xPosLabel;
    QLabel *VarValLabel;
    QLabel *VarNumLabel;
    QLabel *yPosLabel;
    QPlainTextEdit *xText;
    QPlainTextEdit *yText;
    QPlainTextEdit *variableText;
    QPlainTextEdit *valueText;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditorWindow)
    {
        if (EditorWindow->objectName().isEmpty())
            EditorWindow->setObjectName(QStringLiteral("EditorWindow"));
        EditorWindow->resize(175, 214);
        centralwidget = new QWidget(EditorWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(10, 170, 75, 23));
        CloseButton = new QPushButton(centralwidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(90, 170, 75, 23));
        xPosLabel = new QLabel(centralwidget);
        xPosLabel->setObjectName(QStringLiteral("xPosLabel"));
        xPosLabel->setGeometry(QRect(10, 10, 47, 13));
        VarValLabel = new QLabel(centralwidget);
        VarValLabel->setObjectName(QStringLiteral("VarValLabel"));
        VarValLabel->setGeometry(QRect(10, 130, 47, 13));
        VarNumLabel = new QLabel(centralwidget);
        VarNumLabel->setObjectName(QStringLiteral("VarNumLabel"));
        VarNumLabel->setGeometry(QRect(10, 90, 47, 13));
        yPosLabel = new QLabel(centralwidget);
        yPosLabel->setObjectName(QStringLiteral("yPosLabel"));
        yPosLabel->setGeometry(QRect(10, 50, 47, 13));
        xText = new QPlainTextEdit(centralwidget);
        xText->setObjectName(QStringLiteral("xText"));
        xText->setGeometry(QRect(60, 10, 104, 31));
        yText = new QPlainTextEdit(centralwidget);
        yText->setObjectName(QStringLiteral("yText"));
        yText->setGeometry(QRect(60, 50, 104, 31));
        variableText = new QPlainTextEdit(centralwidget);
        variableText->setObjectName(QStringLiteral("variableText"));
        variableText->setGeometry(QRect(60, 90, 104, 31));
        valueText = new QPlainTextEdit(centralwidget);
        valueText->setObjectName(QStringLiteral("valueText"));
        valueText->setGeometry(QRect(60, 130, 104, 31));
        EditorWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(EditorWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        EditorWindow->setStatusBar(statusbar);

        retranslateUi(EditorWindow);

        QMetaObject::connectSlotsByName(EditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditorWindow)
    {
        EditorWindow->setWindowTitle(QApplication::translate("EditorWindow", "Edit", 0));
        SaveButton->setText(QApplication::translate("EditorWindow", "Save Data", 0));
        CloseButton->setText(QApplication::translate("EditorWindow", "Close", 0));
        xPosLabel->setText(QApplication::translate("EditorWindow", "X position:", 0));
        VarValLabel->setText(QApplication::translate("EditorWindow", "Value:", 0));
        VarNumLabel->setText(QApplication::translate("EditorWindow", "Variable #:", 0));
        yPosLabel->setText(QApplication::translate("EditorWindow", "Y position:", 0));
        xText->setPlainText(QApplication::translate("EditorWindow", "0", 0));
        yText->setPlainText(QApplication::translate("EditorWindow", "0", 0));
        variableText->setPlainText(QApplication::translate("EditorWindow", "0", 0));
        valueText->setPlainText(QApplication::translate("EditorWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorWindow: public Ui_EditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
