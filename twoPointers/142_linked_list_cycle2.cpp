/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //fast and slow pointers
    //assuming when they meet, slow moves (a+b) steps, fast moves (a + (b+c)*n + b) steps and fast moves 2 times of distance as slow.
    //therefore, we conclude that a = (b+c)*(n-1) + c
    //considering now 'slow' is b distance away from the "pos" position, it takes (c + (b+c)*n ) steps move forward to 'pos'
    //now, we set a new pointer ptr at head, and move str and slow simultaneously, finally they meet at the 'pos', if exist
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};


class Solution {
public:
    //hash 
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;

        while(head != nullptr){
            if(visited.count(head)){
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
