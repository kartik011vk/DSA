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

    ListNode* find_middle(ListNode* head){
        ListNode* fast = head->next ; 
        ListNode* slow = head ; 
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next ; 
            fast = fast->next->next ; 
        }
        return slow ; 
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* t1 = left ; 
        ListNode* t2 = right ; 
        ListNode* dummyn = new ListNode (-1) ;
        ListNode* temp = dummyn ; 
        while(t1!= NULL && t2!= NULL){
            if (t1->val < t2->val){
                temp->next = t1 ; 
                temp = t1;
                t1 = t1->next ; 
            }
            else{
                temp->next = t2 ; 
                temp = t2; 
                t2 = t2->next ; 
            }

        }
        if(t1){
            temp->next = t1 ; 

        }
        if(t2){
            temp->next = t2 ; 
        }
        return dummyn->next ; 
    }
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head-> next == NULL){
            return head ; 
        }

        ListNode* middle = find_middle(head) ;
        ListNode* left = head ; 
        ListNode* right = middle -> next ; 
        middle->next = NULL ; 

        left = sortList(left) ;
        right = sortList(right) ;
        return merge(left ,right); 

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna