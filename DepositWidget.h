#ifndef DEPOSITWIDGET_H
#define DEPOSITWIDGET_H

#include <QWidget>
namespace Ui {class DepositWidget;};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	´æ¿î. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class DepositWidget : public QWidget
{
	Q_OBJECT

public:
	DepositWidget(QWidget *parent = 0);
	~DepositWidget();
	public slots:
	void on_pushButton_ok_clicked();

private:
	Ui::DepositWidget *ui;
};

#endif // DEPOSITWIDGET_H
