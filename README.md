# push-swap
## ✨ Features
Program that sorts stacks using radix sort
- Uses two stacks `a` and `b` (vector arrays)
- Parses user input and checks for duplicates with a hashtable
- Sorts the stacks with `pb`, `pa`, `ra`, and `rb` operations

<p align="center">
  <img src="doc/" alt="Demo" />
</p>

## 📖 Introduction

> [!INFO]
> - Only digits are allowed (with a single sign) as input, separated by spaces

> The following are considered errors
> - Numbers less than INT_MIN (-2147483648) or greater than INT_MAX (2147483647)
> - Empty argument, e.g. " "
> - Duplicate numbers
> - Leading or trailing non-digit characters, e.g. "a1" "2b"

> [!TIP]
> ## 🚀 How to use
- Run the following command to clone the repository and create `push_swap` program
``` git
git clone https://github.com/mordori/push-swap.git push-swap && cd push-swap && make
```
- Execute the program with numbers in a random order, for example
``` bash
./push_swap -4 7 -10 2 5 1 -8
./push_swap "2 3 1" "6 9 7" 5 8 4
```

> [!TIP]
> Use `shuf` to generate `n` numbers from a range in a randomized order
> ``` bash
> ./push_swap $(shuf -i 0-100 -n 10)
> ```

The program will sort the numbers and print the called operations.

- To delete all of the compiled files, use
``` Makefile
make fclean
```
