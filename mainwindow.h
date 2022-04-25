#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QtNetwork>
#include <recvdata.h>
#include <QtDebug>
#include <windows.h>
#include <dealmsg.h>
#include <writetofiles.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Recvdata; //ʹ��ǰ������
class Senddata;
class DealMsg;
class  WriteToFiles;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;

    Senddata *senddata;
    QUdpSocket *udpSocket; //udp pointer
    QTimer* udpTimer;
    DealMsg* dealMsg;
    WriteToFiles* writeToFiles;
    bool isSave;
    bool isStart;
    bool isASCII;
    bool isHEX;
    BYTE* bufPtr;
    shared_ptr<BYTE*> RECORD_BUF; //�������ݵ�Buffer
    qint64 lenoDatagram; //Datagram�ĳ���
    qint64 lenoDatagramHEX;
    QByteArray datagram; //����UDP������
    QByteArray datagramHEX;
    QHostAddress clientAddr; //�ͻ���IP
    quint16 clientPort; //�ͻ���port
    shared_ptr<CirQueue<unsigned char>> CHdata2;
    shared_ptr<CirQueue<unsigned char>> CHdata3;
    qint64 LenoUDP = 4096;

    void setLocalMsg();
    void OpenDealMsgThread();
    void OpenWriteToFilesThread();
    void stopThread();

private slots:

    void FinishDealMsgThread();
    void FinishWriteToFilesThread();
    void on_pushButton_Start_clicked();
    void on_pushButton_Stop_clicked();

private:
    bool isTimeUpdate;
};
#endif // MAINWINDOW_H
