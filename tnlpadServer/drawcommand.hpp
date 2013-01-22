#ifndef DRAWCOMMAND_HPP
#define DRAWCOMMAND_HPP

#include "command.hpp"
#include <QString>

class DrawCommand : public Command
{
public:
	DrawCommand();
	DrawCommand(const Command&);
	const QByteArray &toPayload() const;

	void set(int x, int y, int x2, int y2);

	int X();
	int Y();
	int X2();
	int Y2();

private:
	int x, y, x2, y2;

};

#endif // DRAWCOMMAND_HPP
