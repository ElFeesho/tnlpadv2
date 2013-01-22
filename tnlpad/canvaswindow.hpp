#ifndef CANVASWINDOW_HPP
#define CANVASWINDOW_HPP

#include <QWidget>
#include "command.hpp"
#include "drawcommand.hpp"

namespace Ui {
class CanvasWindow;
}

class CanvasWindow : public QWidget
{
	Q_OBJECT
	
public:
	explicit CanvasWindow(QWidget *parent = 0);
	~CanvasWindow();
	
public slots:
	void command_received(const Command &command);
	void line_drawn(const DrawCommand &command);
private slots:
	void on_buttonClear_clicked();

private:
	Ui::CanvasWindow *ui;
};

#endif // CANVASWINDOW_HPP
