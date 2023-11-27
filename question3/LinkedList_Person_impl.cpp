//
//  LinkedList_Person_impl.cpp
//

#include <iostream>
#include "Person.h"
#include "LinkedList.h"

// Implementations for Person class
template<>
void LinkedList<Person>::print()
{
    Node* temp = head;
    while(nullptr != temp)
    {
        std::cout << "[" << temp->element->name << ", ";
        std::cout << temp->element->age << ", ";
        std::cout << temp->element->cake_or_cookie << ", " << temp << "] -> " << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<>
LinkedList<Person>* LinkedList<Person>::sort_person_asc()
{
    // Create a copy
    LinkedList<Person>* ret = new LinkedList<Person>(*this);
    
    // bubble sort
    Node* static_node = ret->head;
    Node* moving_node = ret->head;
    
    for (int j = 0; j < ret->size; j++)
    {
        for (int j = 0; j < ret->size; j++)
        {
            if (static_node->element->age <= moving_node->element->age)
            {
                Person* temp = static_node->element;
                static_node->element = moving_node->element;
                moving_node->element = temp;
            }
            moving_node = moving_node->next;
        }
        // advance pointer
        moving_node = ret->head;
        static_node = static_node->next;
    }
    
    return ret;
}
