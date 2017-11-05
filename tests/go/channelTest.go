package main

import (
	"fmt"
	"time"
)

/*
  compile : go build channelTest.go
  run : go run channelTest.go
*/

func pinger(c chan string) {
	for i := 0; ; i++ {
		c <- "ping"
	}
}

func printer(c chan string) {
	for {
		msg := <- c
		fmt.Println(msg)
		time.Sleep(time.Second * 1)
	}
}

func main() {

  fmt.Printf("Start Exemple\n")

	var c chan string = make(chan string)

	go pinger(c)
	go printer(c)

	var input string
	fmt.Scanln(&input)
}
