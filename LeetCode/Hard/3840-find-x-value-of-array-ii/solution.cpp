class Solution {
public:
    struct Node{
        int prod;
        int cnt[5] = {};

        Node(){
            prod = 1;
        }
    };

    int k;
    vector<Node> seg;

    void build(int node, int left, int right, vector<int> &nums){
        if(left==right){
            seg[node].prod = nums[left]%k;
            seg[node].cnt[nums[left]%k] = 1;
            return;
        }

        int mid = left + (right-left)/2;

        build(node*2+1, left, mid, nums);
        build(node*2+2, mid+1, right, nums);

        seg[node] = merge(seg[node*2+1], seg[node*2+2]);
    }

    Node merge(Node &left, Node &right){
        Node res;

        res.prod = (1LL*left.prod * right.prod)%k;

        // Subarrays completely inside left
        for(int rem=0; rem<k; rem++){
            res.cnt[rem] += left.cnt[rem];
        }

        // Subarrays completely inside right
        for(int rem=0; rem<k; rem++){
            int nrem = (1LL*left.prod*rem)%k;
            res.cnt[nrem] += right.cnt[rem];
        }

        return res;
    }

    void update(int node, int left, int right, int index, int value){
        if(left==right){
            seg[node].prod = value%k;

            fill(seg[node].cnt, seg[node].cnt+5, 0);
            seg[node].cnt[value%k] = 1;

            return;
        }

        int mid = left + (right-left)/2;

        if(index<=mid)
            update(node*2+1, left, mid, index, value);
        else
            update(node*2+2, mid+1, right, index, value);

        seg[node] = merge(seg[node*2+1], seg[node*2+2]);
    }

    Node query(int node, int left, int right, int ql, int qr){
        if(right<ql || left>qr)
            return Node(); // outside

        if(ql<=left && right<=qr)
            return seg[node]; // completely inside

        int mid = left + (right-left)/2;

        Node L = query(node*2+1, left, mid, ql, qr);
        Node R = query(node*2+2, mid+1, right, ql, qr);

        return merge(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ){
        int n = nums.size();

        this->k = k;
        seg.resize(4*n, Node());

        build(0, 0, n-1, nums);

        vector<int> ans;

        for(auto &q : queries){
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int need = q[3];

            nums[index] = value;

            update(0, 0, n-1, index, value);

            Node res = query(0, 0, n-1, start, n-1);

            ans.push_back(res.cnt[need]);
        }

        return ans;
    }
};