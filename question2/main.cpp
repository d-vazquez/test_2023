//
//  main.cpp
//

#include <iostream>
#include <thread>

// Question 2
// Counter is a simple counter class that keeps track of
// a count using an internal private variable.

// Complete the code below by doing the following:
// 1.   Implement the method increase_count_by_1() of class Counter.
//      Each call to this method should increment the private
//      variable count by 1.
// 2.   In main(), create 10 simultaneously executing threads that
//      each call counter_fn(cnt, 1000000).

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Counter
{
    std::mutex lock;
    
public:
    Counter()
    {
        this->count = 0;
    }
    void increase_count_by_1()
    {
        // control resource, object is
        // in scope so when returning it will
        // be destroyed and mutex wil be released
#if !defined(DISABLE_THREAD_MUTEX) || DISABLE_THREAD_MUTEX == 0
        std::lock_guard<mutex> locker(lock);    // Comment this to fail test
#endif
        count++;
    }
    void show()
    {
        std::cout << "count = " << count << std::endl;
    }
    unsigned int getCount()
    {
        return count;
    }
private:
    unsigned int count;
};

void counter_fn(Counter& counter, size_t loop)
{
    for(int i=0; i<loop; i++)
    {
        counter.increase_count_by_1();
    }
}

int main()
{
    Counter cnt;
    
    constexpr int loop_count = 1000000; // 10 threads required
    constexpr int thread_count = 10; // 10 threads required
    
    std::vector<std::thread> thread_list;
    
    for(int i = 0; i < thread_count; i++)
    {
        thread_list.push_back(std::thread(counter_fn, std::ref(cnt), loop_count));
    }
    
    for(int i = 0; i < thread_count; i++)
    {
        thread_list[i].join();
    }
    
    cnt.show();
    
    // quick Test
    if(cnt.getCount() != thread_count*loop_count)
    {
        std::cerr << "Error on resource sharing, should be: ";
        std::cerr << thread_count*loop_count << " is: ";
        std::cerr << cnt.getCount() << std::endl;
    }
    else
    {
        std::cout << "Mutex test PASSED" << std::endl;
    }
    
    return 0;
}

