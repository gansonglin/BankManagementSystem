#include "LoginWidget.h"
#include "ui_LoginWidget.h"
#include "MainWidget.h"
#include "RegisterWidget.h"
#include "ClientRequestAPI.h"
#include "QMessageBox"
#include "jsonutil.h"


LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LoginWidget();
	ui->setupUi(this);
	this->setFixedSize(365, 291);
	//setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
	setWindowFlags(windowFlags()&~Qt::WindowMinMaxButtonsHint|Qt::WindowMinimizeButtonHint);  
	this->setWindowTitle(QString::fromLocal8Bit("��¼����"));
}

LoginWidget::~LoginWidget()
{
	delete ui;
}

LoginWidget * LoginWidget::instance()
{
	static LoginWidget t;
	return &t;
}

void LoginWidget::on_pushButton_register_clicked()
{
	RegisterWidget::instance()->show();
	LoginWidget::instance()->hide();
}



void LoginWidget::on_pushButton_ok_clicked()
{
	if (!ClientRequestAPI::instance()->isConnect())
	{
		bool ret = ClientRequestAPI::instance()->connect();
		if (!ret)
		{
			QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ�ܣ�"));
			return;
		}
	}
	QString userName = ui->lineEdit_userName->text();
	QString passWord = ui->lineEdit_passWord->text();
	int ret = JsonUtil::getInstance()->login(userName, passWord);
	if (!ret)
	{
		QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("��¼ʧ�ܣ�"));
		return;
	}
	MainWidget::instance()->setUsername(userName);  //��¼��ǰ�û���
	MainWidget::instance()->show();
	LoginWidget::instance()->hide();
}

