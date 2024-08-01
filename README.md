# **Basic algorithms**
Solving algorithmic problems in C++

## 1. Introduction to Algorithms 
[contest.yandex.ru](https://contest.yandex.ru/contest/22449/problems/)
<details>
  **<summary>Nearest zero[nearest_zero.cpp](https://github.com/Attii/Algorithms-and-Data-Structures/blob/main/sprint1/nearest_zero.cpp)</summary>**
  <br>
  Task
  Timofey is looking for a place to build a house. The street where he wants to live has a length of \( n \), meaning it consists of \( n \) identical consecutive plots. Each plot is either empty or already has a house built on it.

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
