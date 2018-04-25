/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        vector<int> v;
        ListNode* cur = head;
        while(cur) {
        	v.push_back(cur->val);
        	cur = cur->next;
        }
        int n = v.size();
        TreeNode* res =  helper(v,0,n-1);
        return res;
    }

    TreeNode* helper(vector<int>& v,int begin,int end) {
    	if(begin>end) return nullptr;
    	else if(begin == end) return new TreeNode(v[end]);
    	else {
    		int mid = begin + (end - begin) / 2;
    		TreeNode* res = new TreeNode(v[mid]);
    		res->left = helper(v,begin,mid-1);
    		res->right = helper(v,mid+1,end);
    		return res;
    	}
    }
};

//采用链表的方法 其实时间复杂度是一样的
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        return dfs(head,NULL);
    }

    TreeNode* dfs(ListNode* head , ListNode* tail){


        if(head==tail)
            return NULL;

        if( head->next == tail ){
    		TreeNode *root = new TreeNode( head->val );
    		return root;
    	}

        ListNode *slow,*fast;
        slow = fast =head;

        while(fast!=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        root->left = dfs(head,slow);
        root->right = dfs(slow->next,tail);

        return root;
    }



};