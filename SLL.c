#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head;


void begin_insert() {
    struct node *ptr;
    int item;
    ptr=(struct node *) malloc(sizeof(struct node));
    if(ptr==NULL) {
        printf("Memory not allocated\n");
    }
    else {
        printf("Enter the data element\t");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL) {
            head=ptr;
            printf("Node Inserted\n");
        }
        else {
            ptr->next=head;;
            head=ptr;
            printf("Node Inserted\n");
        }
    }
}
void last_insert() {
    struct node * ptr, *temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL) {
        printf("Memory not allocated\n");
    }
    else {
        printf("Enter the data element\t");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL) {
            head=ptr;
            ptr->next=NULL;
            printf("Node Inserted\n");
        }
        else {
            temp=head;
            while(temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("Node Inserted\n");
        }
    }
}
void random_insert() {
    struct node * ptr, * temp;
    int item,loc,i;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL) {
        printf("Memory not allocated\n");
    }
    else {
        printf("Enter the data element\t");
        scanf("%d",&item);
        ptr->data=item;
        printf("Enter Location after which you want to insert data\n");
        scanf("%d",&loc);
        temp=head;
        for(i=0; i<loc; i++) {
            temp=temp->next;

            if(temp==NULL) {
                printf("Can't Insert");
                return;
            }
        }
        ptr->next=temp->next;
        temp->next=ptr;
        printf("Node Inserted\n");


    }
}
void begin_delete() {
    struct node * ptr;
    if(head==NULL) {
        printf("Can't Delete\n");
    }
    else {
        ptr=head;
        head=ptr->next;
        ptr->next=NULL;
        free(ptr);
        ptr=NULL;
        printf("Node Deleted\n");
    }
}
void last_delete() {
    struct node * ptr,* temp;
    if(head==NULL) {
        printf("Can't Delete\n");
    }
    else if(head->next==NULL) {
        head=NULL;
        free(head);
        printf("Node Deleted\n");
    } else {
        temp=head;
        while(temp->next!=NULL) {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        free(temp);
        temp=NULL;
        printf("Node Deleted\n");
    }
}
void random_delete() {
    struct node * ptr,* temp;
    int i,loc;
    printf("Enter location after which you want to delete node\n");
    scanf("%d",&loc);
    temp=head;
    for(i=0; i<loc; i++) {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=temp->next;
    free(temp);
    temp=NULL;
    printf("Node Deleted at location %d\n",i+1);

}
void search() {
    struct node * ptr;
    int i,item,flag;
    ptr=head;
    if(ptr==NULL) {
        printf("List is empty\n");
    }
    else {
        printf("Enter element to be searched\n");
        scanf("%d",&item);
        for(i=0; ptr!=NULL; i++) {
            if(ptr->data==item) {
                printf("The element %d is present at location %d\n",item,i+1);
                flag=1;
                break;
            }
            else {
                flag=0;
            }
            ptr=ptr->next;
        }
        if(flag==0) {
            printf("Item not found\n");
        }
    }
}


void display() {
    struct node * ptr;
    ptr=head;
    if(ptr==NULL) {
        printf("Nothing to print\n");
    }
    else
    {
        while(ptr!=NULL) {
            printf("%d-> ",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main() {
    int choice,n,i;
    do {
        printf("Enter your choice\n");
        printf("1-Insert at beginning\n");
        printf("2-Insert at last \n");
        printf("3-Insert at random location\n");
        printf("4-Delete from beginning\n");
        printf("5-Delete from last\n");
        printf("6-Delete from random location\n");
        printf("7-Search\n");
        printf("8-Display\n");
        printf("9-Exit\n-> ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            printf("Enter no. of nodes: ");
            scanf("%d",&n);
            for(i=0; i<n; i++) {
                begin_insert();
            }
            break;
        case 2:
            printf("Enter no. of nodes: ");
            scanf("%d",&n);
            for(i=0; i<n; i++) {
                last_insert();
            }
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
        }
    } while(choice!=9);

}