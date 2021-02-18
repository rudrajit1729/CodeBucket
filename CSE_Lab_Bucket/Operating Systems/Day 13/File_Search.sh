directory="C:\Users\HP\Desktop\OS"
ex="c"
for i in "$directory"/*;
  do
    extension=`"$i" | cut -d'.' -f2`
    if     [ -f "$i" ]; then        
        if [ $extension == $ex ]; then
            echo "$i"
        fi
    fi
  done


: '
rudrajit1729@DESKTOP-22VPBBI:/mnt/c/Users/HP/Desktop/OS/$ sh File_Search.sh
Output:
C:/Users/HP/Desktop/OS/Day 10/Pipes/pipe1.c
C:/Users/HP/Desktop/OS/Day 10/Pipes/pipe2.c
C:/Users/HP/Desktop/OS/Day 10/Signals/p1.c
C:/Users/HP/Desktop/OS/Day 10/Signals/p2.c
C:/Users/HP/Desktop/OS/Day 10/Signals/p3.c
C:/Users/HP/Desktop/OS/Day 10/Signals/p4.c
C:/Users/HP/Desktop/OS/Day 11/producer_consumer.c
C:/Users/HP/Desktop/OS/Day 12/Memory - Copy.c
C:/Users/HP/Desktop/OS/Day 12/Memory.c
C:/Users/HP/Desktop/OS/Day 12/mem_partition.c

'
