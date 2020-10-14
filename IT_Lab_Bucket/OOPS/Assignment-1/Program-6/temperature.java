class temperature {
    public static void main(String[] args)
    {
        double far=Double.parseDouble(args[0]); // Temperature in degree F is taken as input

        double celc=5.0*(far-32.0)/9.0;
        System.out.println("Temp in degree C "+celc); //Coverted temperature in Celcius is printed
    }
}
