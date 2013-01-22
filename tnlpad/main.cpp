#include <QtGui/QApplication>
#include "joinwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	JoinWindow w;
	w.show();
	
	return a.exec();
}
