#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  {
     //TODO: add your code here
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
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.
<<<<<<< Updated upstream
=======
    int idx;
    PCB* ptr; 
    for (int i = 50; i > 0; i--){
        if (buckets[i] != NULL){
            ptr = buckets[i];
            buckets[i] = ptr->next; 

            ptr->setState(ProcState::RUNNING); 
            delete ptr; 
            num --; 
            return; 
        }
    }
    cout << "The ready queue is empty!" <<endl; 

>>>>>>> Stashed changes
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //TODO: add your code here
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    PCB* ptr; 
    int i = 1; 
    ptr = buckets[i];
    while (i != 51){
        ptr->display(); 
        ptr = ptr->next; 
        if (ptr == NULL){i++; ptr = buckets[i];}
    }
}