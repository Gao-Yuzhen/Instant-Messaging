﻿#include "LoginDialog.h"
#include "ui_LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
	BaseWindow(parent),
	ui(new Ui::LoginDialog)
{

	ui->setupUi(this);
	//设置背景
	// 初始化标题栏;
	this->initTitleBar();
	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
	                 QBrush(QPixmap(":/src/image/login_background.png").scaled(// 缩放背景图.
	                                this->size(),
	                                Qt::IgnoreAspectRatio,
	                                Qt::SmoothTransformation)));    // 使用平滑的缩放方式
	this->setPalette(palette);                                      // 给widget加上背景图
	//设置输入框icon
	ui->editAccount->addAction(QIcon(":/src/image/user.png"), QLineEdit::LeadingPosition);
	ui->editPassword->addAction(QIcon(":/src/image/key.svg"), QLineEdit::LeadingPosition);

	//设置输入提示
	ui->editAccount->setPlaceholderText(QString::fromLocal8Bit("请输入用户名"));
	ui->editPassword->setPlaceholderText(QString::fromLocal8Bit("请输入密码"));
}

LoginDialog::~LoginDialog()
{
	delete ui;
}
void LoginDialog::initTitleBar()
{
	titleBarPtr->setButtonType(MIN_BUTTON);
	titleBarPtr->setTitleWidth(this->width());
	titleBarPtr->setBackgroundColor(219, 219, 255);
}
void LoginDialog::on_btRegister_clicked()
{

}

void LoginDialog::on_btLogin_clicked()
{
	QString userName = ui->editAccount->text().remove(QRegExp("\\s"));  //去除空格
	QString password = ui->editPassword->text().remove(QRegExp("\\s"));
	bool state = true;
	//进行验证

	//进行验证

	if (!state)
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("用户名或密码错误"));
	else {
		this->hide();
		emit showMain();
	}
}

void LoginDialog::receiveShow()
{
	this->show();
}