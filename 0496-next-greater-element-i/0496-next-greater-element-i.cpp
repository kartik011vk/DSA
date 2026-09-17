class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m ; 
        stack<int> st ; 
        for (int i = nums2.size() - 1 ; i>= 0 ; i--){
            while(st.size()> 0 && nums2[i]>= st.top()){
                st.pop() ; 
            }
            if(st.empty()){
                m[nums2[i]] = -1 ; 
            }
            else{
                m[nums2[i]] = st.top() ; 
            }
            st.push(nums2[i]) ; 
        }

        vector<int> ans ; 
        for(int i = 0 ; i< nums1.size() ; i++){
            ans.push_back(m[nums1[i]]) ; 
        }
        return ans ; 

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna