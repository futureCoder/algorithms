// calc project doc.go

/*
calc document
*/
package main

import "fmt"
import "os"
import "calc/simplemath"
import "strconv"

var Usage = func() {
	fmt.Println("USAGE: calc command [arguments]...")
}

func main() {
	args := os.Args[1:]
	if args == nil || len(args) < 2 {
		Usage()
		return
	}

	switch args[0] {
	case "add":
		if len(args) != 3 {
			fmt.Println("USAGE: calc add")
			return
		}
		v1, err1 := strconv.Atoi(args[1])
		v2, err2 := strconv.Atoi(args[2])
		if err1 != nil || err2 != nil {
			fmt.Println("USAGE: calc add")
			return
		}
		ret := simplemath.Add(v1, v2)
		fmt.Println("Result: ", ret)
	case "sqrt":
		if len(args) != 2 {
			fmt.Println("USAGE: calc sqrt")
			return
		}
		v, err := strconv.Atoi(args[1])
		if err != nil {
			fmt.Println("USAGE: calc sqrt")
			return
		}
		ret := simplemath.Sqrt(v)
		fmt.Println("Result: ", ret)
	default:
		Usage()
	}
}
