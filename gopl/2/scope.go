package main

import (
	"fmt"
	"io"
	"log"
	"os"
)

var cwd string

func printCwd() {
	fmt.Println("cwd is", cwd)
}

func openFile() {
	if f, err := os.Open("./cf.go"); err != nil {
		log.Fatal("err open file")
	} else {
		io.Copy(os.Stdout, f)
	}
}

func main() {
	var err error
	cwd, err = os.Getwd()
	if err != nil {
		log.Fatal("fatal")
	}
	printCwd()

}
