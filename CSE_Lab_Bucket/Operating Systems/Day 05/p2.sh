echo "Enter a number: "
read c
x=$c
sum=0
r=0
n=0
while [ $x -gt 0 ]
do
r=`expr $x % 10`
n=`expr $r \* $r \* $r`
sum=`expr $sum + $n`
x=`expr $x / 10`
done

if [ $sum -eq $c ]
then
echo "Armstrong Number."
else
echo "Not an Armstrong Number."
fi

'''
Output
~$ sh p2.sh
Enter a number: 
1
Armstrong Number.
~$ sh p2.sh
Enter a number: 
153
Armstrong Number.
~$ sh p2.sh
Enter a number: 
452
Not an Armstrong Number.
'''