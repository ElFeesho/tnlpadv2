#include "messagecommand.hpp"

MessageCommand::MessageCommand() : Command(Command::MessageCommand, "M")
{
}

const QByteArray &MessageCommand::toPayload() const
{
	return getHeader();
}
