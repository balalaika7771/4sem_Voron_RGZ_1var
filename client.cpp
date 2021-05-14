#include "client.h"
#include "queue.h"
#include <QMainWindow>


client::client()
{
    hEventTerminationSon = CreateEvent(NULL, FALSE,FALSE,L"$MyEventTerminationSonName$");
    mem.setKey("MyKey");
    mem.create(1500);
    Queue *data = (Queue*)mem.data();
    Queue f;
    data[0] = f;
    CreateProcess(L"C:\\Project\\build-son-Desktop_Qt_6_0_3_MinGW_64_bit-Debug\\debug\\son.exe",NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &sti, &pi);
}


 client::~client(){
    SetEvent(hEventTerminationSon);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hEventTerminationSon);
}


void client::send(QString gaz){


    Queue *data = (Queue*)mem.data();
    if (mem.lock())
    {
      Queue m;
      m = data[0];
      m.enQueue(gaz);
      data[0]=m;
      mem.unlock(); // заканчиваем работу с общей памятью
}
}

bool client::vremyaUmirats(){
    GetExitCodeProcess(pi.hProcess,&excode);

        if(excode == STILL_ACTIVE){
              return false;
        }else{
            return true;
        }

}


