#include "messagecommand.hpp"

MessageCommand::MessageCommand() : Command(Command::MessageCommand)
{
}

const QByteArray *MessageCommand::toPayload() const
{
}
