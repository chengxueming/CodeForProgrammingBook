package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"time"
)

func fetch(url string, c chan string) {
	start := time.Now()
	resp, err := http.Get(url)
	if err != nil {
		c <- fmt.Sprint(err)
		return
	}
	n, err := io.Copy(ioutil.Discard, resp.Body)
	resp.Body.Close()
	c <- fmt.Sprintf("%.2f %d %s\n", time.Since(start).Seconds(), n, url)
}

func main() {
	c := make(chan string)
	start := time.Now()
	for _, url := range os.Args[1:] {
		go fetch(url, c)
	}
	for range os.Args[1:] {
		fmt.Println(<-c)
	}
	fmt.Printf("%.2f seconds eplased\n", time.Since(start).Seconds())
}
