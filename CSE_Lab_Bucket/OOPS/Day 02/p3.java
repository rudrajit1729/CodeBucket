// Memory management using static variable in JAVA
// author - rudrajit1729
 
public class p3{ 
  
  static int cnt = 0; // Gets memory only once and retains its value. 
  
  p3(){ 
     cnt++; // Increment the static variable by 1 for each object creation. 
  } 

  void display(){ 
     System.out.println("No. of objects: " + cnt); 
  } 

  public static void main(String[] args) 
  { 
      // Memory efficient - static variable doesnt create copy for each object
      // Can be used to manage class state and consistency between objects due to its 1 src nature.
      p3 obj1 = new p3(); 
      obj1.display(); 
      p3 obj2 = new p3(); 
      obj2.display(); 
      p3 obj3 = new p3(); 
      obj3.display(); 
    } 
}
