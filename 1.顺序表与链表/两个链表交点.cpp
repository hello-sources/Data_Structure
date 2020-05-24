/*************************************************************************
    > File Name: 两个链表交点.cpp
    > Author: ltw
    > Mail: 3245849061@qq.com 
    > Created Time: Sun 24 May 2020 03:27:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


/*ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */

ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    //方法一
	// ListNode *p, *q;
    // int ans1 = 0, ans2 = 0;
    // p = head1, q = head2;
    // while (p) ans1++, p = p->next;
    // while (q) ans2++, q = q->next;
    // int sum = ans1 - ans2;
    //  p = head1, q = head2;
    // if (sum > 0) {
    //     while(sum--) p = p->next;
    //     while (p != q) {
    //         p = p->next;
    //         q = q->next;
    //     } 
    // } else {
    //     while (sum++) q = q->next;
    //     while (p != q) {
    //         p = p->next;
    //         q = q->next;
    //     }
    // }
    // return p;
	//方法二
    ListNode *p1 = head1, *p2 = head2;
    while (p1 != p2) {
        if (p1 == NULL) p1 = head2;
        if (p2 == NULL) p2 = head1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
