#!/bin/bash

###### Config Start
PIPEX_PATH=./pipex
INFILE=/usr/share/dict/words
###### Config End

# func to execute pipex case
execute_pipex_program_1 () {
    $PIPEX_PATH $1 "$2" "$3" out
    cat out > pipex_output
    rm out
}

# func to execute pipex case with 2 args for each cmd
execute_pipex_program_2 () {
    $PIPEX_PATH $1 "$2 $3" "$4 $5" out
    cat out > pipex_output
    rm out
}

# func to execute real case
execute_real_program_1 () {
    < $1 $2 | $3 > out
    cat out > real_output
    rm out
}

# func to execute real case with 2 args for each cmd
execute_real_program_2 () {
    < $1 $2 $3 | $4 $5 > out
    cat out > real_output
    rm out
}

test_program_1 () {
    execute_pipex_program_1 $INFILE $2 $3
    execute_real_program_1 $INFILE $2 $3
    DIFF=$(diff real_output pipex_output)
    if [ "$DIFF" == "" ]; then
        printf "\033[32mtest $1 passed\033[0m\n"
    else
        printf "\033[31mtest $1 failed\033[0m\n"
        cat pipex_output > pipex_output_error_$1
        cat real_output > real_output_error_$1
    fi
    rm pipex_output real_output
}

test_program_2 () {
    execute_pipex_program_2 $INFILE $2 $3 $4 $5
    execute_real_program_2 $INFILE $2 $3 $4 $5
    DIFF=$(diff real_output pipex_output)
    if [ "$DIFF" == "" ]; then
        printf "\033[32mtest $1 passed\033[0m\n"
    else
        printf "\033[31mtest $1 failed\033[0m\n"
        cat pipex_output > pipex_output_error_$1
        cat real_output > real_output_error_$1
    fi
    rm pipex_output real_output
}

# test_program test_number cmd1 cmd2
test_program_2 1 cat -e wc -l
test_program_1 2 cat wc
test_program_1 3 wc cat
test_program_1 4 wc wc
test_program_1 5 echo echo
test_program_2 6 wc -c wc -c