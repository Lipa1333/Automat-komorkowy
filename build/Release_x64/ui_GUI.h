/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QScrollBar>
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
    QPushButton *NewButton;
    QPushButton *ShowButton;
    QPushButton *LoadScriptButton;
    QPlainTextEdit *ScriptText;
    QLabel *ScriptLabel;
    QFrame *line;
    QPushButton *SaveScriptButton;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QPlainTextEdit *xPosEditText;
    QPlainTextEdit *yPosEditText;
    QPlainTextEdit *VarNumText;
    QLabel *xPosEditLabel;
    QLabel *yPosEditLabel;
    QLabel *VarNumLabel;
    QPlainTextEdit *ValueEditText;
    QLabel *ValueLabel;
    QPushButton *SaveValueButton;
    QPushButton *ScopeButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QStringLiteral("GUIClass"));
        GUIClass->resize(749, 698);
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
        StepSaveButton->setGeometry(QRect(10, 160, 75, 23));
        NewButton = new QPushButton(centralWidget);
        NewButton->setObjectName(QStringLiteral("NewButton"));
        NewButton->setGeometry(QRect(10, 10, 75, 23));
        ShowButton = new QPushButton(centralWidget);
        ShowButton->setObjectName(QStringLiteral("ShowButton"));
        ShowButton->setGeometry(QRect(10, 130, 75, 23));
        LoadScriptButton = new QPushButton(centralWidget);
        LoadScriptButton->setObjectName(QStringLiteral("LoadScriptButton"));
        LoadScriptButton->setGeometry(QRect(10, 470, 75, 23));
        ScriptText = new QPlainTextEdit(centralWidget);
        ScriptText->setObjectName(QStringLiteral("ScriptText"));
        ScriptText->setGeometry(QRect(110, 470, 611, 171));
        ScriptLabel = new QLabel(centralWidget);
        ScriptLabel->setObjectName(QStringLiteral("ScriptLabel"));
        ScriptLabel->setGeometry(QRect(10, 650, 981, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 450, 721, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SaveScriptButton = new QPushButton(centralWidget);
        SaveScriptButton->setObjectName(QStringLiteral("SaveScriptButton"));
        SaveScriptButton->setGeometry(QRect(10, 500, 75, 23));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(120, 400, 371, 16));
        horizontalScrollBar->setMaximum(0);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(500, 20, 20, 371));
        verticalScrollBar->setMaximum(0);
        verticalScrollBar->setOrientation(Qt::Vertical);
        xPosEditText = new QPlainTextEdit(centralWidget);
        xPosEditText->setObjectName(QStringLiteral("xPosEditText"));
        xPosEditText->setGeometry(QRect(600, 40, 104, 31));
        yPosEditText = new QPlainTextEdit(centralWidget);
        yPosEditText->setObjectName(QStringLiteral("yPosEditText"));
        yPosEditText->setGeometry(QRect(600, 90, 104, 31));
        VarNumText = new QPlainTextEdit(centralWidget);
        VarNumText->setObjectName(QStringLiteral("VarNumText"));
        VarNumText->setGeometry(QRect(600, 140, 104, 31));
        xPosEditLabel = new QLabel(centralWidget);
        xPosEditLabel->setObjectName(QStringLiteral("xPosEditLabel"));
        xPosEditLabel->setGeometry(QRect(530, 50, 47, 13));
        yPosEditLabel = new QLabel(centralWidget);
        yPosEditLabel->setObjectName(QStringLiteral("yPosEditLabel"));
        yPosEditLabel->setGeometry(QRect(530, 100, 47, 13));
        VarNumLabel = new QLabel(centralWidget);
        VarNumLabel->setObjectName(QStringLiteral("VarNumLabel"));
        VarNumLabel->setGeometry(QRect(530, 140, 51, 20));
        ValueEditText = new QPlainTextEdit(centralWidget);
        ValueEditText->setObjectName(QStringLiteral("ValueEditText"));
        ValueEditText->setGeometry(QRect(600, 190, 104, 31));
        ValueLabel = new QLabel(centralWidget);
        ValueLabel->setObjectName(QStringLiteral("ValueLabel"));
        ValueLabel->setGeometry(QRect(530, 190, 47, 13));
        SaveValueButton = new QPushButton(centralWidget);
        SaveValueButton->setObjectName(QStringLiteral("SaveValueButton"));
        SaveValueButton->setGeometry(QRect(580, 240, 75, 23));
        ScopeButton = new QPushButton(centralWidget);
        ScopeButton->setObjectName(QStringLiteral("ScopeButton"));
        ScopeButton->setGeometry(QRect(10, 190, 75, 23));
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
        NewButton->setText(QApplication::translate("GUIClass", "New", Q_NULLPTR));
        ShowButton->setText(QApplication::translate("GUIClass", "Show", Q_NULLPTR));
        LoadScriptButton->setText(QApplication::translate("GUIClass", "Load Script", Q_NULLPTR));
        ScriptLabel->setText(QApplication::translate("GUIClass", "Script Status: Not loaded", Q_NULLPTR));
        SaveScriptButton->setText(QApplication::translate("GUIClass", "Execute", Q_NULLPTR));
        xPosEditLabel->setText(QApplication::translate("GUIClass", "X position", Q_NULLPTR));
        yPosEditLabel->setText(QApplication::translate("GUIClass", "Y position", Q_NULLPTR));
        VarNumLabel->setText(QApplication::translate("GUIClass", "Variable #", Q_NULLPTR));
        ValueLabel->setText(QApplication::translate("GUIClass", "Value", Q_NULLPTR));
        SaveValueButton->setText(QApplication::translate("GUIClass", "Save value", Q_NULLPTR));
        ScopeButton->setText(QApplication::translate("GUIClass", "Scope", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
