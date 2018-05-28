#include "stack.h"
#include <stdio.h>

t_stack			*init(void)
{
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

// is empty

int is_empty(t_stack *stack)
{
    return(stack->top == 0);
}
//push

void    push(t_stack *stack, void *content)
{
    t_node  *temp;

    temp = (t_node *)malloc(sizeof(t_node));
    
    temp->content = content;
    temp->next = stack->top;
    stack->top = temp;
}
//pop

void    *pop(t_stack *stack)
{
    t_node  *temp;
    void    *content_temporary;

    if (is_empty(stack))
        return(NULL);
    temp = stack->top;
    content_temporary = temp->content;
    stack->top = stack->top->next;
    //free(temp);
    return(content_temporary);
}

// peek

int main()
{
    t_stack *stack;
    char *s = "{([Mohamed](lamine)[kaba])}";
    stack = init();
    push(stack, (void *)'L');
    push(stack, (void *)'a');
    push(stack, (void *)'m');
    push(stack, (void *)'i');
    push(stack, (void *)'n');
    push(stack, (void *)'e');
    //pop(stack);

    while(!is_empty(stack))
    {
        printf("%c", (char)pop(stack));
    }
    return (0);
}