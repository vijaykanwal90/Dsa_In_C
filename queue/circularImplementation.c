#include <stdio.h>
#define size 5

void insert(int arr[], int *front, int *rear, int value)
{

    if ((*rear) == size - 1 || ((*rear) + 1) == (*front))
    {
        printf("queue is full \n");

        if ((*rear) == size - 1 && (*front != 0))
        {

            // printf("queue is not full\n");
            *rear = 0;
            arr[(*rear)] = value;
            (*rear)++;
            printf("%d after one round\n", arr[*rear]);
        }
    }
    else
    {
        if ((*front) == -1)
        {
            (*front) = 0;
            (*rear) = 0;
            arr[(*rear)] = value;
        }

        else
        {
            printf("The value of front is %d\n", *(front));

            (*rear)++;
            printf("The value of rear is %d\n", *(rear));

            arr[(*rear)] = value;
        }
    }
}

void delete(int arr[], int *front, int *rear)
{
    printf("The value of front is %d\n", *(front));
    printf("The value of rear is %d\n", *(rear));

    if ((*front) == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("poped element is %d\n", arr[*(front)]);

        (*front)++;
    }
}

void display(int arr[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = *front;
        if (*front <= *rear)
        {
            while (i <= *rear)
            {
                printf("%d at index %d", arr[i], i);
                i++;
            }
        }
        else
        {
            while (i < size)
            {
                printf("%d at index %d\n", arr[i], i);
                i++;
            }
            i = 0;
            while (i <= *rear)
            {
                printf("%d at index %d\n", arr[i], i);
                i++;
            }
        }
    }
    printf("\n");
}

int main()
{

    int arr[size];
    int front = -1;
    int rear = -1;
    int option;
    do
    {
        printf("1 to enter the value\n");
        printf("2 to delete the value\n");
        printf("3 to display the queue\n");

        printf("4 to exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            int value;
            printf("enter a number\n");
            scanf("%d", &value);
            insert(arr, &front, &rear, value);

            break;
        case 2:
            // insert(arr,&front , &rear);
            delete (arr, &front, &rear);

            break;
        case 3:
            display(arr, &front, &rear);
            // insert(arr,&front , &rear);

            break;
        case 4:
            printf("exit succesfully\n");

            break;
        default:
            printf("Invalid statement\n");
            break;
        }

    } while (option != 4);

    return 0;
}