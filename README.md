# About Matrix Game

Welcome to the Matrix Game! This puzzle game challenges players to slide tiles on a grid to arrange them in the correct order. With various levels of difficulty and sub-levels, it offers a stimulating experience suitable for players of all skill levels.

## Instructions

To control the game, use the following keys:

- **Move Right:** Press `D`
- **Move Left:** Press `A`
- **Move Up:** Press `W`
- **Move Down:** Press `S`

## Game Levels and Sub-Levels

### Levels

1. **Level 1:** 40 moves
2. **Level 2:** 35 moves
3. **Level 3:** 30 moves

### Sub-Levels

- **Easy:** 3x3 grid
- **Medium:** 4x4 grid
- **Hard:** 5x5 grid

## Functions Overview

Here's an overview of the main functions used in the game:

- `random_assign(int** array, int min, int max, int length)`: Assigns random numbers to the grid while ensuring no duplicates.
- `match(int** array, int length)`: Checks if the current arrangement of tiles matches the winning position.
- `display(int** array, int length)`: Displays the grid in a readable format.
- `algorithm(int** array, char direction, int length)`: Moves the blank space in the specified direction and updates the grid.
- `assign_num(int** array, int length)`: Assigns the winning numbers to the grid in ascending order.
- `check_boundary(int** array, int length)`: Checks if the blank space is within the grid boundaries after a move.
- `free_memory(int** array, int length)`: Frees the dynamically allocated memory used for the grid.
- `is_unique(int** array, int length, int i, int j, int rand_num)`: Checks if a number is unique within the grid.

## How to Play

1. **Choose a Level:** Select your preferred level (1 to 3) with different move limits.
2. **Select a Sub-Level:** Choose the grid size (Easy, Medium, Hard).
3. **Start the Game:** Press enter to begin and make moves using `W`, `A`, `S`, `D`.
4. **Win Condition:** Arrange the tiles in ascending order to win.
5. **Next Level:** If you win, you can proceed to the next level or sub-level.

## Enjoy the Challenge!

Matrix Game is designed to test your logical thinking and puzzle-solving skills. We hope you enjoy playing and find the challenge both fun and rewarding.

Feel free to contribute to the project on [GitHub](https://github.com/your-repo-link). Your feedback and suggestions are always welcome!
