#ifndef SENDDATA_H
#define SENDDATA_H

#include <fstream>
#include <sstream>
#include <QMainWindow>
#include <memory>
#include "ui_mainwindow.h"
#include "mainwindow.h"

class Senddata  : public QObject
{
public:
    Senddata(QUdpSocket *socket, Ui::MainWindow *ui);
    ~Senddata();
    void ReadFromFiles(); //ifStream >> sendData
    void getConfig();  //sendData>>msgbuf
    void writeDatagram(); //msgbuf>>UDP

    Ui::MainWindow *UI;

    QUdpSocket *udpSocket;
    ifstream infile; //���ش���������
    QString file; //�����ļ�Ŀ¼
    QString saveFolder;
    string sendData; //����һ��UDP���ݣ�����8192Byte�ᶪ��������65535Byte���޷�����
    QByteArray msgbuf;
    QString DestIP;
    qint16 DestPort;
};

#endif // SENDDATA_H
