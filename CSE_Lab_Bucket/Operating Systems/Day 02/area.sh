echo "Enter the base and height of the triangle : "
read base
read height
area=`expr "scale=3; 1/2*$base*$height"|bc`
echo "area of the triangle = $area"

# Output
# sh area.sh
# Please enter the base and height of the triangle : 2.7
# 3.5
# area of the triangle = 4.725