#ifndef JOINWINDOW_HPP
#define JOINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class JoinWindow;
}

class JoinWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit JoinWindow(QWidget *parent = 0);
	~JoinWindow();
	
private slots:
	void on_buttonConnect_clicked();

private:
	Ui::JoinWindow *ui;
};

#endif // JOINWINDOW_HPP
