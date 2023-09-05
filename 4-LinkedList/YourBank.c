#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct Customer
{
    int acc;
    char name[100];
    char phone[100];
    float balance;
    struct Customer *next;

}* head;

void insert(int acc, char* name, char* phone, float balance)
{

    struct Customer * Customer = (struct Customer *) malloc(sizeof(struct Customer));
    Customer->acc = acc;
    strcpy(Customer->name, name);
    strcpy(Customer->phone, phone);
    Customer->balance = balance;
    Customer->next = NULL;

    if(head == NULL){
        head = Customer;
    }
    else{
        Customer->next = head;
        head = Customer;
    }

}

void search(int acc)
{
    struct Customer * temp = head;
    while(temp!=NULL){
        if(temp->acc==acc){
            printf("Account NO.: %d\n", temp->acc);
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            printf("Bank Balance: %0.4f\n", temp->balance);
            return;
        }
        temp = temp->next;
    }
    printf("Customer with Account no. %d is not found in bank database\n", acc);
}

void update(int acc)
{

    struct Customer * temp = head;
    while(temp!=NULL){
     
        if(temp->acc==acc){
            printf("Account found : %d \n", acc);
            printf("Enter your name: ");
            scanf("%s", temp->name);
            printf("Enter your phone number: ");
            scanf("%s", temp->phone);
            printf("Enter balance you want deposit: ");
            scanf("%f",&temp->balance);
            printf("Details Updates\n");
            return;
        }
        temp = temp->next;

    }
    printf("Customer with Account No. %d is not found !!! in bank database\n", acc);

}

void Delete(int acc)
{
    struct Customer * temp1 = head;
    struct Customer * temp2 = head;
    while(temp1!=NULL){

        if(temp1->acc==acc){

            printf("Customer with Account No. %d found\n", acc);

            if(temp1==temp2){
                head = head->next;
                free(temp1);
            }
            else{
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Account Deleted\n");
            return;

        }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("Customer with Account No. %d is not found in bank database!!!\n", acc);

}
void display()
{
    struct Customer * temp = head;
    while(temp!=NULL){

        printf("Acount No: %d\n", temp->acc);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Balance: %0.4f\n\n", temp->balance);
        temp = temp->next;

    }
}
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int acc;
    float balance;
    printf("1 New Bank account \n 2 Search your Bank details \n3 Delete your account s\n4 Update Bank Details(Deposit/Updation) \n5 Display all Account Holders ");

    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter Account No.: ");
                scanf("%d", &acc);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter Bank Balance: ");
                scanf("%f", &balance);
                insert(acc, name, phone, balance);
                break;
            case 2:
                printf("Enter Account No to search: ");
                scanf("%d",&acc);
                search(acc);
                break;
            case 3:
                printf("EnterAccount No to delete: ");
                scanf("%d", &acc);
                Delete(acc);
                break;
            case 4:
                printf("EnterAccount No to update: ");
                scanf("%d", &acc);
                update(acc);
                break;
            case 5:
                display();
                break;
        }

    } while (choice != 0);
}
