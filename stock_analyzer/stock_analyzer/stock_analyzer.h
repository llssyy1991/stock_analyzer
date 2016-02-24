#ifndef STOCK_ANALYZER_H
#define STOCK_ANALYZER_H

#include <QtWidgets/QMainWindow>
#include "ui_stock_analyzer.h"
#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QUrl>
#include <QUrlQuery>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <vector>
using namespace std;

class stock_analyzer : public QMainWindow
{
	Q_OBJECT

public:
	stock_analyzer(QWidget *parent = 0);
	~stock_analyzer();
	QSqlDatabase db;
	vector<float> datas;
	QString sendrequest(QString);
	void parseprice(QString input);


private:
	Ui::stock_analyzerClass ui;
private slots:
	void on_checkit_clicked();
};

#endif // STOCK_ANALYZER_H
