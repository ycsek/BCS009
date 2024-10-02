#include <stdio.h>
#include <stdlib.h>

// 定义8*8的迷宫
#define ROWS 8
#define COLS 8

typedef struct
{
    int x, y;
} Position;

typedef struct
{
    Position positions[ROWS * COLS];
    int top;
} Stack;
// 初始化栈
void initStack(Stack *stack)
{
    stack->top = -1;
}
// 判断栈是否为空
int isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}
// 入栈
void push(Stack *stack, Position pos)
{
    stack->positions[++stack->top] = pos;
}
// 出栈
Position pop(Stack *stack)
{
    return stack->positions[stack->top--];
}
// 查看栈顶位置
Position peek(Stack *stack)
{
    return stack->positions[stack->top];
}
// 判断是否可以移动
int isValidMove(int maze[ROWS][COLS], int visited[ROWS][COLS], int x, int y)
{
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0 && !visited[x][y];
}

void printPath(Stack *stack)
{
    for (int i = 0; i <= stack->top; i++)
    {
        printf("(%d, %d)-> ", stack->positions[i].x, stack->positions[i].y);
    }
    printf("finish\n");
}

void solveMaze(int maze[ROWS][COLS], Position start, Position end)
{
    int visited[ROWS][COLS] = {0};                             // 标记已经访问过的位置
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 设置移动方位
    Stack stack;
    initStack(&stack);

    push(&stack, start);
    visited[start.x][start.y] = 1;

    while (!isStackEmpty(&stack))
    {
        // 检查当前路径的位置
        Position current = peek(&stack);

        if (current.x == end.x && current.y == end.y)
        {

            printf("Path: ");
            printPath(&stack);
            return;
        }

        int moved = 0;
        for (int i = 0; i < 4; i++)
        {
            // 计算新的x,y坐标
            int newX = current.x + directions[i][0];
            int newY = current.y + directions[i][1];
            // 判断是否可以移动
            if (isValidMove(maze, visited, newX, newY))
            {
                // 将新位置入栈
                push(&stack, (Position){newX, newY});
                visited[newX][newY] = 1;
                moved = 1;
                break;
            }
        }

        if (!moved)
        {
            pop(&stack);
        }
    }

    printf("No path found.\n");
}

int main()
{
    // 定义迷宫，0表示可以通过，1表示障碍物
    int maze[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0}};
    // 设置起点和终点
    Position start = {0, 0};
    Position end = {7, 7};

    solveMaze(maze, start, end);

    return 0;
}