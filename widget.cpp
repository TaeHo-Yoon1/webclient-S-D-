#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //socket_.connected();
    QObject::connect(&socket_, &QAbstractSocket::connected, this, &Widget::doConnected);
    QObject::connect(&socket_, &QAbstractSocket::disconnected, this, &Widget::doDisConnected);
    QObject::connect(&socket_, &QIODevice::readyRead, this, &Widget::doReadyread);

    if (ui->CheckBox->checkState() == Qt::Checked) {
        ui->LEPort->setText("443");
    } else {
        ui->LEPort->setText("80");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doConnected(){

    ui->pteMessgae->insertPlainText("Connected");

}

void Widget::doDisConnected(){

    ui->pteMessgae->insertPlainText("DisConnected");

}

void Widget::doReadyread(){

    ui->pteMessgae->insertPlainText(socket_.readAll());
}

void Widget::on_pbConnect_clicked()
{
    socket_.connectToHost(ui->LEhost->text(), ui->LEPort->text().toUShort());

}


void Widget::on_pbDisConnect_clicked()
{
    socket_.disconnectFromHost();
}


void Widget::on_Clear_clicked()
{
    ui-> pteMessgae ->clear();
}


void Widget::on_pbSend_clicked()
{
    socket_.write(ui->pteSend->toPlainText().toUtf8());
}




void Widget::on_CheckBox_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked) {
        ui->LEPort->setText("443");
    } else {
        ui->LEPort->setText("80");
    }
}

