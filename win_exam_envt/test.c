#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct node {
    int data;
    struct node *next;
};

// 反转链表函数
struct node* reverse(struct node* head) {
    struct node *prev = NULL;
    struct node *curr = head;
    
    while (curr != NULL) {
        struct node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    return prev;
}

// 创建链表函数
struct node* createList(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }
    
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = NULL;
    
    struct node *curr = head;
    for (int i = 1; i < n; i++) {
        struct node *node = (struct node*)malloc(sizeof(struct node));
        node->data = arr[i];
        node->next = NULL;
        curr->next = node;
        curr = node;
    }
    
    return head;
}

// 打印链表函数
void printList(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    struct node *head = createList(arr, n);
    printf("Original List: ");
    printList(head);
    
    struct node *reversedHead = reverse(head);
    printf("Reversed List: ");
    printList(reversedHead);
    
    return 0;
}