#include "TransferWidget.h"
#include "ui_TransferWidget.h"

TransferWidget::TransferWidget(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::TransferWidget();
	ui->setupUi(this);
}

TransferWidget::~TransferWidget()
{
	delete ui;
}

