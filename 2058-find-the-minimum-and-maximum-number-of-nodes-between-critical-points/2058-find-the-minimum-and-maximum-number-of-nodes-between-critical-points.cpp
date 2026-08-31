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
        vector<int> positionList;

        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            if ((curr->val > pre->val && curr->val > next->val) ||
                (curr->val < pre->val && curr->val < next->val)) {
                positionList.push_back(position);
            }
            pre = curr;
            curr = next;
            position++;
        }
        if (positionList.size() < 2) {
            return {-1, -1};
        } else {
            int mn=positionList[1]-positionList[0], mx;
            int n = positionList.size();
            for (int i = 1; i < n; i++) {
                mn = min(mn, positionList[i] - positionList[i - 1]);
            }
            mx = positionList[n - 1] - positionList[0];
            return {mn, mx};
        }
    }
};