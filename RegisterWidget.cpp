#include "RegisterWidget.h"
#include "ui_RegisterWidget.h"
#include "LoginWidget.h"
#include <time.h>
#include "ClientRequestAPI.h"
#include "QMessageBox"
#include <QString>

RegisterWidget::RegisterWidget(QWidget *parent)
: QWidget(parent)/*, _isFirst(true)*/
{
	ui = new Ui::RegisterWidget();
	ui->setupUi(this);

	this->setFixedSize(364, 421);
	this->setWindowTitle(QString::fromLocal8Bit("注册窗口"));
}

RegisterWidget::~RegisterWidget()
{
	delete ui;
}

RegisterWidget * RegisterWidget::instance()
{
	static RegisterWidget t;
	return &t;
} 

void RegisterWidget::on_pushButton_ok_clicked()
{
	//if (_isFirst)
	//{
		//ui->widgetConentOne->hide();
		//ui->widgetConentTwo->show();
		//ui->label_user_name->setText(str);
		//_isFirst = false;
		//return ;
	//}

	if (!ClientRequestAPI::instance()->isConnect())
	{
		bool ret = ClientRequestAPI::instance()->connect();
		if (!ret)
		{
			QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("连接失败！"));
			return;
		}
	}

	bool ret = ClientRequestAPI::instance()->registerAPI(ui->lineEdit_username->text(), ui->lineEdit_passWord->text(), ui->lineEdit_name->text(), ui->lineEdit_idNo->text(), ui->lineEdit_sex->text(), ui->lineEdit_phone->text(), ui->lineEdit_email->text(), ui->lineEdit_address->text(),ui->lineEdit_weight->text(),ui->lineEdit_height->text());
	if (!ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("提示"), QStringLiteral("注册失败！"));
		return;
	}
	//用户名可以是电话，也可以是自定义的字段，和别的用户不重复就行了.
	RegisterWidget::instance()->hide();
	LoginWidget::instance()->show();
}

