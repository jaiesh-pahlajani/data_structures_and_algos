package main

import "fmt"

// Node represents the components of BST
type Node struct {
	Data int
	Left *Node
	Right *Node
}

// Insert - Will add node to tree
func (n *Node) Insert(k int)  {

	if n.Data == 0 {
		n.Data = k
		return
	}

	if n.Data < k {
		// move right
		if n.Right == nil {
			// If right is empty then add new node to the right
			n.Right = &Node{Data: k}
			return
		} else {
			// If already a node exists then try to insert as leaf of right child node
			n.Right.Insert(k)
		}
	} else if n.Data > k {
		// move left
		if n.Left == nil {
			// If right is empty then add new node to the right
			n.Left = &Node{Data: k}
			return
		} else {
			// If already a node exists then try to insert as leaf of right child node
			n.Left.Insert(k)
		}
	}
}

// Search
func (n *Node) Search(value int) bool {

	if n == nil {
		return false
	}

	if value > n.Data {
		n.Right.Search(value)
	} else {
		n.Left.Search(value)
	}
	return true
}

func main()  {
	tree := &Node{}
	tree.Insert(120)
	tree.Insert(200)
	tree.Insert(100)
	fmt.Println(tree.Search(100))
	fmt.Println(tree.Left)

}