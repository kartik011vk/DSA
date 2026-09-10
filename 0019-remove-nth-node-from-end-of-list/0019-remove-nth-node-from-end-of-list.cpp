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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head ; 
        ListNode* slow = head ;
        
        for (int i = 0; i < n; i++){
            first = first-> next ;
        }
           if (first == NULL) {
            ListNode* deletion = head;
            head = head->next;
            delete deletion;
            return head;
        }
        
        while (first->next != NULL){
            slow = slow->next ;
            first = first->next ; 
        }
        ListNode* deletion = slow->next; 
        slow->next = slow->next->next ; 
        delete(deletion) ; 
        return head ; 

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna