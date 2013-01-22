#include "logincommand.hpp"

LoginCommand::LoginCommand(const QString &nick) : Command(Command::LoginCommand, "L"), nick(nick)
{
}

const QByteArray &LoginCommand::toPayload() const
{
	QByteArray nickBytes = nick.toUtf8();
	return "L "+QByteArray::number(nickBytes.size())+' '+nickBytes;
}




