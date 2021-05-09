//
//  main.cpp
//  learn_c++
//
//  Created by Wung Jae Lee on 5/8/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include <thread>
#include <mutex>
#include <chrono>

#include "header1.h"
#include "header2.h"
#include "MyString.h"
#include "vector.h"
using namespace header1;
using header1::foo;

namespace header1 {
int func() {
    foo();
    header2::foo();
    return 1;
}
}


void func1() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 1 in work!\n";
    }
}

void func2() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 2 in work!\n";
    }
}
void func3() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 3 in work!\n";
    }
}

void worker(int start, int end, int* result) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += i;
    }
    *result = sum;
    
    std::thread::id this_id = std::this_thread::get_id();
    printf("thread %x added from %d to %d and got %d \n", this_id, start, end, sum); //thread safe
}

void add_worker(int* count, int num_increments, std::mutex& m) {
   
    std::thread::id this_id = std::this_thread::get_id();
    printf("thread %x started working\n", this_id);
    
    for (int i = 0; i < num_increments; ++i) {
        m.lock();
        (*count)++;
        m.unlock();
    }
    printf("thread %x finished working\n", this_id);
}

template <typename T>
class ThreadSafeQueue {
    std::queue<T> q;
    std::mutex m;
public:
    ThreadSafeQueue(void) : q(), m() {};
    void enqueue(T data) {
        m.lock();
        q.push(data);
        m.unlock();
    }
    
    T dequeue() const {
        m.lock();
        if (q.empty()) {
            m.unlock();
            return NULL;
        }
        T data = q.front();
        q.pop();
        m.unlock();
        
        return data;
    }
    
    int size() const {
        return q.size();
    }
};

template <typename T>
void producer(std::queue<T>& q, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        q.push(num_items);
    }
}

template <typename T>
void producer1(std::queue<T>& q, int num_items, std::mutex& m) {
    for (int i = 0; i < num_items; ++i) {
        m.lock();
        q.push(num_items);
        m.unlock();
    }
}

template <typename T>
void producer2(ThreadSafeQueue<T>& q, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        q.enqueue(i);
    }
}

void producer3(ThreadSafeQueue<int>& q, int num_items) {
    for (int i = 0; i < num_items; ++i) {
        q.enqueue(i);
    }
}


void producer_page(std::queue<std::string>* downloaded_pages, std::mutex* m, int index) {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100*index));
        std::string content = "website: " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";
        
        m->lock();
        downloaded_pages->push(content);
        m->unlock();
    }
}

void consumer_page(std::queue<std::string>* downloaded_pages, std::mutex* m, int* num_processed) {
    while (*num_processed < 25) {
        m->lock();
        
        if (downloaded_pages->empty()) {
            m->unlock();
            
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        
        std::string content = downloaded_pages->front();
        downloaded_pages->pop();
        
        (*num_processed)++;
        m->unlock();
        
        std::cout << content;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /* namespace */
    /*
    std::cout << "Hello, World!\n";
    std::cout << header1::func() << std::endl;
    std::cout << func() << std::endl;
    std::cout << foo() << std::endl;
    std::cout << header2::foo() << std::endl;
     */
    
    /* reference */
    /*
    int a = 3;
    int& another_a = a;
    
    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;
    
    // int& ref = 4; // this is not valid
    const int& ref2 = 4; // this is okay
    
    int arr[3] = { 1, 2, 3 };
    int(&ref)[3] = arr;
    
    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;
    
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
     */
    
    /*
    MyString s('a');
    std::cout << s.length() << std::endl;
    
    MyString s2("hello my name is wungjae");
    std::cout << s2.length() << std::endl;
    s2.println();
    
    MyString s3(s2);
    s3.println();
    std::cout << s3.length() << std::endl;
    */
    
    /*
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(4);
    
    std::cout << "------ int vector -------" << std::endl;
    std::cout << int_vec[0] << std::endl;
    std::cout << int_vec[1] << std::endl;
    
    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    
    std::cout << "------ str vector -------" << std::endl;
    std::cout << str_vec[0] << std::endl;
    std::cout << str_vec[1] << std::endl;
    */
    
    /*
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);
    
    t1.join(); // return after finishing execution
    t2.join();
    t3.join();
     */
    
    /*
    std::vector<std::thread> workers;
    std::vector<int> partial_sums(4);
    for (int i = 0; i < 4; ++i) {
        workers.push_back(std::thread(worker, i*2500, (i+1)*2500, &partial_sums[i]));
    }
    
    for (int i = 0; i < 4; ++i) {
        workers[i].join();
    }
    
    int total = 0;
    for (int i = 0; i < 4; ++i) {
        total += partial_sums[i];
    }
    std::cout << "Total: " << total << std::endl;
    */
    
    /*
    int count = 0;
    std::mutex m;
    std::vector<std::thread> workers;
    for (int i = 0; i < 10; ++i) {
        workers.push_back(std::thread(add_worker, &count, 10000, std::ref(m)));
    }
    
    for (int i = 0; i < 10; ++i) {
        workers[i].join();
    }
    
    std::cout << "Count: " << count << std::endl; // expect 10000*10 = 100,000
     */
    
    
    /*
    std::queue<int> q;
    std::vector<std::thread> producers;
    std::mutex m;
    
    for (int i = 0; i < 5; ++i) {
        producers.push_back(std::thread(producer1<int>, std::ref(q), 10000, std::ref(m)));
    }
    
    for (int i = 0; i < 5; ++i) {
        producers[i].join();
    }
    
    std::cout << "Number of items in queue: " << q.size() << std::endl;
     */
    
    /*
    // this is not thread safe and may result in error
    std::queue<int> q;
    std::vector<std::thread> producers;
    
    for (int i = 0; i < 5; ++i) {
        producers.push_back(std::thread(producer<int>, std::ref(q), 10000));
    }
    
    for (int i = 0; i < 5; ++i) {
        producers[i].join();
    }
    
    std::cout << "Number of items in queue: " << q.size() << std::endl;
    */
    
    /*
    ThreadSafeQueue<int> q;
    std::vector<std::thread> producers;
    for (int i = 0; i < 5; ++i) {
        producers.push_back(std::thread(producer2<int>, std::ref(q), 10000));
        // producers.push_back(std::thread(producer3, std::ref(q), 10000)); // same as above
    }
    for (int i = 0; i < 5; ++i) {
        producers[i].join();
    }
    
    std::cout << "Number of items in queue: " << q.size() << std::endl;
    */
    
    std::queue<std::string> downloaded_pages;
    std::mutex m;
    
    std::vector<std::thread> producers;
    for (int i = 0; i < 5; ++i) {
        producers.push_back(std::thread(producer_page, &downloaded_pages, &m, i+1));
    }
    
    int num_processed = 0;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 3; ++i) {
        consumers.push_back(std::thread(consumer_page, &downloaded_pages, &m, &num_processed));
    }
    
    for (int i = 0; i < 5; ++i) {
        producers[i].join();
    }
    
    for (int i = 0; i < 3; ++i) {
        consumers[i].join();
    }
    return 0;
}
