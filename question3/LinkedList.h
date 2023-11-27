//
//  LinkedList.h
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdint.h>

// this should do a linked list for any type we want, later we declar
// a specific function to sort and print
// copy constructor added, as sort function shall return a copy
template <class T>
class LinkedList
{
public:
    typedef struct _Node
    {
        T*      element;
        _Node*  next;
    } Node;
    
    LinkedList() { } // Do nothing
    
    LinkedList(T* element) // we have an element, add it
    {
        head = new Node();
        tail = head;
        head->element = element;
        head->next = nullptr;
        size++;
    }
    
    // Copy constructor
    LinkedList(LinkedList& ll)
    {
        if(0 != ll.size && nullptr != ll.head)
        {
            // Add firs element
            head = new Node();
            tail = head;
            head->element = ll.head->element;
            head->next = nullptr;
            size++;
            
            // Cicle thru remaining
            Node* temp = ll.head->next;
            while(temp != nullptr)
            {
                tail->next = new Node();
                tail = tail->next;
                tail->element = temp->element;
                tail->next = nullptr;
                size++;
                
                // Next
                temp = temp->next;
            }
        }
    }
    
    // Delete all creted nodes, elements in the nodes
    // shall be deleted by the caller
    ~LinkedList()
    {
        if(nullptr != head)
        {
            while(nullptr != head)
            {
                Node* temp = head->next;
                delete head;
                head = temp;
            }
        }
        tail = nullptr;
    }
    
    // We have a case for an empty linked list, this is
    // for flexibility, we may want to just create an
    // empty linked list
    void add(T* element)
    {
        // not empty
        if(nullptr != head)
        {
            tail->next = new Node();
            tail = tail->next;
            tail->element = element;
            tail->next = nullptr;
        }
        // empty
        else
        {
            head = new Node();
            tail = head;
            head->element = element;
            head->next = nullptr;
        }
        size++;
    }
    
    T* get(uint32_t indx)
    {
        if(indx >= size)
        {
            return nullptr; // out of bounds
        }
        Node* temp = head;
        for(int i = 0; i < indx; i++)
        {
            temp = temp->next;
        }
        
        return temp->element;
    }
    
    // Sort ascending
    LinkedList<T>* sort_person_asc();
    // Print
    void print();
    
private:
    Node*  head = nullptr;
    Node*  tail = nullptr;
    size_t size = 0;
};

#endif /* LinkedList_h */
