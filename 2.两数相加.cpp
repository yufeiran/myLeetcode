// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
        int Len1=0;
        int Len2=0;
        ListNode*nowL1=l1;
        ListNode*nowL2=l2;

        while(nowL1!=nullptr){
            nowL1=nowL1->next;
            Len1++;
        }
        while(nowL2!=nullptr){
            nowL2=nowL2->next;
            Len2++;
        }
        nowL1=l1;
        nowL2=l2;

        //找到大串的
        int maxIndex=(Len1>Len2)?1:2;
        ListNode* newL=(Len1>Len2)?l1:l2;
        ListNode* lastNewL=nullptr;
        ListNode* beginNewL=newL;
        ListNode* subL=(Len1>Len2)?l2:l1;
        //为大串的加小串
        int inc=0;
        while(subL!=nullptr){
            int nowVal=newL->val+subL->val+inc;
            inc=0;
            if(nowVal>=10){
                inc=1;
                nowVal-=10;
            }
            newL->val=nowVal;

            subL=subL->next;
            lastNewL=newL;
            newL=newL->next;

            
        }
        if(Len1!=Len2){
            while(newL!=nullptr){
                int nowVal=newL->val+inc;
                inc=0;
                if(nowVal>=10){
                    inc=1;
                    nowVal-=10;
                }
                newL->val=nowVal;
                if(newL->next==nullptr){
                    lastNewL=newL;
                    break;
                }
                else{
                    lastNewL=newL;
                    newL=newL->next;
                }

            }
        }
        
        if(inc!=0)
        {
            ListNode* temp=new ListNode(1);
            lastNewL->next=temp;
        }

        return beginNewL;
    }
};
// @lc code=end

