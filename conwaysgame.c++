#include <iostream>
#include <vector>

using namespace std;

class GameOfLife {
private:
    int width;
    int height;
    vector<vector<int>> grid;

public:
    GameOfLife(int width, int height) : width(width), height(height), grid(width, vector<int>(height, 0)) {}

    void setInitialState() {
        cout << "Enter the initial state of the grid (0 for dead, 1 for alive):" << endl;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cin >> grid[i][j];
            }
        }
    }

    int countNeighbours(int x, int y) {
        int neighbours = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    neighbours += grid[nx][ny];
                }
            }
        }
        return neighbours;
    }

    void evolve() {
        vector<vector<int>> newGrid(width, vector<int>(height, 0));
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                int neighbours = countNeighbours(x, y);
                if (grid[x][y] == 1) {
                    if (neighbours < 2 || neighbours > 3) {
                        newGrid[x][y] = 0;
                    } else {
                        newGrid[x][y] = 1;
                    }
                } else {
                    if (neighbours == 3) {
                        newGrid[x][y] = 1;
                    }
                }
            }
        }
        grid = newGrid;
    }

    void printGrid() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    void runSimulation(int numSteps) {
        for (int i = 0; i < numSteps; i++) {
            printGrid();
            evolve();
        }
    }
};

int main() {
    int width, height, numSteps;
    cout << "Enter the width and height of the grid: ";
    cin >> width >> height;
    cout << "Enter the number of steps to simulate: ";
    cin >> numSteps;

    GameOfLife game(width, height);
    game.setInitialState();
    game.runSimulation(numSteps);

    return 0;
}