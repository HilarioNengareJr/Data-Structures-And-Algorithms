class Node {
    // structure of a Node object
    constructor(payload, nextLink){
        this.payload = payload;
        this.nextLink = nextLink;  
    }
}



class List {
    constructor (head){
        this.head = head
    }
    
    append(newNode){
        if (!this.head){
            this.head = newNode;
            return;
        }
        
        let current = this.head;
        while(current.nextLink !== null){
            current = current.nextLink;
        }
        current.nextLink = newNode;
        newNode.nextLink = null; // terminator
    }
    
    prepend(newNode) {
        newNode.nextLink = this.head;
        this.head = newNode;
    }
    
    showList(){
        let current = this.head;
        
        while (current !== null){
            console.log(current.payload);
            current = current.nextLink;
        }
    }
}


let nodeOne = new Node(345, null);
let nodeTwo = new Node(567,null);
let nodeThree= new Node(645, null);
let nodeFour = new Node(4578, null);

lst = new List(nodeOne);
lst.append(nodeTwo);
lst.append(nodeThree);
lst.prepend(nodeFour);

lst.showList()

