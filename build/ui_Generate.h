/********************************************************************************
** Form generated from reading UI file 'Generate.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATE_H
#define UI_GENERATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Generate
{
public:
    QWidget *centralwidget;
    QLabel *SizeLabel;
    QLabel *VariableLabel;
    QCheckBox *MooreBox;
    QCheckBox *FloatBox;
    QPushButton *GenerateButton;
    QTextEdit *SizeText;
    QTextEdit *VariableText;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Generate)
    {
        if (Generate->objectName().isEmpty())
            Generate->setObjectName(QStringLiteral("Generate"));
        Generate->resize(413, 172);
        centralwidget = new QWidget(Generate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SizeLabel = new QLabel(centralwidget);
        SizeLabel->setObjectName(QStringLiteral("SizeLabel"));
        SizeLabel->setGeometry(QRect(10, 20, 47, 13));
        VariableLabel = new QLabel(centralwidget);
        VariableLabel->setObjectName(QStringLiteral("VariableLabel"));
        VariableLabel->setGeometry(QRect(10, 60, 101, 16));
        MooreBox = new QCheckBox(centralwidget);
        MooreBox->setObjectName(QStringLiteral("MooreBox"));
        MooreBox->setGeometry(QRect(10, 90, 70, 17));
        FloatBox = new QCheckBox(centralwidget);
        FloatBox->setObjectName(QStringLiteral("FloatBox"));
        FloatBox->setGeometry(QRect(10, 120, 70, 17));
        GenerateButton = new QPushButton(centralwidget);
        GenerateButton->setObjectName(QStringLiteral("GenerateButton"));
        GenerateButton->setGeometry(QRect(120, 110, 75, 23));
        SizeText = new QTextEdit(centralwidget);
        SizeText->setObjectName(QStringLiteral("SizeText"));
        SizeText->setGeometry(QRect(120, 10, 104, 31));
        VariableText = new QTextEdit(centralwidget);
        VariableText->setObjectName(QStringLiteral("VariableText"));
        VariableText->setGeometry(QRect(120, 50, 104, 31));
        Generate->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Generate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Generate->setStatusBar(statusbar);

        retranslateUi(Generate);

        QMetaObject::connectSlotsByName(Generate);
    } // setupUi

    void retranslateUi(QMainWindow *Generate)
    {
        Generate->setWindowTitle(QApplication::translate("Generate", "Generate", 0));
        SizeLabel->setText(QApplication::translate("Generate", "Size:", 0));
        VariableLabel->setText(QApplication::translate("Generate", "Number of variables:", 0));
        MooreBox->setText(QApplication::translate("Generate", "Is Moore", 0));
        FloatBox->setText(QApplication::translate("Generate", "Is Floating", 0));
        GenerateButton->setText(QApplication::translate("Generate", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class Generate: public Ui_Generate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATE_H
