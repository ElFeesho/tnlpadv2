#include "clearcommand.hpp"

ClearCommand::ClearCommand() : Command(Command::ClearCommand, "C")
{
}

const QByteArray &ClearCommand::toPayload() const
{
	return getHeader();
}
