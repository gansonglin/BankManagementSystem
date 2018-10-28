#include "DepositWidget.h"
#include "ui_DepositWidget.h"
#include "ClientRequestAPI.h"
#include "QMessageBox"

DepositWidget::DepositWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DepositWidget();
	ui->setupUi(this);
}

DepositWidget::~DepositWidget()
{
	delete ui;
}

void DepositWidget::on_pushButton_ok_clicked()
{
	QString userName = ui->lineEdit_num->text();
	QString money = ui->lineEdit_money->text();
	bool ret = ClientRequestAPI::instance()->depositAPI(userName, money);
	if (!ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("ÌáÊ¾"), QStringLiteral("´æ¿îÊ§°Ü£¡"));
		return;
	}
	return;
}

