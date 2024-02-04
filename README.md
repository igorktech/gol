# Conway's Game of Life - Terminal Edition

![Game of Life in Action](assets/game-of-life.gif)

This is a terminal implementation of Conway's Game of Life written in C. The game evolves based on simple rules, creating mesmerizing patterns and behaviors.

## Features

-   **Terminal-based:** Play the Game of Life directly in your terminal.
-   **Colorful:** Cells are represented with full blocks and support customizable colors.
-   **Animated:** Watch the evolution of the game over time.

## How to Run

1. Clone the repository:

    ```bash
    git clone https://github.com/igorktech/gol.git
    ```

2. Navigate to the project directory:
    ```bash
    cd gol
    ```
3. Compile the code:
    ```bash
    gcc gol.c -o gol
    ```
4. Run the executable:
    ```bash
    ./gol
    ```

### Optional flags:

-   -w <width>: Set the width of the grid.
-   -h <height>: Set the height of the grid.

Example with custom width and height:

```bash
    ./gol -w 50 -h 50
```
