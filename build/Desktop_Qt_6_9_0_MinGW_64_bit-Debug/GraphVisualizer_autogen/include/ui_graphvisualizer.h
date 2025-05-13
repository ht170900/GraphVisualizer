/********************************************************************************
** Form generated from reading UI file 'graphvisualizer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVISUALIZER_H
#define UI_GRAPHVISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphVisualizer
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *filePathLineEdit;
    QWidget *chartContainer;
    QPushButton *browseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GraphVisualizer)
    {
        if (GraphVisualizer->objectName().isEmpty())
            GraphVisualizer->setObjectName("GraphVisualizer");
        GraphVisualizer->resize(800, 600);
        centralwidget = new QWidget(GraphVisualizer);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        filePathLineEdit = new QLineEdit(centralwidget);
        filePathLineEdit->setObjectName("filePathLineEdit");

        gridLayout->addWidget(filePathLineEdit, 1, 1, 1, 1);

        chartContainer = new QWidget(centralwidget);
        chartContainer->setObjectName("chartContainer");

        gridLayout->addWidget(chartContainer, 0, 0, 1, 2);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");

        gridLayout->addWidget(browseButton, 1, 0, 1, 1);

        GraphVisualizer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraphVisualizer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        GraphVisualizer->setMenuBar(menubar);
        statusbar = new QStatusBar(GraphVisualizer);
        statusbar->setObjectName("statusbar");
        GraphVisualizer->setStatusBar(statusbar);

        retranslateUi(GraphVisualizer);

        QMetaObject::connectSlotsByName(GraphVisualizer);
    } // setupUi

    void retranslateUi(QMainWindow *GraphVisualizer)
    {
        GraphVisualizer->setWindowTitle(QCoreApplication::translate("GraphVisualizer", "GraphVisualizer", nullptr));
        browseButton->setText(QCoreApplication::translate("GraphVisualizer", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphVisualizer: public Ui_GraphVisualizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVISUALIZER_H
