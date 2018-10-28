#include "OpenWidget.h"
#include "ui_OpenWidget.h"
#include "ClientRequestAPI.h"
#include "QMessageBox"
#include <time.h>

OpenWidget::OpenWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::OpenWidget();
	ui->setupUi(this);
}

OpenWidget::~OpenWidget()
{
	delete ui;
}

void OpenWidget::on_pushButton_ok_clicked()
{
	//char num[64] = "";
	//time_t current = time(NULL);
	//struct tm *timeInfo = localtime(&current);

	//sprintf(num, "%04d%02d%02d%02d%02d%02d", timeInfo->tm_year + 1900, timeInfo->tm_mon + 1,
	//	timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

	//if (!ClientRequestAPI::instance()->isConnect())
	//{
	//	bool ret = ClientRequestAPI::instance()->connect();
	//	if (!ret)
	//	{
	//		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("连接失败！"));
	//		return;
	//	}
	//}

	//bool ret = ClientRequestAPI::instance()->registerAPI(ui->lineEdit_username->text().toLatin1().data(), ui->lineEdit_passWord->text().toLatin1().data(), ui->lineEdit_name->text().toLatin1().data(), ui->lineEdit_id->text().toLatin1().data(), ui->lineEdit_phone->text().toLatin1().data(), ui->lineEdit_commit_passWord->text().toLatin1().data(), ui->lineEdit_commit_passWord->text().toLatin1().data());
	//if (!ret)
	//{
	//	QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("注册失败！"));
	//	return;
	//}

	//QString str = QString("%1 %2").arg(QStringLiteral("您的用户名是：")).arg(QString::fromLocal8Bit(num));
	//QMessageBox::warning(NULL, QStringLiteral("提示"), str);

}

