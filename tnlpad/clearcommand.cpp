#include "clearcommand.hpp"

ClearCommand::ClearCommand() : Command(Command::ClearCommand)
{
}

const QByteArray *ClearCommand::toPayload() const
{
	return new QByteArray("C ");
}
