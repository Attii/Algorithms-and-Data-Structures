// https://contest.yandex.ru/contest/22781/run-report/95325199/

/*
--Принцип работы--

Реализация данной задачи является улучшение решения задачи Ограниченная очередь.

Для хранения данных использовался вектор. Индексы "головы" и "хвоста" (начало и конец
соответственно) хранятся в переменных типа integer.

При добавлении в конец очереди используется переменная tail_. После добавления она
увеличивается на единицу. Дабы не вылезти за максимальный размер очереди, берется 
остаток от деления индекса на максимальный размер.

При добавлении в начало очереди индекс начала всегда сдвигается вперёд путем вычитания 
единицы. Если индекс равняется нулю, приравниваем его к max_size_ - 1

В функции pop_back перед печатью мы уменьшаем индекс конца на единицу, так так индекс 
конца всегда (если возможно) указывает на последнее свободное место. В pop_front уменьшение 
происходит после печати, так как индекс начала всегда указыват на первый элемент.

--Доказательство корректности--

Обращение к элементу в векторе происходит за время О(1), так как нам всегда известен 
индекс начала и конца очереди.

--Временная сложность--

Добавление в вектор с заранее зарезервированным местом в памяти происходит за О(1)

Удаление происходит путем приравнивания элемента к NULL, что тоже будет происходить за константное время.

--Пространственная сложность--

Объем использованной памяти зависит напрямую от максимального размера очереди, так как при инициализации 
очереди происходит сразу же резервация места под вектор с помощью функции вектора resize().
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