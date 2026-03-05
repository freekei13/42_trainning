*This project has been created as part of the 42 curriculum by [csamakka].*

## Description

Philosophers is a 42 school project based on the classic **Dining Philosophers Problem**, originally formulated by Edsger Dijkstra in 1965.

The goal is to simulate a group of philosophers sitting at a round table, each alternating between three states: **eating**, **sleeping**, and **thinking**. A fork is placed between each pair of adjacent philosophers. To eat, a philosopher must pick up both forks next to them — but forks are shared resources.

The challenge is to manage concurrent access to these shared resources using **threads** and **mutexes**, while ensuring:
- No philosopher **starves** (dies of hunger)
- No **deadlock** occurs
- No **data race** corrupts the simulation

Each philosopher runs in its own thread, and a dedicated **reaper thread** monitors deaths and meal counts.

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time in ms before a philosopher dies if they haven't started eating |
| `time_to_eat` | Time in ms a philosopher spends eating |
| `time_to_sleep` | Time in ms a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops when all philosophers have eaten this many times |

### Examples

```bash
# 5 philosophers, no one should die
./philo 5 800 200 200

# 4 philosophers, someone will die
./philo 4 310 200 200

# 5 philosophers, stops after each has eaten 5 times
./philo 5 800 200 200 5

# 1 philosopher, takes a fork and dies
./philo 1 800 200 200
```

### Notes

- All time values are in **milliseconds**
- The simulation stops as soon as a philosopher dies, or when all philosophers have eaten the required number of times
- Arguments must be positive integers between `1` and `2147483647`

## Resources

### Documentation & Articles

- [42 Philosophers Guide — Medium](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)
- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [pthread_mutex_lock — Linux man page](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html)
- [gettimeofday — Linux man page](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- [Helgrind: a thread error detector — Valgrind docs](https://valgrind.org/docs/manual/hg-manual.html)
- [42 Cursus Philosophers Guide — GitBook](https://42-cursus.gitbook.io/guide/3-rank-03/philosophers)
- [42_philosophers reference implementation — PedroZappa](https://github.com/PedroZappa/42_philosophers)