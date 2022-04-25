#include "writetofiles.h"

WriteToFiles::WriteToFiles(MainWindow* mainwindow)
{
    mainWindow = mainwindow;

    CHdata = make_shared<CirQueue<unsigned char>>(mainWindow->LenoUDP);
}

void WriteToFiles::run()
{
    qDebug() << "TimeUpdate" << endl;

    //���µ�ǰʱ��
    dateTime = QDateTime::currentDateTime();

    saveFolder =  string("F:/Desktop/UDPConnect/data/");

//    saveFilename1 = QString(saveFolder.c_str())+QString("/[CH1][")+QString::number(PeakNum)
//            +QString("]")+dateTime.toString("yyyyMMddhhmmss")+ QString(".bin");
//    saveFilename2 = QString(saveFolder.c_str())+QString("/[CH2][")+QString::number(PeakNum)
//            +QString("]")+dateTime.toString("yyyyMMddhhmmss")+ QString(".bin");
//    saveFilename3 = QString(saveFolder.c_str())+QString("/[CH3][")+QString::number(PeakNum)
//            +QString("]")+dateTime.toString("yyyyMMddhhmmss")+ QString(".bin");
//    saveFilename4 = QString(saveFolder.c_str())+QString("/[CH4][")+QString::number(PeakNum)
//            +QString("]")+dateTime.toString("yyyyMMddhhmmss")+ QString(".bin");
    saveFilenameAll = QString(saveFolder.c_str())+QString("/[All][")+QString::number(PeakNum)
            +QString("]")+dateTime.toString("yyyyMMddhhmmss")+ QString(".bin");


    //���ļ�
//   outfile1.open(saveFilename1.toStdString().data(),ofstream::binary);
//   outfile2.open(saveFilename2.toStdString().data(),ofstream::binary);
//   outfile3.open(saveFilename3.toStdString().data(), ofstream::binary);
//   outfile4.open(saveFilename4.toStdString().data(), ofstream::binary);
   outfileAll.open(saveFilenameAll.toStdString().data(), ofstream::binary);

    //���ļ�ʧ�����������
//    if (!outfile1.is_open() || !outfile2.is_open() || !outfile3.is_open() || !outfile4.is_open()) return;
    if (!outfileAll.is_open()) return;

    //���Ⱥ�˳��CH1��CH2��CH3��CH4�����ݷֿ��洢

    unsigned int sizeoCHdata; //CHdata�ĳ���

    //ASCII�����
    if(mainWindow->isASCII && (!mainWindow->isHEX)){

        //���CHdata2��Ϊ�գ���CHdata2 >> CHdata
        if(!mainWindow->CHdata2->isEmpty()){

            sizeoCHdata = mainWindow->CHdata2->size();

            CHdata = mainWindow->CHdata2;

//            mainWindow->CHdata2->clear();
        }
        //�������CHdata3��Ϊ�գ���CHdata3 >> CHdata
        else if (!mainWindow->CHdata3->isEmpty()){

            sizeoCHdata = mainWindow->CHdata3->size();

            CHdata = mainWindow->CHdata3;

//            mainWindow->CHdata3->clear();
        }
        else
            qDebug()<<"CHdata is clear ! "<<endl;



//        for(unsigned int i=0; i<sizeoCHdata/4; ++i)
//        {
//            outfile1.write((const char*)CHdata->begin(),sizeof (unsigned char));
//            CHdata->pop();
//            outfile2.write((const char*)CHdata->begin(),sizeof (unsigned char));
//            CHdata->pop();
//            outfile3.write((const char*)CHdata->begin(),sizeof (unsigned char));
//            CHdata->pop();
//            outfile4.write((const char*)CHdata->begin(),sizeof (unsigned char));
//            CHdata->pop();
//        }

          for(unsigned int i=0; i<sizeoCHdata; ++i){
              outfileAll.write((const char*)CHdata->begin(),sizeof (unsigned char));
              CHdata->pop();
          }

        //clear CHdata
        CHdata->clear();

        qDebug()<<"ofstream writing over ! "<<endl;

        qDebug()<<"CHdata have been cleared ! "<<endl;

    }
        //HEX����
        else if((!mainWindow->isASCII) && mainWindow->isHEX){

            //���CHdata2��Ϊ�գ���CHdata2 >> CHdata
            if(!mainWindow->CHdata2->isEmpty()){

                sizeoCHdata = mainWindow->CHdata2->size();

                CHdata = mainWindow->CHdata2;

//                mainWindow->CHdata2->clear();
            }
            //�������CHdata3��Ϊ�գ���CHdata3 >> CHdata
            else if (!mainWindow->CHdata3->isEmpty()){

                sizeoCHdata = mainWindow->CHdata3->size();

                CHdata = mainWindow->CHdata3;

//                mainWindow->CHdata3->clear();
            }
            else
                qDebug()<<"CHdata is clear ! "<<endl;



//            for(unsigned int i=0; i<sizeoCHdata/4; ++i)
//            {
//                outfile1.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile1.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile2.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile2.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile3.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile3.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile4.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();
//                outfile4.write((const char*)CHdata->begin(),sizeof (unsigned char));
//                CHdata->pop();

//            }

            for(unsigned int i=0; i<sizeoCHdata; ++i){
                outfileAll.write((const char*)CHdata->begin(),sizeof (unsigned char));
                CHdata->pop();
            }

            //clear CHdata
            CHdata->clear();

            qDebug()<<"ofstream writing over ! "<<endl;

            qDebug()<<"CHdata have been cleared ! "<<endl;

    }

    //close stream
//    outfile1.close();
//    outfile2.close();
//    outfile3.close();
//    outfile4.close();

      outfileAll.close();

    qDebug()<< "WriteToFiles Thread is Finished ! "<<endl;
    qDebug()<<"-----------------------------------"<<endl;
}

