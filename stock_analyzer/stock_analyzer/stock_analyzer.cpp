#include "stock_analyzer.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>



#define dbhost "localhost"
#define dbname "stockdata"
#define username "root"
#define password "lsylsy2008"

extern double bayecurvefitting(const double[50], const double y[50], double temp);
QString sendrequest(QString);

stock_analyzer::stock_analyzer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName(dbhost);
	db.setDatabaseName(dbname);
	db.setUserName(username);
	db.setPassword(password);
	db.open();
}

stock_analyzer::~stock_analyzer()
{

}

void stock_analyzer::on_checkit_clicked()
{
	QString result=sendrequest(this->ui.textEdit->toPlainText());
	//this->ui.textBrowser->setText(result);
	parseprice(result);

	double x[50];
	for (int i = 0; i < 50; i++)
	{
		x[i] = i + 1;
	}
	double y[50];
	for (int i = 0; i < 50; i++)
	{
		y[i] = datas[i];
	}
	double resultBaye;
	resultBaye=bayecurvefitting(x, y, 50);
	this->ui.textBrowser->append(QString::number(resultBaye));
	/*
	for (int i = 0; i < datas.size(); i++)
	{
		this->ui.textBrowser->append(QString::number(datas[i]));
	}
	*/
}


QString stock_analyzer::sendrequest(QString input)
{
	// create custom temporary event loop on stack
	QEventLoop eventLoop;

	// "quit()" the event-loop, when the network request "finished()"
	QNetworkAccessManager mgr;
	QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

	// the HTTP request
	QNetworkRequest req(QUrl(QString("https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.historicaldata%20where%20symbol%20%3D%20%22"+input+"%22%20and%20startDate%20%3D%20%222015-09-11%22%20and%20endDate%20%3D%20%22" + QDate::currentDate().addDays(-1).toString("yyyy-MM-dd") + "%22%20limit%2050&diagnostics=true&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys")));
	//QNetworkRequest req(QUrl(inputings));
	QNetworkReply *reply = mgr.get(req);
	eventLoop.exec(); // blocks stack until "finished()" has been called
	QString get = reply->readAll();

	if (reply->error() == QNetworkReply::NoError) {
		//success
		qDebug() << "Success" << get;
		delete reply;
	}
	else {
		//failure
		qDebug() << "Failure" << reply->errorString();
		delete reply;
	}

	return get;
}


void stock_analyzer::parseprice(QString input)
{
	QXmlStreamReader reader(input);
	int row = 0;
	while (!reader.atEnd()) {
		// read next token
		QXmlStreamReader::TokenType type = reader.readNext();

		if (type == QXmlStreamReader::StartElement) {
			//qDebug() << "<" << reader.name() << ">";
			if (reader.name() == QString("Open"))
			{
				//qDebug() << reader.readElementText();
				QTableWidgetItem *Item = new QTableWidgetItem;
				QString data = reader.readElementText();
				datas.push_back(data.toFloat());
				this->ui.tableWidget->insertRow(row); 
				Item->setText(data);
				this->ui.tableWidget->setItem(row, 0, Item);
			}
			if (reader.name() == QString("High"))
			{
				//qDebug() << reader.readElementText();
				QString data = reader.readElementText();
				QTableWidgetItem *Item = new QTableWidgetItem;
				Item->setText(data);
				this->ui.tableWidget->setItem(row, 1, Item);
			}
			if (reader.name() == QString("Low"))
			{
				//qDebug() << reader.readElementText();
				QString data = reader.readElementText();
				QTableWidgetItem *Item = new QTableWidgetItem;
				Item->setText(data);
				this->ui.tableWidget->setItem(row, 2, Item);
			}
			if (reader.name() == QString("Close"))
			{
				//qDebug() << reader.readElementText();
				QString data = reader.readElementText();
				QTableWidgetItem *Item = new QTableWidgetItem;
				Item->setText(data);
				this->ui.tableWidget->setItem(row, 3, Item);
				row++;
			}
			
		}
	}

}




