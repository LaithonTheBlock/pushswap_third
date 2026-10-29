*This activity has been created as part of the 42 curriculum by lnazzal, oalroyei.*

# PushSwap

## Description

**PushSwap** The PushSwap project is part of the 42 curriculum. PushSwap is a sorting project with a restricted set of tools.
The program receives a list of unique integers and must sort them in ascending order using two stacks, 
**A** and **B**, and only these 11 operations:

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | Swap the first two elements of A / B / both |
| `pa` / `pb` | Push the top element of B onto A / of A onto B |
| `ra` / `rb` / `rr` | Rotate A / B / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | Rotate A / B / both down (last element becomes first) |

## Instructions

### Compilation

```bash
make        # builds the push_swap executable
make clean  # removes object files
make fclean # removes object files and the executable
make re     # fclean followed by make
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```bash
./push_swap [flags] <numbers>
```

Numbers can be given as separate arguments or as one quoted string:

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap 5 4 "3 2" 1
```

The program prints the list of operations that sorts stack A to **stdout**, one per line. 
The available operations are `sa sb ss pa pb ra rb rr rra rrb rrr`.

### Flags

| Flag | Effect |
|---|---|
| `--simple` | Force the simple strategy (selection sort, O(n²)) |
| `--medium` | Force the medium strategy (chunk sort, O(n√n)) |
| `--complex` | Force the complex strategy (radix sort, O(n log n)) |
| `--adaptive` | Choose the strategy automatically (default) |
| `--bench` | Print statistics to **stderr** after sorting |

Flags can be placed anywhere in the arguments.

### Adaptive mode

The program measures the disorder of the input (the number of inversions divided by the maximum possible number of inversions, from 0 to 1) and picks a strategy:

- 5 numbers or fewer: simple
- disorder below 0.2: simple
- disorder from 0.2 to below 0.5: medium
- disorder of 0.5 or more: complex

### Bench output

With `--bench`, the following is written to stderr, so stdout still contains only the operations:

```
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Errors

On invalid input (non-numeric values, duplicates, values outside the `int` range, or an empty string), the program prints `Error` to stderr and exits with status 1. With no arguments, or if the input is already sorted, it prints nothing.

### Testing

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG   # should print OK
./push_swap $ARG | wc -l                  # number of operations
./push_swap --bench $ARG 2>&1 >/dev/null  # bench output only
valgrind --leak-check=full ./push_swap $ARG
```

## Resources

This project was built using the following references:
* 42 PushSwap Subject Manual
* GeeksforGeeks
* Stack Overflow
* Reddit & Various Online Programming Forums

### AI Usage Policy

**AI was used** to check code formatting compliance (Norminette).
**AI was NOT used** to generate full function logic or answers.

## Additional

### Why these algorithms

The project asks for several strategies, so we picked one algorithm for each level of complexity and a helper that they share. The adaptive mode uses the disorder metric to choose between them.

**Tiny sort (3 elements)**
Three numbers have only six possible orderings, so we handle them directly instead of using a general algorithm. It needs at most 2 operations, so it can't be beaten. It is also the base case of the selection sort: once only 3 numbers are left in stack A, we finish with it.

**Selection sort (simple, O(n²))**
Selection sort is the easiest algorithm to understand and verify. We find the smallest number in A, rotate it to the top by the shorter direction (`ra` or `rra`), push it to B, and repeat until 3 numbers are left. Then we sort those with tiny sort and push everything back. Its cost grows quickly with the input size, which is why it is only used for small inputs (5 numbers or fewer) and for nearly sorted input (disorder below 0.2), where the cost is acceptable and the simple logic is an advantage.

**Chunk sort (medium, O(n√n))**
Chunk sort pushes numbers to B in ranges (chunks) based on their sorted rank. Numbers that are small enough go to B, and the rest are rotated past. Pushing back is then efficient: we always bring the largest number in B to the top, using `rb` or `rrb` depending on which is shorter, and `pa` it to A. This is much cheaper than selection sort on large inputs, and it handles partly sorted input well, so we use it for medium disorder (0.2 to below 0.5). The chunk size is `size / 5 + 1` for up to 100 numbers and `size / 11 + 1` above that. We chose these values by testing.

**Radix sort (complex, O(n log n))**
Radix sort never compares two numbers. It looks at one bit of each number's rank at a time, from the lowest bit to the highest. Numbers whose bit is 0 go to B (`pb`), the others are rotated (`ra`), and then everything is pushed back (`pa`). The number of operations depends only on the size of the input, not on its order, so it gives a predictable result. That makes it the right choice for highly disordered input (0.5 or more), where the other strategies lose their advantage.

**Index normalisation (`index_stack`)**
Before sorting, each number is replaced by its rank (0 to n-1) in the `current` field. Radix sort and chunk sort rely on this: radix needs small non-negative numbers so that it works on a few bits, and chunk sort needs consecutive numbers to build its ranges. It also means that negative numbers and large gaps between values cause no problems.

### Why adaptive mode

No single algorithm is the best for every input. Selection sort is fine for small or nearly sorted input, chunk sort is a good balance for medium input, and radix sort wins when the input is badly shuffled. The adaptive mode measures the disorder (inversions divided by the maximum possible inversions) and picks the matching strategy, so the program does not have to use one algorithm for everything. The `--simple`, `--medium` and `--complex` flags override this choice, and `--bench` shows which strategy was used and how many operations it needed.
