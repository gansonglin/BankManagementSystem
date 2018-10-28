#ifndef GETWIDGET_H
#define GETWIDGET_H

#include <QWidget>
namespace Ui {class GetWidget;};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	È¡¿î widget. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class GetWidget : public QWidget
{
	Q_OBJECT

public:
	GetWidget(QWidget *parent = 0);
	~GetWidget();
public slots:
	void on_pushButton_ok_clicked();
private:
	Ui::GetWidget *ui;
};

#endif // GETWIDGET_H
