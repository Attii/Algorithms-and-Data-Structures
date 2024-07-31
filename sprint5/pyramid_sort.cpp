//https://contest.yandex.ru/contest/24810/run-report/112920902/

/*
--Принцип работы--
Код реализует сортировку кучей, которая включает в себя создание 
максимальной кучи из входных данных и последующее извлечение 
максимального элемента для формирования отсортированного массива. 
Каждый участник соревнования характеризуется количеством решённых задач, 
штрафом и логином. Операции с кучей реализованы через функции sift_up и 
sift_down, которые обеспечивают поддержание свойств максимальной кучи.

--Доказательство корректности--
Код корректно реализует базовые операции работы с кучей:

'sift_up' поддерживает свойства кучи при добавлении нового элемента.
'sift_down' восстанавливает свойства кучи после удаления корневого элемента 
(максимального элемента кучи).

--Временная сложность--
Построение кучи: O(n), где n — количество участников.
Извлечение элементов из кучи для формирования отсортированного массива: 
O(n log n), так как каждое извлечение требует O(log n) времени для 
восстановления свойств кучи.

--Пространственная сложность--
Пространственная сложность: O(n) для хранения элементов кучи.
*/

#include <iostream>
#include <vector>

using namespace std;

struct Participant
{
  string login;
  int solved_tasks;
  int penalty;

  bool operator>(const Participant& other) const {
    if (solved_tasks != other.solved_tasks) {
      return solved_tasks > other.solved_tasks;
    }
    if(penalty != other.penalty) {
      return penalty < other.penalty;
    }
    return login < other.login;
  }

  bool operator<(const Participant& other) const {
    return !(*this > other);
  }

  bool operator==(const Participant& other) const {
    return (solved_tasks == other.solved_tasks && penalty == other.penalty && login == other.login);
  }
};

vector<Participant> read_input() {
  int n;
  cin >> n;

  vector<Participant> res;
  res.reserve(n);

  for (int i = 0; i < n; i++)
  {
    Participant p;
    cin >> p.login >> p.solved_tasks >> p.penalty;
    res.push_back(p);
  }
  
  return res;

}

void sift_up(vector<Participant>& heap, int index) {
  int parent_index = index / 2;
  while (index > 1 && heap[parent_index] < heap[index])
  {
    std::swap(heap[parent_index], heap[index]);
    index = parent_index;
    parent_index = index / 2;
  }
}

void sift_down(std::vector<Participant>& heap, int index) {
    while (true)
    {
      int left = 2 * index;
      int right = 2 * index + 1;

       // Нет дочерних узлов
      if (left >= heap.size()) {
          break;
      }

      // проверяем, что есть оба дочерних узла
      int index_largest = left;
      if (right < heap.size() && heap[right] > heap[left]) {
          index_largest = right; 
      }

      if (heap[index_largest] > heap[index]) {
          std::swap(heap[index], heap[index_largest]);
          index = index_largest;
      } 
      else {
        break;
      }
    }
} 

void heap_add(vector<Participant>& heap, Participant item) {
  heap.push_back(item);
  int index = heap.size() - 1;
  sift_up(heap, index);
}

Participant pop_max(std::vector<Participant>& heap) {
    Participant result = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    sift_down(heap, 1);
    return result;
}

vector<Participant> heapsort(const vector<Participant>& arr) {
  vector<Participant> heap = {Participant()};

  for(const auto& p : arr) {
    heap_add(heap, p);
  }
  
  vector<Participant> sorted_arr;
  while (heap.size() > 1)
  {    
    sorted_arr.push_back(pop_max(heap));
  }

  return sorted_arr;
}

int main() {
  vector<Participant> participants = heapsort(read_input());

  for (const auto& p : participants) {
    std::cout << p.login << endl;
  }

  return 0;
}