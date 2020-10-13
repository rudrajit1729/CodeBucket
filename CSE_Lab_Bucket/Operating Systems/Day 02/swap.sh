echo "Enter value for x : "
read x
echo "Enter value for y : "
read y

echo "Before swap, x = $x and y = $y"

echo "Using 3rd variable\n"
z=$x
x=$y
y=$z
echo "After swap, x = $x and y = $y\n"

echo "Without 3rd variable\n"
x=`expr $x + $y`
y=`expr $x - $y`
x=`expr $x - $y`
echo "After swap, x = $x and y = $y\n"

# Output
# sh swap.sh
# Enter value for x : 
# 5
# Enter value for y : 
# 3
# Before swap, x = 5 and y = 3
# Using 3rd variable

# After swap, x = 3 and y = 5

# Without 3rd variable

# After swap, x = 5 and y = 3