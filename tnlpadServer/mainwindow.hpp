#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "user.hpp"
#include <QVector>

#include <QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void broadcastCommand(Command &command, User *except = 0);

public slots:
	void newClient();
	void userRetrievedCommand(User *user, Command &command);
	
private:
	Ui::MainWindow *ui;

	int idStart;

	QVector<User*> users;

	QTcpServer tcpServer;
};

#endif // MAINWINDOW_HPP
