#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct s_node
{
  int num;
  struct s_node *next;
}              t_node;

void ft_create(t_node **H, int n, int pos)
{
  t_node *temp1;
  t_node *temp2;
  int i;
  temp1 = (t_node *)malloc(sizeof(t_node));
  temp1->num = n;
  if(pos == 1)
  {
    temp1->next = *H;
    *H = temp1;
    return;
  }
  i = 0;
  temp1->next = 0;
  temp2 = *H;
  while(i++ < pos - 2)
    temp2 = temp2->next;
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void ft_print(t_node **H)
{
  t_node *temp;
  temp = *H;
  while(temp != NULL)
  {
    printf("%d ", temp->num);
    temp = temp->next;
  }
  
}
void ft_del(t_node **h, int pos)
{
  int i;
  i = 0;
  t_node *temp1;
  t_node *temp2;
  
  temp1 = *h;
  if(pos == 1)
  {
    *h = temp1->next;
    bzero(temp1, sizeof(t_node));
    free(temp1);
    return;
  }
  while(i++ < pos -2)
    temp1 = temp1->next;
  
  temp2 = temp1->next;
  temp1->next = temp2->next;
  bzero(temp2, sizeof(t_node));
  free(temp2);
}
void ft_reverse(t_node **h)
{
  t_node *prev;
  t_node *cur;
  t_node *next;

  prev = NULL;
  cur = *h;
  while(cur != NULL)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  *h = prev;
}
void ft_rev2(t_node **h)
{
  t_node *rev;
  t_node *temp;

  temp = NULL;
  rev = NULL;
  while(*h)
  {
    temp = *h;
    *h = (*h)->next;
    temp->next = rev;
    rev = temp;
  }
  *h = rev;
}
int main(void)
{
  int i;
  int j;
  t_node *head;
  head = NULL;
  i = 1;
  j = 1;
  while(j < 5)
    ft_create(&head, 5*i++, j++);
  printf("\n");
  ft_print(&head);
  ft_del(&head, 1);
  printf("\n");
  ft_print(&head);
   printf("\n");
  ft_rev2(&head);
  ft_print(&head);
  return 0;
}