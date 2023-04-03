var numRescueBoats = function (people, limit) {
    people.sort((a, b) => a - b);
    let low = 0, high = people.length - 1;
    let boatCount = 0;
    while(low <= high){
        if(people[low] + people[high] <= limit) low++;
        high--;
        boatCount++;
    }
    return boatCount;
};

let people = [1,2], limit = 3;
console.log(numRescueBoats(people, limit));