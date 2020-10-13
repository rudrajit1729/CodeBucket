echo "Enter temp in Celsius"
read C

F=`expr "scale=2; 9/5*$C+32"|bc`

echo "Temp in Fahrenheit = $F"

# Output
# sh C2F.sh
# Enter temp in Celsius
# 23.3
# Temp in Fahrenheit = 73.94