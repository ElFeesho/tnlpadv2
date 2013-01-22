#ifndef CLEARCOMMAND_HPP
#define CLEARCOMMAND_HPP

#include "command.hpp"

class ClearCommand : public Command
{
public:
	ClearCommand();

	const QByteArray &toPayload() const;
};

#endif // CLEARCOMMAND_HPP
