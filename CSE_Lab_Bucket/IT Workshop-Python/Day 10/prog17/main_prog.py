#Creatures package includes various modules
import Creatures
print("Find your information about creatures:examples and characteristics")
while(1):
    print("Press\n1 for fish\n2 for birds\n3 for amphibians\n4 for mammals\n5 for reptiles\n6 to exit:")
    c=int(input())
    if c==1:
        Creatures.fish.fish.examples()
        Creatures.fish.fish.chars()
    elif c==2:
        Creatures.birds.birds.examples()
        Creatures.birds.birds.chars()
    elif c==3:
        Creatures.amphibians.amphibians.examples()
        Creatures.amphibians.amphibians.chars()
    elif c==4:
        Creatures.mammals.mammals.examples()
        Creatures.mammals.mammals.chars()
    elif c==5:
        Creatures.reptiles.reptiles.examples()
        Creatures.reptiles.reptiles.chars()
    elif c==6:
        print("Thank You!!!")
        break
    else:
        print("Wrong input")
        
#for each module class concept has been introduced purposefully.
#to be noted  same process can be implemented without introducing separate classes.
        
