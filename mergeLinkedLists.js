
/**
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

// definition of class ListNode
class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

// function to merge the two linked lists
var mergeTwoLists = function(list1, list2) {
    let temp = new ListNode();
    let current  = temp; // [0, null] -> [list1]

    if (!list1){
        return list2;
    }
    else if (!list2){
        return list1;
    }

    while (list1 !== null && list2 !== null){
        if(list1.val <= list2.val){
            current.next = list1;
            list1 = list1.next;
        }
        else{
            current.next = list2;
            list2 = list2.next;
        }

        current = current.next; // update current to be the next node
    }

    // if we have any other un appended nodes in either lists
    if(list1 !== null){
        current.next = list1;
        list1 = list1.next;
    }else{
        current.next = list2;
        list2 = list2.next;
    }

    return temp.next;
};
