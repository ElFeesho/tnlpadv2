#include "command.hpp"

Command::Command(CommandType type)
{
	this->type = type;
}

Command::CommandType Command::getType() const
{
	return type;
}
