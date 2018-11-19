// map1.go
package main

import (
	"fmt"
)

type PersonInfo struct {
	ID      string
	Name    string
	Address string
}

func modify(slice []int) {
	slice = append(slice, 6)
	fmt.Println(slice)
}

func main() {
	/*	var personDB map[string]PersonInfo
		personDB = make(map[string]PersonInfo)

		personDB["1234"] = PersonInfo{"12345", "TOM", "ROOM203,..."}
		personDB["1"] = PersonInfo{"1", "Jack", "ROOM 101,..."}
		person, ok := personDB["1234"]
		if ok {
			fmt.Println("Found Person ", person.Name, " with ID 1234")
		} else {
			fmt.Println("Did not find person with ID 1234")
		} */
	var j int = 5
	a := func() func() {
		var i int = 10
		return func() {
			fmt.Printf("i, j: %d %d\n", i, j)
		}
	}()
	a()
	j *= 2
	a()
}
