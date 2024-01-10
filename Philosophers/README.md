## 42 - Philosophers

Philosophers an individual project about introduction to the basics of process threading, and how work on the same memory space.
And learn about mutexes, semaphores, and shared memory.

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in *1965 by Edsger Dijkstra* as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation

[More informations](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

## Usage

```
$ ./philo
Error: Incorrect number of arguments
Usage: ./philo philo_count time_to_die time_to_eat time_to_sleep [option: must_eat_count]
$ ./philo 3 200 50 50 2
0 1 has taken a fork
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
51 3 is sleeping
51 1 has taken a fork
51 1 is eating
51 2 has taken a fork
101 3 is thinking
101 3 has taken a fork
101 1 is sleeping
101 2 has taken a fork
101 2 is eating
151 1 is thinking
151 3 has taken a fork
151 3 is eating
151 2 is sleeping
151 1 has taken a fork
201 2 is thinking
```