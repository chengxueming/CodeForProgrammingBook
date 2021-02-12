package main

import (
	"strings"
	"testing"
)

func BenchmarkEcho(b *testing.B) {
	s := strings.Repeat("aaaaaa,", 100)
	arr := strings.Split(s, ",")
	for i := 0; i < b.N; i++ {
		strings.Join(arr, ",")
	}
}
