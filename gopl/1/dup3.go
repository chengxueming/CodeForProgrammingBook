package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {
	files := os.Args[1:]
	counts := make(map[string][]string)
	for _, file := range files {
		content, err := ioutil.ReadFile(file)
		if err != nil {
			fmt.Fprintf(os.Stderr, "dup2 err %v\n", err)
			continue
		}
		for _, line := range strings.Split(string(content), "\n") {
			counts[line] = append(counts[line], file)
		}
	}
	fmt.Println(counts, files)
	for line, files := range counts {
		if len(files) > 1 {
			fmt.Printf("%s\t%v\n", line, files)
		}
	}
}
