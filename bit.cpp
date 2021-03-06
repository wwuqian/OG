//1.集合栈
//class SetOfStacks {
//public:
//	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
//		// write code here
//		vector<vector<int>> ret;
//		if(ope.empty() || size == 0)
//			return ret;
//		for(int i = 0;i < ope.size(); ++i)
//		{
//			//如果是入栈操作，每个操作的第一个数代表操作类型：1
//			if(ope[i][0] == 1)
//			{
//				//如果当前不存在stack，或者当前的stack已经满了
//				//就建立一个新的stack
//				if(ret.empty() || ret.back().size() == size)
//				{
//					vector<int> tmp;
//					tmp.push_back(ope[i][1]);
//					ret.push_back(tmp);
//				}
//				else  //直接在当前stack压入元素
//				{
//					ret.back().push_back(ope[i][1]);
//				}
//			}
//			//出栈操作
//			else if(ope[i][0] == 2)
//			{
//				//如果当前栈是空的，那么就将空栈丢掉，并在前一个栈弹出一个元素
//				if(ret.back().empty())
//				{
//					ret.pop_back();
//					ret.back().pop_back();
//				}
//				//在当前栈中直接弹出栈
//				else
//					ret.back().pop_back();
//			}
//		}
//		return ret;
//	}
//};

//2.双栈排序
//class TwoStacks {
//public:
//	vector<int> twoStacksSort(vector<int> numbers) {
//		// write code here
//		vector<int> assist;  //辅助栈
//		int length = numbers.size();
//		if(length == 0)
//			return assist;
//		while(numbers.size() != 0)
//		{
//			int tmp = numbers.back();
//			numbers.pop_back();
//			while(assist.size() != 0 && tmp < assist.back())
//			{
//				numbers.push_back(assist.back());
//				assist.pop_back();
//			}
//			assist.push_back(tmp);
//		}
//		while(assist.size() != 0)
//		{
//			numbers.push_back(assist.back());
//			assist.pop_back();
//		}
//		return numbers;
//	}
//};

//3.用两个栈实现队列
//class Solution
//{
//public:
//	void push(int node) {
//		stack1.push(node);
//	}
//
//	int pop() {
//		int tmp;
//		while(stack2.empty())
//		{
//			while(!stack1.empty())
//			{
//				tmp = stack1.top();
//				stack2.push(tmp);
//				stack1.pop();
//			}
//		}
//		tmp = stack2.top();
//		stack2.pop();
//		return tmp;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};

//4.用递归函数和栈操作逆序栈
//class ReverseStack {
//public:
//	int level = 0;
//	vector<int> reverseStackRecursively(vector<int> stack, int top){
//		if(top > 0){
//			int val = stack[top-1];
//			++level;
//			stack = reverseStackRecursively(stack,top-1);
//			--level;
//			stack[level] = val;
//		}
//		return stack;
//	}
//};
//#include<iostream>
//#include<vector>
//using namespace std;
//class ReverseStack {
//public:
//	vector<int> reverseStackRecursively(vector<int> stack,int top) 
//	{
//		top--;
//		if(top == -1||top == 0) 
//			return stack;
//		reverseStack(stack,top);
//		return stack;
//	}
//
//	int getAndRemoveLastElem(vector<int> &stack,int &top)
//	{
//
// 		int res = stack[top--];
//		if(top == -1)
//			return res;
//		int last = getAndRemoveLastElem(stack,top);
//		stack[++top] = res; 
//		return last;
//	}
//
//	void reverseStack(vector<int> &stack,int &top)
//	{
//		if(top == -1) 
//			return;
//		int last = getAndRemoveLastElem(stack,top);
//		reverseStack(stack,top);
//		stack[++top] = last;
//	}
//};
//
//int main()
//{
//	ReverseStack stack;
//	vector<int> v;
//	vector<int> ret;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	for(int i = 0;i < 5; ++i)
//		cout << v[i] << " ";
//	cout << endl;
//	ret = stack.reverseStackRecursively(v,5);
//	for(int i = 0;i < 5; ++i)
//		cout << ret[i] << " ";
//	cout << endl;
//
//	return 0;
//
//}

//5.把二叉树打印成多行
//#include<queue>
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//class Solution {
//public:
//        vector<vector<int> > Print(TreeNode* pRoot) {
//            vector<vector<int>> res;
//            if(pRoot == NULL)
//                return res;
//            queue<TreeNode*> q;
//            q.push(pRoot);
//            while(!q.empty())
//            {
//                vector<int> vec;
//                int size = q.size();
//                for(int i = 0;i < size; i++)
//                {
//                    TreeNode* temp = q.front();
//                    vec.push_back(temp->val);
//                    if(temp->left)
//                        q.push(temp->left);
//                    if(temp->right)
//                        q.push(temp->right);
//                    q.pop();
//                }
//                res.push_back(vec);
//            }
//            return res;
//        }
//};

//6.对称的二叉树
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//class Solution {
//public:
//    bool isSymmetrical(TreeNode* pRoot)
//    {
//        if(pRoot == NULL)
//            return true;
//        return isSymmetricalCore(pRoot->left,pRoot->right);
//    }
//    
//    bool isSymmetricalCore(TreeNode* left,TreeNode* right)
//    {
//        if(left == NULL && right == NULL)
//            return true;
//        if(left == NULL || right == NULL)
//            return false;
//        if(left->val == right->val)
//            return isSymmetricalCore(left->right,right->left)
//                   && isSymmetricalCore(left->left,right->right);
//        return false;
//    }
//};

//7.二叉树的深度
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//class Solution {
//public:
//    int TreeDepth(TreeNode* pRoot)
//    {
//        if(pRoot == NULL)
//            return 0;
//        int leftLength = TreeDepth(pRoot->left) + 1;
//        int rightLength = TreeDepth(pRoot->right) + 1;
//        return leftLength >= rightLength ? leftLength : rightLength;
//            
//    }
//};

//8.binary-tree-preorder-traversal:二叉树的前序遍历
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int > vec;
//        stack<TreeNode*> s;
//        if(root != NULL)
//        {
//            s.push(root);
//            while(!s.empty())
//            {
//                root = s.top();
//                s.pop();
//                vec.push_back(root->val);
//                if(root->right)
//                    s.push(root->right);
//                if(root->left)
//                    s.push(root->left);
//            }
//        }
//        return vec;
//    }
//};

//9.输入一颗二叉树，判断该二叉树是否是平衡二叉树。
//左子树和右子树的高度差不超过1
//class Solution {
//public:
//	bool IsBalanced_Solution(TreeNode* pRoot) {
//		if(pRoot == NULL)
//			return true;
//		int left = GetDepth(pRoot->left);
//		int right = GetDepth(pRoot->right);
//		if(abs(left-right) <= 1)
//			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
//		else
//			return false;
//	}
//
//	//求二叉树的深度
//	int GetDepth(TreeNode* pRoot)
//	{
//		if(pRoot == NULL)
//			return true;
//		int leftLength = GetDepth(pRoot->left);
//		int rightLength = GetDepth(pRoot->right);
//		return leftLength >= rightLength ? leftLength+1:rightLength+1;
//	}
//};

//10.binary-tree-postorder-traversal：二叉树的后序遍历
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode *root) {
//        vector<int > vec;
//        stack<TreeNode*> s;
//        deque<int > deq;
//        if(root != NULL)
//        {
//            s.push(root);
//            while(!s.empty())
//            {
//                root = s.top();
//                s.pop();
//                deq.push_front(root->val);
//                if(root->left)
//                    s.push(root->left);
//                if(root->right)
//                    s.push(root->right);
//            }
//            while(!deq.empty())
//            {
//                vec.push_back(deq.front());
//                deq.pop_front();
//            }
//        }
//        return vec;
//    }
//};

//11.binary-tree-maximum-path-sum:二叉树任意路径上的最大值
//链接：https://www.nowcoder.com/questionTerminal/da785ea0f64b442488c125b441a4ba4a
//来源：牛客网

//Given a binary tree, find the maximum path sum.
//
//The path may start and end at any node in the tree.
//
//For example:
//Given the below binary tree,
//
//1
/// \
//2   3
//
//Return6.
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    int res;
//    int maxPathSum(TreeNode *root) {
//        res = INT_MIN;
//        maxSum(root);
//        return res;
//    }
//    
//    int maxSum(TreeNode* root)
//    {
//        if(root == NULL)
//            return 0;
//        int left_Max = max(0,maxSum(root->left));
//        int right_Max = max(0,maxSum(root->right));
//        res = max(res, left_Max + right_Max + root->val);
//        return max(left_Max,right_Max) + root->val;
//    }
//};

//class Solution {
//public:
//    int maxPathSum(TreeNode *root) {
//        int Max_sum = INT_MIN;
//        maxSum(root);
//        return res;
//    }
//    
//    int maxSum(int& Max_sum, TreeNode* root)
//    {
//        if(root == NULL)
//            return 0;
//        int left = maxSum(Max_sum, root->left));
//        int right = maxSum(Max_sum, root->right));
		  //int sum = root->val;
//        if(left > 0)
			//sum += left;
		 // if(right > 0)
			//  sum += right;
		 // Max_sum = max(Max_sum,sum);
		 // int tmp = max(left,right);
//        return tmp > 0 ? tmp + root->val:root->val;
//    }
//};

//用队列实现：
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//	int maxPathSum(TreeNode *root) {
//		if (root == 0) 
//			return 0;
//		
//		queue<TreeNode*> q;
//		q.push(root);
//		int max = root->val;
//		while (!q.empty()) {
//		TreeNode *node = q.front();
//		q.pop();
//		int left = maxPathSumCore(node->left);
//		int right = maxPathSumCore(node->right);
//		int cur = node->val;
//		if (left > 0) 
//  		   cur += left;
//		
//		if (right > 0) 
//  		   cur += right;
//		
//		if (cur > max) 
//  		   max = cur;
//		
//		if (node->left != 0) 
//  		   q.push(node->left);
//		
//		if (node->right != 0) 
//  		   q.push(node->right);
//		
//		}
//		return max;
//	}
//
//	int maxPathSumCore(TreeNode *node) {
//		if (node == 0) {
//			return 0;
//		}
//		int left = maxPathSumCore(node->left);
//		int right = maxPathSumCore(node->right);
//		int max = node->val;
//
//		int bigger = left >= right ? left : right;
//
//		if (bigger > 0) {
//			max += bigger;
//		}
//		return max;
//	}
//};

//12.






//13.recover-binary-search-tree:
//链接：https://www.nowcoder.com/questionTerminal/67c7172122b54b748e78eac7b183b5f3
//来源：牛客网
//
//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.


//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
// 
//class Solution {
//public:
//    TreeNode *pre,*a,*b;
//    void recoverTree(TreeNode *root) {
//			pre = a = b = NULL;
//			dfs(root);
//			if(a && b) 
//               swap(a->val,b->val);
//    }
//    void dfs(TreeNode *root){
//         if(root == NULL) return;
//         dfs(root->left);
//         if(pre && pre->val > root->val){
//         	if(a == NULL)
//						a=pre;
//           b=root;
//         }
//         pre=root;
//         dfs(root->right);
//    }
//};

//14.validate-binary-search-tree
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    TreeNode* pre = NULL;
//    bool isValidBST(TreeNode *root) {
//        if(root != NULL){
//            if(isValidBST(root->left) == false)
//                return false;
//            if(pre != NULL && root->val <= pre->val)
//                return false;
//            pre = root;
//            return isValidBST(root->right);
//        }
//        return true;
//    }
//};

//15.two-sum
//class Solution {
//public:
//	vector<int> twoSum(vector<int> &numbers, int target) {
//		unordered_map<int,int> map;
//		vector<int> res;
//		for(int i = 0;i < numbers.size();++i)
//		{
//			//  numbers中存在两个数的和为target
//			if(map.count(target - numbers[i]))
//			{
//				//返回的下表从1开始
//				res.push_back(map[target - numbers[i]] + 1);
//				res.push_back(i + 1);
//				break;
//			}
//			if(map.count(numbers[i]) != 1)
//				map[numbers[i]] = i;
//		}
//		return res;
//	}
//};

//16.牛客网：到底买不买（20）
//输入：ppRYYGrrYBR2258
//      YrR8RrY
//输出：Yes 8

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main()
//{
//	int hash[128] = {0};
//	char a[1010],b[1010];
//	cin >> a >> b;
//	int len1 = strlen(a);
//	int len2 = strlen(b);
//	for(int i = 0;i < len1;++i)
//		hash[a[i]]++;
//	int num = 0;
//	for(int i = 0;i < len2; ++i)
//	{
//		if(hash[b[i]] > 0){
//			hash[b[i]]--;
//			num++;
//		}
//	}
//	if(num == len2)
//		cout << "Yes" << " " << len1-num <<'\n';
//	else
//		cout << "No" << " " << len2-num << '\n';
//	return 0;
//}

//17.牛客网：旧键盘（20）
//输入：
//7_This_is_a_test
//
//_hs_s_a_es
//输出：
//7TI

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1,s2;
//	cin >> s1 >> s2;
//	bool hash[256] = {false};
//	int len1 = s1.length();
//	int len2 = s2.length();
//	for(int i = 0;i < len2; ++i)
//	{
//		s2[i] = towupper(s2[i]);
//		hash[s2[i]] = true;
//	}
//	for(int i = 0;i < len1; ++i)
//	{
//		s1[i] = towupper(s1[i]);
//		if(hash[s1[i]] == false) //说明键盘换掉了
//			cout << s1[i];
//		//意思是让换掉的键只输出一次。输出后，将这个值的hash位置置true，下次就不会再输出
//		hash[s1[i]] = true; 
//	}
//
//	return 0;
//}

//18.末尾0的个数：

//把所有的数字进行分解质因数，例如：
//6 = 2*3
//15 = 3*5
//64 = 2*2*2*2*2*2 = 2^6
//100 = 2^2 * 5^2
//576 = 2^6 * 3^2
//那么我们在计算n的阶乘时，实际上就是把所有小于等于n的正整数分解成质因数，然后再将其乘到一起，那么末尾0的个数实际上就是2*5的个数，而2的个数明显是很多很多的，所以问题就转化成了5的个数。
//而只有5的倍数才有5这个因数，所以，问题就进一步简化为小于等于n的数中有多少个数是5的倍数

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n,count = 0;
//	cin >> n;
//	while(n /= 5)
//		count += n;
//	cout << count << endl;
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//int countFactZeros(int num) {
//	int count = 0;
//	if (num < 0) return -1;
//
//	for (int i = 5; num / i > 0; i *= 5) {
//		count += num / i;
//	}
//
//	return count;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	cout << countFactZeros(n) << endl;
//
//	return 0;
//}

//19.无线OSS-高精度整数加法
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//string add(string num1,string num2)
//{
//	string result;
//	int c = 0; //用于进位
//	int temp;  //用于临时保存按位相加后的结果
//	if(num1.size() != num2.size()){//两个操作数的长度不相同，先补零
//		while(num1.size() < num2.size())
//			num1.insert(0,1,'0');
//		while(num2.size() < num1.size())
//			num2.insert(0,1,'0');
//	}
//	if(num1[0] != '-' && num2[0] != '-'){//两个数同为正数
//		for(int i = num1.size()-1; i >= 0; --i)
//		{
//			//按位相加，从低位开始
//			temp = (int)(num1[i]-'0')+(int)(num2[i]-'0') + c;
//			if(temp > 9){
//				temp = temp % 10; //两数相加大于10，只保留个位数
//				c = 1; //进位
//			}
//			else
//				c = 0; //进位清0
//			result += to_string(temp);
//		}
//		if(c == 1)
//			result += '1'; //最高位还有进位，则补一个‘1’
//		//result是从低位往高位进行添加相加的结果，逆置字符串后就是相加后的结果
//		reverse(result.begin(),result.end()); 
//	}
//	else if(num1[0] == '-' && num2[0] == '-'){ //两个操作数均为负数‘-’
//		for(int i = num1.size()-1; i > 0; i--){
//			//负数的最高位位符号位，不用管
//			temp = (int)(num1[i]-'0') + (int)(num2[i]-'0') + c;
//			if(temp > 9){
//				temp = temp % 10;
//				c = 1;
//			}
//			else
//				c = 0;
//			result += to_string(temp);
//		}
//		if(c == 1)
//			result += '1'; //最高位有进位
//		result += '1';
//		reverse(result.begin(),result.end());
//	}
//	return result;
//}
//
//int main()
//{
//	string num1,num2;
//	while(cin >> num1 >> num2){
//		cout << add(num1,num2) << endl;
//	}
//	return 0;
//}

//20.word-ladder :有难度，没看懂
//class Solution {
//public:
//
//	int ladderLength(string start, string end, unordered_set<string>&dict)
//	{
//		queue<string> q;
//		q.push(start);
//		int res = 1;
//		while (!q.empty())
//		{
//			int qsize = q.size(); //层次遍历，记录当前队列大小
//			while (qsize--)
//			{
//				string cur_front = q.front();
//				q.pop();
//				int size = cur_front.size();
//				for (int i = 0; i < size; i++)
//				{
//					char ch = cur_front[i];  //对队列头字符串每一个字符进行替换
//					for (int j = 0; j < 26; j++)
//					{
//						cur_front[i] = 'a' + j;//替换字符
//						if (cur_front == end)
//							return res+1;//找到答案，退出
//						if (dict.find(cur_front) != dict.end())
//						{
//							q.push(cur_front);//变换在字典中找到了
//							dict.erase(cur_front);//从字典中删除
//						}
//					}
//					cur_front[i] = ch;//还原队列头字符串，因为有可能在字典中可以找到多个“近邻字符串”
//				}
//			}
//			res++;//遍历一层，res+1
//		}
//		return 0;
//	}
//};

//21.search-in-rotated-sorted-array-ii
//class Solution {
//public:
//	bool search(int A[], int n, int target) {
//		if (A == NULL || n == 0) 
//			return false;
//		int left = 0, right = n - 1;
//		while (left <= right) {
//			int mid = (left + right) / 2;
//			if (A[mid] == target) 
//				return true;
//			else if (A[mid] < A[right]) {
//				if (A[mid] < target && A[right] >= target) 
//					left = mid + 1;
//				else 
//					right = mid - 1;
//			}
//			else if (A[mid] > A[right]){
//				if (A[left] <= target && A[mid] > target) 
//					right = mid - 1;
//				else 
//					left = mid + 1;
//			} 
//			else 
//				--right;
//		}
//		return false;
//	}
//};

//22.search-in-rotated-sorted-array


//23.word-search
//class Solution {
//public:
//	bool exist(vector<vector<char> > &board, string word) {
//		int row = board.size(); //行
//		int col = board[0].size(); //列
//		for(int i = 0;i < row;i++)
//			for(int j = 0;j < col;j++)
//				if(DFS(board,i,j,0,word))
//					return true;
//		return false;
//	}
//
//	bool DFS(vector<vector<char> > &board,int i,int j,int s,string word)
//	{
//		int row = board.size();
//		int col = board[0].size();
//		if(i < 0 || j < 0 || i >= row || j >= col)
//			return false;
//		if(word[s] == board[i][j])
//		{
//			if(s == word.size()-1)
//				return true;
//			char ch = board[i][j];
//			//原二维数组中将遍历过的用‘*’标记，
//			//还有一种方法是创建一个和原数组大小相同的数组，将遍历过的位置置为true
//			board[i][j] = '*';
//			bool flag = ( DFS(board,i-1,j,s+1,word) ||
//				DFS(board,i,j+1,s+1,word) ||
//				DFS(board,i+1,j,s+1,word) ||
//				DFS(board,i,j-1,s+1,word) );
//			board[i][j] = ch;
//			return flag;
//		}
//		return false;
//	}
//};

//24.set-matrix-zeroes
//class Solution {
//public:
//	void setZeroes(vector<vector<int> > &matrix) {
//		int m = matrix.size();
//		int n = matrix[0].size();
//		if(m == 0 || n == 0)
//			return;
//		bool row = false;
//		bool col = false;
//		//验证第一列是否有0
//		for(int i = 0;i < m;i++){
//			if(matrix[i][0] == 0){
//				col = true;
//				break; //跳出for循环
//			}
//		}
//		//验证第一行是否有0
//		for(int j = 0;j < n;j++){
//			if(matrix[0][j] == 0){
//				row = true;
//				break; 
//			}
//		}
//
//		//标记数组，用第一行和第一列记录0的位置
//		for(int i = 1;i < m;i++)
//		{
//			for(int j = 1;j < n;j++)
//			{
//				//当某元素为0，则将(0,j)这个元素置0；(i,0)这个元素置0
//				if(matrix[i][j] == 0){
//					matrix[i][0] = 0;
//					matrix[0][j] = 0;
//				}
//			}
//		}
//
//		//根据标记数组进行清零，将第i行，第j列进行清零
//		for(int i = 1;i < m;i++)
//		{
//			for(int j = 1;j < n; j++)
//				if(0 == matrix[i][0] || 0 == matrix[0][j])
//					matrix[i][j] = 0;
//		}
//
//		//如果原来的数组的第一行有0，处理第一行
//		if(row)
//			for(int j = 0;j < n;j++)
//				matrix[0][j] = 0;
//
//		if(col)
//			for(int i = 0;i < m;i++)
//				matrix[i][0] = 0;
//	}
//};  

//25.search-for-a-range
//class Solution {
//public:
//	vector<int> searchRange(int A[], int n, int target) {
//		vector<int> res;
//		if(A == NULL || n < 0)
//			return res;
//		int low = 0,high = n-1,mid;
//		int start = -1;
//		int end = -1;
//		while(low <= high)
//		{
//			mid = (low+high)/2;
//			if(A[mid] > target)
//				high = mid-1;
//			else if(A[mid] < target)
//				low = mid + 1;
//			else //A[mid] == target
//			{
//				int index = mid;
//				//向左夹逼
//				while(index >= 0 && A[index] == target)
//					index--;
//				start = index + 1; //记录左边界
//				index = mid;
//				//向右夹逼
//				while(index < n && A[index] == target)
//					index++;
//				end = index - 1; //记录右边界
//				break;
//			}
//		}
//		res.push_back(start);
//		res.push_back(end);
//		return res;
//	}
//};

//26.search-insert-position
//class Solution {
//public:
//	int searchInsert(int A[], int n, int target) {
//		int low = 0,high = n-1;
//		int mid;
//		while(low <= high)
//		{
//			mid = (low + high)/2;
//			if(A[mid] == target)
//				return mid;
//			else if(A[mid] < target)
//				low = mid + 1;
//			else
//				high = mid - 1;
//			//如果low==high时，都没找见，就说明数组中没有该元素
//			//该元素应该在此时的low位置
//		}
//		return low;
//	}
//};

//27.leetcode: combination
//class Solution {
//public:
//	vector<vector<int> > combine(int n, int k) {
//		vector<vector<int> > res;
//		vector<int> path;
//		DFS(res,path,n,k,1);
//		return res;
//	}
//
//	void DFS(vector<vector<int> > &res,vector<int> &path,int n,int k,int start){
//		if(path.size() == k)
//			res.push_back(path);
//		for(int i = start;i <= n; ++i)
//		{
//			path.push_back(i);
//			DFS(res,path,n,k,i+1);
//			path.pop_back();
//		}
//	}
//};

//28.sqrtx:求一个整数的平方根
//二分法：
//class Solution {
//public:
//	int sqrt(int x){
//		if(x<=1) 
//			return x;
//		
//		int begin = 1;
//		int end = x;
//		int mid = 0;
//		while(begin <= end) {
//			mid = begin + (end - begin)/2;
//			//不要写成middle*middle==x，会溢出
//			if(mid == x/mid)
//			{
//				return mid;
//			} 
//			else
//			{
//				if (mid < x/mid) 
//					begin = mid + 1;
//				else 
//					end = mid - 1;
//			}
//		} 
//		//结束条件end一定<begin，所以返回end
//		return end;
//	}
//};

//牛顿法：y(n+1) = y(n) + (x / y(n))/2
//class Solution {
//public:
//	int sqrt(int x) {
//		if (x == 0) 
//			return 0;
//		double lastY = 0;
//		double y = 1;
//		while (y != lastY)
//		{
//			lastY = y;
//			y = (y + x / y) / 2;
//		}
//		return (int)(y);
//	}
//};

//29.restore-ip-address ：IP地址的转换
//class Solution {
//public:
//	vector<string> restoreIpAddresses(string s) {
//		vector<string> res;
//		string tmp;
//		DFS(res,tmp,s,0);
//		return res;
//	}
//	void DFS(vector<string> &res,string tmp,string s,int count){
//		if(count == 3 && isValid(s)) //合法并且个数为3
//		{
//			res.push_back(tmp+s);
//			return;
//		}
//		for(int i = 1;i < 4 && i < s.size(); ++i){
//			string sub = s.substr(0,i);
//			if(isValid(sub))
//				DFS(res,tmp+sub+'.',s.substr(i),count+1);
//		}
//	}
//
//	bool isValid(string &s){
//		stringstream ss(s);
//		int num;
//		ss >> num; //将字符串转化为整型
//		//num = atoi(s.c_str());
//		if(s.size() > 1)
//			return s[0] != '0' && num >= 0 && num <= 255;
//		return num >= 0 && num <= 255;
//	}
//}; 
//30.permutations :全排列
//class Solution {
//public:
//	vector<vector<int> > permute(vector<int> &num) {
//		vector<vector<int>> res;
//		if(num.size() == 0)
//			return res;
//		sort(num.begin(),num.end());
//		DFS(num,res,0);
//		return res;
//	}
//	void DFS(vector<int> &num,vector<vector<int>> &res,int begin){
//		if(begin == num.size())
//			res.push_back(num);
//		for(int i = begin;i < num.size();i++){
//			swap(num[i],num[begin]);
//			DFS(num,res,begin+1);
//			swap(num[i],num[begin]);
//		}
//	}
//};

//31.二进制中1的个数
//最优解：
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		while(n != 0){
//			++count;
//			n = n & (n-1);
//		}
//		return count;
//	}
//};

//一般解：
//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		int flag = 1;
//		//用n的每一位和1进行按位与，结果为1，说明该位置上为1
//		while(flag != 0){
//			if((n & flag) != 0)
//				count++;
//			flag = flag << 1; //flag循环一次左移一位
//		}
//		return count;
//	}
//};

//32.变态跳台阶：
//class Solution {
//public:
//	//方法一:递归的改进
//	int jumpFloorII_1(int number) {
//		if(number <= 0)
//			return -1;
//		else if(number == 1)
//			return 1;
//		else  //number >= 2
//			return 1 << (number-1); //return 2*jumpFloorII_1(number-1);
//	}
//
//	//方法二：
//	int jumpFloorII_2(int number){
//		int jump = 1;
//		while(--number)
//			jump *= 2; //f(n) = 2*f(n-1)
//		return jump;
//	}
//};

//33.求1+2+...+n
//求1+2+3+...+n，要求不能使用乘除法、
//for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		if(n == 1)
//			return 1;
//		return Sum_Solution(n-1) + n;
//	}
//};

//34. permutations-ii:全排列
//class Solution {
//public:
//	vector<vector<int>> res;
//	vector<vector<int> > permuteUnique(vector<int> &num) {
//		sort(num.begin(),num.end());
//		DFS(num,0);
//		sort(res.begin(),res.end());
//		res.erase(unique(res.begin(),res.end()),res.end());
//		return res;
//	}
//
//	void DFS(vector<int> &num, int step){
//		if(step == num.size()){
//			res.push_back(num);
//			return;
//		}
//		for(int i = step;i < num.size();++i){
//			swap(num[step],num[i]);
//			DFS(num,step+1);
//			swap(num[step],num[i]);
//		}
//	}
//};

//35.max-points-on-a-line
//在一个平面上有n个点，返回同一条直线上有最多数量的点的个数。
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
//class Solution {
//public:
//    int maxPoints(vector<Point> &points) {
//        int size = points.size();
//        if(size == 0)
//            return 0;
//        else if(size == 1)
//            return 1;
//        int ret = 0;
//        for(int i = 0;i < size; i++)
//        {
//            int curmax = 1;
//            map<double,int> Map; //斜率，点数--map
//            int vert = 0; //垂直点
//            int dup = 0;   //重复点
//            for(int j = 0;j < size; j++)
//            {
//                //两个点不是一个点
//                if(j != i){
//                    double x1 = points[i].x-points[j].x;
//                    double y1 = points[i].y-points[j].y;
//                    if(x1 == 0 && y1 == 0) //重复的点
//                        dup++;
//                    else if(x1 == 0){  //垂直的点
//                        if(vert == 0)
//                            vert = 2;
//                        else
//                            vert++;
//                        curmax = max(vert,curmax);
//                    }
//                    else{
//                        double k = y1 / x1;  //求斜率
//                        if(Map[k] == 0)
//                            Map[k] = 2;
//                        else
//                            Map[k]++;
//                        curmax = max(Map[k],curmax);
//                    }
//                }
//            }
//            ret = max(ret,curmax+dup);
//        }
//        return ret;
//    }
//};

//36.marge-intervals:合并区间
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//class Solution {
//public:
//    static bool compare(const Interval& a,const Interval& b)
//    {
//        return (a.start <= b.start);
//    }
//    
//    vector<Interval> merge(vector<Interval> &intervals) {
//        if(intervals.empty())
//            return intervals;
//        //根据每个区间的第一个元素进行排序
//        sort(intervals.begin(),intervals.end(),compare);
//        vector<Interval> res;
//        res.push_back(intervals[0]);
//        for(int i = 1;i < intervals.size();i++)
//        {
//            //区间有覆盖的地方
//            if(intervals[i].start <= res.back().end) //2 < 3
//                res.back().end = max(intervals[i].end,res.back().end); //合并区间
//            else  //区间不连续
//                res.push_back(intervals[i]);
//        }
//        return res;
//    }
//};

//37.不用加减乘除做加法
//不考虑进位：a ^ b
//考虑进位: (a&b)<<1 :a,b同为1时，会有进位
//class Solution {
//public:
//	int Add(int num1, int num2)
//	{
//		int sum = 0; //不含进位的和
//		int carry = 0; //进位
//		while(num2 != 0)
//		{
//			sum = num1 ^ num2; 
//			carry = (num1 & num2) << 1;
//			num1 = sum;
//			num2 = carry;
//		}
//		return num1;
//	}
//};

//38.plus-one:加一运算
//class Solution {
//public:
//	vector<int> plusOne(vector<int> &digits) {
//		int n = digits.size();
//		for(int i = n-1;i >= 0;i--)
//		{
//			if(digits[i] == 9) //有进位 
//				digits[i] = 0;
//			else{
//				digits[i] += 1; //没有进位，加一后直接返回
//				return digits;
//			}
//		}
//		if(digits[0] == 0)
//			digits.insert(digits.begin(),1);
//		return digits;
//	}
//};

//39.binary-tree-zigzag-level-order-traversal:二叉树按照"Z"字形顺序打印
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//非递归：使用栈，每一层的数据存到栈中
//class Solution {
//public:
//    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
//        vector<vector<int>> result;
//        queue<TreeNode*> q;
//        if(root != NULL)
//            q.push(root);
//        while(!q.empty())
//        {
//            int size = q.size();
//            vector<int> v;
//            while(size--) //执行size个循环
//            {
//                TreeNode* cur = q.front();
//                q.pop();
//                if(cur->left)
//                    q.push(cur->left);
//                if(cur->right)
//                    q.push(cur->right);
//                v.push_back(cur->val);
//            }
//            //在二维数组中偶数的下标要进行逆置
//            if(result.size()%2 != 0) 
//                reverse(v.begin(),v.end());
//            result.push_back(v);
//        }
//        return result;
//    }
//};

//递归的方式：
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//  // 递归版
//	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
//		vector<vector<int> > res;
//		zigzagTraverse(root, 1, res, true);
//		return res;
//	}
//  // 广度优先搜索, 每一层节点只会保存在该层对应的vector中
//	void zigzagTraverse(TreeNode* root, int level, vector<vector<int> > &res, bool left_to_right) {
//		if (root == NULL) 
//			return ;
//		// 为每层创建一个vector
//		if (level > res.size()) 
//			res.push_back(vector<int>());
//
//		if (left_to_right)//从左向右遍历
//			res[level-1].push_back(root->val);
//		else
//			res[level-1].insert(res[level-1].begin(), root->val);
//
//		// 递归进入下一层:第一层：从左向右，第二层：从右向左 ...
//		zigzagTraverse(root->left, level + 1, res, !left_to_right);
//		zigzagTraverse(root->right, level + 1, res, !left_to_right);
//	}
//};
//

//40.sort-colors:颜色排序
//O(n*n)
//class Solution {
//public:
//	void sortColors(int A[], int n) {
//		int count[3] = {0};
//		int index = 0;
//		for (int i = 0; i < n; ++i) 
//			++count[A[i]];
//		for (int i = 0; i < 3; ++i) {
//			for (int j = 0; j < count[i]; ++j) {
//				A[index++] = i;
//			}
//		}
//	}
//};

//O(n)
//class Solution {
//public:
//	void sortColors(int A[], int n) {
//		int start = 0;
//		int end = n-1;
//		for(int i = 0;i <= end;++i)
//		{
//			if(A[i] == 0)
//			{
//				swap(A[i],A[start]);
//				++start;
//			}
//			else if(A[i] == 2)
//			{
//				swap(A[i],A[end]);
//				//为什么要--i：A[i]和A[end]交换后，从交换处开始遍历，但出了该条件，
//				//for循环中i会加1，所以此处要--i
//				--i; 
//				--end;
//			}
//		}
//	}
//};

//41.multiply-strings:字符串相乘
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if(num1 == "0" || num2 == "0")
//			return "0";
//		vector<int> vec(num1.size()+num2.size(),0);
//		string result = "";
//		char tmp = '0';
//		//依次相乘的结果存到vector中
//		for(int i = num1.size()-1;i >= 0; --i)
//		{
//			for(int j = num2.size()-1;j >= 0; --j)
//				vec[i + j + 1] += (num1[i]-'0')*(num2[j]-'0');
//		}
//		//对vector中的数据进行进位处理
//		for(int i = vec.size()-1;i > 0;--i)
//		{
//			vec[i-1] += vec[i] / 10;
//			vec[i] = vec[i] % 10;
//		}
//		int i = 0;
//		寻找第一个不为0的位置
//		while(vec[i] == 0)
//			++i;
//		while(i != vec.size()){
//			tmp = vec[i] + '0';
//			result += tmp;
//			++i;
//		}
//		return result;
//	}
//};

//42.swap-nodes-in-pairs:成对交换结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if(head == NULL)
//            return head;
//        ListNode* newNode = new ListNode(-1);
//        ListNode* pre = newNode;
//        newNode->next = head;
//        while(pre->next && pre->next->next){
//            ListNode* tmp = pre->next->next;
//            pre->next->next = tmp->next;
//            tmp->next = pre->next;
//            pre->next = tmp;
//            pre = tmp->next;
//        }
//        return newNode->next;
//    }
//};

//43.reverse-integer:
//class Solution {
//public:
//	int reverse(int x) {
//		int result = 0;
//		while(x != 0)
//		{
//			result = result*10 + x%10;
//			x /= 10;
//			if(result > INT_MAX || result < INT_MIN)
//				return 0;
//		}
//		return result;
//	}
//};

//每次计算新的结果时，再用逆运算判断与上一次循环的结果是否相同，不同就溢出
//public int reverse(int x) {
//  int res=0;
//  while(x!=0){
//    //最后一位
//    int tail=x%10;
//    int newRes=res*10+tail;
//  	   //如果newRes-tail)/10!=res说明产生了溢出
//  	  if((newRes-tail)/10!=res)
//       return 0;
//   res=newRes;
//	  x=x/10;
//	}
//  return res;
//}

//class Solution {
//	bool isOverflow=false;
//public:
//	int reverse(int x) {
//		int flag=1;
//		if(x<0)
//			flag=-1,x=-x;
//
//		string tmp=to_string(x);
//		::reverse(tmp.begin(),tmp.end());
//
//		string imax=to_string(INT_MAX);
//		if(tmp.size()>= imax.size() && tmp>imax){
//			isOverflow=true;
//			return 0;
//		}
//		return stoi(tmp)*flag;
//	}
//};

//44.字符串中找出连续最长的数字串
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string str;
//	while(cin >> str)
//	{
//		vector<string> vec;
//		string tmp = "";
//		//为了使末尾的数字串能够push进去，所以要i <= str.length()
//		for(int i = 0;i <= str.length();++i)
//		{
//			if(str[i] >= '0' && str[i] <= '9')
//				tmp += str[i];
//			else
//			{
//				if(tmp.length() != 0)
//					vec.push_back(tmp);
//				tmp.clear();
//			}
//		}
//		int max = 0;
//		int length = 0;
//		//找最大的数字串
//		for(int i = 0;i < vec.size();++i){
//			if(max < (vec[i]).length())
//			{
//				max = (vec[i]).length();
//				length = max;
//			}
//		}
//		//输出最长的数字串
//		for(int i = 0;i < vec.size();++i)
//		{
//			if((vec[i]).length() == max)
//				cout << vec[i];
//		}
//		cout << ',' << length << endl;
//	}
//	return 0;
//}

//45.求和：背包问题
//输入两个整数 n 和 m，从数列1，2，3.......n 
//中随意取几个数,使其和等于 m ,要求将其中所有的可能组合列出来
//#include<iostream>
//using namespace std;
//void BagProblem_Solution(int n, int m)
//{
//	if(n < 1|| m < 1)
//		return;
//	if(n > m)
//		n = m;
//
//	int num = 1 << n;               //枚举次数
//	for(int i = 1; i < num; i++)  //枚举所有情况
//	{
//		int sum = 0;
//		int j, k;
//		for(j = i, k = 1; j != 0; j>>=1, k++) //针对每种情况求和，判断是否满足条件
//		{
//			if(j&1)
//				sum += k;
//		}
//		if(sum == m) //如果满足，打印结果
//		{
//			for(j = i, k = 1; j != 0; j>>=1, k++)
//			{
//				if(j&1)
//					cout<<k<<' ';
//			}
//			cout<<endl;
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	BagProblem_Solution(n, m);
//	return 0;
//}

//46.最大连续数列和
//对于一个有正有负的整数数组，请找出总和最大的连续数列。
//给定一个int数组A和数组大小n，请返回最大的连续数列的和。
//保证n的大小小于等于3000。
//[1,2,3,-6,1]
//6

//class MaxSum {
//public:
//	int getMaxSum(vector<int> A, int n) {
//		// write code here
//		int tmp = A[0];
//		int maxval = A[0];
//		for(int i = 1;i < n;++i){
//			if(tmp < 0)
//				tmp = A[i];
//			else
//				tmp = tmp + A[i];
//			maxval = max(tmp,maxval);
//		}
//		return maxval;
//	}
//};
//
//int getMaxSum(vector<int> A, int n) {
//	// write code here
//	vector<int> record(n);
//	int maxval = A[0];
//	record[0] = A[0];
//	for(int i = 1;i < n;i++){
//		if(record[i-1] < 0)
//			record[i] = A[i];
//		else
//			record[i] = record[i-1] + A[i];
//		maxval = max(record[i], maxval);
//	}
//	return maxval;
//}

//47.电话号码
//#include<iostream>
//#include<string>
//#include<set> //不重复
//using namespace std;
//int main()
//{
//	string str;
//	int len = 0;
//	string number = "22233344455566677778889999";
//	while(cin >> len){
//		set<string> setval;
//		int count = 0;
//		for(int i = 0;i < len;i++){
//			count = 0;
//			string res;
//			cin >> str;
//			for(int j = 0;j < str.length();j++){
//				if(str[j] >= 'A' && str[j] <= 'Z'){
//					res += number[str[j]-'A'];
//					count++;
//					if(count == 3)
//						res += '-';
//				}
//				else if(str[j] >= '0' && str[j] <= '9'){
//					res += str[j];
//					count++;
//					if(count == 3)
//						res += '-';
//				}
//			}
//			setval.insert(res);
//		}
//		for(set<string>::iterator it = setval.begin(); it != setval.end(); it++)
//			cout << *it <<endl;
//		cout << endl;
//	}
//	return 0;
//}

//48.数字和为sum的方法数
//#include<iostream>
//#include<algorithm>
//using namespace std;
////注意：最终结果int类型存不下，需要64位数据
////注意：dp不能放在main里，栈存不下。需要存在全局数据区
//long long dp[1000][1000];
//int main()
//{
//	int n,num;
//	cin >> n >> num;
//	int tmp[1000];
//	for(int i = 1;i <= n; ++i)
//		cin >> tmp[i];
//	//初始化dp,用前i个组成和为0的方案，只有1种，就是什么都不取，和为0；
//	for(int i = 0;i < n;++i)
//		dp[i][0] = 1;
//	//用0个元素不能组成1~sum
//	for(int j = 1;j < num;j++)
//		dp[0][j] = 0;
//	for(int i = 1;i <= n;++i)
//	{
//		for(int j = 0;j <= num; ++j)
//		{
//			if(tmp[i] <= j)
//				dp[i][j] = dp[i-1][j] + dp[i-1][j-tmp[i]];
//			else
//				dp[i][j] = dp[i-1][j];
//		}
//	}
//	cout << dp[n][num] << endl;
//	return 0;
//}

//49.进制转换
//将十进制数M，转换为N进制数
//#include<iostream>
//using namespace std;
//int main()
//{
//	string str = "",table = "0123456789abcdef";
//	int m,n;
//	cin >> m >> n;
//	if(m == 0)
//	{
//		cout << "0" << endl;
//		return 0;
//	}
//	while(m != 0){
//		if(m < 0)
//		{
//			m = -m;
//			cout << "-";
//		}
//		str = table[m%n] + str;
//		m /= n;
//	}
//
//	cout << str << endl;
//	return 0;
//}

//50.末尾0的个数
//n!中2*5=10，有1个0；2的个数比5的个数多，所以看有多少个5
//n/5 :即就每个数可以由几个5相乘，再把全部的5加到一起就是了。
//高斯函数有条性质：对任意正实数x，n是正整数，
//则从1到x的整数中，n的倍数有[x/n]个。
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int count = 0;
//	while(n){
//		count += n/5;
//		n /= 5;
//	}
//	cout << count << endl;
//	return 0;
//}

//51.地下迷宫
//小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
//为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,
//小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)
//(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动
//一个单位距离需要消耗1点体力值,向上爬一个单位距离需要消耗3个单位的体力值,
//向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,小青蛙将无法逃离迷宫。
//现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。

//#include <iostream>
//#include <vector>
//using namespace std;
// 
///*
//* 声明：这份代码是照搬@null_ptr的 但是代码没什么注释，乍一看不好理解，
//* 所以我作了比较详细的注释，方便参考
//* 基本思想：典型的迷宫问题，DFS穷举所有路径，找出剩余体力最多的路径
//*/
// 
//#define VISITED 2
// 
//int m, n, P;     // 输入m，n，P
//int maze[10][10];   // 迷宫地图
//int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};// 左，右，上，下移动，例如：{0, -1}代表向左移动一步
//int cost[4] = {-1, -1, -3, 0};    // 左，右，上，下移动的体力消耗，例如：{0， -1}对应-1
//int final_P = -200;    // 剩余的体力值，初始为较小的数，保证final_P被正确更新
// 
//// 存储各点的数据结构
//struct mazePoint {
//	mazePoint(int _x, int _y)
//		: x(_x), y(_y) 
//	{}
//	int x, y;
//};
//// 存储每次遍历到的路径
//vector<mazePoint> pathStack;
//// 存储最终的最优路径
//vector<mazePoint> minCostPath;
// 
//// 函数：打印路径
//void printPath(const vector<mazePoint>& path) {
//	for (int i = 0; i < path.size(); ++i) {
//		cout << "[" << path[i].x << "," << path[i].y << "]";
//		if (i < path.size() - 1) {
//			cout << ",";
//		}
//	}
//}
// 
//// 函数：寻找最优路径
//void search(int x, int y, int cur_P) {
//	// 将当前点加入路径并标记为VISITED
//	pathStack.push_back(mazePoint(x, y));
//	maze[x][y] = VISITED;
//
//	// 如果当前点为出口且当前体力值>=0，则更新final_P与minCostPath，并返回
//	if (x == 0 && y == m-1 && cur_P >= 0) {
//		if (cur_P > final_P) {
//		final_P = cur_P;
//		minCostPath = pathStack;
//		}
//		pathStack.pop_back();   // 为了回退至之前的节点，将当前结点弹出
//		maze[x][y] = 1;    // 注意：之前maze[x][y]被标记为VISITED（值为2），回退后应该将其还原为1
//		return;
//	}
//
//	// 如果当前点并非出口且当前体力值>=0，则分别向左右上下四个方向探索，并计算相应的消耗
//	// 如果新的点再边界内且为可达点，递归调用search函数
//	if (cur_P > 0) {
//		for (int i = 0; i < 4; ++i) {
//			int nx = x + dir[i][0];
//			int ny = y + dir[i][1];
//			int nP = cur_P + cost[i];
//
//			if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1)
//				search(nx, ny, nP);
//		}
//	}
//
//	pathStack.pop_back();    // 为了回退至之前的节点，将当前结点弹出
//	maze[x][y] = 1;    // 注意：之前maze[x][y]被标记为VISITED（值为2），回退后应该将其还原为1
//}
// 
//// 主函数
//int main() {
//	cin >> n >> m >> P;
//	for (int i = 0; i < n; ++i)
//		for (int j = 0; j < m; ++j)
//			cin >> maze[i][j];
//
//	search(0, 0, P);
//
//	if (final_P != -200)    // 如果final_P更新过，输出最优路径
//		printPath(minCostPath);
//	else    // 如果final_P为初始值-200，代表其没有被更新过，也就意味着没有可行路径
//		cout << "Can not escape!";
//
//	return 0;
//}

//52.链表中倒数第K个节点
//输入一个链表，输出该链表中倒数第k个结点。
//考点是：代码的鲁棒性
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//class Solution {
//public:
//    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//        if(pListHead == NULL || k <= 0)
//            return NULL;
//        ListNode* slow = pListHead;
//        ListNode* fast = pListHead;
//        for(int i = 1;i < k;++i)
//        {
//            if(fast->next != NULL)
//                fast = fast->next;
//            else
//                return NULL;
//        }
//        while(fast->next != NULL)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//};

//53.机器人的运动范围
//递归
//class Solution {
//public:
//	int movingCount(int threshold, int rows, int cols)
//	{
//		bool* flag=new bool[rows*cols];
//		for(int i=0;i<rows*cols;i++)
//			flag[i]=false;
//		int count=moving(threshold,rows,cols,0,0,flag);//从（0,0）坐标开始访问;
//		delete[] flag;
//		return count;
//	}
//	//计算最大移动位置
//	int moving(int threshold,int rows,int cols,int i,int j,bool* flag)
//	{
//		int count=0;
//		if(check(threshold,rows,cols,i,j,flag))
//		{
//			flag[i*cols+j]=true;
//			//标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
//			//因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
//			count=1+moving(threshold,rows,cols,i-1,j,flag)
//   			   +moving(threshold,rows,cols,i,j-1,flag)
//           +moving(threshold,rows,cols,i+1,j,flag)
//	         +moving(threshold,rows,cols,i,j+1,flag);
//		}
//		return count;
//	}
//	//检查当前位置是否可以访问
//	bool check(int threshold,int rows,int cols,int i,int j,bool* flag)
//	{
//		if(i>=0 && i<rows && j>=0 && j<cols
//			&& getSum(i)+getSum(j)<=threshold
//			&& flag[i*cols+j]==false)
//			return true;
//		return false;
//	}
//	//计算位置的数值
//	int getSum(int number)
//	{
//		int sum=0;
//		while(number>0)
//		{
//			sum+=number%10;
//			number/=10;
//		}
//		return sum;
//	}
//};
//
////非递归：栈
//class Solution {
//public:
//	int movingCount(int threshold, int rows, int cols)
//	{
//		vector<vector<bool> > grid(rows);
//		for(int i = 0;i < rows;++i)
//			grid[i].resize(cols,false);
//		queue<pair<int,int>> que;
//		if(Reached(threshold, 0, 0))
//		{
//			que.push(make_pair(0, 0));
//			grid[0][0] = true;
//		}
//		int count = 0;
//		while(!que.empty())
//		{
//			count++;
//			int x,y;
//			//std::tie(C++11)：用于绑定键值对的元素
//			tie(x,y) = que.front();
//			que.pop();
//			//向下走：
//			if(x + 1 < rows && !grid[x+1][y] && Reached(threshold,x+1,y))
//			{
//				grid[x+1][y] = true;
//				que.push(make_pair(x+1,y));
//			}
//			//向右走：
//			if(y + 1 < cols && !grid[x][y+1] && Reached(threshold,x,y+1))
//			{
//				grid[x][y+1] = true;
//				que.push(make_pair(x,y+1));
//			}
//		}
//		return count;
//	}
//	bool Reached(int threshold, int x, int y)
//	{
//		int sum = 0;
//		while(x > 0)
//		{
//			sum += x % 10;
//			x /= 10;
//		}
//		while(y > 0)
//		{
//			sum += y % 10;
//			y /= 10;
//		}
//		return (sum <= threshold);
//	}
//};

//54.triangle
//给一个三角形的数组，找出从上往下最小的路径和。
//每一步只能移动到下一行的相邻数字上
//方法一：不使用额外空间
//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		for(int i = triangle.size()-2; i >= 0; --i)
//		{
//			for(int j = 0;j < triangle[i].size();++j)
//				triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
//		}
//		return triangle[0][0];
//	}
//};

//方法二：O(N)的空间复杂度
//class Solution{
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		vector<int> res(triangle.back());
//		for(int i = triangle.size()-2; i >= 0; --i){
//			for(int j = 0;j < triangle[i].size(); ++j){
//				res[j]=triangle[i][j]+min(res[j],res[j+1]);
//			}
//		}
//		return res[0];
//	}
//}

//方法三：使用递归dfs深度优先遍历

//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) 
//	{
//		if(triangle.empty())
//			return 0;
//		if(triangle.size() == 1 )
//			return triangle[0][0];
//
//
//		//后序遍历的思想:算出左子树的最小和，和右子树的最小和，根节点和其中较小的值相加。
//		int leftsum = minSumPath(triangle, 1, 0);
//
//		int rightsum = minSumPath(triangle, 1,1);
//
//		int minsum = triangle.at(0).at(0);
//
//		return (minsum + min(leftsum,rightsum));
//	}
//
//	int minSumPath(vector<vector<int> > &triangle,int row, int col)
//	{
//		if( row < triangle.size())
//		{
//			int left = minSumPath(triangle, row+1, col);
//			int right = minSumPath(triangle, row+1, col+1);
//
//			return triangle.at(row).at(col) + min(left,right);
//		}
//		return 0;
//	}
//};

//55.合并两个排序的链表
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
//class Solution {
//public:
//    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//    {
//        if(pHead1 == NULL)
//            return pHead2;
//        if(pHead2 == NULL)
//            return pHead1;
//        ListNode *newNode,*newP;
//        //找出合并后的第一个节点
//        if(pHead1->val <= pHead2->val){
//            newNode = pHead1;
//            newP = newNode;
//            pHead1 = pHead1->next;
//        }
//        else{
//            newNode = pHead2;
//            newP = newNode;
//            pHead2 = pHead2->next;
//        }
//        
//        while(pHead1 != NULL && pHead2 != NULL)
//        {
//            if(pHead1->val <= pHead2->val)
//            {
//                newP->next = pHead1;
//                pHead1 = pHead1->next;
//                newP = newP->next;
//            }
//            else{
//                newP->next = pHead2;
//                pHead2 = pHead2->next;
//                newP = newP->next;
//            }
//        }
//        if(pHead1)
//            newP->next = pHead1;
//        if(pHead2)
//            newP->next = pHead2;
//        return newNode;
//    }
//};

//56.复杂链表的复制

///*struct RandomListNode {
//    int label;
//    struct RandomListNode *next, *random;
//    RandomListNode(int x) :
//            label(x), next(NULL), random(NULL) {
//    }
//};*/
//
//class Solution {
//public:
//    RandomListNode* Clone(RandomListNode* pHead)
//    {
//        if(pHead == NULL)
//            return NULL;
//        //复制链表
//        RandomListNode* currNode = pHead;
//        while(currNode)
//        {
//            RandomListNode* pCloned = new RandomListNode(currNode->label);
//            pCloned->next = currNode->next;
//            currNode->next = pCloned;
//            currNode = pCloned->next;
//        }
//        //复制random指针
//        currNode = pHead;
//        while(currNode)
//        {
//            RandomListNode* pCloned = currNode->next;
//            if(currNode->random)
//                pCloned->random = currNode->random->next;
//            currNode = pCloned->next;
//        }
//        //拆分链表
//        RandomListNode* pClonedHead = pHead->next;
//        RandomListNode* pClonedNode = pHead->next;
//        currNode = pHead;
//        while(currNode->next)
//        {
//            pClonedNode = currNode->next;
//            currNode->next = pClonedNode->next;
//            currNode = pClonedNode;
//        }
//        return pClonedHead;
//    }
//};

//57、二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//class Solution {
//public:
//    //双向链表的左边头结点和右边头结点
//    TreeNode* leftHead = NULL;
//    TreeNode* rightHead = NULL;
//    TreeNode* Convert(TreeNode* pRootOfTree)
//    {
//        if(pRootOfTree == NULL)
//            return NULL;
//        Convert(pRootOfTree->left);
//        if(rightHead == NULL)
//            leftHead = rightHead = pRootOfTree;
//        else
//        {
//            rightHead->right = pRootOfTree;
//            pRootOfTree->left = rightHead;
//            rightHead = pRootOfTree;
//        }
//        Convert(pRootOfTree->right);
//        return leftHead;   //双向链表的左边头结点
//    }
//};

//58.两个链表的第一个公共结点
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//class Solution {
//public:
//    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
//        ListNode* p1 = pHead1;
//        ListNode* p2 = pHead2;
//        while(p1 != p2)
//        {
//            if(p1 != NULL)
//                p1 = p1->next;
//            if(p2 != NULL)
//                p2 = p2->next;
//            if(p1 != p2)
//            {
//                if(p1 == NULL)
//                    p1 = pHead2;
//                if(p2 == NULL)
//                    p2 = pHead1;
//            }
//        }
//        return p1;
//    }
//};

//方法二：使用栈
//使用栈来实现: 将两个链表分别push进stack1和stack2，再不断的pop，
//记录两个相等的节点，最后一次记录的节点就是第一个公共结点。
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//	val(x), next(NULL) {
//	}
//};*/
//
//class Solution {
//public:
//	ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
//		stack<ListNode*> s1;
//		stack<ListNode*> s2;
//		if(pHead1 == NULL || pHead2 == NULL)
//			return NULL;
//		while(pHead1)
//		{
//			s1.push(pHead1);
//			pHead1 = pHead1->next;
//		}
//		while(pHead2)
//		{
//			s2.push(pHead2);
//			pHead2 = pHead2->next;
//		}
//		ListNode* firCom = NULL;
//		while(!s1.empty() && !s2.empty())
//		{
//			ListNode* top1 = s1.top();
//			ListNode* top2 = s2.top();
//			s1.pop();
//			s2.pop();
//			if(top1 == top2)
//				firCom = top1;
//		}
//		return firCom;
//	}
//};

//方法三：
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
//
//class Solution {
//public:
//    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
//        int len1 = LengthOfList(pHead1);
//        int len2 = LengthOfList(pHead2);
//        if(len1 > len2)
//            pHead1 = WalkStep(pHead1,len1-len2);
//        else
//            pHead2 = WalkStep(pHead2,len2-len1);
//        while(pHead1 != NULL)
//        {
//            if(pHead1 == pHead2)
//                return pHead1;
//            pHead1 = pHead1->next;
//            pHead2 = pHead2->next;
//        }
//        return NULL;
//        
//    }
//    int LengthOfList(ListNode* Head)
//    {
//        if(Head == NULL)
//            return 0;
//        int count = 0;
//        while(Head)
//        {
//            count++;
//            Head = Head->next;
//        }
//        return count;
//    }
//    
//    ListNode* WalkStep(ListNode* Head, int step)
//    {
//        while(step--)
//        {
//            Head = Head->next;
//        }
//        return Head;
//    }
//};

//方法四：使用map
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//class Solution {
//public:
//    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
//        map<ListNode*,int> map;
//        ListNode* cur = pHead1;
//        while(cur)
//        {
//            map[cur] = 1;
//            cur = cur->next;
//        }
//        cur = pHead2;
//        while(cur){
//            if(map[cur])
//                return cur;
//            cur = cur->next;
//        }
//        return NULL;
//    }
//};

//59.linked-list-cycle:判断链表是否带环
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    bool hasCycle(ListNode *head) {
//        if(head == NULL)
//            return false;
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while(fast && fast->next)
//        {
//            fast = fast->next->next;
//            slow = slow->next;
//            if(fast == slow)
//                return true;
//        }
//        return false;
//    }
//};

//扩展：链表带环，求环的入口处

//Definition for singly-linked list.
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
// 
//class Solution
//{
//public:
//	//求相遇点
//	ListNode* MeetingNode(ListNode* head)
//	{
//		if(head == NULL)
//			return NULL;
//		ListNode* fast = head;
//		ListNode* slow = head;
//		//fast走的比slow快，不带环fast一定比slow先为空
//		while(fast && fast->next)
//		{
//			fast = fast->next->next;
//			slow = slow->next;
//			if(fast == slow)
//				return fast;
//		}
//		return NULL;
//	}
//
//	ListNode* Entrance(ListNode* head)
//	{
//		if(head = =NULL)
//			return NULL;
//		ListNode* ret = MeetingNode(head);
//		if(NULL == ret)
//		{
//			cout << "这个链表不带环！" << endl;
//			return NULL;
//		}
//		ListNode* fast = head;
//		ListNode* slow = ret;
//		while(fast)
//		{
//			fast = fast->next;
//			slow = slow->next;
//			if(fast == slow)
//				return fast;
//		}
//	}
//};

//60.删除链表中重复的节点
//递归：
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* pHead)
//    {
//        //只有0个或1个节点的时候
//        if(NULL == pHead || pHead->next == NULL)
//            return pHead;
//       if(pHead->val == pHead->next->val)
//       {
//           ListNode* node = pHead->next;
//           //找到一个和当前结点不重复的值
//           while(node != NULL && node->val == pHead->val)
//               node = node->next;
//           return deleteDuplication(node);
//       }
//        else //当前结点不是重复的节点
//        {
//            pHead->next = deleteDuplication(pHead->next);
//            return pHead;
//        }
//    }
//};

//非递归：
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
//class Solution {
//public:
//    ListNode* deleteDuplication(ListNode* pHead)
//    {
//        if(pHead == NULL || pHead->next == NULL)
//            return pHead;
//        ListNode* newHead = new ListNode(-1);
//        newHead->next = pHead;
//        ListNode* pre = newHead;
//        ListNode* last = newHead->next;
//        while(last)
//        {
//            //找到第一个和当前结点不相同的节点
//            if(last->next && last->val == last->next->val)
//            {
//                while(last->next != NULL && last->val == last->next->val)
//                    last = last->next;
//                pre->next = last->next;
//                last = last->next;
//            }
//            else
//            {
//                pre = pre->next;
//                last = last->next;
//            }
//        }
//        return newHead->next;
//    }
//};

//62.reorder-list：重排链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    void reorderList(ListNode *head) {
//        if(head == NULL || head->next == NULL || head->next->next == NULL)
//            return;
//        //使用快慢指针找到链表的中点，偶数个节点，中点偏左
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while(fast->next && fast->next->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        
//        //以中心为界，将链表分为两部分，将后面的部分逆置
//        //1-2-3-4-5    1-2-3-NULL  4-5-NULL  5-4-NULL
//        fast = slow->next;
//        slow->next = NULL;
//        slow = fast;  //slow指向后面链表的头
//        //将slow及后面进行逆置
//        fast = slow->next;
//        slow->next = NULL; 
//        ListNode* tmp;
//        while(fast != NULL)
//        {
//            tmp = fast->next;
//            fast->next = slow;
//            slow = fast;
//            fast = tmp;
//        }
//        
//        //合并两个链表
//        ListNode* p = head;
//        ListNode* q = slow;
//        while(p != NULL && q != NULL)
//        {
//            tmp = p->next;
//            p->next = q;
//            p = tmp;
//            tmp = q->next;
//            q->next = p;
//            q = tmp;
//        }
//    }
//};

//63.sort-list:
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
//public:
//    ListNode *sortList(ListNode *head) {
//        if(head == NULL || head->next == NULL)
//            return head;
//        //找中点：偶数节点，中点是偏左
//        ListNode* fast = head->next;
//        ListNode* slow = head;
//        while(fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        
//        //将链表一分为2，分别对左右两部分进行归并排序
//        ListNode* right = sortList(slow->next);
//        slow->next = NULL;
//        ListNode* left = sortList(head);
//        
//        return Merge(left,right);
//    }
//    
//    ListNode* Merge(ListNode* left,ListNode* right)
//    {
//        ListNode* newHead = new ListNode(-1);
//        ListNode* cur = newHead;
//        while(left && right)
//        {
//            if(left->val < right->val)
//            {
//                cur->next = left;
//                left = left->next;
//            }
//            else{
//                cur->next = right;
//                right = right->next;
//            }
//            cur = cur->next;
//        }
//        if(left)
//            cur->next = left;
//        if(right)
//            cur->next = right;
//        return newHead->next;
//    }
//};

//64. convert-sorted-list-to-binary-search-tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    TreeNode *sortedListToBST(ListNode *head) {
//        return ToBST(head,NULL);
//    }
//    
//    TreeNode* ToBST(ListNode* head,ListNode* tail)
//    {
//        if(head == tail)
//            return NULL;
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while(fast != tail && fast->next != tail)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        TreeNode* root = new TreeNode(slow->val);
//        root->left = ToBST(head,slow);
//        root->right = ToBST(slow->next,tail);
//        
//        return root;
//    }
//};

//65.partition-list:对链表进行分区
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *partition(ListNode *head, int x) {
//        if(head == NULL)
//            return NULL;
//        ListNode* newHead1 = new ListNode(0);
//        ListNode* newHead2 = new ListNode(0);
//        ListNode* cur1 = newHead1;
//        ListNode* cur2 = newHead2;
//        while(head != NULL)
//        {
//            if(head->val < x){
//                cur1->next = head;
//                cur1 = cur1->next;
//            }
//            else{
//                cur2->next = head;
//                cur2 = cur2->next;
//            }
//            head = head->next;
//        }
//        cur1->next = newHead2->next;
//        cur2->next = NULL;
//        return newHead1->next;
//    }
//};

//67.用两个栈实现队列
//class Solution
//{
//public:
//	void push(int node) {
//		stack1.push(node);
//	}
//
//	int pop() {
//		if(stack1.empty() && stack2.empty())
//		{
//			cout << "queue is empty" << endl;
//			return -1;
//		}
//		int top;
//		if(stack2.empty())
//		{
//			while(!stack1.empty())
//			{
//				top = stack1.top();
//				stack2.push(top);
//				stack1.pop();
//			}
//		}
//		top = stack2.top();
//		stack2.pop();
//		return top;
//	}
//
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};

//用两个队列实现栈
//class Solution
//{
//public:
//	void push(int node) {
//		if(!queue2.empty())
//			queue2.push(node);
//		else
//			queue1.push(node);
//
//	}
//
//	int pop() {
//		if(queue1.empty() && queue2.empty())
//		{
//			cout << "stack is empty" << endl;
//			return -1;
//		}
//		int front;
//		if(queue1.size() > 0)
//		{
//			while(queue1.size() > 1)
//			{
//				front = queue1.front();
//				queue2.push(front);
//				queue1.pop();
//			}
//			//此时queue1中只有1个元素，进行出栈
//			front  = queue1.front();
//			queue1.pop();
//		}
//		else if(queue2.size() > 0)
//		{
//			while(queue2.size() > 1)
//			{
//				front = queue2.front();
//				queue1.push(front);
//				queue2.pop();
//			}
//			//此时queue2中只有1个元素，进行出栈
//			front = queue2.front();
//			queue2.pop();
//		}
//		return front;
//	}
//
//private:
//	queue<int> queue1;
//	queue<int> queue2;
//};

//68.add-two-numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
//        if(l1 == NULL)
//            return l2;
//        if(l2 == NULL)
//            return l1;
//        ListNode* head = new ListNode(0);
//        ListNode* cur = head;
//        int temp = 0;
//        while(l1 != NULL || l2 != NULL || temp != 0)
//        {
//            if(l1 != NULL)
//            {
//                temp += l1->val;
//                l1 = l1->next;
//            }
//            if(l2 != NULL)
//            {
//                temp += l2->val;
//                l2 = l2->next;
//            }
//            cur->next = new ListNode(temp % 10);
//            cur = cur->next;
//            temp = temp / 10;
//        }
//        return head->next;
//    }
//};

//69.rotate-list:旋转链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *rotateRight(ListNode *head, int k) {
//        if(head == NULL || k == 0)
//            return head;
//        ListNode* cur = head;
//        int len = 1;
//        while(cur->next)
//        {
//            len++;
//            cur = cur->next;
//        }
//        //此时cur指向最后一个节点
//        k = len - (k % len);
//        //首尾相连一下
//        cur->next = head;
//        for(int i = 0;i < k;++i)
//        {
//            cur = cur->next;
//        }
//        //新的头结点：
//        head = cur->next;
//        //cur指向此刻的尾，置空一下
//        cur->next = NULL;
//        return head;
//    }
//};

//70.remove-nth-node-from-end-of-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    //O(n)
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        if(head == NULL)
//            return head;
//        ListNode* newHead = new ListNode(0);
//        newHead->next = head;
//        head = newHead;
//        ListNode* fast = head;
//        ListNode* slow = head;
//        //fast先走n步
//        for(int i = 0;i < n;i++)
//            fast = fast->next;
//        while(fast->next)
//        {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        //此时slow在待删除节点的前一个位置
//        ListNode* del = slow->next;
//        slow->next = del->next;
//        delete del;
//        return newHead->next;
//    }
//};

//71.把二叉树打印成多行
///*
//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//    TreeNode(int x) :
//            val(x), left(NULL), right(NULL) {
//    }
//};
//*/
//class Solution {
//public:
//        vector<vector<int> > Print(TreeNode* pRoot) {
//            vector<vector<int > > v;
//            if(pRoot == NULL)
//                return v;
//            queue<TreeNode*> q;
//            int index,size;
//            q.push(pRoot);
//            while(!q.empty())
//            {
//                index = 0;
//                size = q.size();
//                vector<int> tmp;
//                while(index < size)
//                {
//                    index++;
//                    TreeNode* front = q.front();
//                    q.pop();
//                    tmp.push_back(front->val);
//                    if(front->left)
//                        q.push(front->left);
//                    if(front->right)
//                        q.push(front->right);
//                }
//                v.push_back(tmp);
//            }
//            return v;
//        }
//};

//72.二叉树的镜像
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//class Solution {
//public:
//	void Mirror(TreeNode* pRoot)
//	{
//		if(pRoot == NULL)
//			return;
//		TreeNode* tmp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tmp;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//	}
//};

//73.二叉树的深度
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//class Solution {
//public:
//    int TreeDepth(TreeNode* pRoot)
//    {
//        if(pRoot == NULL)
//            return 0;
//        int leftDepth = TreeDepth(pRoot->left);
//        int rightDepth = TreeDepth(pRoot->right);
//        return leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
//    }
//};

//74.判断一颗二叉树是不是平衡二叉树
//class Solution{
//public:
//	//方法一：对多个节点进行重复遍历
//	//每遍历到一个节点，需要对它的左右子树求高度差，会反复的求高度
//	//O(n)
//	int Height(TreeNode* root)
//	{
//		if(root == NULL)
//			return 0;
//		int leftHeight = Height(root->left);
//		int rightHeight = Height(root->right);
//		return leftHeight > rightHeight ? leftHeight+1 : rightHeight + 1;
//	}
//	//判断二叉树是否为平衡二叉树
//	bool IsAVLBinaryTree(TreeNode* root)
//	{
//		if(root == NULL)
//			return true;
//		//平衡因子
//		int pf = abs(Height(root->left)-Height(root->right));
//		return ((pf < 2) && (IsAVLBinaryTree(root->left)) 
//			&& (IsAVLBinaryTree(root->right)));
//	}
//
//	//方法二：遍历一遍的算法
//	//需要一个引用变量记录当前的高度
//	bool IsAVLBinaryTree2(TreeNode* root,int& depth)
//	{
//		if(root == NULL)
//		{
//			depth = 0;
//			return true;
//		}
//
//		int left = 0;
//		int right = 0;
//		if(IsAVLBinaryTree2(root->left,left) && IsAVLBinaryTree2(root->right,right))
//		{
//			int pf = abs(right-left);
//			if(pf < 2);
//			{
//				depth = (left > right) ? left+1 : right+1;
//				return true;
//			}
//		}
//		return false;
//	}
//};

//字节跳动面试题1：未通过，思路和合并区间的类似，但输入输出有问题
//struct Interval {
//  int start;
//  int end;
//  Interval() : start(0), end(0) {}
//  Interval(int s, int e) : start(s), end(e) {}
//};
//
//
//static bool compare(const Interval& a,const Interval& b)
//{
//    return (a.start <= b.start);
//}
//
//vector<Interval> merge(vector<Interval> &intervals) {
//    if(intervals.empty())
//        return intervals;
//    sort(intervals.begin(),intervals.end(),compare);
//    vector<Interval> res;
//    res.push_back(intervals[0]);
//    for(int i = 1;i < intervals.size();i++)
//    {
//        if(intervals[i].start <= res.back().end) //2 < 3
//            res.back().end = max(intervals[i].end,res.back().end); //合并区间
//        else 
//            res.push_back(intervals[i]);
//    }
//    return res;
//}
//
//int main()
//{
//	vector<Interval> v;
//	Interval val;
//	int editor = 0;
//	cin >> editor;
//	int a,b;
//	while(editor--)
//	{
//		while(cin >> a >> b)
//		{
//			val.start = a;
//			val.end = b;
//			v.push_back(val);
//		}
//	}
//	return 0;
//}

//75.二叉搜索树的后序遍历序列
//class Solution {
//public:
//	bool VerifySquenceOfBST(vector<int> sequence) {
//		int size = sequence.size();
//		if(size == 0)
//			return false;
//		return judge(sequence,0,size-1);
//	}
//
//	bool judge(vector<int>& a,int left,int right)
//	{
//		if(left >= right)
//			return true;
//		int mid = right;
//		//最终的i为左子树和右子树的分界部分
//		while(mid > left && a[mid-1] > a[right])
//			--mid; //第一个出现的右子树节点
//		for(int i = mid-1; i >= left; --i)
//		{
//			//此时遍历的序列是左子树部分，因此应全小于根节点
//			if(a[i] > a[right])
//				return false;
//		}
//		return judge(a,left,mid-1) && judge(a,mid,right-1);
//	}
//};

//76.二叉树的下一个节点
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next; //父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//class Solution {
//public:
//    TreeLinkNode* GetNext(TreeLinkNode* pNode)
//    {
//        if(pNode == NULL)
//            return pNode;
//        //pNode的右为空
//        if(pNode->right == NULL)
//        {
//            //找到第一个作为左节点的pNode的祖宗节点
//            while(pNode && pNode->next && pNode == pNode->next->right)
//                pNode = pNode->next;
//            //此时的pNode的父节点就是要找的节点
//            return pNode->next;
//        }
//        //pNode存在右结点，找到它的右子树的最左节点
//        pNode = pNode->right;
//        while(pNode && pNode->left)
//            pNode = pNode->left;
//        return pNode;
//    }
//};

//77.重建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
//        int size = vin.size();
//        if(size == 0)
//            return NULL;
//        vector<int> left_pre,right_pre,left_vin,right_vin;
//        //前序遍历的第一个节点是重建的根节点
//        TreeNode* head = new TreeNode(pre[0]);
//        int root = 0;
//        for(int i = 0;i < size;++i)
//        {
//            if(vin[i] == pre[0])
//            {
//                root = i;
//                break;
//            }
//        }
//        for(int i = 0;i < root;++i)
//        {
//            left_vin.push_back(vin[i]);
//            left_pre.push_back(pre[i+1]);
//        }
//        for(int i = root+1;i < size;++i)
//        {
//            right_vin.push_back(vin[i]);
//            right_pre.push_back(pre[i]);
//        }
//        
//        //对前序遍历和中序遍历的根节点，左子树和右子树再进行递归
//        head->left = reConstructBinaryTree(left_pre,left_vin);
//        head->right = reConstructBinaryTree(right_pre,right_vin);
//        return head;
//    }
//};

//78.对称的二叉树
///*
//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//    TreeNode(int x) :
//            val(x), left(NULL), right(NULL) {
//    }
//};
//*/
////递归版
//class Solution {
//public:
//    bool isSymmetrical(TreeNode* pRoot)
//    {
//        if(pRoot == NULL)
//            return true;
//        return IsCommTree(pRoot->left,pRoot->right);
//    }
//    
//    bool IsCommTree(TreeNode* left,TreeNode*right)
//    {
//        if(left == NULL && right == NULL)
//            return true;
//        if(left == NULL || right == NULL)
//            return false;
//        if(left->val != right->val)
//            return false;
//        return IsCommTree(left->left,right->right)
//            && IsCommTree(left->right,right->left);
//    }
//};
//
////非递归版：利用队列
//class Solution {
//public:
//    bool isSymmetrical(TreeNode* pRoot)
//    {
//        if(pRoot == NULL)
//            return true;
//        queue<TreeNode*> q1,q2;
//        TreeNode *left,*right;
//        q1.push(pRoot);
//        q2.push(pRoot);
//        while(!q1.empty() && !q2.empty())
//        {
//            left = q1.front();
//            q1.pop();
//            right =q2.front();
//            q2.pop();
//            if(left == NULL && right == NULL)
//                continue;
//            if(left == NULL || right == NULL)
//                return false;
//            if(left->val != right->val)
//                return false;
//            q1.push(left->left);
//            q2.push(right->right);
//            q1.push(left->right);
//            q2.push(right->left);
//        }
//        return true;
//    }
//};

//79.binary-tree-preorder-traversal
//递归版
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> v;
//        if(root == NULL)
//            return v;
//        PreOrder(root,v);
//        return v;
//    }
//    
//    void PreOrder(TreeNode* root,vector<int>& res)
//    {
//        if(root == NULL)
//            return;
//        res.push_back(root->val);
//        PreOrder(root->left,res);
//        PreOrder(root->right,res);
//    }
//};

//非递归
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> v;
//        if(root == NULL)
//            return v;
//        stack<TreeNode*> s;
//        s.push(root);
//        while(!s.empty())
//        {
//            TreeNode* top = s.top();
//            s.pop();
//            v.push_back(top->val);
//            if(top->right)
//                s.push(top->right);
//            if(top->left)
//                s.push(top->left);
//        }
//        return v;
//    }
//};

//80.序列化二叉树
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
//使用前序遍历进行序列化
//class Solution {
//public:
//    char* Serialize(TreeNode *root) {    
//        if(root == NULL)
//            return NULL;
//        string str;
//        _Serialize(root,str);
//        char* ret = new char[str.length()+1];
//        int i;
//        for(i = 0;i < str.length();++i)
//            ret[i] = str[i];
//        ret[i] = '\0';
//        return ret;
//    }
//
//	void _Serialize(TreeNode* root,string& str)
//	{
//		if(root == NULL)
//		{
//			str += '#';
//			return;
//		}
//		string tmp = to_string(root->val);
//		str += tmp;
//		str += ',';
//		_Serialize(root->left,str);
//		_Serialize(root->right,str);
//	}
//
//    TreeNode* Deserialize(char *str) {
//        if(str == NULL)
//            return NULL;
//        TreeNode* ret = _Deserialize(&str);
//        return ret;
//    }
//    
//    TreeNode* _Deserialize(char** str)
//    {
//        if(**str == '#')
//        {
//            ++(*str);
//            return NULL;
//        }
//        int num = 0;
//        while(**str != '\0' && **str != ',')
//        {
//            num = num*10 + ((**str)-'0');
//            ++(*str);
//        }
//        TreeNode* root = new TreeNode(num);
//        if(**str == '\0')
//            return root;
//        else{
//            //此时的**str=','
//            ++(*str);
//            root->left = _Deserialize(str);
//            root->right = _Deserialize(str);
//            return root;
//        }
//    }
//};




