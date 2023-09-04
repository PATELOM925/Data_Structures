#include<stdio.h>
#include<stdlib.h>

//Creates a structure to form a queue
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

//Adds element to the queue
void enqueue(struct queue *q, int val){
        q->size--;
        q->r++;
        q->arr[q->r] = val;
        printf("Serial number added is : %d\n", val);
}


//Removes the first element that had been added. Follows the principle FIFO(First In First Out)
int dequeue(struct queue *q){
    q->size++;
    int a = -1;
    q->f++;
    a = q->arr[q->f];
    return a;
}

int main(){
    //Initializing a structure
    struct queue q;
    q.size = 7;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    printf("Hello!\nlet's test the queue function \n Write the following number in descending order\n");
    printf("1. 2132 \n2. 0 \n3. 121 \n4. 23 \n5. 19898 \n");
    printf("6. 54 \n 7.1100001 \n");
    printf("Enter descends.\n\n");

    int loop=0; //Checks the number of times the for loop is run
    for(int i=0;i<7;i++)
    {
        printf("1. Enter Correct number\n2. Delete Wrong number\n");
        int num;
        scanf("%d", &num);
        if(num==1){
            int position;
            printf("Enter number in descending.\n");
            scanf("%d", &position);
            loop++;
            //Run for loop as long as we count to number of inputs taken already
            for(int n=0;n<=loop;n++)
            {
                //Checks if input is repeated
                if(position==q.arr[i]){
                    printf("This number has been already added\n");
                    //Decrements i as the input is not added since it is repeated
                    i--;
                    //Decrement loop as the input is not added to the queue
                    loop--;
                    break;
                }
                else{
                    enqueue(&q, position);
                    break;
                }
            }
        }
        else if(num==2){
            dequeue(&q);
            i--;
        }
        else if(num==3){
            printf("\n");
            for (int j = 1; j <= q.r; j++) {
                printf("%d\t",q.arr[j]);
            }
            printf("\n");
            i--;
        }
        else{
            printf("Invalid Option.\n try again.\n");
            loop--;
        }
    }


    int order[7]={7,5,1,3,6,4,2};
    //used to count the number of matching positions

    int t=0;
    for(int i=0;i<7;i++)
    {
        if(dequeue(&q)==order[i]){t++;}
    }
    printf("Correct order: ");
    for(int i=0;i<7;i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");
    printf("Your answer order :        ");
    for(int i=1;i<=7;i++)
    {
        printf("%d ", q.arr[i]);
    }

    return 0;
}