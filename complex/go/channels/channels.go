package main

import (
    "fmt"
    "runtime"
    "sync"
)

func provider(c chan string, wait_group * sync.WaitGroup) {
    letters := make([]string, 14)
    letters[13] = "!"
    letters[12] = "b"
    letters[11] = "u"
    letters[10] = "H"
    letters[9] = "t"
    letters[8] = "i"
    letters[7] = "G"
    letters[6] = " "
    letters[5] = ","
    letters[4] = "o"
    letters[3] = "l"
    letters[2] = "l"
    letters[1] = "e"
    letters[0] = "H"

    for i := 0 ; i < 14; i++ {
        c <- letters[i]
    }
    (*wait_group).Done()
}
func printer(c chan string, wait_group * sync.WaitGroup) {
    for {
        msg := <- c
        fmt.Print(msg)
        if msg == "!" {
            fmt.Print("\n")
            break;
        }
    }
    (*wait_group).Done()
}
func main() {
    c := make(chan string)
    var wait_group sync.WaitGroup
    runtime.GOMAXPROCS(4)
    wait_group.Add(2)
    go provider(c, &wait_group)
    go printer(c, &wait_group)

    wait_group.Wait()
}
