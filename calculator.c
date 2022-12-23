# include <stdio.h>
# include <stdlib.h>
# include <string.h>
struct node{
    float data;
    struct node *next;
};

int sizeoflist(struct node* head1, struct node*head2){
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    int count1 = 0,count2 = 0;
    while (temp1!= NULL){
        count1 += 1;
        temp1 = temp1 ->next;
    }
    while (temp2!= NULL){
        count2 += 1;
        temp2 = temp2 ->next;
    }
    if(count1 != count2){
        return -1;
    }
    else{
        return 1;
    }

}
struct node* insert_atend(float ele,struct node*head){
    struct node *temp;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;
    if (head==NULL)
    {
        printf("\nInserted at head \n");
        head= newnode;
    }
    else{
        temp = head;
        while(temp ->next != NULL){
            temp = temp->next;
        }
        printf("Inserted at last\n");
        temp->next = newnode;
    }
    return head;
}
struct node *addition(struct node *h1, struct node*h2, struct node *h3){
    struct node * temp1 = h1;
    struct node * temp2 = h2;
    float x, sum, y;
    while((temp1 != NULL) && (temp2 != NULL)){
        x = temp1->data;
        y = temp2->data;
        sum = x + y;
        h3 = insert_atend(sum,h3); 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return h3;
}
struct node *multiplication(struct node *h1, struct node*h2, struct node *h4){
    struct node * temp1 = h1;
    struct node * temp2 = h2;
    float x, mul, y;
    while((temp1 != NULL) && (temp2 != NULL)){
        x = temp1->data;
        y = temp2->data;
        mul = x*y;
        h4 = insert_atend(mul,h4); 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return h4;
}
struct node *subtraction(struct node *h1, struct node*h2, struct node *h5){
    struct node * temp1 = h1;
    struct node * temp2 = h2;
    float x,diff, y;
    while((temp1 != NULL) && (temp2 != NULL)){
        x = temp1->data;
        y = temp2->data;
        diff = x - y;
        h5 = insert_atend(diff,h5); 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return h5;
}
struct node *division(struct node *h1, struct node*h2, struct node *h6){
    struct node * temp1 = h1;
    struct node * temp2 = h2;
    float x, div, y;
    while((temp1 != NULL) && (temp2 != NULL)){
        x = temp1->data;
        y = temp2->data;
        div = x / y;
        h6 = insert_atend(div,h6); 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return h6;
}
void display_List(struct node *head)
{
    struct node* t; 
    t = head; 
    while (t != NULL) {
        
        if (t->next == NULL) {
            printf(" %f->NULL", t->data);
        }
        else {
            printf(" %f->", t->data);
        }
        t = t->next; 
    }
}
int main(){
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    struct node *head4 = NULL;
    struct node *head5 = NULL;
    struct node *head6 = NULL;
    int choice;int ch;float ele;
    choice = 1;
    while(choice != 0){
        printf("\n1. INSERT INTO 1 LIST : \n");
        printf("2. INSERT INTO 2 LIST : \n");
        printf("3. PRINT LINKED LIST 1 \n");
        printf("4. PRINT LINKED LIST 2 \n");
        printf("5. ADDITION LIST \n");
        printf("6. MULTIPLICATION LIST \n");
        printf("7. SUBTRACTION LIST \n");
        printf("8. DIVISION LIST \n");
        printf("9. EXIT\n");
        printf("ENTER YOUR CHOICE : \n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the data");
                scanf("%f", &ele);
                head1 = insert_atend(ele, head1);
                break;
            case 2:
                printf("Enter the data"); 
                scanf("%f", &ele);
                head2 = insert_atend(ele, head2);
                break; 
            case 3:
                printf("Display LINKED LIST 1\n");
                display_List(head1);
                break;
            case 4:
                printf("Display LINKED LIST 2\n");
                display_List(head2);
                break;
            case 5:
                if (sizeoflist(head1, head2) == 1){
                    printf("ADDITION\n");
                    head3 = addition(head1, head2, head3);
                    display_List(head3);
                }
                else{
                    printf("Lists are not of equal sizes.. \n");
                }
                break;
            case 6:
                if (sizeoflist(head1, head2) == 1){
                    printf("MULTIPLICATION\n");
                    head4 = multiplication(head1, head2, head4);
                    display_List(head4);
                }
                else{
                    printf("Lists are not of equal sizes.. \n");
                }
                break;
            case 7:
                if (sizeoflist(head1, head2) == 1){
                    printf("SUBTRACTION\n");
                    head5 = subtraction(head1, head2, head5);
                    display_List(head5);
                }
                else{
                    printf("Lists are not of equal sizes.. \n");
                }
                break;
            case 8:
                if (sizeoflist(head1, head2) == 1){
                    printf("DIVISION\n");
                    head6 = division(head1, head2, head6);
                    display_List(head6);
                }
                else{
                    printf("Lists are not of equal sizes.. \n");
                }
                break;
            case 9:
                choice = 1;
                break;
        }
    }    
    return 0;
}