#include <stdio.h>
#define array_size 3

void push(int arr[], int *top)
{

    if (*top == (array_size-1))
    {
        printf("array is full element can't be pushed");
    }
    else {

        (*top)++;
        printf("Enter the element");
        scanf("%d", &arr[(*top)]);
    }
}
void pop(int arr[], int *top)
{
    if (*top == -1)
    {
        printf("stack is empty , pop can not be performed");
    }
    else
    {
        (*top)--;
    }
}
void display(int arr[], int *top)
{

    for (int i = 0; i <= (*top); i++)
    {

        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{

    int arr[array_size];
    int top = -1;
    int option;

    while (option != 4)
    {
        printf("1 for push operation\n");
        printf("2 for pop operation\n");
        printf("3 for display operation\n");
        printf("4 for exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push(arr, &top);
            break;
        case 2:
            pop(arr, &top);
            break;
        case 3:
            display(arr, &top);
            break;
        case 4:
            break;
        default:
            printf("invalid input\n");
            break;
        }
    }
    return 0;
}