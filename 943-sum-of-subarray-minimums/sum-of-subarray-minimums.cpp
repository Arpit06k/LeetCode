class Solution {
public:

    vector<int> nse(vector<int>& num1) {
        int n = num1.size();
        vector<int> nsee(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && num1[st.top()] >= num1[i]) {
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsee;
    }

    vector<int> pse(vector<int>& num2) {
        int n = num2.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && num2[st.top()] > num2[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        vector<int> left = pse(arr);
        vector<int> right = nse(arr);
        long total = 0; // Initialize total
        
        for(int i = 0; i < n; i++) {
            int l = i - left[i]; // Distance to the previous smaller element
            int r = right[i] - i; // Distance to the next smaller element
            total = (total + (long)arr[i] * l * r) % mod;
        }

        return total;
    }
};
