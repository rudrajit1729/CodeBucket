## OS LAB 1
## 09/09/2020
## author - rudrajit1729

#1
touch empty1 empty2 empty3 empty4 empty5

#2
cat > text

#3
cat text

#4
cp text newtext

#5
cat > matter

#6
echo cat text matter > txtmat

#7
rm text

#8
chmod 666 newtxt

#9
mv newtext oldtext

#10
mkdir mydir

#11
mv oldtext matter mydir

#12
mkdir mydir/newdir

#13
mv mydir/* mydir/newdir #Executes but with error msg

#14
date +%d/%m/%y

#15
who #Shows nothing on online shell but works on local system

#16
tree /* #Shows a massive output (not rec until necessary)

#17
who |wc -l

#18
# It fails if xyz has data in it i.e., is non empty

#19
# Goes to home 

#20
cat > details.txt # Create a file to store details of atleast 10 students
# Format:
#Roll|Name|Dept|HOD
1|Rudy|CSE|XYZ # Example for format
^Z
# 20a
cut -d "|" -f 1,3 details.txt #Shows 1st and 3rd columns for each row in details.txt
1|CSE # Sample Output
# 20b
sort -k2,2 -t '|' details.txt # Displays sorted order based on names
# -k used to specify column, start column specified(sorting wrt single column value will be same)
# -t "|" has been used to specify delimiter

#21
#Create a file 
cat > abc.txt
I am a boy
i am a boy
I AM A BOY
i am indian   
^Z
#Match with grep
grep "I am a boy" abc.txt # Displays the text as it exists
grep -i "I am a boy" abc.txt # Displays all occurances of text ignoring case
grep -n "I am a boy" abc.txt # Displays matching text and line number
grep -v "I am a boy" abc.txt # Displays all lines not matching text
grep -c "I am a boy" abc.txt # Displays text and number of lines where match occurs

#22
cat > numbers.txt # Create file and store numbers 
sort numbers.txt # Shows numbers in sorted order
sort numbers.txt > output.txt # Sorts numbers and stores sorted list in output 
