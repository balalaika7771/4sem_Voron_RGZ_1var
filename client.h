#ifndef CLIENT_H
#define CLIENT_H
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <QMainWindow>
#include "QSharedMemory"
class client
{
    HANDLE hEventTerminationSon;//событие по которуму следим работает ли родительский процесс
    DWORD excode;//событие по которому следим работает ли дочерний процесс
    QSharedMemory mem;//выбрал QSharedMemory потому что qt не давал лезть в память когда в Visual всё работало(минус крос плотформ,печаль)
    STARTUPINFO sti = {0};
    PROCESS_INFORMATION pi= {0};
public:
    client();
    ~client();

    void send(QString gaz);
    bool vremyaUmirats();
};



#endif // CLIENT_H
