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
    DealMsg(QUdpSocket *socket);

    void setFlag();
    void resetFlag();

    QUdpSocket *udpSocket;
    BYTE* bufPtr;
    shared_ptr<BYTE*> RECORD_BUF; //�������ݵ�Buffer
    qint64 lenoDatagram; //Datagram�ĳ���
    QByteArray datagram; //����UDP������
    QHostAddress clientAddr; //�ͻ���IP
    quint16 clientPort; //�ͻ���port
    shared_ptr<CirQueue<unsigned char>> CHdata2; //����
     qint64 LenoUDP = 2000*60000;
     bool isDone;  //�ж��߳��Ƿ����

protected:
        //QThread���麯��
        //�̴߳�����
        //����ֱ�ӵ��ã�ͨ��start()��ӵ���
         void run();

signals:
    //�߳�ִ���귢��
//    void finished();
};

#endif // DEALMSG_H
