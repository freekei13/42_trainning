*This project has been created as part of the 42 curriculum by [csamakka].*

## Description

Push Swap is a sorting algorithm project using two stacks: **stack a** and **stack b**. The goal is to sort a list of integers into stack a in ascending order, using the fewest possible operations.

The following operations are available:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements of stack a. Does nothing if 0 or 1 element. |
| `sb` | Swap the first 2 elements of stack b. Does nothing if 0 or 1 element. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the top element of stack b and push it to the top of stack a. Does nothing if b is empty. |
| `pb` | Take the top element of stack a and push it to the top of stack b. Does nothing if a is empty. |
| `ra` | Shift all elements of stack a up by 1. The first element becomes the last. |
| `rb` | Shift all elements of stack b up by 1. The first element becomes the last. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | Shift all elements of stack a down by 1. The last element becomes the first. |
| `rrb` | Shift all elements of stack b down by 1. The last element becomes the first. |
| `rrr` | `rra` and `rrb` at the same time. |

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./push_swap "3 1 2"
```

```bash
./push_swap 3 1 2
```

### Verify with checker

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

## Resources

- [42 Cursus GitBook](https://42-cursus.gitbook.io/guide/) — General 42 project guide
- Stack Overflow and various programming blogs
- Fellow 42 students

### AI Usage

**Tool used:** ChatGPT

AI was used to understand the **Turkish sort algorithm**. The AI was instructed to guide through explanations without providing final code, in order to understand the concept and implement it independently.
