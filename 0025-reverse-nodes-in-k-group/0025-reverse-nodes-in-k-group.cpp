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

    ListNode* reverse(ListNode* head){
        ListNode* temp = head ; 
        ListNode* next = head->next ; 
        ListNode*previous = NULL  ; 
        while (temp != NULL){
            ListNode* next = temp->next ; 
            temp->next = previous ;
            previous = temp ; 
            temp = next ; 

        }
        return head ; 

    }

    ListNode* findknode(ListNode* head , int k){

        k = k-1 ; 
        ListNode* temp = head ; 
        while(temp != NULL && k >0){
            k-- ; 
            temp = temp->next ; 
        }
        return temp ;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head ;
        ListNode* prevnode = NULL ; 
        while(temp!= NULL){

            ListNode* knode = findknode(temp, k) ; 
            if (knode == NULL){
                if(prevnode){
                    prevnode->next = temp ; 
                    break ;
                }
            }
            ListNode* nextnode = knode->next ; 
            knode->next = NULL ; 
            reverse(temp) ; 
            if (temp == head){
                head = knode ; 
            }
            else{
                prevnode->next = knode ; 
            }
            prevnode = temp ; 
            temp = nextnode ; 
        }
        return head ; 
        
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna