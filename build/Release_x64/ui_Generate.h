/********************************************************************************
** Form generated from reading UI file 'Generate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
    QLabel *label;
    QCheckBox *VonBox;
    QLabel *label_2;
    QCheckBox *ClassicBox;
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
        MooreBox->setGeometry(QRect(240, 30, 70, 17));
        MooreBox->setChecked(true);
        FloatBox = new QCheckBox(centralwidget);
        FloatBox->setObjectName(QStringLiteral("FloatBox"));
        FloatBox->setGeometry(QRect(240, 100, 70, 17));
        FloatBox->setChecked(true);
        GenerateButton = new QPushButton(centralwidget);
        GenerateButton->setObjectName(QStringLiteral("GenerateButton"));
        GenerateButton->setGeometry(QRect(120, 110, 75, 23));
        SizeText = new QTextEdit(centralwidget);
        SizeText->setObjectName(QStringLiteral("SizeText"));
        SizeText->setGeometry(QRect(120, 10, 104, 31));
        VariableText = new QTextEdit(centralwidget);
        VariableText->setObjectName(QStringLiteral("VariableText"));
        VariableText->setGeometry(QRect(120, 50, 104, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 10, 101, 16));
        VonBox = new QCheckBox(centralwidget);
        VonBox->setObjectName(QStringLiteral("VonBox"));
        VonBox->setGeometry(QRect(240, 50, 121, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 80, 111, 16));
        ClassicBox = new QCheckBox(centralwidget);
        ClassicBox->setObjectName(QStringLiteral("ClassicBox"));
        ClassicBox->setGeometry(QRect(240, 120, 70, 17));
        Generate->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Generate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Generate->setStatusBar(statusbar);

        retranslateUi(Generate);

        QMetaObject::connectSlotsByName(Generate);
    } // setupUi

    void retranslateUi(QMainWindow *Generate)
    {
        Generate->setWindowTitle(QApplication::translate("Generate", "Generate", Q_NULLPTR));
        SizeLabel->setText(QApplication::translate("Generate", "Size:", Q_NULLPTR));
        VariableLabel->setText(QApplication::translate("Generate", "Number of variables:", Q_NULLPTR));
        MooreBox->setText(QApplication::translate("Generate", "Moore", Q_NULLPTR));
        FloatBox->setText(QApplication::translate("Generate", "Floating", Q_NULLPTR));
        GenerateButton->setText(QApplication::translate("Generate", "Generate", Q_NULLPTR));
        label->setText(QApplication::translate("Generate", "Neighbors rules:", Q_NULLPTR));
        VonBox->setText(QApplication::translate("Generate", "Von Neumann", Q_NULLPTR));
        label_2->setText(QApplication::translate("Generate", "Border rules:", Q_NULLPTR));
        ClassicBox->setText(QApplication::translate("Generate", "Classic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Generate: public Ui_Generate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATE_H
