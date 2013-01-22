#include "networkengine.hpp"

#include "logincommand.hpp"
#include "drawcommand.hpp"
#include "joincommand.hpp"
#include "nickcommand.hpp"
#include "clearcommand.hpp"

NetworkEngine::NetworkEngine(QObject *parent) :
   QObject(parent)
{
	_socket = new QTcpSocket(this);

	connect(_socket,SIGNAL(connected()),this, SLOT(socketConnected()));
	connect(_socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
}

NetworkEngine *NetworkEngine::instance()
{
	if(NetworkEngine::_inst == NULL)
	{
		NetworkEngine::_inst = new NetworkEngine();
	}

	return _inst;
}

void NetworkEngine::login(const QString &nick, const QString &host)
{
	_inst->setNickName(nick);
	_inst->getSocket()->connectToHost(host,0xf00f);
}

void NetworkEngine::send_command(const Command &command)
{
	const QByteArray *payload = command.toPayload();
	_inst->getSocket()->write(*payload);
	delete payload;
}

NetworkEngine *NetworkEngine::_inst = NetworkEngine::instance();

QTcpSocket *NetworkEngine::getSocket()
{
	return _socket;
}

void NetworkEngine::setNickName(const QString &nickname)
{
	this->nickname = nickname;
}

QByteArray *NetworkEngine::readChunk()
{
	QByteArray buffer;
	while(_socket->bytesAvailable()>0)
	{
		buffer.append(_socket->read(1));
		if(buffer.endsWith(' '))
			break;
	}
	buffer.chop(1);

	return new QByteArray(buffer);
}

QByteArray *NetworkEngine::readChunk(int size)
{
	return new QByteArray(_socket->read(size));
}

User *NetworkEngine::getUserByID(int id)
{
	for(int i = 0; i<users.size(); i++)
	{
		User *user = users.at(i);
		if(user->getID() == id)
		{
			return user;
		}
	}

	return NULL;
}

int NetworkEngine::readProtocolHeader()
{
	QByteArray header = _socket->read(2);
	header.chop(1);
	return header.at(0);
}

void NetworkEngine::socketConnected()
{
	// Now that we're connected to the server, we need
	// to login.
	LoginCommand loginCommand(nickname);
	send_command(loginCommand);
}

void NetworkEngine::socketReadyRead()
{
	while(_socket->bytesAvailable()>0)
	{
		switch(readProtocolHeader())
		{
		case 'L': // OGIN
			{
				QByteArray *sizeBuf = readChunk();
				QByteArray *messageChunk = readChunk(sizeBuf->toInt());
				QString message(*messageChunk);
				delete sizeBuf;
				delete messageChunk;
				emit login_response(message);
			}
			break;
		case 'C': // LEAR SCREEN
		{
			ClearCommand newClear;
			_socket->readAll(); // Currently not bothered who clears the screen
			emit incoming_command(newClear);
		}
			break;
		case 'D': // RAWING
		{
			QByteArray *x = readChunk();
			QByteArray *y = readChunk();
			QByteArray *x2 = readChunk();
			QByteArray *y2 = readChunk();
			DrawCommand newLine;
			newLine.set(x->toInt(), y->toInt(), x2->toInt(), y2->toInt());
			delete x;
			delete y;
			delete x2;
			delete y2;
			emit incoming_command(newLine);
		}
			break;
		case 'J': // OIN
		{
			QByteArray *idBuf = readChunk();
			QByteArray *sizeBuf = readChunk();
			QByteArray *nickChnk = readChunk(sizeBuf->toInt());
			QString nick(*nickChnk);

			User *newUser = new User(idBuf->toInt(), nick);
			users.append(newUser);
			JoinCommand newJoin;
			delete idBuf;
			delete sizeBuf;
			delete nickChnk;

			emit incoming_command(newJoin);
		}
			break;
		case 'N': // ICKNAME CHANGE
		{
			QByteArray *idBuf = readChunk();
			QByteArray *sizeBuf = readChunk();
			QByteArray *nickChnk = readChunk(sizeBuf->toInt());
			QString nick(*nickChnk);

			int id = idBuf->toInt();

			User *user = getUserByID(id);

			if(user == NULL)
			{
				delete idBuf;
				delete sizeBuf;
				delete nickChnk;
				break;
			}

			NickCommand newNick(idBuf->toInt(), user->getNickname(), nick);
			user->setNickname(nick);

			delete idBuf;
			delete sizeBuf;
			delete nickChnk;

			emit incoming_command(newNick);
		}
			break;
		case 'T': // EXT MESSAGE
		{
				QByteArray *sizeBuf = readChunk();
				QByteArray *messageChnk = readChunk(sizeBuf->toInt());
				QString message(*messageChnk);
				delete messageChnk;
				delete sizeBuf;
		}
		default:
			emit connection_error();
			break;
		}
	}
}
