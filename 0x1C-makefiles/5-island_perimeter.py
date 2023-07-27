#!/usr/bin/python3
"""Module that calculates the perimeter of an island in a grid."""

def island_perimeter(grid):
    perimeter = 0

    rows = len(grid)
    cols = len(grid[0])

    # Iterate through each cell in the grid
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # Check if the cell is a land zone
                # Check top neighbor
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1  # Increment perimeter if the top neighbor is water or out-of-bounds

                # Check bottom neighbor
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1  # Increment perimeter if the bottom neighbor is water or out-of-bounds

                # Check left neighbor
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1  # Increment perimeter if the left neighbor is water or out-of-bounds

                # Check right neighbor
                if j == cols - 1 or grid[i][j + 1] == 0:
                    perimeter += 1  # Increment perimeter if the right neighbor is water or out-of-bounds

    return perimeter
