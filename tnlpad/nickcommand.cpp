#include "nickcommand.hpp"

NickCommand::NickCommand() : Command(Command::NickCommand)
{
}

NickCommand::NickCommand(int id, const QString &oldNick, const QString &newNick) : Command(Command::NickCommand), id(id), oldNick(oldNick), newNick(newNick)
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

const QByteArray *NickCommand::toPayload() const
{
	QByteArray nickBytes = newNick.toUtf8();
	return new QByteArray("N "+QByteArray::number(nickBytes.size())+' '+nickBytes);
}
