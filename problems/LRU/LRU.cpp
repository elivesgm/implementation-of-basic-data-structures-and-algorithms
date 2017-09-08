#include <stdio.h>
#include <stdlib.h>

#define M_MAX_PAGE_NUM 10
#define OK  0
#define ERR -1


struct Node {
    int    page_id;
    Node*  pnext;
};

Node* add_node_to_head(struct Node* head, int page_id) {
    Node* p = (struct*)malloc(sizeof(Node));
    if (!p) return head;
    p->page_id = page_id;
    p->pnext = head;
    head = p;
    return head;
}

Node* LRU(struct Node * head, int page_id){
    Node *p = head, *prev;
    int  curPageNum = 0;
    if (!head) return add_node_to_head(head, page_id);
        
    prev = head;
    while(prev && curPageNum <= M_MAX_PAGE_NUM) {
        p = prev->pnext;
        ++curPageNum;
        if (!p) return add_node_to_head(head, page_id);
 
        if (p->page_id == page_id) {
            prev->pnext = p->pnext;
            p->pnext = head;
            head = p;
            return head;
        }
        prev = prev->pnext;
    }
    
    add_node_to_head(head, page_id);
    prev->pnext = NULL;
    free(p);
    return head;
}