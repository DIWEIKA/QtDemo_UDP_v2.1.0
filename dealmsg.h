#ifndef DEALMSG_H
#define DEALMSG_H

#include <QThread>
#include <QUdpSocket>
#include <QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"

class DealMsg;
class  WriteToFiles;

/*QThread DealMsg used for dealing UDP response*/

class DealMsg : public QThread
{
public:
    DealMsg(QUdpSocket *socket, Ui::MainWindow *ui);


    void readDatagram();
    void getDatafromByteToFloat();
    void execute();

    QUdpSocket *udpSocket;
    BYTE* bufPtr;
    shared_ptr<BYTE*> RECORD_BUF; //�������ݵ�Buffer
    qint64 lenoDatagram; //Datagram�ĳ���
    QByteArray datagram; //����UDP������
    QHostAddress clientAddr; //�ͻ���IP
    quint16 clientPort; //�ͻ���port
    shared_ptr<CirQueue<float>> CHdata; //���Channel���ݵ�����
    shared_ptr<CirQueue<unsigned char>> CHdata2; //����
    Ui::MainWindow *UI;

protected:
        //QThread���麯��
        //�̴߳�����
        //����ֱ�ӵ��ã�ͨ��start()��ӵ���
         void run();

signals:
    //signal �߳�ִ���귢��
    void isDone();
};

#endif // DEALMSG_H
