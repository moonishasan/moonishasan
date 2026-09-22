class Solution {
    class Node{
        public:
            int mul=1;
            array<int,5> freq{};
    };
    class segmentTree{
        public:
            vector<Node> seg;
            int n;
            segmentTree(int n){
                seg.resize(4*n);
                this->n=n;
            }
            void merge(int idx,int left,int right, int k){
                seg[idx].mul=(seg[left].mul*seg[right].mul)%k;
                seg[idx].freq=seg[left].freq;
                for(int r=0;r<k;r++){
                    int nr=(seg[left].mul*r)%k;
                    seg[idx].freq[nr]+=seg[right].freq[r];
                }
            }
            void build(int idx,int l,int r,int k,vector<int> &nums){
                if(l>r) return;
                if(l==r){
                    seg[idx].mul=nums[l]%k;
                    seg[idx].freq[nums[l]%k]++;
                    return;
                }
                int mid=(l+r)/2;
                build(2*idx+1,l,mid,k,nums);
                build(2*idx+2,mid+1,r,k,nums);
                merge(idx,2*idx+1,2*idx+2,k);
            }
            void update(int idx,int ind,int val,int l,int r,int k){
                if(l>r) return;
                if(l==r){
                    seg[idx].mul=val%k;
                    for(int i=0;i<5;i++){
                        seg[idx].freq[i]=0;
                    }
                    seg[idx].freq[val%k]=1;
                    return;
                }
                int mid=(l+r)/2;
                if(ind<=mid) update(2*idx+1,ind,val,l,mid,k);
                else update(2*idx+2,ind,val,mid+1,r,k);
                merge(idx,2*idx+1,2*idx+2,k);
            }
            Node query(int idx,int ql,int qr,int l,int r,int k){
                if(ql>r || qr<l) return Node();
                if(l>=ql && r<=qr) return seg[idx];
                int mid=(l+r)/2;
                Node left=query(2*idx+1,ql,qr,l,mid,k);
                Node right=query(2*idx+2,ql,qr,mid+1,r,k);
                Node ans;
                ans.mul=(left.mul*right.mul)%k;
                ans.freq=left.freq;
                for(int i=0;i<k;i++){
                    int nr=(left.mul*i)%k;
                    ans.freq[nr]+=right.freq[i];
                }
                return ans;
            }
    };
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        segmentTree tree(n);
        tree.build(0,0,n-1,k,nums);
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            int ind=queries[i][0];
            int value=queries[i][1];
            int start=queries[i][2];
            int x=queries[i][3];
            tree.update(0,ind,value,0,n-1,k);
            Node res=tree.query(0,start,n-1,0,n-1,k);
            ans[i]=res.freq[x];
        }
        return ans;
    }
};