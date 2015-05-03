package main

import (
	"fmt"
)

type HelloInterface interface {
	print()
}

type GitHubPrint struct {
}

func (g GitHubPrint) print() {
	fmt.Println("Hello, GitHub!")
}

func main() {
	GitHubPrint{}.print()
}
