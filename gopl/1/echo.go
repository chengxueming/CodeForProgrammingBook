package main

import (
	"fmt"
	"os"
)

func Echo(args []string, split string) string {
	var s, sep string
	for _, arg := range os.Args[1:] {
		s += sep + arg
		sep = split
	}
	return s
}

func main() {
	fmt.Println(Echo(os.Args[1:], " "))
}
