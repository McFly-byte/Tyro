/********************************************************************************
** Form generated from reading UI file 'pigsty.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIGSTY_H
#define UI_PIGSTY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <mybutton.h>

QT_BEGIN_NAMESPACE

class Ui_Pigsty
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    MyButton *pushButton;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    MyButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menustart;

    void setupUi(QMainWindow *Pigsty)
    {
        if (Pigsty->objectName().isEmpty())
            Pigsty->setObjectName(QStringLiteral("Pigsty"));
        Pigsty->resize(1280, 880);
        actionquit = new QAction(Pigsty);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        centralwidget = new QWidget(Pigsty);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(930, 0, 351, 321));
        widget_3->setStyleSheet(QStringLiteral("background-image: url(:/i/a.jpg);"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalSpacer = new QSpacerItem(87, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral("background-image: url(:/i/ii.jpg);"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        pushButton = new MyButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 0, 1, 1);

        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/i/ii.jpg);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton_2 = new MyButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_2->addWidget(widget, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 61, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);

        Pigsty->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Pigsty);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 26));
        menustart = new QMenu(menubar);
        menustart->setObjectName(QStringLiteral("menustart"));
        Pigsty->setMenuBar(menubar);

        menubar->addAction(menustart->menuAction());
        menustart->addAction(actionquit);

        retranslateUi(Pigsty);

        QMetaObject::connectSlotsByName(Pigsty);
    } // setupUi

    void retranslateUi(QMainWindow *Pigsty)
    {
        Pigsty->setWindowTitle(QApplication::translate("Pigsty", "MainWindow", Q_NULLPTR));
        actionquit->setText(QApplication::translate("Pigsty", "\351\200\200\345\207\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pigsty", "\346\203\263\350\246\201\346\267\273\345\212\240\347\232\204\347\214\252\347\274\226\345\217\267", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Pigsty", "PushButton", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pigsty", "\345\270\214\346\234\233\345\215\226\346\216\211\347\232\204\347\214\252\347\274\226\345\217\267", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Pigsty", "PushButton", Q_NULLPTR));
        menustart->setTitle(QApplication::translate("Pigsty", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pigsty: public Ui_Pigsty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIGSTY_H
