#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int power;
    struct node *next;
} node_type;

void insertData(node_type **head, int data1, int power1)
{
    node_type *node;
    node = (node_type *)malloc(sizeof(node_type));
    if (node == NULL)
    {
        printf("space not available \n");
    }
    else
    {
        node->data = data1;
        node->power = power1;
        node->next = NULL;
        if ((*head) == NULL)
        {
            (*head) = node;
        }
        else
        {
            node_type *temp = (*head);
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            if (node->power != 0)
            {

                temp->next = node;
                temp = node;
            }
            else
            {
                temp->next = node;
                temp = node;
                node = NULL;
            }
        }
    }
}
void display(node_type *head)
{
    node_type *temp = head;
    
    printf("displaying node\n");
    while (temp != NULL)
    {   
         if(temp->power==0){
        printf("%dx^%d ", temp->data, temp->power);

        }
        else {
        printf("%dx^%d  + ", temp->data, temp->power);

        }

        temp = temp->next;
    }
    printf("\n");
}
void add(node_type *first, node_type *second)
{
    node_type *firstTemp = first;
    node_type *secondTemp = second;
    node_type *sum = NULL;
    int data;
    int power;
    while (firstTemp!= NULL && secondTemp != NULL)
    {
        if (firstTemp->power == secondTemp->power)
        {
            data = firstTemp->data + secondTemp->data;
            power = firstTemp->power;       
            insertData(&sum, data, power);
            firstTemp = firstTemp->next;
            secondTemp = secondTemp->next;
        }
        else if (firstTemp->power > secondTemp->power)
            {
                data = firstTemp->data;
                power = firstTemp->power;
            
                insertData(&sum, data, power);

                firstTemp = firstTemp->next;
            }
            else
            {
                data = secondTemp->data;
                power = secondTemp->power;
              
                insertData(&sum, data, power);

                secondTemp = secondTemp->next;
            }
        }
         while (firstTemp != NULL) {
        data = firstTemp->data;
        power = firstTemp->power;
        insertData(&sum, data, power);
        firstTemp = firstTemp->next;
    }

    while (secondTemp != NULL) {
        data = secondTemp->data;
        power = secondTemp->power;
        insertData(&sum, data, power);
        secondTemp = secondTemp->next;
    }
    node_type *temp = sum;
    printf("displaying node\n");
   
    while (temp != NULL)
    {
        if(temp->power==0){
        printf("%dx^%d ", temp->data, temp->power);

        }
        else {
        printf("%dx^%d  + ", temp->data, temp->power);

        }
        temp = temp->next;
    }
    printf("\n");

    }

int main()
{
    node_type *first = NULL;
    node_type *second = NULL;

    int option;

    while (option != 6)
    {
        printf("1 for insertion in  1st polynomial \n");
        printf("2 for insertion in  2nd polynomial\n");
        printf("3 for display 1st polynomial\n");
        printf("4 for display 2nd polynomial\n");
        printf("5 to add the polynomials\n");
        printf("6 to exit\n");
        

        printf("7 for exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int power1;
            int data1;

            printf("Enter the coeficient\n");
            scanf("%d", &data1);
            printf("Enter the order\n");
            scanf("%d", &power1);
            insertData(&first, data1, power1);
            break;
        case 2:
            printf("Enter the coeficient\n");
            int data;
            scanf("%d", &data);
            printf("Enter the order\n");
            int power;
            scanf("%d", &power);
            insertData(&second, data, power);

            break;
        case 3:
            display(first);
            break;
        case 4:
            display(second);
            break;
        case 5:
            add(first, second);
            break;
        case 6 :
            printf("exit successfully\n");
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }

    return 0;
}