#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <QByteArray>

class Command
{
public:
	enum CommandType
	{
		DrawCommand,
		ClearCommand,
		JoinCommand,
		LeaveCommand,
		LoginCommand,
		NickCommand,
		MessageCommand
	};

	Command(CommandType type);
	CommandType getType() const;
	virtual const QByteArray *toPayload() const = 0;
private:
	CommandType type;
};

#endif // COMMAND_HPP
