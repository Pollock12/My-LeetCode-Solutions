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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* pre = head;
        ListNode* curr = head->next;
        int position = 1;
        int prev_cri = -1, curr_cri = -1, first_cri = -1;
        int mn = 1e9, mx = -1;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            if ((curr->val > pre->val && curr->val > next->val) ||
                (curr->val < pre->val && curr->val < next->val)) {
                if (prev_cri == -1) {
                    prev_cri = position;
                } else if (curr_cri == -1) {
                    curr_cri = position;
                } else {
                    prev_cri = curr_cri;
                    curr_cri = position;
                }
                if (first_cri == -1) {
                    first_cri = position;
                }
                if (prev_cri != -1 && curr_cri != -1)
                    mn = min(mn, curr_cri - prev_cri);
            }
            pre = curr;
            curr = next;
            position++;
        }
        if (mn == 1e9)
            mn = -1;
        if (first_cri != -1 && curr_cri != -1) {
            mx = curr_cri - first_cri;
        }
        return {mn, mx};
    }
};