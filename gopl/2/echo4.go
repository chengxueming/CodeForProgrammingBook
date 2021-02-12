package main

import (
	"flag"
	"fmt"
	"strings"
)

var n = flag.Bool("n", false, "not display new line")
var sep = flag.String("sep", " ", "join the args of program")

func main() {
	flag.Parse()
	fmt.Println(strings.Join(flag.Args(), *sep))
	if !*n {
		fmt.Println()
	}
}
