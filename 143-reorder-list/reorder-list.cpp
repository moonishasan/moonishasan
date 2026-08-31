/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* split_at_mid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev != NULL){
            prev->next = NULL;   // split at middle
        }
        return slow;     // slow = rightHead
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;   // prev becomes the head of reversed list
    }
    void ZigZagLL(ListNode* head){
        ListNode* rightHead = split_at_mid(head);
        ListNode* rightHeadRev = reverse(rightHead);

        // alternate merging
        ListNode* left = head;
        ListNode* right = rightHeadRev;
        ListNode* prev = right;

        while(left != NULL && right != NULL){
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            prev = right;
            left = nextLeft;
            right = nextRight;
        }
        if(right != NULL){
            prev->next = right;
        }

    }
    void reorderList(ListNode* head) {
        ListNode* rightHead = split_at_mid(head);
        ListNode* rightHeadRev = reverse(rightHead);

        // alternate merging
        ListNode* left = head;
        ListNode* right = rightHeadRev;
        ListNode* prev = right;

        while(left != NULL && right != NULL){
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            prev = right;
            left = nextLeft;
            right = nextRight;
        }
        if(right != NULL){
            prev->next = right;
        }

    }
};