/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *StartButton;
    QPushButton *StepButton;
    QPushButton *StopButton;
    QPushButton *LoadButton;
    QPushButton *SaveButton;
    QCheckBox *StepSaveButton;
    QPlainTextEdit *XCoordinateText;
    QLabel *XCoordinateLabel;
    QLabel *YCoordinateLabel;
    QPlainTextEdit *YCoordinateText;
    QPushButton *NewButton;
    QPushButton *ShowButton;
    QPushButton *EditButton;
    QPushButton *LoadScriptButton;
    QPlainTextEdit *ScriptText;
    QLabel *ScriptLabel;
    QFrame *line;
    QPushButton *SaveScriptButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(1009, 667);
        GUIClass->setAutoFillBackground(false);
        GUIClass->setDocumentMode(false);
        GUIClass->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setGeometry(QRect(10, 40, 75, 23));
        StepButton = new QPushButton(centralWidget);
        StepButton->setObjectName(QStringLiteral("StepButton"));
        StepButton->setGeometry(QRect(10, 70, 75, 23));
        StopButton = new QPushButton(centralWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));
        StopButton->setGeometry(QRect(10, 100, 75, 23));
        LoadButton = new QPushButton(centralWidget);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));
        LoadButton->setGeometry(QRect(10, 350, 75, 23));
        SaveButton = new QPushButton(centralWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(10, 320, 75, 23));
        StepSaveButton = new QCheckBox(centralWidget);
        StepSaveButton->setObjectName(QStringLiteral("StepSaveButton"));
        StepSaveButton->setGeometry(QRect(10, 290, 75, 23));
        XCoordinateText = new QPlainTextEdit(centralWidget);
        XCoordinateText->setObjectName(QStringLiteral("XCoordinateText"));
        XCoordinateText->setGeometry(QRect(10, 200, 71, 31));
        XCoordinateText->setCursorWidth(0);
        XCoordinateLabel = new QLabel(centralWidget);
        XCoordinateLabel->setObjectName(QStringLiteral("XCoordinateLabel"));
        XCoordinateLabel->setGeometry(QRect(10, 170, 61, 20));
        YCoordinateLabel = new QLabel(centralWidget);
        YCoordinateLabel->setObjectName(QStringLiteral("YCoordinateLabel"));
        YCoordinateLabel->setGeometry(QRect(10, 230, 61, 20));
        YCoordinateText = new QPlainTextEdit(centralWidget);
        YCoordinateText->setObjectName(QStringLiteral("YCoordinateText"));
        YCoordinateText->setGeometry(QRect(10, 260, 71, 31));
        YCoordinateText->setCursorWidth(0);
        NewButton = new QPushButton(centralWidget);
        NewButton->setObjectName(QStringLiteral("NewButton"));
        NewButton->setGeometry(QRect(10, 10, 75, 23));
        ShowButton = new QPushButton(centralWidget);
        ShowButton->setObjectName(QStringLiteral("ShowButton"));
        ShowButton->setGeometry(QRect(10, 150, 75, 23));
        EditButton = new QPushButton(centralWidget);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        EditButton->setGeometry(QRect(10, 380, 75, 23));
        LoadScriptButton = new QPushButton(centralWidget);
        LoadScriptButton->setObjectName(QStringLiteral("LoadScriptButton"));
        LoadScriptButton->setGeometry(QRect(10, 440, 75, 23));
        ScriptText = new QPlainTextEdit(centralWidget);
        ScriptText->setObjectName(QStringLiteral("ScriptText"));
        ScriptText->setGeometry(QRect(110, 440, 881, 171));
        ScriptLabel = new QLabel(centralWidget);
        ScriptLabel->setObjectName(QStringLiteral("ScriptLabel"));
        ScriptLabel->setGeometry(QRect(10, 620, 981, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 420, 1011, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SaveScriptButton = new QPushButton(centralWidget);
        SaveScriptButton->setObjectName(QStringLiteral("SaveScriptButton"));
        SaveScriptButton->setGeometry(QRect(10, 470, 75, 23));
        GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIClass->setStatusBar(statusBar);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "Cellular Automata", Q_NULLPTR));
        StartButton->setText(QApplication::translate("GUIClass", "Start", Q_NULLPTR));
        StepButton->setText(QApplication::translate("GUIClass", "Step", Q_NULLPTR));
        StopButton->setText(QApplication::translate("GUIClass", "Stop", Q_NULLPTR));
        LoadButton->setText(QApplication::translate("GUIClass", "Load", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("GUIClass", "Save", Q_NULLPTR));
        StepSaveButton->setText(QApplication::translate("GUIClass", "Save step?", Q_NULLPTR));
        XCoordinateText->setPlainText(QApplication::translate("GUIClass", "0", Q_NULLPTR));
        XCoordinateLabel->setText(QApplication::translate("GUIClass", "X coordinate", Q_NULLPTR));
        YCoordinateLabel->setText(QApplication::translate("GUIClass", "Y coordinate", Q_NULLPTR));
        YCoordinateText->setPlainText(QApplication::translate("GUIClass", "0", Q_NULLPTR));
        NewButton->setText(QApplication::translate("GUIClass", "New", Q_NULLPTR));
        ShowButton->setText(QApplication::translate("GUIClass", "Show", Q_NULLPTR));
        EditButton->setText(QApplication::translate("GUIClass", "Edit", Q_NULLPTR));
        LoadScriptButton->setText(QApplication::translate("GUIClass", "Load Script", Q_NULLPTR));
        ScriptLabel->setText(QApplication::translate("GUIClass", "Script Status: Not loaded", Q_NULLPTR));
        SaveScriptButton->setText(QApplication::translate("GUIClass", "Execute", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
