#ifndef USER_HPP
#define USER_HPP

#include <QString>

class User
{
public:
	User();
	User(int id, const QString &nickname);

	const int getID() const;
	const QString &getNickname() const;

	void setNickname(const QString &newNick);
private:
	int id;
	QString nick;
};

#endif // USER_HPP
