#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    for (int i = 0; i < 51; i++){
        buckets[i] = NULL;
    }
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {}


/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    // When adding a PCB to the queue, you must change its state to READY.
    int pri; 
    num++; 

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

}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.s
    PCB* ptr;
    num--;
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
    return ptr;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    return num;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
   PCB* ptr;  
   for (int i = 49; i >= 0; i--){
        ptr = buckets[i];
        while (ptr != NULL){ 
                ptr->display();
                ptr = ptr->next; 
            }
        }
   }