

// checks if stack is full
int isFull(int stack[], int *top, int size)
{
    if (*top >= size)
        return 1;
    return 0;
}

// checks if stack is Empty
int isEmpty(int stack[], int *top)
{
    if (*top == -1)
        return 1;
    return 0;
}

// Push element into *top of stack
int push(int stack[], int *top, int data, int size)
{
    if (!isFull(stack, &*top, size))
    {
        stack[++*top] = data;
        return stack[*top];
    }
}

// Pop the *top element
int pop(int stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[(*top)--];
    return 0;
}

// Peek the top element
int peek(int stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[*top];
    return 0;
}
// display the elements in the stack
void displayStack(int stack[], int *top)
{
    if (!isEmpty(stack, &*top))
    {
        int i;
        printf("[%d", stack[0]);
        for (i = 1; i <= *top; i++)
        {
            printf(",%d", stack[i]);
        }
        printf("]\n");
    }
}
