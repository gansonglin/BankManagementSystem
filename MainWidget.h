#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <map>
#include <string>
namespace Ui {class MainWidget;};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	主窗口 widget. </summary>
///
/// <remarks>	gan songlin, 2017/9/30. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();
	static MainWidget * instance();
	void initUI();
	void showPage(const std::string & str);
	QString getUsername() const { return m_username; }
	void setUsername(QString val) { m_username = val; }
	public slots:
	void on_pushButton_open_clicked();
	void on_pushButton_deposit_clicked();
	void on_pushButton_get_clicked();
	void on_pushButton_turn_clicked();
	void on_pushButton_search_clicked();
	void on_pushButton_exit_clicked();

private:
	Ui::MainWidget *ui;
	std::map<std::string , QWidget *> _map;
	/// <summary>	当前的用户名. </summary>
	QString m_username;
};

#endif // MAINWIDGET_H
