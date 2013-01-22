#ifndef NICKCOMMAND_HPP
#define NICKCOMMAND_HPP

#include "command.hpp"

#include <QString>

class NickCommand : public Command
{
public:
	NickCommand();
	NickCommand(int id, const QString &oldNick, const QString &newNick);

	const int getID() const;

	const QString &getOldNick() const;
	const QString &getNewNick() const;

	const QByteArray &toPayload() const;
private:
	int id;
	QString oldNick;
	QString newNick;
};

#endif // NICKCOMMAND_HPP
