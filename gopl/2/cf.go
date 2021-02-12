package main

import (
	"fmt"
	"os"
	"strconv"

	"github.com/chengxueming/tempconv"
)

func main() {
	for _, arg := range os.Args[1:] {
		argf, err := strconv.ParseFloat(arg, 64)
		if err != nil {
			fmt.Fprintf(os.Stderr, "param error %s %v\n", arg, err)
			os.Exit(1)
		}
		c := tempconv.Celsius(argf)
		f := tempconv.Fahrenheit(argf)
		fmt.Printf("%v equal to %v, %v equal to %v", c, tempconv.CToF(c), f, tempconv.FToC(f))
	}
}
