package main

import (
	"flag"
	"fmt"
	"log"
	"strconv"
)

func gcd(x, y int) int {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

func main() {
	flag.Parse()
	if len(flag.Args()) < 2 {
		log.Fatal("Useage: gcd num1 num2")
	}
	num1, err := strconv.Atoi(flag.Args()[0])
	if err != nil {
		log.Fatal("num1 is not a number")
	}
	num2, err := strconv.Atoi(flag.Args()[1])
	if err != nil {
		log.Fatal("num2 is not a number")
	}
	fmt.Println(gcd(num1, num2))
}
