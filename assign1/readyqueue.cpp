#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
    for (int i = 1; i < 51; i++){
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
    pcbPtr->setState(ProcState::READY);  
    int i = pcbPtr->priority; 
    num ++; 
    if (buckets[i] == NULL){
        buckets[i] = tails[i] = pcbPtr; 
        return; 
    } 
    tails[i]->next = pcbPtr;
    pcbPtr->prev = tails[i]; 
    tails[i] = pcbPtr; 
    return;

}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.s
    PCB* ptr;
    int i = 50; 

    while (buckets[i] == NULL && i != 0){i--;}
    if (i == 0){
        cout << "The ready queue is empty!" <<endl; 
        return NULL; 
    }


    ptr = buckets[i];
    if (ptr->next != NULL){
        buckets[i] = ptr->next; 
        buckets[i]->prev = NULL; 
    }
  

    ptr->setState(ProcState::RUNNING);
    delete ptr; 
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
   for (int i = 50; i > 0; i--){
        ptr = buckets[i];
        if (ptr != NULL){
            cout << "Priority " << i << ": ";
            while (ptr != NULL){
                ptr->display();
                ptr = ptr->next; 
            }
        }
   }