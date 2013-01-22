#include "joincommand.hpp"

JoinCommand::JoinCommand() : Command(Command::JoinCommand, "J")
{
}

const QByteArray &JoinCommand::toPayload() const
{
}
