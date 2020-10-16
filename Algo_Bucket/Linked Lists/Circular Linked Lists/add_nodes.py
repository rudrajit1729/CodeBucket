#In this program, we will create a circular linked list and insert every new node at the beginning of the list. If the list is empty, then head and tail will point to the newly added node. If the list is not empty,
#then we will store the data of the head into a temporary node temp and make new node as the head.
class Node:    
  def __init__(self,data):    
    self.data = data;    
    self.next = None;    
     
class CreateList:
    
      
  def __init__(self):    
    self.head = Node(None);    
    self.tail = Node(None);    
    self.head.next = self.tail;    
    self.tail.next = self.head;    
        
  #This function will add at the start of the list.    
  def addAtStart(self,data):    
    newNode = Node(data);
    
        
    if self.head.data is None:
        
      #If list is empty, both head and tail would point to new node.    
      self.head = newNode;    
      self.tail = newNode;    
      newNode.next = self.head;    
    else:    
           
        temp = self.head;    
          
        newNode.next = temp;    
        
        self.head = newNode;    
            
        self.tail.next = self.head;    
     
  #Displays all the nodes in the list    
  def display(self):    
    current = self.head;    
    if self.head is None:    
      print("List is empty");    
      return;    
    else:    
        print("Adding nodes to the start of the list: ");
        
        #Prints each node by incrementing pointer.    
        print(current.data),    
        while(current.next != self.head):    
            current = current.next;    
            print(current.data),    
        print("\n");    
     
class CircularLinkedList:    
  cl = CreateList();    
      
  #Adding 10 to the list    
  cl.addAtStart(10);    
  cl.display();    
  #Adding 20 to the list    
  cl.addAtStart(20);    
  cl.display();    
  #Adding 30 to the list    
  cl.addAtStart(30);    
  cl.display();    
  #Adding 40 to the list    
  cl.addAtStart(40);    
  cl.display(); 
