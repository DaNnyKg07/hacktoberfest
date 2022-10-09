#include<bits/stdc++.h>
using namespace std;
struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return head;
        //  cout<<"call"<<head->val<<endl;
        if(k==1)
            return head;
          ListNode* curr=head;
          ListNode* prev=NULL;
          ListNode* next=NULL;
        
        for(int i=1;i<=k;i++)
        {   if(curr==NULL)
            return head;
            cout<<curr->val<<endl;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
           
        }
        head->next=reverseKGroup(curr,k);
        return prev;
        
        
        
    }
