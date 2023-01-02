// checks if stack is full
int isFull(char stack[], int *top, char size)
{
    if (*top >= size)
        return 1;
    else
        return 0;
}

// checks if stack is Empty
int isEmpty(char stack[], int *top)
{
    if (*top == -1)
        return 1;
    else
        return 0;
}

// Push element into *top of stack
int push(char stack[], int *top, char data, int size)
{
    if (!isFull(stack, &*top, size))
    {
        stack[++*top] = data;
        return stack[*top];
    }
}

// Pop the *top element
int pop(char stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[(*top)--];
    else
        return 0;
}

// Peek the top element
int peek(char stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[*top];
    else
        return 0;
}
