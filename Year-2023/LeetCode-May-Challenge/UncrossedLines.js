var maxUncrossedLines = function (nums1, nums2) {
    let n = nums1.length, m = nums2.length, size = Math.max(n + 1, m + 1);
    if (n === 1 && m === 1 && nums1[0] !== nums2[0]) return 0;
    let dp = new Array(size);
    for (let i = 0; i < size; ++i) dp[i] = new Array(size).fill(-1);
    for (let i = 0; i < Math.max(n, m); ++i) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= m; ++j) {
            if (nums1[i - 1] === nums2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
};

let nums1 = [1, 4, 2], nums2 = [1, 2, 4];
console.log(maxUncrossedLines(nums1, nums2));