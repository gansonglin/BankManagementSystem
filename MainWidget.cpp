#include "MainWidget.h"
#include "ui_MainWidget.h"
#include <map>
#include "OpenWidget.h"
#include "DepositWidget.h"
#include "GetWidget.h"
#include "informationsetting.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::MainWidget();
	ui->setupUi(this);
	setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
	setWindowTitle(QStringLiteral("会员管理系统"));
	initUI();
	this->setFixedSize(1141, 736);
}

MainWidget::~MainWidget()
{
	delete ui;
}

MainWidget * MainWidget::instance()
{
	static MainWidget t;
	return &t;
}

void MainWidget::initUI()
{
	QVBoxLayout * layout = new QVBoxLayout;
	std::string str1 = "open";
	InformationSetting *ow = new InformationSetting;
	_map.insert(std::pair<std::string&, QWidget *>(str1, ow));
	layout->addWidget(ow);
	ow->show();

	std::string str2 = "deposit";
	DepositWidget *dw = new DepositWidget;
	_map.insert(std::pair<std::string&, QWidget *>(str2, dw)); 
	layout->addWidget(dw);
	dw->hide();

	std::string str3 = "get";
	GetWidget *gw = new GetWidget;
	_map.insert(std::pair<std::string&, QWidget *>(str3, gw));
	layout->addWidget(gw);
	gw->hide();

	ui->widget->setLayout(layout);
}

void MainWidget::showPage(const std::string & str)
{
	for (std::map<std::string , QWidget *>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (it->second->isVisible())
		{
			it->second->hide();
		}
	}
	for (std::map<std::string , QWidget *>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (it->first == str)
		{
			it->second->show();
			break;
		}
	}
}

void MainWidget::on_pushButton_open_clicked()
{
	showPage("open");
}

void MainWidget::on_pushButton_deposit_clicked()
{
	showPage("deposit");
}

void MainWidget::on_pushButton_get_clicked()
{
	showPage("get");
}

void MainWidget::on_pushButton_turn_clicked()
{

}

void MainWidget::on_pushButton_search_clicked()
{

}

void MainWidget::on_pushButton_exit_clicked()
{
	exit(0);
}

