#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
namespace Ui {class RegisterWidget;};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A register widget. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class RegisterWidget : public QWidget
{
	Q_OBJECT

public:
	RegisterWidget(QWidget *parent = 0);
	~RegisterWidget();
	static RegisterWidget * instance();
	public slots:
	void on_pushButton_ok_clicked();

private:
	Ui::RegisterWidget *ui;
	//bool _isFirst;
	char num[64];
};

#endif // REGISTERWIDGET_H
