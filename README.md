# Big-O Through Operation Counts

This lab measures how operation counts grow as the input size increases. The
implementation is in [main.cpp](main.cpp) and uses the required input sizes
`10`, `100`, `500`, and `2000`.

## Build and Run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o big_o_counts
./big_o_counts
```

## Results

The program produces these counter values:

| Input size `n` | `directAccess()` | `oneLoop()` | `divideBy2()` | `insideLoopD2()` | `nestedLoop()` |
|---:|---:|---:|---:|---:|---:|
| 10 | 1 | 10 | 3 | 30 | 100 |
| 100 | 1 | 100 | 6 | 600 | 10,000 |
| 500 | 1 | 500 | 8 | 4,000 | 250,000 |
| 2,000 | 1 | 2,000 | 10 | 20,000 | 4,000,000 |

## Complexity

1. `directAccess()` - **O(1)**
2. `oneLoop()` - **O(n)**
3. `divideBy2()` - **O(log n)**
4. `insideLoopD2()` - **O(n log n)**
5. `nestedLoop()` - **O(n^2)**

`divideBy2()` performs one division per iteration until the value is at most
1. `insideLoopD2()` repeats that logarithmic process for each of the `n`
outer-loop iterations, producing `n * floor(log2(n))` counted operations for
these inputs.