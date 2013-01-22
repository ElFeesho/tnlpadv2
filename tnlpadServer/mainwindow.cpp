#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	idStart = 1;

	if(tcpServer.listen(QHostAddress::Any, 0xf00f))
	{
		ui->textConsole->append("<b>Listening on port 0xf00f</b><br/>");
	}

	connect(&tcpServer, SIGNAL(newConnection()),this, SLOT(newClient()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::broadcastCommand(Command &command, User *except)
{
	ui->textConsole->append("<b>Broadcasting Command</b><br/>");
	foreach(User *user, users)
	{
		if(user == except)
			continue;

		user->sendCommand(command);
	}
}

void MainWindow::newClient()
{
	while(tcpServer.hasPendingConnections())
	{
		ui->textConsole->append("<b>Added New Client</b><br/>");
		User *user = new User(tcpServer.nextPendingConnection(),idStart++);
		connect(user, SIGNAL(userRetrievedCommand(User*,Command&)), this, SLOT(userRetrievedCommand(User*, Command&)));
		users.append(user);
	}
}

void MainWindow::userRetrievedCommand(User *user, Command &command)
{
	ui->textConsole->append("<b>Got Command from user</b><br/>");
	switch(command.getType())
	{
		case Command::ClearCommand:
			broadcastCommand(command, user);
			break;

	case Command::DrawCommand:
		broadcastCommand(command, user);
		break;
	case Command::JoinCommand:
		broadcastCommand(command);
		break;
	case Command::LeaveCommand:
		broadcastCommand(command);
		break;
	case Command::MessageCommand:
		broadcastCommand(command);
		break;
	case Command::NickCommand:
		broadcastCommand(command);
		break;
	}
}
