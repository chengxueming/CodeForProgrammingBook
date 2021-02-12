package main

import (
	"fmt"
	"net/http"
	"os"
	"strings"
)

func main() {
	// handler := func(w http.ResponseWriter, r *http.Request) {

	// }
	// http.HandleFunc("/", handler)
	// http.ListenAndServe("localhost:8000", nil)
	for _, url := range os.Args[1:] {
		if !strings.HasPrefix(url, "http://") && !strings.HasPrefix(url, "https://") {
			url = "http://" + url
		}
		resp, err := http.Get(url)
		if err != nil {
			fmt.Fprintf(os.Stderr, "err in get %s %v\n", url, err)
			continue
		}
		fmt.Println(resp.Status)
		// _, err = io.Copy(os.Stdout, resp.Body)
		resp.Body.Close()
		if err != nil {
			fmt.Fprintf(os.Stderr, "read err %s %v\n", url, err)
		}
	}
}
