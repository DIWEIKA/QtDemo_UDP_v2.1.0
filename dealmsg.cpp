#include "dealmsg.h"

DealMsg::DealMsg(QUdpSocket *socket , Ui::MainWindow *ui)
{
    udpSocket = socket;

    UI = ui;

    //CHdata��ʼ��
     CHdata2 = make_shared<CirQueue<unsigned char>>(LenoUDP);
}

DealMsg::~DealMsg()
{

}

void DealMsg::run()
{
    while(udpSocket->hasPendingDatagrams()){
        //���͵�UDP���ݰ��Ĵ�С
        qDebug()<<"pending UDP datagram size = "<< udpSocket->pendingDatagramSize()<<endl;

        //datagram << UDP
       readDatagram();

       //release bufPtr
        delete bufPtr;
        bufPtr = NULL;

       //define a new BYTE[]
       bufPtr = new BYTE[lenoDatagram]();

        //define a new RECORD_BUF
       RECORD_BUF = make_shared<BYTE*>(bufPtr);

       //RECORD_BUF << datagram
       memcpy(*RECORD_BUF,datagram.data(),lenoDatagram);

       //CHData << RECORD_BUF
       getDatafromByteToFloat();

    }

    //exit dealMsg Thread
     quit();

}

void DealMsg::readDatagram()
{
     qDebug()<<"readDatagram ... "<<endl;

        //clear datagram
        datagram.clear();

        //datagram init
        datagram.resize(udpSocket->pendingDatagramSize());

        //��ȡ�Է����͵����ݣ�������datagram
         lenoDatagram = udpSocket->readDatagram(datagram.data(),datagram.size(),&clientAddr,&clientPort);
}

void DealMsg::getDatafromByteToFloat()
{
     qDebug()<<"getDatafromByteToFloat ... "<<endl;

    for(int i=0; i<lenoDatagram; i++)
     {
       unsigned char usCHDATA =(*RECORD_BUF)[i];

//       qDebug()<<"usCHDATA= "<<usCHDATA<<endl;

//        CHdata->push(float(usCHDATA));

        //����
        CHdata2->push(usCHDATA);

    }
}
