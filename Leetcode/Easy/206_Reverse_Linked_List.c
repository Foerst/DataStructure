/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head) return NULL;
    struct ListNode*p=head;
    struct ListNode*ret=(struct ListNode*)malloc(sizeof(struct ListNode));
    ret->val=head->val;
    ret->next=NULL;
    while(p=p->next){
        struct ListNode*tmp=(struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val=p->val;
        tmp->next=ret;
        ret=tmp;
    }
    return ret;
}
