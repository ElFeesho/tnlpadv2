#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <QByteArray>
#include <QString>

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

	Command(CommandType type, const QString &header);
	CommandType getType() const;

	void setSenderID(int id);
	int getSenderID();

	const QByteArray &getHeader() const;

	virtual const QByteArray &toPayload() const = 0;
private:
	CommandType type;
	QByteArray header;
	int senderID;
};

#endif // COMMAND_HPP
