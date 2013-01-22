#include "logincommand.hpp"

LoginCommand::LoginCommand(const QString &nick) : Command(Command::LoginCommand), nick(nick)
{
}

const QByteArray *LoginCommand::toPayload() const
{
	QByteArray nickBytes = nick.toUtf8();
	QByteArray *payload = new QByteArray("L "+QByteArray::number(nickBytes.size())+' '+nickBytes);
	return payload;
}




