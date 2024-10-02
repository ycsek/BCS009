/*
 * @Author: Yuchen Shi
 * @Date: 14-09-2024 14:14:02
 * @Last Editors: Y.Shi
 * @Contact Last Editors: yuchenshi327@outlook.com
 * @LastEditTime: 18-09-2024 19:42:53
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// 创建新节点
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// 打印链表
void printList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d,", current->data);
        current = current->next;
    }
}

// 拆分链表, 奇数位置的节点放在1, 偶数位置的节点放在2
void splitList(struct node *head, struct node **head1, struct node **head2)
{
    // 初始化链表
    struct node *current = head;
    struct node *oddList = NULL;
    struct node *evenList = NULL;
    struct node *oddTail = NULL;
    struct node *evenTail = NULL;

    while (current != NULL)
    {
        if (current->data % 2 != 0)
        { // 奇数位置
            if (oddList == NULL)
            {
                oddList = current;
                oddTail = oddList;
            }
            else
            {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        else
        { // 偶数位置
            if (evenList == NULL)
            {
                evenList = current;
                evenTail = evenList;
            }
            else
            {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        // 移动到下一个节点
        current = current->next;
    }

    // 断开链表
    if (oddTail != NULL)
    {
        oddTail->next = NULL;
    }
    if (evenTail != NULL)
    {
        evenTail->next = NULL;
    }
    // 返回拆分后的链表
    *head1 = oddList;
    *head2 = evenList;
}

int main()
{
    struct node *head = NULL;
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    // 创建链表
    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);
    head->next->next->next->next->next = create_node(6);
    head->next->next->next->next->next->next = create_node(7);
    head->next->next->next->next->next->next->next = create_node(8);
    head->next->next->next->next->next->next->next->next = create_node(9);
    head->next->next->next->next->next->next->next->next->next = create_node(10);

    // 拆分链表
    splitList(head, &head1, &head2);

    // 打印链表
    printf("List 1 (Odd parts): ");
    printList(head1);

    printf("List 2 (Even parts): ");
    printList(head2);

    return 0;
}
