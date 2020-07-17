//21. 合并两个有序链表
//https://leetcode-cn.com/problems/merge-two-sorted-lists/
//https://leetcode.com/problems/merge-two-sorted-lists/discuss/9715/Java-1-ms-4-lines-codes-using-recursion
//递归法还是不太明白
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode Head(0), *pre = &Head;
        while (l1 && l2) {
            if(l1->val < l2->val) {
                pre->next = l1; //pre的下一个节点为 l1
                l1 = l1->next;
            }
            else {
                pre->next = l2;//pre的下一个节点为 l2
                l2 = l2->next;
            }
            pre = pre->next;
        }
	// 合并后 l1 和 l2 最多只有一个还未被合并完，直接将链表末尾指向未合并完的链表即可
        pre->next = l1 == NULL? l2 : l1;
        return Head.next;
    }
};