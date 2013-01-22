#ifndef USER_HPP
#define USER_HPP

#include <QObject>

#include "command.hpp"

#include <QTcpSocket>

#include <QByteArray>
#include <QString>

class User : public QObject
{
	Q_OBJECT
public:
	explicit User(QObject *parent = 0);
	
	User(QTcpSocket *socket, int id, QObject *parent = 0);


	void sendCommand(Command &command);
signals:
	void userRetrievedCommand(User *, Command&);
public slots:
	void dataReady();

private:
	const QByteArray *readChunk();
	const QByteArray &readChunk(int size);
	int readProtocolHeader();

	QTcpSocket *_socket;

	int id;
	QString nickName;
};

#endif // USER_HPP
