/**
* Given an array of integers nums and an integer target, 
* return indices of the two numbers such that they add up to target.
*/

function twoSum(nums, target) {
    // initialise a hashmap that will map out each index to a value key.
    const handleIndices = {};
    // initialise an array data structure to hold the returned indices.
    const indices = [];

    // traverse the nums data structure 
    for (let i = 0; i < nums.length; i++) {
        // subtract the individual value from the target and store it as complement 
        let complement = target - nums[i];
        // if the complement is present in nums then we store both indices
        if (handleIndices.hasOwnProperty(complement)) {
            indices.push(handleIndices[complement], i);
            break; 
        }
        // if its not then we store the current index
        handleIndices[nums[i]] = i;
    }

    return indices;
}

