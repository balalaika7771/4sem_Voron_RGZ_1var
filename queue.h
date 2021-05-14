#ifndef QUEUE_H
#define QUEUE_H
#include <QMainWindow>
#include <string.h>
#include <iostream>
#define SIZE 10   /* Размер круговой очереди */
struct node
{
   int ID;
   tm timeinfo;
   char str[100];

};

class Queue
{
private:
node items[SIZE];
int front, rear;
int IDZ;

public:
Queue(){
       front = -1;
       rear = -1;
       IDZ = 0;
   }
 bool isFull();
 bool isEmpty();
 void enQueue(QString element);
 QString deQueue(tm &timeinfo,int &nodeID);
};

#endif // QUEUE_H
