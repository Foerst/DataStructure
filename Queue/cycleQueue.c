
//定义一个循环队列
#define MAXSIZE 100
typedef struct
{
    ElemType *base; // 用于存放内存分配基地址
    // 这里你也可以用数组存放
    int front;
    int rear;
}

//初始化一个循环队列
initQueue(cycleQueue *q)
{
    q->base = (ElemType *) malloc (MAXSIZE * sizeof(ElemType));
    if( !q->base )
        exit(0);
    q->front = q->rear = 0;
}

//入队列操作
InsertQueue(cycleQueue *q, ElemType e)
{
    if( (q->rear+1)%MAXSIZE == q->front )
        return; // 队列已满
    q->base[q->rear] = e;
    q->rear = (q->rear+1) % MAXSIZE;
}


//出队列操作
DeleteQueue(cycleQueue *q, ElemType *e)
{
    if( q->front == q->rear )
        return ; // 队列为空
    *e = q->base[q->front];
    q->front = (q->front+1) % MAXSIZE;
}
