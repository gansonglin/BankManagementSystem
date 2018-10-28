#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
namespace Ui {class LoginWidget;};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	µÇÂ¼ widget. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget(QWidget *parent = 0);
	~LoginWidget();
	static LoginWidget *instance();
public slots:
	void on_pushButton_register_clicked();
	void on_pushButton_ok_clicked();

private:
	Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
