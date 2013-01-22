#ifndef MESSAGECOMMAND_HPP
#define MESSAGECOMMAND_HPP

#include "command.hpp"
#include <QString>

class MessageCommand : public Command
{
public:
	MessageCommand();

	const QByteArray &toPayload() const;
};

#endif // MESSAGECOMMAND_HPP
