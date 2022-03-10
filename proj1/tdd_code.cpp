//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Dmitrii Kozhevnikov <xkozhe00@stud.fit.vutbr.cz>
// $Date:       $2020-03-01
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Dmitrii Kozhevnikov
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    root = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *element = GetHead(); //  take root
    while (element != NULL) {   //  if we have something in root
        Element_t *newElement = element;
        element = element->pNext;   
        delete newElement;  //  delete old element
    }
}

void PriorityQueue::Insert(int value)
{
    Element_t *element = GetHead();

    //  root is empty
    if(element == NULL) {
        root = createNewElement(NULL, NULL, value);
        return;
    }
    else {

        while (value > element->value) {
            if (element->pNext == NULL) {
                break;
            }
            else {
                element = element->pNext;
            } 
        }
        // first element
        if (((element->pPrev == NULL && element->pNext == NULL) || (element->pPrev == NULL && element->pNext != NULL)) && (value <= element->value)) {
            root = createNewElement(element, NULL, value);
            element->pPrev = root;
            return;
        }
        else if ((element->pPrev == NULL && element->pNext == NULL) && (value > element->value)) {
            Element_t *newElement = createNewElement(NULL, root, value);
            root->pNext = newElement;
            return;
        }  
        else if ((element->pPrev == NULL && element->pNext != NULL) && (value > element->value)) {
            Element_t *newElement = createNewElement(element->pNext, element, value);
            element->pNext = newElement;
            element->pNext->pPrev = newElement;
        }
        
        // last  element
        else if ((element->pPrev != NULL && element->pNext == NULL) && (value <= element->value)) {
            Element_t *newElement = createNewElement(element, element->pPrev, value);
            element->pPrev->pNext = newElement;
            element->pPrev = newElement;            
            return;
        }
        else if ((element->pPrev != NULL && element->pNext == NULL) && (value > element->value)) {
            Element_t *newElement = createNewElement(NULL, element, value);
            element->pNext = newElement;            
            return;
        
        }
        //  stred element
        else if (element->pNext != NULL && element->pPrev != NULL && value <= element->value) {
            Element_t *newElement = createNewElement(element, element->pPrev, value);
            element->pPrev->pNext = newElement;
            element->pPrev = newElement;
            return;
        }
        else if (element->pNext != NULL && element->pPrev != NULL && value > element->value) {
            Element_t *newElement = createNewElement(element->pNext, element, value);
            element->pNext = newElement;
            element->pNext->pPrev = newElement;
            return;
        }
    }

}


bool PriorityQueue::Remove(int value)
{
    Element_t *element = Find(value);
    // if we find element
    if (element) {
        if (element->pNext == NULL && element->pPrev == NULL) {
            root = NULL;
        }
        else if (element->pNext != NULL && element->pPrev == NULL) {
            element->pNext->pPrev = NULL;
            root = element->pNext;
        }
        // last element
        else if (element->pPrev != NULL && element->pNext == NULL) {
            element->pPrev->pNext = NULL;
        }  
        //  stred element
        else if (element->pNext != NULL && element->pPrev != NULL) {
            element->pPrev->pNext = element->pNext;
            element->pNext->pPrev = element->pPrev;
        }
        delete element;
        return true;
    }
    
    // element is not remove
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    Element_t *element = GetHead();
    //  root is empty
    if (element == NULL) { 
        return NULL;
    }
    //  root is not empty
    else {
        for (element; element != NULL; element = element->pNext) {
            //  we find value
            if (element->value == value) {
                return element;
            }
            //  we can not find value
  
        }
        
    }
    return NULL;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return root;
}

PriorityQueue::Element_t *PriorityQueue::createNewElement(Element_t *pNext, Element_t *pPrev, int value)
{
	Element_t *element = new Element_t;
    element->pNext = pNext;
	element->pPrev = pPrev;
    element->value = value;
	return element;
}
/*** Konec souboru tdd_code.cpp ***/
