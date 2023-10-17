/**
 * @param {number} n
 * @param {number[]} leftChild
 * @param {number[]} rightChild
 * @return {boolean}
 */
var validateBinaryTreeNodes = function (n, leftChild, rightChild) {
    let count = n - 1;
    let parent = new Array(n).fill(-1);
    let visited = new Array(n).fill(0);

    for (let i = 0; i < n; ++i) {
        if(leftChild[i] === -1) continue;
            if(visited[leftChild[i]] === 1) return false;
            let temp = parent[i];
            while(temp !== -1){
                if(temp === leftChild[i]) return false;
                temp = parent[temp];
            }

            parent[leftChild[i]] = i;
            visited[leftChild[i]] = 1;
            count--;
    }

    for (let i = 0; i < n; ++i) {
        if(rightChild[i] === -1) continue;
            if(visited[rightChild[i]] === 1) return false;
            let temp = parent[i];
            while(temp !== -1){
                if(temp === rightChild[i]) return false;
                temp = parent[temp];
            }

            parent[rightChild[i]] = i;
            visited[rightChild[i]] = 1;
            count--;
    }

    return count === 0;
};

let n = 4, leftChild = [1, -1, 3, -1], rightChild = [2, -1, -1, -1];
console.log(validateBinaryTreeNodes(n, leftChild, rightChild));
