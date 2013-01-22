#include "canvaswindow.hpp"
#include "clearcommand.hpp"
#include "drawcommand.hpp"
#include "ui_canvaswindow.h"
#include "networkengine.hpp"

CanvasWindow::CanvasWindow(QWidget *parent) :
   QWidget(parent),
   ui(new Ui::CanvasWindow)
{
	ui->setupUi(this);
	connect(NetworkEngine::instance(), SIGNAL(incoming_command(const Command&)), this, SLOT(command_received(const Command&)));
	connect(ui->canvas, SIGNAL(draw_command(DrawCommand)),this, SLOT(line_drawn(DrawCommand)));
}

CanvasWindow::~CanvasWindow()
{
	delete ui;
}

void CanvasWindow::command_received(const Command &command)
{
	switch(command.getType())
	{
	case Command::ClearCommand:
		ui->canvas->clearCanvas();
		break;
	case Command::DrawCommand:
		break;
	case Command::JoinCommand:
		break;
	case Command::NickCommand:
		break;
	case Command::MessageCommand:
		break;
	}

	if(command.getType() == Command::DrawCommand)
	{
		ui->canvas->drawLine((DrawCommand&)command);
	}
}

void CanvasWindow::line_drawn(const DrawCommand &command)
{
	NetworkEngine::send_command(command);
}

void CanvasWindow::on_buttonClear_clicked()
{
	 ui->canvas->clearCanvas();
	 ClearCommand c;
	 NetworkEngine::send_command(c);
}
