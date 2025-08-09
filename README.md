# push_swap
## ✨ Features
Program that sorts a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) in ascending order using indexed least significant digit (LSD) [radix sort](https://en.wikipedia.org/wiki/Radix_sort).

The goal of the project was not computational efficiency, but to minimize the number of operations performed.
- Uses two LIFO (Last In — First Out) stacks `a` and `b` (vector arrays)
- Parses and validates user input for duplicates with a hashtable
- Indexes the numbers using insertion sort with a temporary copy
- Sorts the stacks with `pb`, `pa`, `sa`, `ra`, and `rra` operations
- Worst-case [time complexity](https://en.wikipedia.org/wiki/Time_complexity) is $O(n^2)$ with insertion sort as the dominant term
- [Space complexity](https://en.wikipedia.org/wiki/Space_complexity) is $O(n)$
- Very stable — sorts 100 numbers in fewer than 1,100 operations and 500 numbers in fewer than 7000 operations under all conditions

## 📖 Introduction

> [!NOTE]
> ## 🔡 Input
✔ Only `digits` are allowed (with a single sign) as input, separated by `spaces`

The following are considered errors:

&nbsp;&nbsp;&nbsp;&nbsp;❌ Numbers less than `INT_MIN` (-2147483648) or greater than `INT_MAX` (2147483647)

&nbsp;&nbsp;&nbsp;&nbsp;❌ Empty argument, e.g. `" "`

&nbsp;&nbsp;&nbsp;&nbsp;❌ Duplicate numbers

&nbsp;&nbsp;&nbsp;&nbsp;❌ Leading or trailing non-digit characters, e.g. `"a1" "2b"`

> [!TIP]
> ## 🚀 How to use
- Run the following command to clone the repository and create `push_swap` program
``` git
git clone https://github.com/mordori/push_swap.git push_swap && cd push_swap && make
```
- Execute the program with numbers in a random order, for example
``` bash
./push_swap -4 7 -102 2 5 0 1 -8
```
or
``` bash
./push_swap "2 3 1" "6 9 7" 5 8 4
```

> [!TIP]
> Use `shuf` to generate `n` unique numbers from a range in a randomized order
> ``` bash
> ./push_swap $(shuf -i 0-100 -n 10)
> ```
> To count the amount of instructions used, pipe to `wc`
> ``` bash
> ./push_swap $(shuf -i 0-100 -n 10) | wc -l
> ```

The program will sort the numbers and print out the called operations.

- To delete all of the compiled files, use
``` Makefile
make fclean
```
