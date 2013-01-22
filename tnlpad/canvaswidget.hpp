#ifndef CANVASWIDGET_HPP
#define CANVASWIDGET_HPP

#include <QWidget>
#include <QPainter>
#include "drawcommand.hpp"

class CanvasWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CanvasWidget(QObject *parent = 0);
	~CanvasWidget();

	void mousePressEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent * ev);

	void paintEvent(QPaintEvent *);

	void clearCanvas();
	void drawLine(int x, int y, int x2, int y2);
	void drawLine(DrawCommand &command);

signals:
	void draw_command(const DrawCommand &command);
public slots:

private:
	QImage buffer;
	QPainter *imagePainter;
	
	int lastX, lastY;
};

#endif // CANVASWIDGET_HPP
