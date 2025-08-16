#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 105

typedef struct {
    int x, y;
} Point;

int visited[MAXN][MAXN];
int dist[MAXN][MAXN];
char grid[MAXN][MAXN];

int n;

int isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '.' && !visited[x][y]);
}

int minimumMoves(char grid[MAXN][MAXN], int startX, int startY, int goalX, int goalY) {
    memset(visited, 0, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    Point queue[MAXN * MAXN];
    int front = 0, rear = 0;

    // Start point
    queue[rear++] = (Point){startX, startY};
    visited[startX][startY] = 1;
    dist[startX][startY] = 0;

    // BFS
    while (front < rear) {
        Point curr = queue[front++];
        int x = curr.x, y = curr.y;

        if (x == goalX && y == goalY)
            return dist[x][y];

        // Move in 4 directions until hitting X or border
        // Move UP
        for (int i = x - 1; i >= 0 && grid[i][y] == '.'; i--) {
            if (!visited[i][y]) {
                visited[i][y] = 1;
                dist[i][y] = dist[x][y] + 1;
                queue[rear++] = (Point){i, y};
            }
        }
        // Move DOWN
        for (int i = x + 1; i < n && grid[i][y] == '.'; i++) {
            if (!visited[i][y]) {
                visited[i][y] = 1;
                dist[i][y] = dist[x][y] + 1;
                queue[rear++] = (Point){i, y};
            }
        }
        // Move LEFT
        for (int j = y - 1; j >= 0 && grid[x][j] == '.'; j--) {
            if (!visited[x][j]) {
                visited[x][j] = 1;
                dist[x][j] = dist[x][y] + 1;
                queue[rear++] = (Point){x, j};
            }
        }
        // Move RIGHT
        for (int j = y + 1; j < n && grid[x][j] == '.'; j++) {
            if (!visited[x][j]) {
                visited[x][j] = 1;
                dist[x][j] = dist[x][y] + 1;
                queue[rear++] = (Point){x, j};
            }
        }
    }
    return -1; // If not reachable
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    printf("%d\n", result);

    return 0;
}
