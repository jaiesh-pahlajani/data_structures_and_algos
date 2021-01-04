package main

import "fmt"

// Node Struct
type node struct {
	data int
	next *node
}

// LinkedList
type linkedList struct {
	head *node
	length int
}

// Add value before head
func (l *linkedList) prepend (newNode *node) {
	currentHead := l.head
	l.head = newNode
	l.head.next = currentHead
	l.length++
}

// Print all elements
func (l linkedList) printData() {
	currentNode := l.head
	for l.length!=0 {
			fmt.Println(currentNode.data)
			currentNode = currentNode.next
			l.length--
	}
	fmt.Println("-------------------------------------------------------------------------------------------------")

}

// Delete node by value
func (l *linkedList) deleteByValue(value int)  {
	currentNode := l.head
	length := l.length
	prevNode := &node{}

	// Loops through list if not empty
	for length!=0 {

		// Case 1: If node is head
		if currentNode.data == value && length==l.length{
			l.head = currentNode.next
			l.length--
			break
		}

		// Case 2: If node is tail
		if currentNode.data == value && length==0 {
			prevNode.next = nil
			currentNode.next = nil
			l.length--
			break
		}

		// Case 3: If node is absent
		if currentNode.data == value {
			prevNode.next = currentNode.next
			currentNode.next = nil
			l.length--
			break
		}

		prevNode = currentNode
		currentNode = currentNode.next
		length--
	}
}

func main()  {
	myList := linkedList{}
	node1 := &node{
		data: 48,
	}
	node2 := &node{
		data: 58,
	}
	node3 := &node{
		data: 18,
	}
	node4 := &node{
		data: 100,
	}
	node5 := &node{
		data: 2,
	}
	node6 := &node{
		data: 96,
	}
	myList.prepend(node1)
	myList.prepend(node2)
	myList.prepend(node3)
	myList.prepend(node4)
	myList.prepend(node5)
	myList.prepend(node6)

	//fmt.Println(myList)

	myList.printData()
	fmt.Println(myList.length)

	myList.deleteByValue(18)

	myList.printData()
	fmt.Println(myList.length)

	myList.deleteByValue(96)
	myList.printData()
	fmt.Println(myList.length)

	myList.deleteByValue(48)
	myList.printData()
	fmt.Println(myList.length)
}
