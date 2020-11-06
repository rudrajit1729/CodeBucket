read -p "Enter a number: " n
fact=1

while [ $n -gt 1 ]
do
  fact=$((fact * n))
  n=$((n - 1))
done

echo $fact

'''
Output
sh p6.sh
Enter a number: 5
120
'''