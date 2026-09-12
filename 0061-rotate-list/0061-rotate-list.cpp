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
    ListNode* find_n_node(ListNode* head, int n ){
        int cnt = 1 ; 
        ListNode* temp = head ; 
        while(temp != NULL){
            if(cnt == n){
                return temp ; 
            }
            temp = temp->next ; 
            cnt ++ ;
        }
        return temp ; 
    }


    ListNode* rotateRight(ListNode* head, int k) {

        int len = 1;
        ListNode* tail = head ;
        if( head == NULL || k == 0 ){
            return head ;
        }
        while (tail->next != NULL ){
            tail = tail-> next ; 
            len++ ; 
        }
        if (k % len == 0){
            return head ;
        }
        k = k % len ; 
        tail-> next = head ; 
        ListNode* new_last_node = find_n_node( head, len - k ); 
        head = new_last_node->next ; 
        new_last_node ->next = NULL ; 
        return head ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna