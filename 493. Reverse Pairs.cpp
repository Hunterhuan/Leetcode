
// solution1: 暴力法
// failed，因为有INT_MAX,所以不能乘2


// solution2: Binary search Tree
// 超时
class Solution {
public:
class Node {
public:
    Node *left, *right;
    int val;
    int count_ge;
    Node(int val)
    {
        this->val = val;
        this->count_ge = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* head, int val)
{
    if (head == NULL)
        return new Node(val);
    else if (val == head->val)
        head->count_ge++;
    else if (val < head->val)
        head->left = insert(head->left, val);
    else {
        head->count_ge++;
        head->right = insert(head->right, val);
    }
    return head;
}

int search(Node* head, long long target)
{
    if (head == NULL)
        return 0;
    else if (target == head->val)
        return head->count_ge;
    else if (target < head->val)
        return head->count_ge + search(head->left, target);
    else
        return search(head->right, target);
}

int reversePairs(vector<int>& nums)
{
    Node* head = NULL;
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        // 把遍历过的都插入到Binary search Tree中，便于统计个数
        // 这步就是search有多少个小于这个值的
        count += search(head, nums[i] * 2LL + 1);
        head = insert(head, nums[i]);
    }
    return count;
}
};




// Binary Indexed Tree.
// 过了
class Solution {
public:
void update(vector<int>& BIT, int index, int val)
{
    while (index > 0) {
        BIT[index] += val;
        index -= index & (-index);
    }
}

int query(vector<int>& BIT, int index)
{
    int sum = 0;
    while (index < BIT.size()) {
        sum += BIT[index];
        index += index & (-index);
    }
    return sum;
}
int reversePairs(vector<int>& nums)
{
    int n = nums.size();
    vector<int> nums_copy(nums);

    sort(nums_copy.begin(), nums_copy.end());

    vector<int> BITS(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
        update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
    }
    return count;
}
};




// solution 4: MergeSort
// 突然想到这个和那个分治法求逆序对的个数的题是一样的
// 算法课上讲到的题
class Solution {
public:
void merge(vector<int>& A, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

int mergesort_and_count(vector<int>& A, int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

int reversePairs(vector<int>& nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}
};