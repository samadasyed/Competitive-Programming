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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ((!list1) && (!list2)){
            return nullptr; 
        }
        
        if (!list1) {
            return list2; 
        }
        if (!list2) {
            return list1; 
        }

        ListNode dummy(0); 
        ListNode* current = &dummy; 

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1; 
                list1 = list1->next; 
            }

            else { 
                current->next = list2; 
                list2= list2->next; 
            }
            current = current->next; 
        }
        if (list1 != nullptr) {
            current->next = list1; 
        }
        else {
            current->next = list2; 
        }
        return dummy.next;


    }
};

/**
      ListNode* newList; 
        while (list1->next != nullptr && list2->next !=nullptr){
            if (list1->val > list2->val) {
                newList->next->val = list1->val; 
            }
            else if (list2->val > list1->val) {
                newList->next->val = list2->val; 
            }
        }
        return newList; 
        
**/