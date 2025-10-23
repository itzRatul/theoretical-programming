#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int value;
    char name[20];
    struct node *pre,*next;
};
void printFunction(struct node *start)
{   
    if(start==NULL){
        printf("List is Empty!");
        return;
    }
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%s %d ",ptr->name,ptr->value);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node* addFirst(struct node *start)
{
    int value;
    char str[20];
    printf("Enter name and value to insert at 1st position : ");
    scanf("%s %d",str,&value);
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        fprintf(stderr,"Error:Mamory allocation failed!\n");
        return start;
    }
    strcpy(temp->name,str);
    temp->value=value;
    temp->pre=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    temp->next=start;
    start->pre=temp;
    start=temp;
    return start;
}
struct node *addLast(struct node *start)
{
    int value;
    char str[20];
    printf("Enter name and value to insert at last position : ");
    scanf("%s %d",str,&value);
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        fprintf(stderr,"Error:Mamory allocation failed!\n");
        return start;
    }
    strcpy(temp->name,str);
    temp->value=value;
    temp->pre=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        return start;
    }
    struct node *ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp->pre=ptr;
    ptr->next=temp;
    return start;
}
struct node *addAnyPosition(struct node *start)
{
    int pos;
    int value;
    char str[20];
    printf("Enter name, value and position to insert at last position : ");
    scanf("%s %d %d",str,&value,&pos);
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        fprintf(stderr,"Error:Mamory allocation failed!\n");
        return start;
    }
    strcpy(temp->name,str);
    temp->value=value;
    temp->pre=NULL;
    temp->next=NULL;
    if(pos==1){
        if(start==NULL)
        {
            start=temp;
            return start;
        }
        temp->next=start;
        start->pre=temp;
        start=temp;
        return start;
    }
    if(pos < 1) {
        printf("Error: Position must be greater than 0\n");
        free(temp);
        return start;
    }
    struct node *ptr = start;
    int currentPos = 1;
    while(ptr != NULL && currentPos < pos-1) {
        ptr = ptr->next;
        currentPos++;
    }
    if(ptr == NULL) {
        printf("Position out of range! List has only %d nodes\n", currentPos);
        free(temp);
        return start;
    }
    temp->next=ptr->next;
    temp->pre=ptr;
    if(ptr->next != NULL) {
        ptr->next->pre = temp;
    }
    ptr->next=temp;
    return start;
}
struct node *addAfterAnyString(struct node *start)
{
    char searchStr[20];
    int value;
    char newStr[20];
    
    printf("Enter the name to search: ");
    scanf("%s", searchStr);
    printf("Enter new name and value to insert after '%s': ", searchStr);
    scanf("%s %d", newStr, &value);
    
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return start;
    }    
    strcpy(temp->name, newStr);
    temp->value = value;
    temp->pre = NULL;
    temp->next = NULL;    
    //Empty list
    if(start == NULL) {
        printf("List is empty! Cannot insert after '%s'\n", searchStr);
        free(temp);
        return start;
    }
    
    struct node *ptr = start;
    int found = 0;    
    //Search for the node with matching name
    while(ptr != NULL) {
        if(strcmp(ptr->name, searchStr) == 0) {
            found = 1;
            break;
        }
        ptr = ptr->next;
    }    
    //String not found
    if(!found) {
        printf("Name '%s' not found in the list!\n", searchStr);
        free(temp);
        return start;
    }    
    //Insert after the found node
    temp->next = ptr->next;
    temp->pre = ptr;
    
    if(ptr->next != NULL) {
        ptr->next->pre = temp;
    }
    
    ptr->next = temp;
    printf("Successfully inserted '%s' after '%s'\n", newStr, searchStr);
    return start;
}
struct node* deleteLast(struct node *start)
{
    if(start==NULL)
    {
        printf("LinkList is already empty!");
        return NULL;
    }
    if(start->next==NULL){
        free(start);
        return NULL;
    }
    struct node *ptr = start;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    return start;    
}
struct node* deleteFirst(struct node *start)
{
    if(start==NULL)
    {
        printf("LinkList is already empty!");
        return NULL;
    }
    if(start->next==NULL){
        free(start);
        return NULL;
    }
    struct node *ptr = start->next;
    free(start);
    start=ptr;
    return start;
}
struct node* deleteByString(struct node* start)
{
    if(start == NULL)
    {
        printf("LinkList is already empty!\n");
        return NULL;
    }    
    char searchStr[20];
    printf("Enter the name to delete: ");
    scanf("%s", searchStr);    
    // Count occurrences
    struct node *checkPtr = start;
    int occurrenceCount = 0;
    while(checkPtr != NULL) {
        if(strcmp(checkPtr->name, searchStr) == 0) {
            occurrenceCount++;
        }
        checkPtr = checkPtr->next;
    }    
    if(occurrenceCount == 0) {
        printf("Name '%s' not found in the list!\n", searchStr);
        return start;
    }    
    int occurrence = 1;
    if(occurrenceCount > 1) {
        printf("Found %d occurrences of '%s'. Which one to delete? (1 to %d): ", 
               occurrenceCount, searchStr, occurrenceCount);
        scanf("%d", &occurrence);
        
        if(occurrence < 1 || occurrence > occurrenceCount) {
            printf("Invalid occurrence number!\n");
            return start;
        }
    }
    
    struct node *ptr = start;
    struct node *prev = NULL;
    int currentOccurrence = 0;    
    // Search for the specific occurrence
    while(ptr != NULL) {
        if(strcmp(ptr->name, searchStr) == 0) {
            currentOccurrence++;
            if(currentOccurrence == occurrence) {
                break;
            }
        }
        prev = ptr;
        ptr = ptr->next;
    }    
    // Delete the node
    if(prev == NULL) {
        // Delete first node
        start = ptr->next;
        if(start != NULL) {
            start->pre = NULL;
        }
    } else {
        // Delete middle or last node
        prev->next = ptr->next;
        if(ptr->next != NULL) {
            ptr->next->pre = prev;
        }
    }
    free(ptr);
    printf("'%s' (occurrence %d) deleted successfully!\n", searchStr, occurrence);
    return start;
}
int main()
{
    struct node *head = NULL;
    int choice;
    
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Add at first position\n");
        printf("2. Add at last position\n");
        printf("3. Add at any position\n");
        printf("4. Add after any string\n");
        printf("5. Delete first node\n");          
        printf("6. Delete last node\n");           
        printf("7. Delete by string\n");           
        printf("8. Print list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                head = addFirst(head);
                break;
            case 2:
                head = addLast(head);
                break;
            case 3:
                head = addAnyPosition(head);
                break;
            case 4:
                head = addAfterAnyString(head);
                break;
            case 5:
                head = deleteFirst(head);          
                break;
            case 6:
                head = deleteLast(head);           
                break;
            case 7:
                head = deleteByString(head);      
                break;
            case 8:
                printFunction(head);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 9);
    
    // Free all memory before exiting
    struct node *current = head;
    while(current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}