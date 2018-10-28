#include "GetWidget.h"
#include "ui_GetWidget.h"
#include "ClientRequestAPI.h"
#include "QMessageBox"

GetWidget::GetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::GetWidget();
	ui->setupUi(this);
}

GetWidget::~GetWidget()
{
	delete ui;
}

void GetWidget::on_pushButton_ok_clicked()
{
	QString userName = ui->lineEdit_num->text();
	QString money = ui->lineEdit_money->text();
	bool ret = ClientRequestAPI::instance()->getAPI(userName, money);
	if (!ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("ÌáÊ¾"), QStringLiteral("´æ¿îÊ§°Ü£¡"));
		return;
	}
	return;
}

