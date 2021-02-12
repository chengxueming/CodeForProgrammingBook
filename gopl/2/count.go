package main

import (
	"fmt"
	"os"
	"strconv"

	"github.com/chengxueming/popcount"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Useage: %s target\n", os.Args[0])
		os.Exit(1)
	}
	num, err := strconv.ParseUint(os.Args[1], 10, 64)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Useage: %s target\n", os.Args[0])
		os.Exit(1)
	}
	fmt.Println(popcount.PopCount2(num))
}
