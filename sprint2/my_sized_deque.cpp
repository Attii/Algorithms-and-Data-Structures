// https://contest.yandex.ru/contest/22781/run-report/95325199/

/*
--Principle of Operation--

The implementation of this task improves upon the solution for the Bounded Queue problem.

A vector is used for data storage. The indices of the "head" and "tail" (beginning and end, 
respectively) are stored in integer variables.

When adding to the end of the deque, the `tail_` variable is used. After adding, it is 
incremented by one. To avoid exceeding the maximum size of the deque, the index is taken 
modulo the maximum size.

When adding to the beginning of the deque, the start index is always moved forward by 
subtracting one. If the index equals zero, it is set to `max_size_ - 1`.

In the `pop_back` function, the tail index is decremented by one before printing, as the 
tail index always (if possible) points to the last free space. In `pop_front`, the decrement 
occurs after printing because the head index always points to the first element.

--Proof of Correctness--

Accessing an element in the vector occurs in O(1) time since the indices of the beginning and 
end of the deque are always known.

--Time Complexity--

Adding to a vector with pre-allocated memory space occurs in O(1) time.

Deletion involves setting an element to NULL, which also occurs in constant time.

--Space Complexity--

The amount of memory used directly depends on the maximum size of the deque, as space is 
immediately reserved for the vector during initialization using the `resize()` function of 
the vector.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MySizedDeque
{
private:
    int head_;
    int size_;
    vector<int> sizedDeque_;

public:
    MySizedDeque(int max_size)
        : head_(0)
        , size_(0)
        , sizedDeque_(max_size)
    {
    }

    void push_back(int value)
    {
        if (size_ < sizedDeque_.size())
        {
            int tail = (head_ + size_) % sizedDeque_.size();
            sizedDeque_[tail] = value;
            ++size_;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    void pop_back()
    {
        if (size_ != 0)
        {
            int tail = (head_ + size_ - 1) % sizedDeque_.size();
            cout << sizedDeque_[tail] << endl;
            sizedDeque_[tail] = NULL;
            --size_;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    void push_front(int value)
    {
        if (size_ < sizedDeque_.size())
        {
            head_ = (head_ + sizedDeque_.size() - 1) % sizedDeque_.size();
            sizedDeque_[head_] = value;
            ++size_;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    void pop_front()
    {
        if (size_ != 0)
        {
            cout << sizedDeque_[head_] << endl;
            sizedDeque_[head_] = NULL;
            head_ = (head_ + 1) % sizedDeque_.size();
            --size_;
        }
        else
        {
            cout << "error" << endl;
        }
    }
};

int main()
{
    int n, max;
    cin >> n >> max;
    string line;
    MySizedDeque mySizedDeque(max);
    for (; n > 0; --n)
    {
        cin >> line;
        if (line == "push_front")
        {
            cin >> line;
            mySizedDeque.push_front(stoi(line));
        }
        if (line == "push_back")
        {
            cin >> line;
            mySizedDeque.push_back(stoi(line));
        }
        if (line == "pop_back")
        {
            mySizedDeque.pop_back();
        }
        if (line == "pop_front")
        {
            mySizedDeque.pop_front();
        }
    }
}
