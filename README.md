# 🚀 Push Swap

> An algorithm project to sort data using a limited set of instructions and two stacks.

---

## 🎯 Project Goals

This project is a pure **algorithmic challenge**. The goal is to sort a given list of numbers using two stacks (`a` and `b`) and a restricted set of operations (like `sa`, `pb`, `ra`, `rrb`, etc.). The challenge is not just to sort them, but to do so in the **fewest possible moves**, forcing a deep dive into sorting algorithms, data structures, and optimization.

## 🛠️ Technical Details

* **Two-Stack Algorithm:** All operations are based on moving numbers between stack `a` (the start) and stack `b` (a temporary buffer) to eventually have stack `a` sorted.
* **Instruction Set:** Implements the 11 allowed operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
* **Sorting Logic:** The core of the project. This involves creating an efficient algorithm (often based on concepts like Radix Sort or "Turk" algorithms) to decide the optimal sequence of moves to sort the stack.
* **Argument Handling:** The program correctly parses input given as a series of numbers in one or multiple arguments.
* **Bonus Checker:** The repository also includes a `checker` program (in the `bonus` folder) that reads instructions from standard input to verify if a list of moves successfully sorts the stack.

## ⚙️ How to Compile & Run

1.  Clone the repository:
    ```bash
    git clone [https://github.com/carlopezc/Push_swap.git](https://github.com/carlopezc/Push_swap.git)
    cd Push_swap
    ```
2.  Compile the project:
    ```bash
    make
    ```
    This will create the main executable `push_swap`. (It also creates the `checker` executable for the bonus).

3.  Run the program with a list of numbers:
    ```bash
    # The arguments can be space-separated numbers
    ./push_swap 4 67 3 8 2

    # Or a single string argument
    ./push_swap "4 67 3 8 2"
    ```
    The program will output the list of instructions (like `pb`, `ra`, `sa`) required to sort the numbers.

### Bonus Checker (Opcional)

You can test the output of your `push_swap` by piping it into the `checker`:

```bash
ARG="4 67 3 8 2"; ./push_swap $ARG | ./checker $ARG
