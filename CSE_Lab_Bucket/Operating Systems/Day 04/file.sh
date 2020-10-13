read -p "Enter file name: " f
read -p "Enter line start: " l
read -p "Enter line end: " e
more +$l -$e $f

# Output
# Enter file name: file.txt
# Enter line start: 1
# Enter line end: 2
# 1
# 2