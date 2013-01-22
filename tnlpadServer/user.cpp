#include "user.hpp"

#include "logincommand.hpp"
#include "clearcommand.hpp"
#include "nickcommand.hpp"
#include "joincommand.hpp"
#include "drawcommand.hpp"

static const char SeparatorToken = ' ';

User::User(QObject *parent) :
   QObject(parent)
{
}

User::User(QTcpSocket *socket, int id, QObject *parent) : QObject(parent), _socket(socket), id(id)
{
	connect(_socket, SIGNAL(readyRead()),this, SLOT(dataReady()));
}

void User::dataReady()
{
	while(_socket->bytesAvailable()>0)
	{
		switch(readProtocolHeader())
		{
		case 'L': // OGIN
			{
				const QByteArray *sizeBuf = readChunk();
				QString nick(readChunk(sizeBuf->toInt()));
				delete sizeBuf;
				LoginCommand loginCommand(nick);

				emit userRetrievedCommand(this, loginCommand);
			}
			break;
		case 'C': // LEAR SCREEN
		{
			ClearCommand newClear;
			emit userRetrievedCommand(this, newClear);
		}
			break;
		case 'D': // RAWING
		{
			const QByteArray *x = readChunk();
			const QByteArray *y = readChunk();
			const QByteArray *x2 = readChunk();
			const QByteArray *y2 = readChunk();
			DrawCommand newLine;
			newLine.set(x->toInt(), y->toInt(), x2->toInt(), y2->toInt());
			delete x;
			delete y;
			delete x2;
			delete y2;
			emit userRetrievedCommand(this, newLine);
		}
			break;
		case 'N': // ICKNAME CHANGE
		{
			const QByteArray *idBuf = readChunk();
			const QByteArray *sizeBuf = readChunk();

			QString newNick(readChunk(sizeBuf->toInt()));

			int id = idBuf->toInt();

			delete idBuf;
			delete sizeBuf;

			NickCommand newNickCmd(id, nickName, newNick);
			nickName = newNick;
			emit userRetrievedCommand(this, newNickCmd);
		}
			break;
		case 'T': // EXT MESSAGE
		{
			const QByteArray *sizeBuf = readChunk();
			QString message(readChunk(sizeBuf->toInt()));
			delete sizeBuf;
		}
		default:
			break;
		}
	}
}


const QByteArray *User::readChunk()
{
	QByteArray *buffer = new QByteArray();
	int count = 0;
	qDebug("Bytes to read: %lld", _socket->bytesAvailable());
	while(_socket->bytesAvailable()>0)
	{
		QByteArray data = _socket->read(1);
		buffer->append(data);
		if(buffer->at(count) == SeparatorToken)
			break;
		count++;
	}
	buffer->chop(1);

	return buffer;
}

const QByteArray &User::readChunk(int size)
{
	return _socket->read(size);
}

int User::readProtocolHeader()
{
	const QByteArray *header = readChunk();
	int h = header->at(0);
	delete header;
	return h;
}

void User::sendCommand(Command &command)
{
	_socket->write(command.toPayload());
}
