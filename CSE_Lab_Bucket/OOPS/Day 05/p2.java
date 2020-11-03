interface Enemy{
   public abstract void showHealth();
}
public class p2 implements Enemy{
   public void showHealth() {
      System.out.println("Shows Enemy Health");
   }
   public static void main(String args[]) {
      Enemy E = new Enemy();
      showHealth();
   }
}