#include "drawcommand.hpp"

DrawCommand::DrawCommand() :  Command(Command::DrawCommand)
{

}

const QByteArray *DrawCommand::toPayload() const
{
	QByteArray *payload = new QByteArray("D "+QByteArray::number(x)+' '+QByteArray::number(y)+' '+QByteArray::number(x2)+' '+QByteArray::number(y2)+' ');
	return payload;
}

void DrawCommand::set(int x, int y, int x2, int y2)
{
	this->x = x;
	this->y = y;
	this->x2 = x2;
	this->y2 = y2;
}

int DrawCommand::X()
{
	return x;
}

int DrawCommand::Y()
{
	return y;
}

int DrawCommand::X2()
{
	return x2;
}

int DrawCommand::Y2()
{
	return y2;
}
