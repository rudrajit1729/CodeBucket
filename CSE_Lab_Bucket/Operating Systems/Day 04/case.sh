case $1 in
    1) cat file1.txt file2.txt > file3.txt
       cat file3.txt;;
    2) grep "Rudrajit" file1.txt;;
    *) echo "Invalid Option";;
esac

# Output
# sh case.sh 1
# My name is Rudrajit
# I am 21.
# ~$ sh case.sh 2
# My name is Rudrajit
# ~$ sh case.sh 7
# Invalid Option