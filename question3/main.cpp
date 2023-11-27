//
//  main.cpp
//

#include <iostream>
#include <cassert>
#include "Person.h"
#include "LinkedList.h"

// Question 3

// Implement a linked list of objects of class Person, 
// and create a function that returns a new copy of that linked
// listed sorted by age in ascending order. Please use C++.

//
// Unit test of Linked List class
//
#define _assert_msg(e, m)   \
    if(!(e)) \
    {   \
        std::cerr << m << std::endl; \
        assert(e); \
    }

int main(int argc, const char *argv[])
{
    // Test 1
    // Empty list/ copy
    {
        try
        {
            LinkedList<Person> ll;
            LinkedList<Person>* sorted = ll.sort_person_asc();
            _assert_msg(&ll != sorted, "ERROR Test 1: LinkedList did not made a copy");
        }
        catch (const std::exception &exc)
        {
            std::cerr << "ERROR Test 1: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 1: PASSED" << std::endl;
    }
    
    // Test 2
    // Indexing
    {
        try
        {
            Person p1("John Smith",     27, "cake");
            Person p2("Mike Johnson",   34, "cookie");
            Person p3("Juan Perez",     40, "cake");
            
            LinkedList<Person> ll;
            ll.add(&p1);
            ll.add(&p2);
            ll.add(&p3);
            
            LinkedList<Person>* sorted = ll.sort_person_asc();
            _assert_msg(sorted->get(0)->age == 27, "ERROR Test 2");
            _assert_msg(sorted->get(1)->age == 34, "ERROR Test 2");
            _assert_msg(sorted->get(2)->age == 40, "ERROR Test 2");
            _assert_msg(sorted->get(3) == nullptr, "ERROR Test 2");
            _assert_msg(sorted->get(-1) == nullptr, "ERROR Test 2");
            _assert_msg(sorted->get(10000) == nullptr, "ERROR Test 2");
        }
        catch (const std::exception &exc)
        {
            std::cerr << " Test 2: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 2: PASSED" << std::endl;
    }
    
    // Test 3
    // Sorting in order
    {
        try
        {
            Person p1("John Smith",     27, "cake");
            Person p2("Mike Johnson",   34, "cookie");
            Person p3("Juan Perez",     40, "cake");
            Person p4("Maria Wall",     45, "cookie");
            
            LinkedList<Person> ll;
            ll.add(&p1);
            ll.add(&p2);
            ll.add(&p3);
            ll.add(&p4);
            
            LinkedList<Person>* sorted = ll.sort_person_asc();
            _assert_msg(sorted->get(0)->age == 27, "ERROR Test 3");
            _assert_msg(sorted->get(1)->age == 34, "ERROR Test 3");
            _assert_msg(sorted->get(2)->age == 40, "ERROR Test 3");
            _assert_msg(sorted->get(3)->age == 45, "ERROR Test 3");
        }
        catch (const std::exception &exc)
        {
            std::cerr << " Test 3: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 3: PASSED" << std::endl;
    }
    
    // Test 4
    // Sorting worst case
    {
        try
        {
            Person p1("John Smith",     27, "cake");
            Person p2("Mike Johnson",   34, "cookie");
            Person p3("Juan Perez",     40, "cake");
            Person p4("Maria Wall",     45, "cookie");
            
            LinkedList<Person> ll;
            ll.add(&p4);
            ll.add(&p3);
            ll.add(&p2);
            ll.add(&p1);
            
            LinkedList<Person>* sorted = ll.sort_person_asc();
            _assert_msg(sorted->get(0)->age == 27, "ERROR Test 4");
            _assert_msg(sorted->get(1)->age == 34, "ERROR Test 4");
            _assert_msg(sorted->get(2)->age == 40, "ERROR Test 4");
            _assert_msg(sorted->get(3)->age == 45, "ERROR Test 4");
        }
        catch (const std::exception &exc)
        {
            std::cerr << " Test 4: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 4: PASSED" << std::endl;
    }
    
    // Test 5
    // Sorting random large quantity
    {
        try
        {
            std::vector<uint32_t> age_list;
            std::vector<Person*> person_list;
            
            // Test linked list
            LinkedList<Person> ll;
            
            // Init rand
            srand(1000);    // TODO: seed rand
            
            for(int i = 0; i < 10000; i++)
            {
                uint32_t age = ((uint32_t)rand()%100 + 1);
                age_list.push_back(age);    // Store age into a vector
                
                // create person object
                Person* temp = new Person("temp name", age, "temp cookie");
                
                // Store Person for later free
                person_list.push_back(temp);
                
                // Add the element to the list
                ll.add(temp);
            }
            
            // Sort our reference vector
            std::sort(age_list.begin(), age_list.end());
            
            // Get sorted linked list
            LinkedList<Person>* sorted = ll.sort_person_asc();
            
            // Compare
            for(int i = 0 ; i < age_list.size(); i++)
            {
                _assert_msg(sorted->get(i)->age == age_list[i], "ERROR Test 5");
            }
            
            // free malloc
            for(int i = 0 ; i < person_list.size(); i++)
            {
                delete person_list[i];
                person_list[i] = nullptr; // No stray pointers
            }
        }
        catch (const std::exception &exc)
        {
            std::cerr << " Test 5: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 5: PASSED" << std::endl;
    }
    
    // Test 6
    // List copied nodes
    {
        try
        {
            LinkedList<Person> ll;
            LinkedList<Person>* sorted = ll.sort_person_asc();
            _assert_msg(&ll != sorted, "ERROR Test 6: LinkedList did not made a copy");
            _assert_msg(ll.get(0) == sorted->get(0), "ERROR Test 6: LinkedList not storing same element");
        }
        catch (const std::exception &exc)
        {
            std::cerr << "ERROR Test 6: exception reached" << std::endl;
            std::cerr << exc.what();
        }
        std::cout << "Test 6: PASSED" << std::endl;
    }
    
    return 0;
}
