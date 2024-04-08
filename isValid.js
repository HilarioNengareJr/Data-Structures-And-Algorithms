function isValid(s) {
    let stack = [];

    for (const i of s) {
        if (i === '(' || i === '[' || i === '{') {
            stack.push(i);
        } else if (
            (i === ')' && stack[stack.length - 1] === '(') ||
            (i === '}' && stack[stack.length - 1] === '{') ||
            (i === ']' && stack[stack.length - 1] === '[')
        ) {
            stack.pop(); // Remove the corresponding opening bracket
        } else {
            return false; // If no matching opening bracket found, return false
        }
    }

    return stack.length === 0; // Return true if stack is empty (all brackets matched)
}
