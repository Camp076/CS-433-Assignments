/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Jaiden Camp
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */
#include <iostream>
#include "pcbtable.h"
using namespace std; 
/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {
   this->capacity = size; 
   this->arr = new PCB*[capacity];
   for (int i = 0; i < capacity; i++){
       this->arr[i] = NULL; 
   }
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
    for (int i = 0; i < capacity; i++){
        if (arr[i] != NULL){
            delete arr[i]; 
        }
    }
    delete [] arr;
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    PCB* ptr = arr[idx];  

    if (idx >= capacity){
        cout << "The index is out of bounds!" <<endl;
        return NULL;
    }

    if (ptr == NULL){
        cout << "There is no PCB at this index!" <<endl; 
        return NULL;
    }

    return ptr; 
    
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    // Add a PCB pointer to the PCBTable at index idx.
    PCB* ptr = arr[idx];
    
    if (idx >= capacity){
        cout << "The index is out of bounds!" <<endl;
        return; 
    }
    
    if (ptr != NULL){
        cout << "This index is already in use!" <<endl;
        return; 
    }

    arr[idx] = pcb; 
    return; 
}
