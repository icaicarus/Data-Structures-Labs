#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{
    listSize = 0;
    listHead = new DNode();
    listTail = new DNode();
    persistHead = new DNode();
    listTail->prev = listHead;
    listHead->next = listTail;
    persistHead = listHead;
}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode *readerHead = listHead;
    DNode *p;
    while(readerHead->next != NULL){
        p = readerHead;
        readerHead = readerHead->next;
        delete p;
    }
    delete readerHead;
    listHead = NULL;
    listTail = NULL;
}

int objPosDLinkedList::getSize()
{
    return listSize;
}

bool objPosDLinkedList::isEmpty()
{
   if(listSize == 0) return true;
   else return false;
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    DNode *p = new DNode();
    p->data = thisPos;
    p->next = listHead->next;
    p->prev = listHead;
    listHead->next = p;
    p->next->prev = p;
    listSize++;
}

void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    DNode *p = new DNode();
    p->data = thisPos;
    p->next = listTail;
    p->prev = listTail->prev;
    p->next->prev = p;
    p->prev->next = p;
    listSize++;
}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{
    if(index >= listSize - 1) insertTail(thisPos);
    else if(index <= 0) insertHead(thisPos);
    else{
        DNode *readerHead = listHead;
        for(int i = 0; i < index; i++){
            readerHead = readerHead->next;
        }
        DNode *p = new DNode();
        p->data = thisPos;
        p->next = readerHead->next;
        p->prev = readerHead;
        p->prev->next = p;
        p->next->prev = p;
        listSize++;
    }
    
}

objPos objPosDLinkedList::getHead() const
{
    return listHead->next->data;
}

objPos objPosDLinkedList::getTail() const
{
    return listTail->prev->data;
}

objPos objPosDLinkedList::get(int index) const
{
    objPos info;
    if(index >= listSize - 1) return getTail();
    if(index <= 0) return getHead();
    DNode *readerHead = listHead;
    for(int i = 0; i < index; i++){
        readerHead = readerHead->next;
    }
    return readerHead->next->data;
}

objPos objPosDLinkedList::getNext()
{
    persistHead = persistHead->next;
    if(persistHead->next == nullptr){
        resetReadPos();
        return objPos(0,0,0,0,0);
    }
    else{
        return persistHead->data;
    }
    
}

void objPosDLinkedList::resetReadPos()
{
    persistHead = listHead;
}

void objPosDLinkedList::set(const objPos &thisPos, int index)
{
    if(index >= listSize) index = listSize - 1;
    if(index < 0) index = 0;
    DNode *readerHead = listHead;
    for(int i = 0; i < index; i++){
        readerHead = readerHead->next;
    }
    readerHead->next->data = thisPos;

}

objPos objPosDLinkedList::removeHead()
{
    DNode* p = listHead->next;
    objPos objVal = p->data;
    listHead->next = p->next;
    p->next->prev = listHead;     
    delete p;
    listSize--;
    return objVal;
    
}

objPos objPosDLinkedList::removeTail()
{
    DNode* p = listTail->prev;
    objPos objVal = p->data;
    listTail->prev = p->prev;
    p->prev->next = listTail;
    delete p;
    listSize--;
    return objVal;
}

objPos objPosDLinkedList::remove(int index)
{
    if(index >= listSize - 1) return removeTail();
    else if(index <= 0) return removeHead();
    DNode* p = listHead->next;
    for(int i = 0; i < index; i++){
        p = p->next;
    }
    objPos objVal = p->data;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    listSize--;
    return objVal;
}

void objPosDLinkedList::printList() const
{
    // DNode *readerHead = listHead;
    // int i = 1;
    // std::cout << "Head: " << listHead << endl;
    // while(readerHead->next != listTail){
    //     readerHead = readerHead->next;
    //     std::cout << "Element " << i << " (Address: " << &readerHead << ")" << endl;
    //     std::cout << "Data: " << readerHead->data[0] << ", " << readerHead->data[1] << ", " << readerHead->data[2] << ", " << readerHead->data[3] << ", " << readerHead->data[4] << endl;
    //     std::cout << "Next: " << readerHead->next << endl;
    //     std::cout << "Prev: " << readerHead->prev << endl;
    //     i++;
    // }
    // std::cout << "Tail: " << readerHead->next << endl;
    
}


