#ifndef TRANSFERWIDGET_H
#define TRANSFERWIDGET_H

#include <QWidget>
namespace Ui {class TransferWidget;};

class TransferWidget : public QWidget
{
	Q_OBJECT

public:
	TransferWidget(QWidget *parent = 0);
	~TransferWidget();

private:
	Ui::TransferWidget *ui;
};

#endif // TRANSFERWIDGET_H
