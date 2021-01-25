/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainScene
{
public:
    QAction *actionquit;
    QAction *actioninformation;
    QAction *actionsave;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menustart;

    void setupUi(QMainWindow *mainScene)
    {
        if (mainScene->objectName().isEmpty())
            mainScene->setObjectName(QStringLiteral("mainScene"));
        mainScene->resize(1280, 880);
        actionquit = new QAction(mainScene);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        actioninformation = new QAction(mainScene);
        actioninformation->setObjectName(QStringLiteral("actioninformation"));
        actionsave = new QAction(mainScene);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        centralWidget = new QWidget(mainScene);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainScene);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
        menustart = new QMenu(menuBar);
        menustart->setObjectName(QStringLiteral("menustart"));
        mainScene->setMenuBar(menuBar);

        menuBar->addAction(menustart->menuAction());
        menustart->addAction(actionquit);
        menustart->addAction(actioninformation);
        menustart->addAction(actionsave);

        retranslateUi(mainScene);

        QMetaObject::connectSlotsByName(mainScene);
    } // setupUi

    void retranslateUi(QMainWindow *mainScene)
    {
        mainScene->setWindowTitle(QApplication::translate("mainScene", "mainScene", Q_NULLPTR));
        actionquit->setText(QApplication::translate("mainScene", "\351\200\200\345\207\272", Q_NULLPTR));
        actioninformation->setText(QApplication::translate("mainScene", "\344\277\241\346\201\257", Q_NULLPTR));
        actionsave->setText(QApplication::translate("mainScene", "\350\257\273\346\241\243", Q_NULLPTR));
        menustart->setTitle(QApplication::translate("mainScene", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainScene: public Ui_mainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
