#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    for (int i = 0; i < 50; i++){
        buckets[i] = NULL;
        tails[i] = NULL; 
    }
    num = 0;
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    for (int i = 49; i >= 0; i--){
        while (buckets[i] != NULL){this->removePCB();}      
    }
    delete[]buckets;
    delete[]tails;
}


/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    // When adding a PCB to the queue, you must change its state to READY.
    int pri;  

    pcbPtr->setState(ProcState::READY); 
    pri = pcbPtr->getPriority();
    pri--; 

    if (buckets[pri] == NULL){
        buckets[pri] = pcbPtr; 
        tails[pri] = pcbPtr;
    }

    else{
        tails[pri]->next = pcbPtr;
        pcbPtr->prev = tails[pri];
        tails[pri] = pcbPtr;
    }

    num++;
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.s
    PCB* ptr;
    int i = 49; 

    while (buckets[i] == NULL && i > 0){i--;}
    if (i == 0){
        cout << "The queue is empty!" << endl;
        return NULL;
    }
    
    ptr = buckets[i];
    buckets[i] = ptr->next;
    if (buckets[i] != NULL){
        buckets[i]->prev = NULL;
    }
    ptr->next = NULL;
    ptr->prev = NULL; 
    ptr->setState(ProcState::RUNNING);
    num--;
    cout << "Number of elements: " <<num <<endl; 
    return ptr;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {return num;}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
   PCB* ptr;  

   if (num == 0){
       cout << "The queue is empty!" << endl;
       return;
   }
   
   for (int i = 49; i >= 0; i--){
        ptr = buckets[i];
        while (ptr != NULL){ 
                ptr->display();
                ptr = ptr->next; 
            }
        }
         cout << "Number of elements: " << num << endl;
   }