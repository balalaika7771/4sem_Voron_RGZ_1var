#include "queue.h"


bool Queue::isFull(){
       if(front == 0 && rear == SIZE - 1){
           return true;
       }
       if(front == rear + 1) {
           return true;
       }
       return false;
   }


bool Queue::isEmpty(){
        if(front == -1) return true;
        else return false;
    }


void Queue::enQueue(QString element){
        if(isFull()){
           // Queue is full
        } else {
            if(front == -1) {front = 0;}
            rear = (rear + 1) % SIZE;

            std::string ar = element.toStdString();

            for (int i=0;i<100;i++){
            items[rear].str[i] = ' ';
            }
            for(int i = 0;ar[i] !='\0' && i < 99;i++){
                items[rear].str[i] = ar[i];
            }

            items[rear].ID = IDZ;
            IDZ = IDZ + 1;
            time_t seconds = time(NULL);
            tm timeinfo = *localtime(&seconds);
            items[rear].timeinfo = timeinfo;
        }

    }

QString Queue::deQueue(tm &timeinfo,int &nodeID){
        QString element;
        if(isEmpty()){
            return("");
        } else {
            for(int i = 0; i < 100;i++){
               element +=  QChar (items[front].str[i]);
            }
            nodeID = items[front].ID;
            timeinfo = items[front].timeinfo;
            if(front == rear){
                front = -1;
                rear = -1;
            } /* Q имеет только один элемент, поэтому мы удаляем очередь после удаления. */
            else {
                front=(front+1) % SIZE;
            }

            return(element);
        }

    }

