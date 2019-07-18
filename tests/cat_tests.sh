#/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
DEF="\033[0m"

ft_cat="./c_cat_tests"
input_folder="tests/input_files"

for file in "$input_folder"/*; do

    ft_ret="$($ft_cat $file)"
    ret="$(cat $file)"

    if [[ "$ft_ret" == "$ret" ]]; then
        printf "%-50s$GREEN%s$DEF\n" "$file" "OK"
    else
        printf "%-50s$RED%s$DEF\n" "$file" "KO"
    fi

done

printf "\nReading on STDIN:\n"
$ft_cat "STDIN"

