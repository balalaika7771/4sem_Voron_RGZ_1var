#ifndef SERVER_H
#define SERVER_H

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <QApplication>
#include "QSharedMemory"
#include "queue.h"
class server
{
    HANDLE hEventTerminationSon;
    QSharedMemory mem;
public:
    server();
    ~server();
    bool vremyaUmirats();
    QString getData(tm& timeinfo,int &nodeID);
};



#endif // SERVER_H
