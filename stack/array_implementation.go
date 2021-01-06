package main

import (
	"fmt"
)

// Stack represents stack that holds a slice
type Stack struct {
	items []int
}

// Push value at end
func (s *Stack) Push(value int)  {
	s.items = append(s.items, value)
}

// Pop value at end and return removed value
func (s *Stack) Pop() int {
	if len(s.items) > 0 {
		value := s.items[len(s.items)-1]
		s.items = s.items[:len(s.items)-1]
		fmt.Printf("Value popped: %v \n", value)
		return value
	} else {
		errMsg :=  "Stack is empty!"
		fmt.Println(errMsg)
		return 0
	}
}

func main()  {
	myStack := Stack{}
	myStack.Push(2)
	myStack.Push(1)
	myStack.Push(8)
	myStack.Push(6)
	fmt.Println(myStack)
	myStack.Pop()
	fmt.Println(myStack)
	myStack.Pop()
	fmt.Println(myStack)
}