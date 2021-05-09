//
//  thread_safe_queue.h
//  learn_c++
//
//  Created by Wung Jae Lee on 5/9/21.
//

#ifndef thread_safe_queue_h
#define thread_safe_queue_h

#include <iostream>
#include <mutex>
#include <condition_variable>

#define LOCKED 0
#define UNLOCKED 1

// suppose we have atomic operations such as atomic_test_and_set, atomic_load

template <typename T>
class ThreadSafeQueue {
    std::queue<T> q;
    int spinlock;
    
    void lock() {
        while (atomic_test_and_set(&spinlock, LOCKED) == LOCKED) {
            // lock is locked
            while (atomic_load(&spinlock) == LOCKED);
            // lock is unlocked
        }
        // acquired the lock
    };
    void unlock() {
        atomic_test_and_set(&spinlock, UNLOCKED);
    };
    
public:
    ThreadSafeQueue() {
        spinlock = UNLOCKED;
    }
    
    void enqueue(T data) {
        lock(); // busy waiting
        q.push(data);
        unlock();
    }
    
    T dequeue() {
        lock();
        if (q.empty()) {
            unlock();
            return NULL;
        }
        T data = q.pop();
        unlock();
        return data;
    };
    
    bool empty() {
        return q.empty();
    }
}

template <typename T>
class ThreadSafeQueue2 {
    std::queue<T> q;
    mutable std::mutex m;
    std::condition_variable c;
    
public:
    ThreadSafeQueue2(void) : q(), m(), c() {};
    ~ThreadSafeQueue2(void) {};
    
    void enqueue(T data) {
        std::lock_guard<std::mutex> lock(m);
        q.push(data);
        c.notify_one();
    }
    
    T dequeue(void) {
        std::unique_lock<std::mutex> lock(m);
        while (q.empty()) {
            // release lock as long as the wait and reacquire it afterwards
            c.wait(lock);
        }
        T data = q.front();
        q.pop();
        return data;
    }
}


#endif /* thread_safe_queue_h */
