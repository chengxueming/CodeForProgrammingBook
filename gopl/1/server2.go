package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
)

var count uint32
var mu sync.Mutex

func counter(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "request count %d", count)
}

func handler(w http.ResponseWriter, r *http.Request) {
	// mu.Lock()
	count++
	fmt.Printf("incr to %d\n", count)
	// 	mu.Unlock()
	fmt.Fprintf(w, "URL.path = %q", r.URL.Path)
}

func echo(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "%s %s %s\n", r.Method, r.URL, r.Proto)
	for k, v := range r.Header {
		fmt.Fprintf(w, "Header [%q] = %q\n", k, v)
	}
	fmt.Fprintf(w, "Host = %q\n", r.Host)
	fmt.Fprintf(w, "RemoteAddr = %q\n", r.RemoteAddr)
	if err := r.ParseForm(); err != nil {
		log.Print(err)
	}
	for k, v := range r.Form {
		fmt.Fprintf(w, "Form[%q] = %q\n", k, v)
	}
}

func main() {
	http.HandleFunc("/", handler)
	http.HandleFunc("/echo", echo)
	http.HandleFunc("/counter", counter)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}
