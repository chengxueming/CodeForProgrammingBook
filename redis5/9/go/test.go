package main

import (
	"fmt"
	"time"
)
 
func main()  {
	timeObj := time.Now()
	fmt.Println(timeObj.Second(), timeObj.Nanosecond())
}