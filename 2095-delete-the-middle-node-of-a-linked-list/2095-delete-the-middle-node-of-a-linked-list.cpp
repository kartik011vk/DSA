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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head ; 
        if (temp == NULL || temp->next == NULL){
            return NULL ; 
        }
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        fast = fast->next->next ; 
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next ; 
            fast = fast->next->next ; 
        }
        ListNode* middle = slow -> next ; 
        slow->next = slow->next->next ; 
        delete(middle) ; 
        return head ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna