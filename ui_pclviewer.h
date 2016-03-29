/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_File;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton_browse;
    QPushButton *pushButton_load;
    QGroupBox *groupBox_ColorMode;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_Axis;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_x;
    QRadioButton *radioButton_y;
    QRadioButton *radioButton_z;
    QGroupBox *groupBox_Color;
    QVBoxLayout *horizontalLayout_c;
    QRadioButton *radioButton_BlueRed;
    QRadioButton *radioButton_GreenMagenta;
    QRadioButton *radioButton_WhiteRed;
    QRadioButton *radioButton_GreyRed;
    QRadioButton *radioButton_Rainbow;
    QGroupBox *groupBox_Size;
    QHBoxLayout *horizontalLayout_s;
    QSlider *horizontalSlider_p;
    QSpacerItem *verticalSpacer_3;
    QVTKWidget *qvtkWidget;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->setWindowModality(Qt::NonModal);
        PCLViewer->resize(896, 498);
        PCLViewer->setMinimumSize(QSize(0, 0));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_File = new QGroupBox(centralwidget);
        groupBox_File->setObjectName(QString::fromUtf8("groupBox_File"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_File->sizePolicy().hasHeightForWidth());
        groupBox_File->setSizePolicy(sizePolicy);
        groupBox_File->setMinimumSize(QSize(180, 60));
        horizontalLayout = new QHBoxLayout(groupBox_File);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_path = new QLineEdit(groupBox_File);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));
        lineEdit_path->setMinimumSize(QSize(50, 40));

        horizontalLayout->addWidget(lineEdit_path);

        pushButton_browse = new QPushButton(groupBox_File);
        pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));
        pushButton_browse->setMinimumSize(QSize(30, 40));

        horizontalLayout->addWidget(pushButton_browse);

        pushButton_load = new QPushButton(groupBox_File);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setMinimumSize(QSize(50, 40));

        horizontalLayout->addWidget(pushButton_load);


        verticalLayout_2->addWidget(groupBox_File);

        groupBox_ColorMode = new QGroupBox(centralwidget);
        groupBox_ColorMode->setObjectName(QString::fromUtf8("groupBox_ColorMode"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_ColorMode->sizePolicy().hasHeightForWidth());
        groupBox_ColorMode->setSizePolicy(sizePolicy1);
        groupBox_ColorMode->setMinimumSize(QSize(230, 180));
        verticalLayout = new QVBoxLayout(groupBox_ColorMode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_Axis = new QGroupBox(groupBox_ColorMode);
        groupBox_Axis->setObjectName(QString::fromUtf8("groupBox_Axis"));
        sizePolicy.setHeightForWidth(groupBox_Axis->sizePolicy().hasHeightForWidth());
        groupBox_Axis->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox_Axis);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_x = new QRadioButton(groupBox_Axis);
        radioButton_x->setObjectName(QString::fromUtf8("radioButton_x"));
        radioButton_x->setChecked(false);

        horizontalLayout_2->addWidget(radioButton_x);

        radioButton_y = new QRadioButton(groupBox_Axis);
        radioButton_y->setObjectName(QString::fromUtf8("radioButton_y"));
        radioButton_y->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_y);

        radioButton_z = new QRadioButton(groupBox_Axis);
        radioButton_z->setObjectName(QString::fromUtf8("radioButton_z"));
        radioButton_z->setChecked(false);

        horizontalLayout_2->addWidget(radioButton_z);


        verticalLayout->addWidget(groupBox_Axis);

        groupBox_Color = new QGroupBox(groupBox_ColorMode);
        groupBox_Color->setObjectName(QString::fromUtf8("groupBox_Color"));
        horizontalLayout_c = new QVBoxLayout(groupBox_Color);
        horizontalLayout_c->setObjectName(QString::fromUtf8("horizontalLayout_c"));
        radioButton_BlueRed = new QRadioButton(groupBox_Color);
        radioButton_BlueRed->setObjectName(QString::fromUtf8("radioButton_BlueRed"));
        radioButton_BlueRed->setChecked(false);

        horizontalLayout_c->addWidget(radioButton_BlueRed);

        radioButton_GreenMagenta = new QRadioButton(groupBox_Color);
        radioButton_GreenMagenta->setObjectName(QString::fromUtf8("radioButton_GreenMagenta"));
        radioButton_GreenMagenta->setChecked(false);

        horizontalLayout_c->addWidget(radioButton_GreenMagenta);

        radioButton_WhiteRed = new QRadioButton(groupBox_Color);
        radioButton_WhiteRed->setObjectName(QString::fromUtf8("radioButton_WhiteRed"));
        radioButton_WhiteRed->setChecked(false);

        horizontalLayout_c->addWidget(radioButton_WhiteRed);

        radioButton_GreyRed = new QRadioButton(groupBox_Color);
        radioButton_GreyRed->setObjectName(QString::fromUtf8("radioButton_GreyRed"));
        radioButton_GreyRed->setChecked(false);

        horizontalLayout_c->addWidget(radioButton_GreyRed);

        radioButton_Rainbow = new QRadioButton(groupBox_Color);
        radioButton_Rainbow->setObjectName(QString::fromUtf8("radioButton_Rainbow"));
        radioButton_Rainbow->setChecked(true);

        horizontalLayout_c->addWidget(radioButton_Rainbow);


        verticalLayout->addWidget(groupBox_Color);


        verticalLayout_2->addWidget(groupBox_ColorMode);

        groupBox_Size = new QGroupBox(centralwidget);
        groupBox_Size->setObjectName(QString::fromUtf8("groupBox_Size"));
        sizePolicy.setHeightForWidth(groupBox_Size->sizePolicy().hasHeightForWidth());
        groupBox_Size->setSizePolicy(sizePolicy);
        groupBox_Size->setMinimumSize(QSize(180, 60));
        horizontalLayout_s = new QHBoxLayout(groupBox_Size);
        horizontalLayout_s->setObjectName(QString::fromUtf8("horizontalLayout_s"));
        horizontalSlider_p = new QSlider(groupBox_Size);
        horizontalSlider_p->setObjectName(QString::fromUtf8("horizontalSlider_p"));
        horizontalSlider_p->setGeometry(QRect(30, 320, 160, 29));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(1);
        horizontalSlider_p->setOrientation(Qt::Horizontal);

        horizontalLayout_s->addWidget(horizontalSlider_p);


        verticalLayout_2->addWidget(groupBox_Size);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_2);

        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy2);
        qvtkWidget->setMinimumSize(QSize(640, 480));

        horizontalLayout_3->addWidget(qvtkWidget);

        PCLViewer->setCentralWidget(centralwidget);
        QWidget::setTabOrder(pushButton_load, radioButton_z);

        retranslateUi(PCLViewer);

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "Point Cloud Viewer", 0, QApplication::UnicodeUTF8));
        groupBox_File->setTitle(QApplication::translate("PCLViewer", "File", 0, QApplication::UnicodeUTF8));
        lineEdit_path->setText(QApplication::translate("PCLViewer", "../demo.pcd", 0, QApplication::UnicodeUTF8));
        pushButton_browse->setText(QApplication::translate("PCLViewer", "Browse...", 0, QApplication::UnicodeUTF8));
        pushButton_load->setText(QApplication::translate("PCLViewer", "Load", 0, QApplication::UnicodeUTF8));
        groupBox_ColorMode->setTitle(QApplication::translate("PCLViewer", "Color", 0, QApplication::UnicodeUTF8));
        groupBox_Axis->setTitle(QApplication::translate("PCLViewer", "Axis", 0, QApplication::UnicodeUTF8));
        radioButton_x->setText(QApplication::translate("PCLViewer", "X", 0, QApplication::UnicodeUTF8));
        radioButton_y->setText(QApplication::translate("PCLViewer", "Y", 0, QApplication::UnicodeUTF8));
        radioButton_z->setText(QApplication::translate("PCLViewer", "Z", 0, QApplication::UnicodeUTF8));
        groupBox_Color->setTitle(QApplication::translate("PCLViewer", "Gradient", 0, QApplication::UnicodeUTF8));
        radioButton_BlueRed->setText(QApplication::translate("PCLViewer", "Blue to red", 0, QApplication::UnicodeUTF8));
        radioButton_GreenMagenta->setText(QApplication::translate("PCLViewer", "Green to magenta", 0, QApplication::UnicodeUTF8));
        radioButton_WhiteRed->setText(QApplication::translate("PCLViewer", "White to red", 0, QApplication::UnicodeUTF8));
        radioButton_GreyRed->setText(QApplication::translate("PCLViewer", "Grey / red", 0, QApplication::UnicodeUTF8));
        radioButton_Rainbow->setText(QApplication::translate("PCLViewer", "Rainbow", 0, QApplication::UnicodeUTF8));
        groupBox_Size->setTitle(QApplication::translate("PCLViewer", "Size", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
