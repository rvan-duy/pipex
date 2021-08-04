#!/bin/bash

func to execute pipex case
func to execute real case

loop to call those functions:
    execute func1 > pipex_output
    execute func2 > real_output
    store in diff variable = diff pipex_output real_output
    check if diff is ""
    if it is, continue print test passed
    if its not error and print with test failed, but also continue.



https://stackoverflow.com/questions/3611846/bash-using-the-result-of-a-diff-in-a-if-statement
https://ryanstutorials.net/bash-scripting-tutorial/bash-functions.php
