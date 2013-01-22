#ifndef LOGINCOMMAND_HPP
#define LOGINCOMMAND_HPP

#include <QString>

#include "command.hpp"

class LoginCommand : public Command
{
public:
	LoginCommand(const QString &nick);

	const QByteArray &toPayload() const;

private:
	QString nick;
};

#endif // LOGINCOMMAND_HPP
