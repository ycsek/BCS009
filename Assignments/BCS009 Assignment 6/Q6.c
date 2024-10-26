#include <stdio.h>
#include <stdlib.h>

typedef struct GLNode
{
    int tag; // 0表示原子，1表示子表
    union
    {
        char atom;
        struct
        {
            struct GLNode *hp, *tp; // 子表结点的指针域，hp指向表头，tp指向表尾
        } ptr;
    } data;
} *Glist;

// 创建一个原子节点
Glist createAtom(char atom)
{
    Glist node = (Glist)malloc(sizeof(struct GLNode));
    node->tag = 0;
    node->data.atom = atom;
    return node;
}

// 创建一个子表节点
Glist createSublist(Glist hp, Glist tp)
{
    Glist node = (Glist)malloc(sizeof(struct GLNode));
    node->tag = 1;
    node->data.ptr.hp = hp;
    node->data.ptr.tp = tp;
    return node;
}

// 递归计算广义表中的原子个数
int countAtoms(Glist glist)
{
    if (glist == NULL)
    {
        return 0;
    }
    if (glist->tag == 0)
    {
        return 1; // 原子节点
    }
    else
    {
        // 子表节点，递归计算表头和表尾的原子个数
        return countAtoms(glist->data.ptr.hp) + countAtoms(glist->data.ptr.tp);
    }
}

int main()
{
    // 创建广义表
    Glist a = createAtom('a');
    Glist b = createAtom('b');
    Glist c = createAtom('c');
    Glist d = createAtom('d');
    Glist sublist = createSublist(b, c);
    Glist glist = createSublist(a, sublist);

    // 计算原子个数
    int atomCount = countAtoms(glist);
    printf("Atom Number: %d\n", atomCount);

    // 释放内存
    free(a);
    free(b);
    free(c);
    free(d);
    free(sublist);
    free(glist);

    return 0;
}