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
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCriticalIdx = -1;
        int prevCriticalIdx = -1;
        int minDist = INT_MAX;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int currentIndex = 1;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            bool isMaxima = (curr->val > prev->val) && (curr->val > nextNode->val);
            bool isMinima = (curr->val < prev->val) && (curr->val < nextNode->val);

            if (isMaxima || isMinima) {
                if (firstCriticalIdx == -1) {
                    firstCriticalIdx = currentIndex;
                } else {
                    minDist = min(minDist, currentIndex - prevCriticalIdx);
                }
                prevCriticalIdx = currentIndex;
            }

            prev = curr;
            curr = curr->next;
            currentIndex++;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        int maxDist = prevCriticalIdx - firstCriticalIdx;
        return {minDist, maxDist};
    }
};
