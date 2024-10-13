# 42-Philosophers

The **Philosophers** project is a well-known problem in concurrent programming. It demonstrates challenges like **deadlock**, **starvation**, and **mutexes** in multithreaded environments. The objective is to synchronize philosophers who alternately think, eat, and sleep, without causing a deadlock.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Implementation Details](#implementation-details)
- [Directory Structure](#directory-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Project Rules](#project-rules)
- [Authors](#authors)

## Project Description

In the **Philosophers** project, several philosophers are seated around a table, with a bowl of spaghetti in the center. Each philosopher has two forks but can only eat when holding both forks at the same time. The challenge is to prevent **deadlock** (where no philosopher can proceed) and ensure that all philosophers can eat without starving.

### Problem Breakdown:
1. Philosophers alternate between **eating**, **sleeping**, and **thinking**.
2. Philosophers can only eat if they can pick up both forks (one from the left and one from the right).
3. After eating, they place the forks back on the table and proceed to sleep, then think.

This project requires implementing a multithreaded solution that handles the synchronization between philosophers, ensuring that deadlocks are avoided and that every philosopher has the opportunity to eat.

## Features

- **Multithreading**: Each philosopher is represented by a separate thread.
- **Mutexes**: Used to handle access to shared resources (forks) and prevent race conditions.
- **Deadlock Prevention**: Ensures that no deadlock occurs, and philosophers are able to eat without causing indefinite blocking.
- **Custom Timing**: The project allows for the configuration of time for eating, sleeping, and thinking.

## Implementation Details

The program is implemented using **threads** and **mutexes** to solve the concurrency problem. Key components include:
- **Philosopher Threads**: Each philosopher is managed by a separate thread.
- **Mutex Locks**: Used to control access to the forks and ensure synchronization between philosophers.
- **State Logging**: The state of each philosopher (eating, thinking, or sleeping) is logged, along with a timestamp to track progress.

## Directory Structure

```plaintext
.
├── Makefile
├── includes
│   └── philo.h
├── src
│   ├── philo.c
│   ├── utils
│   │   ├── cleaner.c
│   │   ├── atoi_isdigit.c
│   │   ├── print_and_exit.c
│   │   └── check_args.c
│   ├── action
│   │   ├── init.c
│   │   ├── forks_and_eat.c
│   │   └── action_utils.c
│   └── main_logic
│       ├── routine.c
│       └── start_monitor.c

```

## Installation

To compile the project, simply run the following commands:
```bash
git clone https://github.com/ashleyfletcher76/42-Philosophers.git
cd 42-Philosophers
make
```
This will generate the executable philo.
## Usage
You can run the project by specifying the number of philosophers and timing configurations:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep - optional [number_of_times_each_philosopher_must_eat]

Example:
```bash
./philo 5 800 200 200
```

This will run the simulation with 5 philosophers, where each philosopher:

    Dies if they don’t start eating within 800 milliseconds.
    Takes 200 milliseconds to eat.
    Sleeps for 200 milliseconds after eating.

## Project Rules

- The project must be written in C.
- Global variables are forbidden.
- Mutexes must be used to prevent philosophers from accessing shared forks simultaneously.
- The program must handle errors (e.g., invalid input or memory issues).
- The simulation must stop when all philosophers have eaten the required number of meals (if specified).

## Authors

- **Ashley Fletcher** - *Developer* - [GitHub Profile](https://github.com/ashleyfletcher76)
