/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */

// @lc code=start
#include <semaphore.h>

class Foo {
public:
    sem_t first_done;
    sem_t second_done;
    Foo() {
        sem_init(&first_done,0,0);
        sem_init(&second_done,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_done);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_done);
    }

    void third(function<void()> printThird) {
        sem_wait(&second_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
// @lc code=end

