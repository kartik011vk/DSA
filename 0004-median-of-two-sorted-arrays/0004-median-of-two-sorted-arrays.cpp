class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;

        int ind1 = (n / 2) - 1;
        int ind2 = n / 2;

        int cnt = 0;

        int indexel1 = -1;
        int indexel2 = -1;

        int i = 0;
        int j = 0;

        // Traverse both arrays
        while (i < n1 && j < n2) {

            if (nums1[i] <= nums2[j]) {

                if (cnt == ind1) {
                    indexel1 = nums1[i];
                }

                if (cnt == ind2) {
                    indexel2 = nums1[i];
                }

                i++;
                cnt++;
            }

            else {

                if (cnt == ind1) {
                    indexel1 = nums2[j];
                }

                if (cnt == ind2) {
                    indexel2 = nums2[j];
                }

                j++;
                cnt++;
            }
        }

        // Remaining elements of nums1
        while (i < n1) {

            if (cnt == ind1) {
                indexel1 = nums1[i];
            }

            if (cnt == ind2) {
                indexel2 = nums1[i];
            }

            i++;
            cnt++;
        }

        // Remaining elements of nums2
        while (j < n2) {

            if (cnt == ind1) {
                indexel1 = nums2[j];
            }

            if (cnt == ind2) {
                indexel2 = nums2[j];
            }

            j++;
            cnt++;
        }

        // Odd number of elements
        if (n % 2 == 1) {
            return indexel2;
        }

        // Even number of elements
        return (double)(indexel1 + indexel2) / 2.0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna