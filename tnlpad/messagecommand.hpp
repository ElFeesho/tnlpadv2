#ifndef MESSAGECOMMAND_HPP
#define MESSAGECOMMAND_HPP

#include "command.hpp"

class MessageCommand : public Command
{
public:
	MessageCommand();

	const QByteArray *toPayload() const;
};

#endif // MESSAGECOMMAND_HPP
