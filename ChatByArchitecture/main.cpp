#include "ChatByArchitecture.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChatByArchitecture w;
	w.show();
	return a.exec();
}
