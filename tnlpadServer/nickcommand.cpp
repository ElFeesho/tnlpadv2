#include "nickcommand.hpp"

NickCommand::NickCommand() : Command(Command::NickCommand, "N")
{
}

NickCommand::NickCommand(int id, const QString &oldNick, const QString &newNick) :
	Command(Command::NickCommand, "N"), id(id), oldNick(oldNick), newNick(newNick)
{

}

const int NickCommand::getID() const
{
	return id;
}

const QString &NickCommand::getOldNick() const
{
	return oldNick;
}

const QString &NickCommand::getNewNick() const
{
	return newNick;
}

const QByteArray &NickCommand::toPayload() const
{
	QByteArray nickBytes = newNick.toUtf8();
	return getHeader()+QByteArray::number(nickBytes.size())+' '+nickBytes;
}
