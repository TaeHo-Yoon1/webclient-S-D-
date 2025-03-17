#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
<<<<<<< HEAD
#include <QSslSocket>

=======
// #include <QTcpSocket>
#include <QSslSocket>
>>>>>>> f5a7d39918c75767a85579b9967be62551bfb0d4

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //QTcpSocket socket_;
    QSslSocket socket_;

public slots :
    void doConnected();
    void doDisConnected();
    void doReadyread();


private slots:
    void on_pbConnect_clicked();

    void on_pbDisConnect_clicked();

    void on_Clear_clicked();

    void on_pbSend_clicked();

    void on_CheckBox_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
