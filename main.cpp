#include "LoginWidget.h"
#include <QtWidgets/QApplication>
#include "informationsetting.h"
#include "RegisterWidget.h"

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginWidget::instance()->show();

	//InformationSetting informationSetting;
	//informationSetting.show();

	//RegisterWidget registerWidget;
	//registerWidget.show();

	return a.exec();
}
