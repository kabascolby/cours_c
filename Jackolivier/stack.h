#ifndef _STACK_H_
# define _STACK_H_
# include <stdlib.h>
# define CE(a, b) ((a) == (b))
# define CE2(a, b, c) (CE(a, b) || CE(a, c))
# define CE3(a,b,c,d) (CE2(a,b,c) || CE(a, b))
typedef struct		s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	t_node			*top;
}					t_stack;
#endif