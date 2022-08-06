var poorPigs = function(buckets, minutesToDie, minutesToTest) {
    return Number.parseInt(Math.ceil(Math.log(buckets)/ Math.log(minutesToTest/minutesToDie + 1)));
};
let buckets = 1000, minutesToDie = 15, minutesToTest = 60;
console.log(poorPigs(buckets, minutesToDie, minutesToTest));