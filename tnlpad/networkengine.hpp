#ifndef NETWORKENGINE_HPP
#define NETWORKENGINE_HPP

#include <QObject>
#include <QTcpSocket>
#include <QVector>
#include "user.hpp"
#include "command.hpp"

class NetworkEngine : public QObject
{
	Q_OBJECT
private:
	explicit NetworkEngine(QObject *parent = 0);
	
public:
	static NetworkEngine *instance();

	static void login(const QString &nick, const QString &host);

	static void send_command(const Command &command);
signals:
	void login_response(const QString &response);

	void incoming_command(const Command &command);
	
	void connection_error();

public slots:
	void socketConnected();
	void socketReadyRead();

private:
	QTcpSocket *getSocket();
	void setNickName(const QString &nickname);
	QByteArray *readChunk();
	QByteArray *readChunk(int size);

	User *getUserByID(int id);

	int readProtocolHeader();

	QTcpSocket *_socket;

	QString nickname;

	QVector<User*> users;

	static NetworkEngine *_inst;
};

#endif // NETWORKENGINE_HPP
