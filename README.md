# push-swap
## ✨ Features
brief
-

<p align="center">
  <img src="doc/" alt="Demo" />
</p>

## 📖 Introduction


> [!TIP]
> ## 🚀 How to use
- Run the following command to clone the repository and create `push_swap` program
``` git
git clone https://github.com/mordori/push-swap.git push-swap && cd push-swap && make
```
- Execute the program with numbers in random order, for example
``` bash
./push_swap -4 7 -10 2 5 1 -8
```

> [!TIP]
> Use shuf to generate `n` numbers from a range in randomized order
> ``` bash
> ./push_swap $(shuf -i -100-100 -n 10)
> ```

The program will print the called operations and output the total amount in the end

- To delete all of the compiled files, use
``` Makefile
make fclean
```
