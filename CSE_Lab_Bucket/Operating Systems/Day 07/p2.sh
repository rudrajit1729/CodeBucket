clear
i="y"
echo "Enter name of database "
read db
if [[ ! -e $db ]]
then
    touch $db
    echo "Roll  |  Name  |  City">>$db
    
fi

while [ $i = "y" ]
do
clear
echo "1.View the Data Base "
echo "2.View Specific Records "
echo "3.Add Records "
echo "4.Delete Records "
echo "5.Update Records "
echo "6.Exit "
echo "Enter your choice "
read ch
    case $ch in
        1)
		  cat $db;;
        2)echo "Enter Roll "
          read id
            grep -i "$id" $db;;
        3)echo "Enter Roll: "
          read id
          echo "Enter new std name: "
          read name
          echo "Enter City: "
          read city
          echo "$id  |  $name  |  $city">>$db;;
        4)echo "Enter Roll"
          read id
          dbs1=$(grep -v $id $db)
          echo $dbs1 > $db
          echo "Record is deleted"
          cat db;;
        5)echo "Enter Roll"
          read id
          dbs1=$(grep -v $id $db)
          echo $dbs1 > $db
          echo "Enter new std name: "
          read name
          echo "Enter City: "
          read city
          echo "$id  |  $name  |  $city">>$db;;
        6)exit;;
        *)echo "Invalid choice ";;
    esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done