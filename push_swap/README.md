*This project has been created as part of the 42 curriculum by <csamakka>*

**Description**
--
There are 2 stacks : stack a et stack b.

The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at disposal: **sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb,
rrr.**

- **sa** (swap a): Swap the first 2 elements at the top of stack a.
    - Do nothing if there is only one element or none.
- **sb** (swap b): Swap the first 2 elements at the top of stack b.
    - Do nothing if there is only one element or none.
- **ss** : sa and sb at the same time.
- **pa** (push a): Take the first element at the top of b and put it at the top of a.
    - Do nothing if b is empty.
- **pb** (push b): Take the first element at the top of a and put it at the top of b.
    - Do nothing if a is empty.
- **ra** (rotate a): Shift up all elements of stack a by 1.
    - The first element becomes the last one.
- **rb** (rotate b): Shift up all elements of stack b by 1.
    - The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** (reverse rotate a): Shift down all elements of stack a by 1.
    - The last element becomes the first one.
- **rrb** (reverse rotate b): Shift down all elements of stack b by 1.
    - The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

**Instructions**
--
type ***make*** in the terminal for compiling the program **push_swap**.
```
make
```

To execute the program : 
```
./push_swap "3 1 2"
```
```
./push_swap 3 1 2
```
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
**Resources**
--
- 42 gitbook - https://42-cursus.gitbook.io/guide/
- Chatgpt - To explain Turkish sort.
    - I give AI an instruction to guide me through explainations without final code.
- Students