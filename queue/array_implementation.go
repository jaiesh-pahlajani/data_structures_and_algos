package main

import "fmt"

// Queue represents a queue that holds a slice
type Queue struct {
	items []int
}

// Enqueue at end of slice
func (q *Queue) Enqueue(value int) {
	q.items = append(q.items, value)
}

// Dequeue at start of slice
func (q *Queue) Dequeue() int {
	if len(q.items) > 0 {
		val := q.items[0]
		q.items = q.items[1:]
		return val
	} else {
		fmt.Println("Queue is empty!")
		return 0
	}
}

func main()  {
	myQueue := Queue{}
	myQueue.Enqueue(1)
	myQueue.Enqueue(100)
	myQueue.Enqueue(10)
	myQueue.Dequeue()
	fmt.Println(myQueue)
}
