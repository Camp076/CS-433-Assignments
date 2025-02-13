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
ReadyQueue::~ReadyQueue() {
    //TODO: add your code to release dynamically allocate memory
}

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
    tails[i] = pcbPtr; 
    return;

}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    // When removing a PCB from the queue, you must change its state to RUNNING.
    int idx;
    PCB* ptr; 
    for (int i = 50; i > 0; i--){
        if (buckets[i] != NULL){
            ptr = buckets[i];
            buckets[i] = ptr->next; 

            ptr->setState(ProcState::RUNNING); 
            delete ptr; 
            return; 
        }
    }
    cout << "The ready queue is empty!" <<endl; 

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
    //TODO: add your code here
}