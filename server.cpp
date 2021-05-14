#include "server.h"
#include <TlHelp32.h>



server::server()
{

    hEventTerminationSon = OpenEvent(EVENT_ALL_ACCESS,FALSE,L"$MyEventTerminationSonName$");
    mem.setKey("MyKey");
    mem.attach();

}


server::~server()
{
    CloseHandle(hEventTerminationSon);
}

bool server::vremyaUmirats()
{
    return WaitForSingleObject(hEventTerminationSon , 0 ) == WAIT_OBJECT_0;
}

QString  server::getData(tm& timeinfo,int &nodeID)
{
    QString gaz;


    Queue *data = (Queue*)mem.data(); // указатель на общую память
    if (mem.lock())//питоняшка
    {

      Queue m;
      m = data[0];
      gaz = m.deQueue(timeinfo,nodeID);
      data[0] = m;

      mem.unlock();

}

    return gaz;
}
