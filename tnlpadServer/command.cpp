#include "command.hpp"

Command::Command(CommandType type, const QString &header)
{
	this->header = header.toUtf8();
	this->type = type;
}

void Command::setSenderID(int id)
{
	this->senderID = id;
}

int Command::getSenderID()
{
	return senderID;
}

const QByteArray &Command::getHeader() const
{
	return header+' '+QByteArray::number(senderID)+' ';
}

Command::CommandType Command::getType() const
{
	return type;
}
