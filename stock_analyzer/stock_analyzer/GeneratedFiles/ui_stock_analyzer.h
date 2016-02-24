/********************************************************************************
** Form generated from reading UI file 'stock_analyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCK_ANALYZER_H
#define UI_STOCK_ANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stock_analyzerClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QPushButton *checkit;
    QTextBrowser *textBrowser;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *stock_analyzerClass)
    {
        if (stock_analyzerClass->objectName().isEmpty())
            stock_analyzerClass->setObjectName(QStringLiteral("stock_analyzerClass"));
        stock_analyzerClass->resize(600, 400);
        centralWidget = new QWidget(stock_analyzerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 10, 111, 31));
        checkit = new QPushButton(centralWidget);
        checkit->setObjectName(QStringLiteral("checkit"));
        checkit->setGeometry(QRect(150, 10, 91, 31));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 50, 311, 231));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(340, 50, 256, 192));
        stock_analyzerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(stock_analyzerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        stock_analyzerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(stock_analyzerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        stock_analyzerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(stock_analyzerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        stock_analyzerClass->setStatusBar(statusBar);

        retranslateUi(stock_analyzerClass);

        QMetaObject::connectSlotsByName(stock_analyzerClass);
    } // setupUi

    void retranslateUi(QMainWindow *stock_analyzerClass)
    {
        stock_analyzerClass->setWindowTitle(QApplication::translate("stock_analyzerClass", "stock_analyzer", 0));
        checkit->setText(QApplication::translate("stock_analyzerClass", "click", 0));
        textBrowser->setPlaceholderText(QApplication::translate("stock_analyzerClass", "aaaaa", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("stock_analyzerClass", "Open_price", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("stock_analyzerClass", "High_price", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("stock_analyzerClass", "Low_price", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("stock_analyzerClass", "Close_price", 0));
    } // retranslateUi

};

namespace Ui {
    class stock_analyzerClass: public Ui_stock_analyzerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCK_ANALYZER_H
