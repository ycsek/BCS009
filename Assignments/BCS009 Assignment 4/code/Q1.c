#include <stdio.h>
#include <stdlib.h>

// 定义节点
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

//定义队列
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// 创建新节点
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// 创建新队列
Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 将节点加入队列
void enqueue(Queue *q, int data)
{
    // 如果队列为空则创建一个front和rear都指向的节点
    Node *temp = newNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    //更新rear指针
    q->rear->next = temp;
    q->rear = temp;
}

// 从队列中取出节点
int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    int data = temp->data;
    free(temp);
    return data;
}

// 模拟出列过程
void simulate(int n)
{
    Queue *q = createQueue();
    for (int i = 1; i <= n; i++)
    {
        enqueue(q, i);
    }
    // 记录当前报数
    int count = 1;
    while (q->front != NULL)
    {
        int person = dequeue(q);
        if (count == 1)
        {
            printf("%d ", person);
            count = 2;
        }
        else
        {
            enqueue(q, person);
            count = 1;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of people: ");//设定队列人数
    scanf("%d", &n);
    simulate(n);
    return 0;
}