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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* dummynode = new ListNode(-1);

        ListNode* curr = dummynode;

        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {

            int sum = carry;

            if (temp1 != NULL) {
                sum = sum + temp1->val;
            }

            if (temp2 != NULL) {
                sum = sum + temp2->val;
            }

            ListNode* newn = new ListNode(sum % 10);

            carry = sum / 10;

            curr->next = newn;
            curr = curr->next;

            if (temp1 != NULL) {
                temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                temp2 = temp2->next;
            }
        }

        if (carry != 0) {
            curr->next = new ListNode(carry);
        }

        return dummynode->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna