# philosophers
A multithread simulation in C

![ezgif com-gif-maker](https://user-images.githubusercontent.com/31427890/151238802-1a51feed-a5ac-4fc8-8f48-c3c7c77da95a.gif)

## 🗂 Table of Contents
* [About](#-about)
* [Getting Started](#-getting-started)
* [How to Use](#-how-to-use)
* [Bibliography](#-bibliography)
* [42 École | 42 São Paulo](#-42-école--42-são-paulo)

## 🧐 About
The objective of this project is to create a multithread program that simulates a dinner where a 'philosopher' (thread) can eat
only if he can get two forks (there is a fork for each philosopher). After eating, the philosopher should sleep then start to think
and try to get two forks again. The simulation stops if a philosopher doesn't eat at a given (tiem_to_die) time or eat the maximum number of meals.

The project can be resumed in the following chart:

![philosopher_chart](https://user-images.githubusercontent.com/31427890/151245142-25df8aee-86cd-4ea4-9bdd-ad325695e188.png)
*chart made by: Paulo Cunha*

This project is part of 42 École/ 42 SP curriculum.\
Topics such as parallelism, multithreading and mutexes were addressed.

## 🏁 Getting Started
A Linux OS and the `gcc` compiler are needed.

#### ⚙️ Installing
To compile the code, clone the repo, and run the following commands.
```
$ git clone https://github.com/filipebafica/philosophers.git
$ cd philosophers
$ make
```
This is going to generate an executable named `philo`.

## 🎈 How to Use
Run the `philo` executable passing the arguments:
* number_of_philosophers 
* time_to_die 
* time_to_eat 
* time_to_sleep
* [number_of_times_each_philosopher_must_eat]

```
$ ./philo 5 800 200 200 7
```

## 📜 Bibliography
* [Unix Threads in C](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
* [Multithreading Code](https://www.youtube.com/watch?v=7ENFeb-J75k)

## 🏫 42 École | 42 São Paulo
42 École is a network of tech schools spread around the world where anyone can learn how to code for free.\
At 42 there are no teachers or classrooms, each student learns from and works with each other (peer-to-peer learning).\
To see more go to https://www.42.fr/ and https://www.42sp.org.br/.
