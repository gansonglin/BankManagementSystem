#include <QFileDialog>
#include <QTimer>

#include "informationsetting.h"
#include "ui_informationsetting.h"
#include "ClientRequestAPI.h"
#include "MainWidget.h"

InformationSetting::InformationSetting(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::InformationSetting();
	ui->setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("������������"));
	ui->label_picture->setPixmap(QPixmap(QString::fromLocal8Bit("D:\\project\\BankManagementSystem\\BankManagementSystem\\Ĭ��.jpg")).scaled(100, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	//this->setFixedSize(878, 648);
}

InformationSetting::~InformationSetting()
{
	delete ui;
}

void InformationSetting::initData()
{
	//��������
	if (!ClientRequestAPI::instance()->isConnect())
	{
		bool ret = ClientRequestAPI::instance()->connect();
		if (!ret)
		{
			//QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("����ʧ�ܣ�"));
			return;
		}
	}
	QString  userName = MainWidget::instance()->getUsername();
	QString  passWord;
	QString  name;
	QString  id;
	QString  sex;
	QString  phone;
	QString  email;
	QString  address;
	QString  weight;
	QString  height;
	bool ret = ClientRequestAPI::instance()->getUserInfoAPI(userName, passWord, name, id,  sex,  phone, email,  address,  weight,  height);
	if (!ret)
	{
		//QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("ע��ʧ�ܣ�"));
		return;
	}
	
	//��ʾ����
	ui->lineEdit_username->setText(userName);
	ui->lineEdit_password->setText(passWord);
	ui->lineEdit_confirm_password->setText(passWord);
	ui->lineEdit_name->setText(name);
	ui->lineEdit_id->setText(id);
	ui->lineEdit_sex->setText(sex);
	ui->lineEdit_phone->setText(phone);
	ui->lineEdit_emial->setText(email);
	ui->lineEdit_address->setText(address);
	ui->lineEdit_weight->setText(weight);
	ui->lineEdit_height->setText(height);
}

void InformationSetting::updataData()
{
	//�޸�����
}


void InformationSetting::showEvent(QShowEvent *event)
{
	return;
	//��ʾ֮ǰ��������
	//initData();

	QTimer::singleShot(8000, Qt::VeryCoarseTimer, this,SLOT(onLoadData()));
	
}

void InformationSetting::on_pushButton_modify_picture_clicked()
{
	QFileDialog fileDialog;
	fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
	fileDialog.setFileMode(QFileDialog::ExistingFile);
	

	//int r = fileDialog.exec();
	//QString str = fileDialog.getOpenFileName();
	//if (fileDialog.exec() == 1)
	//{

	//}
	QString str = fileDialog.getOpenFileName();
	QFileInfo fileInfo(str);
	if (fileInfo.suffix().compare("png", Qt::CaseInsensitive) || fileInfo.suffix().compare("jpeg", Qt::CaseInsensitive))
	{
		ui->label_picture->setPixmap(QPixmap(str).scaled(100,150,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	}
	
}

void InformationSetting::on_pushButton_save_clicked()
{
	initData();
}

void InformationSetting::onLoadData()
{
	initData();
}
