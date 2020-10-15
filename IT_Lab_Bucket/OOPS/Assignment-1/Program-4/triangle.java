class triangle {
        public static void main(String[] args)
        {
            double a=Double.parseDouble(args[0]); // The sides of a triangle are passed as commandline arguments.
            double b=Double.parseDouble(args[1]);
            double c=Double.parseDouble(args[2]);
            
            if ((a+b)>c&&(c+a)>b&&(b+c)>a) // To check if Triangle exists.
            {
            double s=(a+b+c)/2.0;
            double area=Math.sqrt((s-a)*(s-b)*(s-c)*s);
            System.out.print("Perimeter: "+(s*2.0)+"\nArea: "+area); // Finding area and perimeter of Triangle if it exists.
            }
            else
            {
                System.out.println("Triangle cannot be formed with given sides.");
            }
            
        }
    
}
