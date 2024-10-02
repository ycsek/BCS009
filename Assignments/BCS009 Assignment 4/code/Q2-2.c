#include <stdio.h>
#include <stdbool.h>

#define N 8
#define M 8

typedef struct
{
    int x, y;
} Point;

typedef struct
{
    Point points[N * M];
    int front, rear; // 设定队首和队尾
} Queue;

// 初始化队列
void initQueue(Queue *q)
{
    q->front = q->rear = 0;
}
// 判断队列是否为空
bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}
// 入队
bool enqueue(Queue *q, Point p)
{
    if ((q->rear + 1) % (N * M) == q->front)
    {
        return false; // Queue is full
    }
    q->points[q->rear] = p;
    q->rear = (q->rear + 1) % (N * N);
    return true;
}
// 出队
bool dequeue(Queue *q, Point *p)
{
    if (isEmpty(q))
    {
        return false;
    }
    *p = q->points[q->front];
    q->front = (q->front + 1) % (N * M);
    return true;
}
// 检查当前节点在迷宫内且未被访问过
bool isValid(int x, int y, int maze[N][N], bool visited[N][M])
{
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y]);
}

void printPath(Point path[N][M], Point end)
{
    Point current = end;
    printf("Path: ");
    while (path[current.x][current.y].x != -1 && path[current.x][current.y].y != -1)
    {
        printf("(%d, %d) <- ", current.x, current.y);
        current = path[current.x][current.y];
    }
    printf("Start\n");
}
// 使用广度优先搜索查找路径
bool bfs(int maze[N][M], Point start, Point end)
{
    int rowNum[] = {-1, 0, 0, 1}; // 行方向，左右
    int colNum[] = {0, -1, 1, 0}; // 列方向，上下

    bool visited[N][M] = {false};
    Point path[N][M];//存储路径的前驱节点

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            path[i][j] = (Point){-1, -1};
        }
    }
    // 设置起点已访问
    visited[start.x][start.y] = true;

    Queue q;
    initQueue(&q);
    enqueue(&q, start);

    while (!isEmpty(&q))
    {
        Point curr;
        dequeue(&q, &curr);

        // 判断是否到达终点，到达则打印路径
        if (curr.x == end.x && curr.y == end.y)
        {
            printPath(path, end);
            return true;
        }
        // 遍历当前节点的四个相邻节点
        for (int i = 0; i < 4; i++)
        {
            int x = curr.x + rowNum[i];
            int y = curr.y + colNum[i];

            if (isValid(x, y, maze, visited))
            {
                visited[x][y] = true;
                path[x][y] = curr;
                Point adj = {x, y};
                enqueue(&q, adj);
            }
        }
    }

    printf("No path found from (%d, %d) to (%d, %d)\n", start.x, start.y, end.x, end.y);
    return false;
}

int main()
{
    // 定义迷宫，0表示可以通过，1表示障碍物
    int maze[N][M] = {
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}};

    // 设置起点和终点
    Point start = {0, 0};
    Point end = {7, 7};

    bfs(maze, start, end);

    return 0;
}