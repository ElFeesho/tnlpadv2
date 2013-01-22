#ifndef JOINCOMMAND_HPP
#define JOINCOMMAND_HPP

#include "command.hpp"
#include <QString>

class JoinCommand : public Command
{
public:
	JoinCommand();

	const QByteArray &toPayload() const;
};

#endif // JOINCOMMAND_HPP
