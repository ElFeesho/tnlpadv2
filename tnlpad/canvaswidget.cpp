#include "canvaswidget.hpp"
#include <QDebug>
#include <QMouseEvent>

CanvasWidget::CanvasWidget(QObject *parent) :
	QWidget(NULL)
{
	Q_UNUSED(parent);
	buffer = QImage(800, 600, QImage::Format_ARGB32);
	imagePainter = new QPainter(&buffer);
	imagePainter->fillRect(0,0,800,600, QBrush(Qt::white));

	QPen pen(QBrush(Qt::black),3);
	imagePainter->setPen(pen);
	imagePainter->setRenderHint(QPainter::Antialiasing);
}

CanvasWidget::~CanvasWidget()
{
	delete imagePainter;
}

void CanvasWidget::mousePressEvent(QMouseEvent *ev)
{
	lastX = ev->x();
	lastY = ev->y();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent * ev)
{
	Q_UNUSED(ev);
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *ev)
{
	drawLine(lastX, lastY, ev->x(), ev->y());
	DrawCommand command;
	command.set(lastX, lastY, ev->x(), ev->y());
	emit draw_command(command);

	lastX = ev->x();
	lastY = ev->y();
}

void CanvasWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawImage(0, 0, buffer);
}

void CanvasWidget::clearCanvas()
{
	imagePainter->fillRect(0, 0, 800, 600, QBrush(Qt::white));
	repaint();
}

void CanvasWidget::drawLine(int x, int y, int x2, int y2)
{
	imagePainter->drawLine(x, y, x2, y2);
	repaint();
}

void CanvasWidget::drawLine(DrawCommand &command)
{
	drawLine(command.X(), command.Y(), command.X2(), command.Y2());
}
