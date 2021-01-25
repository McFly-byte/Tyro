/********************************************************************************
** Form generated from reading UI file 'pigfarm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIGFARM_H
#define UI_PIGFARM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pigfarm
{
public:
    QAction *actionquit;
    QAction *actionsave;
    QWidget *centralwidget;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QMenu *menustart;

    void setupUi(QMainWindow *Pigfarm)
    {
        if (Pigfarm->objectName().isEmpty())
            Pigfarm->setObjectName(QStringLiteral("Pigfarm"));
        Pigfarm->resize(1280, 880);
        actionquit = new QAction(Pigfarm);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        actionsave = new QAction(Pigfarm);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        centralwidget = new QWidget(Pigfarm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(450, 0, 381, 113));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QWidget(widget_4);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(label_2);


        gridLayout_2->addWidget(widget, 0, 0, 2, 1);

        widget_2 = new QWidget(widget_4);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 1, 1, 1);

        widget_3 = new QWidget(widget_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(label_8);


        gridLayout_2->addWidget(widget_3, 1, 1, 1, 1);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(170, 40, 182, 43));
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 1, 1, 1);

        spinBox = new QSpinBox(widget_5);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout_3->addWidget(spinBox, 0, 2, 1, 1);

        Pigfarm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Pigfarm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        menustart = new QMenu(menubar);
        menustart->setObjectName(QStringLiteral("menustart"));
        Pigfarm->setMenuBar(menubar);

        menubar->addAction(menustart->menuAction());
        menustart->addAction(actionquit);
        menustart->addAction(actionsave);

        retranslateUi(Pigfarm);

        QMetaObject::connectSlotsByName(Pigfarm);
    } // setupUi

    void retranslateUi(QMainWindow *Pigfarm)
    {
        Pigfarm->setWindowTitle(QApplication::translate("Pigfarm", "MainWindow", Q_NULLPTR));
        actionquit->setText(QApplication::translate("Pigfarm", "\351\200\200\345\207\272", Q_NULLPTR));
        actionsave->setText(QApplication::translate("Pigfarm", "\345\255\230\346\241\243", Q_NULLPTR));
        label->setText(QApplication::translate("Pigfarm", "\347\214\252\345\234\272\347\254\254", Q_NULLPTR));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("Pigfarm", "\345\244\251", Q_NULLPTR));
        label_5->setText(QString());
        label_4->setText(QApplication::translate("Pigfarm", "\346\200\273\346\224\257\345\207\272", Q_NULLPTR));
        label_7->setText(QApplication::translate("Pigfarm", "\346\200\273\346\224\266\345\205\245", Q_NULLPTR));
        label_8->setText(QString());
        label_6->setText(QApplication::translate("Pigfarm", "\346\227\266\351\227\264\345\217\202\346\225\260", Q_NULLPTR));
        menustart->setTitle(QApplication::translate("Pigfarm", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pigfarm: public Ui_Pigfarm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIGFARM_H
