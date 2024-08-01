# **Basic algorithms**
Solving algorithmic problems in C++

## 1. Introduction to Algorithms 
[contest.yandex.ru](https://contest.yandex.ru/contest/22449/problems/)

<details>
  <summary>Nearest zero (<a href="https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint1/nearest_zero.cpp">nearest_zero.cpp</a>)</summary>
 
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
