#include "linked_list.h"

int main()
{
    int i;
    int n;
    int j;
    i = 0;

    intarray *head;
    head = NULL;
    printf("how many integer do you want to create");
    scanf("%d", &n);
    while(i < n)
    {
        printf("entrer le %d element(s)", i + 1);
        scanf("%d", &j);
        insert(&head, j);
        Print(&head);
        i++;
    }
    return (0);
}

void insert(intarray **head, int n)
{
    intarray *node;
    node = (intarray *)malloc(sizeof(intarray));
    node->i = n;
    node->next = *head;
    *head = node;
}
void Print(intarray **head)
{
    intarray *s;
    s = *head;

    while(s != NULL)
    {
        printf("%d\n",s->i);
        s = s->next;
    }

}