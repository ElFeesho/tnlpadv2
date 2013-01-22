#include "user.hpp"

User::User() : id(0), nick("Unnamed")
{
}

User::User(int id, const QString &nickname) : id(id), nick(nickname)
{
}

const int User::getID() const
{
	return id;
}

const QString &User::getNickname() const
{
	return nick;
}

void User::setNickname(const QString &newNick)
{
	nick = newNick;
}


