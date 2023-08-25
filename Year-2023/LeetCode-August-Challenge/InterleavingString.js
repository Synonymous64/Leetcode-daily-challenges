var isInterleave = function (s1, s2, s3) {
    let dp = new Array(s1.length + 1).fill(-1);
    for (let i = 0; i < dp.length; ++i)
        dp[i] = new Array(s2.length + 1).fill(-1);

    const findInterleave = (s1, s2, s3, i, j, k, dp) => {
        if (dp[i][j] !== -1) return dp[i][j];
        if (i === s1.length && j === s2.length && k === s3.length) return true;

        let x = false, y = false;
        if (i < s1.length && s1[i] === s3[k])
            x = findInterleave(s1, s2, s3, i + 1, j, k + 1, dp);
        if (j < s2.length && s2[j] == s3[k])
            y = findInterleave(s1, s2, s3, i, j + 1, k + 1, dp);

        return dp[i][j] = x || y;
    }

    return findInterleave(s1, s2, s3, 0, 0, 0, dp);
};

let s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
console.log(isInterleave(s1, s2, s3));