package main

import ("fmt"
        "runtime"
        "sync"
)

func main() {
    runtime.GOMAXPROCS(14)
    var wait_group sync.WaitGroup
    letter_mutex := make([]sync.Mutex, 14)

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

    for i := 1; i< 14; i++ {
        // Lock all of the other mutexes
        letter_mutex[i].Lock()
    }

    for i := 0; i < 14; i++ {
        wait_group.Add(1)
        go func (i int, letters []string) {
            letter_mutex[i].Lock()
            fmt.Print(letters[i])
            if i < 13 {
                letter_mutex[i+1].Unlock()
            }
            wait_group.Done()
        } (i, letters)
    }
    wait_group.Wait()
    fmt.Print("\n")
}
