#include "stock_analyzer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	stock_analyzer w;
	w.show();
	return a.exec();
}
