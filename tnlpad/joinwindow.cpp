#include "joinwindow.hpp"
#include "ui_joinwindow.h"

#include "canvaswindow.hpp"
#include "networkengine.hpp"

JoinWindow::JoinWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::JoinWindow)
{
	ui->setupUi(this);
}

JoinWindow::~JoinWindow()
{
	delete ui;
}

void JoinWindow::on_buttonConnect_clicked()
{
	 QString nick = ui->textName->text();
	 QString host = ui->textHost->text();

	 if(nick.length()<=0)
	 {
		 nick = "Unnamed";
	 }

	 if(host.length()==0)
	 {
		 host = "127.0.0.1";
	 }

	 NetworkEngine::login(nick, host);

	 CanvasWindow *window = new CanvasWindow();
	 window->show();

	 this->close();
}
