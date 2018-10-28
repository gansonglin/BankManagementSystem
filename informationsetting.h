#pragma once

#include <QWidget>
namespace Ui { class InformationSetting; };

class InformationSetting : public QWidget
{
	Q_OBJECT

public:
	InformationSetting(QWidget *parent = Q_NULLPTR);
	~InformationSetting();
private:
	void initData();
	void updataData();

protected:
	void showEvent(QShowEvent *event);
private:
	Ui::InformationSetting *ui;
public slots:
	//ÐÞ¸ÄÍ·Ïñ
	void on_pushButton_modify_picture_clicked();
	void on_pushButton_save_clicked();
	void onLoadData();
};
