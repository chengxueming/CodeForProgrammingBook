package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func countLines(reader io.Reader, counts map[string]int) {
	input := bufio.NewScanner(reader)
	for input.Scan() {
		counts[input.Text()]++
	}
}

func main() {
	files := os.Args[1:]
	counts := make(map[string]int)
	if len(files) == 0 {
		countLines(os.Stdin, counts)
	} else {
		for _, file := range files {
			f, err := os.Open(file)
			if err != nil {
				fmt.Fprintf(os.Stderr, "dup2 err %v\n", err)
				continue
			}
			countLines(f, counts)
		}
	}
	fmt.Println(counts, files)
	for line, n := range counts {
		if n > 1 {
			fmt.Printf("%d\t%s\n", n, line)
		}
	}
}
