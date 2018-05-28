#include "stack1.h"
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

void    push(t_stack *stack, char content)
{
	t_node  *temp;

	temp = (t_node *)malloc(sizeof(t_node));
	
	temp->content = content;
	temp->next = stack->top;
	stack->top = temp;
}
//pop

char pop(t_stack *stack)
{
	t_node  *temp;
	char    content_temporary;

	if (is_empty(stack))
		return(0);
	temp = stack->top;
	content_temporary = temp->content;
	stack->top = stack->top->next;
	//free(temp);
	return(content_temporary);
}

// peek
t_node *peek(t_stack *stack)
{
	return(stack->top);
}

int is_pair(char a, char b)
{
   return((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'));
}

int is_balance(t_stack *stack, char *s)
{
	int i;
	i = -1;
	while(s[++i])
	{
		if(CE3(s[i], '{', '[', '('))
		{
			push(stack, s[i]);
			printf("push:%-2c", stack->top->content);
		}
		else if(CE3(s[i], '}', ']', ')'))
		{
			if(is_empty(stack) || !is_pair((char)stack->top->content, s[i]))
				return(0);
			printf("pop:%-2c",pop(stack));
			
		}
	}
    if(is_empty(stack))
	    return(1);
    return(0);
}
int main()
{
	t_stack *stack;
	char *s = "{([Mohamed]((lamine)[kaba])}";
	stack = init();
	printf("\n%d", is_balance(stack, s));
	/* push(stack, (void *)'L');
	push(stack, (void *)'a');
	push(stack, (void *)'m');
	push(stack, (void *)'i');
	push(stack, (void *)'n');
	push(stack, (void *)'e');
   // pop(stack);

	while(!is_empty(stack))
	{
		printf("%c", (char)pop(stack));
	} */
	return (0);
}