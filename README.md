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
and try to get 2 forks again. The simulation stops if a philosopher doesn't eat at a given (tiem_to_die) time or eat the maximum number of meals.

The project can be resumed in the following chart:

![philosopher_chart](https://user-images.githubusercontent.com/31427890/151245142-25df8aee-86cd-4ea4-9bdd-ad325695e188.png)
*chart made by: Paulo Cunha*

This project is part of 42 École/ 42 SP curriculum.\
Topics such as parallelism , multithreading and mutexes were addressed.
