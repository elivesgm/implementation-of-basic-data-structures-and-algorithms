## build
```shell
g++ -std=c++11 01knapsack.cpp -o 01knapsack
```

## run and test
```shell
./01knapsack
5
10
2 2 6 5 4
6 3 5 4 6
INPUT:
 N=5
 M=10
 w=0 2 2 6 5 4
 v=0 6 3 5 4 6
OUTPUT:
 Result = DEBUG:
0 0 0 0 0 0 0 0 0 0 0
0 0 6 6 6 6 6 6 6 6 6
0 0 6 6 9 9 9 9 9 9 9
0 0 6 6 9 9 9 9 11 11 14
0 0 6 6 9 9 9 10 11 13 14
0 0 6 6 9 9 12 12 15 15 15
15
```
