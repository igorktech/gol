#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 30

const char *palette[2] = {"153;51;255", "204;204;255"};

int count_neighbours(int h, int w, bool grid[h][w], int i, int j);
void show(int h, int w, bool grid[h][w]);
void evolve(int h, int w, bool grid[h][w]);
void run_engine(int h, int w);

int main(int argc, char *argv[])
{
    int width = -1;
    int height = -1;

    int opt;
    while ((opt = getopt(argc, argv, "w:h:")) != -1) {
        switch (opt) {
            case 'w':
                width = atoi(optarg);
                break;
            case 'h':
                height = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s -w <width> -h <height>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (width == -1)
        width = GRID_SIZE;

    if (height == -1)
        height = GRID_SIZE;

    srand(time(NULL));

    run_engine(height, width);

    return 0;
}

int count_neighbours(int h, int w, bool grid[h][w], int i, int j)
{
    int count = 0;
    for (int row = i - 1; row <= i + 1; row++) {
        for (int col = j - 1; col <= j + 1; col++) {
            if (row == i && col == j)
                continue;
            int row_idx = (row + h) % h;
            int col_idx = (col + w) % w;
            count += grid[row_idx][col_idx];
        }
    }
    return count;
}

void show(int h, int w, bool grid[h][w])
{
    printf("\033[H");
    for (int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            printf("\033[48;2;%sm",palette[grid[row][col]]); // background 
            printf("\033[38;2;%sm",palette[grid[row][col]]); // foreground
            printf("██"); // full block 
        }
        printf("\033[49m\n");
    }
    fflush(stdout);
}

void evolve(int h, int w, bool grid[h][w])
{
    bool buffer[h][w];
    char neighbours = 0;
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++)
        {
            neighbours = count_neighbours(h, w, grid, i, j);
            buffer[i][j] = (neighbours == 3 || (neighbours == 2 && grid[i][j]));
        }

    for (int i = 0; i < h; i++) 
        for (int j = 0; j < w; j++)
            grid[i][j] = buffer[i][j];
}

void run_engine(int h, int w)
{
    bool grid[h][w];

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            grid[row][col] = rand() % 2;
        }
    }
    // glider
    /* grid[1][3] = 1; */
    /* grid[2][4] = 1; */
    /* grid[3][2] = 1; */
    /* grid[3][3] = 1; */
    /* grid[3][4] = 1; */

    printf("\033[2J");
    for (;;)
    {
        show(h, w, grid);
        evolve(h, w, grid);
        usleep(100000);
    }
}

