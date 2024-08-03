# **Basic algorithms**
Solving algorithmic problems in C++

## 1. Introduction to Algorithms 
[contest.yandex.ru](https://contest.yandex.ru/contest/22449/problems/)

<details><summary>Nearest zero (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint1/nearest_zero.cpp">nearest_zero.cpp</a>)</summary>
  <br>
  
### Task
  
  Timofey is looking for a place to build a house. The street where he wants to live has a length of n, meaning it consists of n  identical consecutive plots. Each plot is either empty or already has a house built on it.

Sociable Timofey does not want to live far from other people on this street. Therefore, it is important for him to know the distance from each plot to the nearest empty plot. If the plot is empty, this distance will be zero — the distance to itself.

Help Timofey calculate these distances. For this, you have a map of the street. Houses in Timofey's city were numbered in the order they were built, so their numbers on the map are unordered. Empty plots are marked with zeros.

### Input Format
The first line contains the length of the street — \( n \) (1 ≤ \( n \) ≤ \( 10^6 \)). The next line contains \( n \) non-negative integers — house numbers and designations of empty plots on the map (zeros). It is guaranteed that there is at least one zero in the sequence. House numbers (positive integers) are unique and do not exceed \( 10^9 \).

### Output Format
For each of the plots, output the distance to the nearest zero. Print the numbers in one line, separated by spaces.

### Example 1
**Input**
```
5
0 1 4 9 0
```
**Output**
```
0 1 2 1 0
```

### Example 2
**Input**
```
6
0 7 9 4 8 20
```
**Output**
```
0 1 2 3 4 5
```
</details>

<details>
  <summary>Sleight of hand (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint1/sleight_of_hand.cpp">sleight_of_hand.cpp</a>)</summary>

  <br>

  ### Task

  The game "Speed Typing Trainer" consists of a 4x4 field of keys, which either have a dot or a digit from one to nine. The essence of the game is as follows: in each round, a combination of digits and dots appears on the field. At time \( t \), the player must simultaneously press all the keys that have the digit \( t \).

If at time \( t \) all the required keys are pressed, the players score one point. If there are no keys with the digit \( t \) on the field, no point is awarded.

Two players can press \( k \) keys each at the same time. Determine the number of points Gosha and Timofey can earn if they press the keys together. Let's consider Example 1, where \( k = 3 \).

Suppose \( t = 1 \). In this case, one player must press two keys with the digit 1. To find out how many keys two players will press, use the formula: \( k \times 2 \). It turns out that together the boys will press six keys and earn a point.

When \( t = 2 \), the two players need to press seven keys simultaneously. But this is not possible for the guys: each can press only three keys. No point is awarded.

At \( t = 3 \), each player needs to press one key. Success! Now Gosha and Timofey have two points.

There are no other digits on the field. Therefore, in the next rounds, where \( t = 4 \ldots t = 9 \), no points will be awarded. Thus, Gosha and Timofey will earn two points.

Determine the number of points Gosha and Timofey can earn if they press the keys together.

### Input Format
The first line contains an integer \( k \) (1 ≤ \( k \) ≤ 5).

The next four lines represent the appearance of the trainer — 4 characters in each line. Each character is either a dot or a digit from 1 to 9. The characters in one line are consecutive and not separated by spaces.

### Output Format
Print a single number — the maximum number of points that Gosha and Timofey can score.

### Example 1
**Input**
```
3
1231
2..2
2..2
2..2
```
**Output**
```
2
```

### Example 2
**Input**
```
4
1111
9999
1111
9911
```
**Output**
```
1
```

### Example 3
**Input**
```
4
1111
1111
1111
1111
```
**Output**
```
0
```
</details>

## 2. Basic structures
[contest.yandex.ru](https://contest.yandex.ru/contest/22779/problems/)

<details>
  <summary>Deque (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint2/my_sized_deque.cpp">my_sized_deque.cpp</a>)</summary>
  
  <br>

### Task
Gosha implemented a data structure called Deque (double-ended queue), where the maximum size is determined by a given number. The methods `push_back(x)`, `push_front(x)`, `pop_back()`, and `pop_front()` worked correctly. However, if the deque had many elements, the program ran very slowly. The problem was that not all operations were performed in O(1) time complexity. Help Gosha! Write an efficient implementation.

Attention: Use a circular buffer for the implementation.

### Input format
The first line contains the number of commands `n` — an integer not exceeding 100,000. The second line contains the number `m` — the maximum size of the deque. It does not exceed 50,000. The next `n` lines contain one of the following commands:

- `push_back(value)` – add an element to the end of the deque. If the deque already contains the maximum number of elements, output "error".
- `push_front(value)` – add an element to the beginning of the deque. If the deque already contains the maximum number of elements, output "error".
- `pop_front()` – output the first element of the deque and remove it. If the deque was empty, output "error".
- `pop_back()` – output the last element of the deque and remove it. If the deque was empty, output "error".

`Value` is an integer not exceeding 1000 in absolute value.

### Output format
Output the result of each command on a separate line. For successful `push_back(x)` and `push_front(x)` commands, do not output anything.

### Example 1

#### Input
```plaintext
4
4
push_front 861
push_front -819
pop_back
pop_back
```

#### Output
```plaintext
861
-819
```

### Example 2

#### Input
```plaintext
7
10
push_front -855
push_front 0
pop_back
pop_back
push_back 844
pop_back
push_back 823
```

#### Output
```plaintext
-855
0
844
```

### Example 3

#### Input
```plaintext
6
6
push_front -201
push_back 959
push_back 102
push_front 20
pop_front
pop_back
```

#### Output
```plaintext
20
102
```
</details>

<details><summary>Calculator (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint2/polish_calculator.cpp">polish_calculator.cpp</a>)</summary>
  <br>

  ### Task 

The task is related to reverse Polish notation. It is used for parsing arithmetic expressions. It is also sometimes called postfix notation.

In postfix notation, operands are located before the operators.

Example 1:
```
3 4 +
```
means 3 + 4 and equals 7.

Example 2:
```
12 5 /
```
Since division is integer division, the result is 2.

Example 3:
```
10 2 4 * -
```
means 10 - 2 * 4 and equals 2.

Let's analyze the last example in more detail:

The * sign is immediately after the numbers 2 and 4, so the operation indicated by this sign must be applied to them, that is, multiply these two numbers. As a result, we get 8.

After that, the expression becomes:

```
10 8 -
```
The "minus" operation must be applied to the two preceding numbers, that is, 10 and 8. As a result, we get 2.

Let's consider the algorithm in more detail. To implement it, we will use a stack.

To calculate the value of an expression written in reverse Polish notation, you need to read the expression from left to right and follow these steps:

1. **Process the input symbol**:
   - If an operand is encountered, it is placed on the top of the stack.
   - If an operation sign is encountered, the operation is performed on the required number of values taken from the stack in the order they were added. The result of the performed operation is placed on the top of the stack.
2. **If the input set of characters is not fully processed, go back to step 1**.
3. **After fully processing the input set of characters, the result of the expression calculation is on the top of the stack**. If there are several numbers left in the stack, only the top element should be output.

**Note about negative numbers and division**: In this task, division is understood as mathematical integer division. This means that rounding always occurs downwards. Specifically, if `a / b = c`, then `b ⋅ c` is the largest number that does not exceed `a` and is simultaneously divisible by `b`.

For example, `-1 / 3 = -1`. Be careful: in C++, Java, and Go, for instance, division works differently.

In the current task, it is guaranteed that there is no division by a negative number.

### Input Format
The single line contains an expression written in reverse Polish notation. Numbers and arithmetic operations are separated by spaces.

The input may include the operations: `+`, `-`, `*`, `/` and numbers, whose absolute value does not exceed 10000.

It is guaranteed that the value of intermediate expressions in the test data does not exceed 50000 in absolute value.

### Output Format
Output a single number — the value of the expression.

### Example 1

**Input**:
```
2 1 + 3 *
```

**Output**:
```
9
```

### Example 2

**Input**:
```
7 2 + 4 * 2 +
```

**Output**:
```
38
```
  
</details>

## 3. Recursion and sorting
[contest.yandex.ru](https://contest.yandex.ru/contest/23638/problems/)

<details><summary>Search in a broken array (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint3/broken_search.cpp">broken_search.cpp</a>)</summary>
<br>

  ### Task 

Alla made a mistake when copying data from one data structure to another. She stored an array of numbers in a circular buffer. The array was sorted in ascending order, allowing elements to be found in logarithmic time. Alla copied the data from the circular buffer to a regular array but shifted the data of the original sorted sequence (the array could still remain sorted). Nonetheless, it's necessary to ensure the ability to find an element in it in O(log n) time.
You can assume that the array contains only unique elements.
You are required to implement a function that performs the search in the broken array. Note that reading data and printing the answer is not required.

### Input format
The function accepts an array of natural numbers and a target number k. The length of the array does not exceed 10000. The elements of the array and the number k do not exceed 10000 in value.
In the examples:
The first line contains the number n — the length of the array.
The second line contains a positive number k — the target element.
In the next line, n natural numbers are given separated by spaces — the elements of the array.

### Output format
The function should return the index of the element equal to k if it is present in the array (indexing starts from zero). If the element is not found, the function should return -1.
The array cannot be modified.
To filter out inefficient solutions, your function will be run from 10000 to 1000000 times.

### Example 1

**Input**:
```
9
5
19 21 100 101 1 4 5 7 12
```

**Output**:
```
6
```

### Example 2

**Input**:
```
2
1
5 1
```

**Output**:
```
1
```
</details>
