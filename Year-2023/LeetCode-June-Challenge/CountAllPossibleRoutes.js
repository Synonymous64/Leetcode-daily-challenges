var countRoutes = function (locations, start, finish, fuel) {
    let dp = new Array(101);
    for (let i = 0; i < 101; ++i)
        dp[i] = new Array(201).fill(-1);
    let mod = 1000000007;

    const helper = (locations, idx, finish, fuel) => {
        if (fuel <= 0) return idx === finish ? 1 : 0;
        if (dp[idx][fuel] !== -1) return dp[idx][fuel];

        let res = 0;
        if (idx === finish) res = 1;

        for (let i = 0; i < locations.length; ++i) {
            if (i !== idx && Math.abs(locations[idx] - locations[i]) <= fuel) {
                res = (res % mod + helper(locations, i, finish, fuel - Math.abs(locations[idx] - locations[i])) % mod) % mod;
            }
        }

        return dp[idx][fuel] = res;
    }
    return helper(locations, start, finish, fuel);
};

let locations = [2, 3, 6, 8, 4], start = 1, finish = 3, fuel = 5;
console.log(countRoutes(locations, start, finish, fuel));