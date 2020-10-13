// Concept of Composition in JAVA
// author - rudrajit1729

import java.io.*;
import java.util.*;

// Class for Recipe
class Recipe{
	String dish; int amt;
	Recipe(String dish, int amt){
		this.dish = dish;
		this.amt = amt;
	}
}

// Class for restaurant
class Restaurant{

	// List of recipes
	private final List<Recipe> recipes;

	Restaurant(List<Recipe> recipes){
		this.recipes = recipes;
	}

	public List<Recipe> getAllRecipes(){
		return recipes;
	}
}

class p1_composition{
	public static void main(String args[])throws IOException{
		Recipe r1 = new Recipe("Paparoni Pizza", 200);
		Recipe r2 = new Recipe("Italian Pasta", 190);
		Recipe r3 = new Recipe("Sz. Noodles", 240);

		// Composition - Recipe is a class and is composed when 
		// Restaurant class uses Recipe type list

		List<Recipe> recipes = new ArrayList<Recipe>();
		recipes.add(r1);
		recipes.add(r2);
		recipes.add(r3);

		Restaurant res = new Restaurant(recipes);

		List<Recipe> rec = res.getAllRecipes();
		for(Recipe r: rec){
			System.out.println("Recipe: " + r.dish + "\nPrice(Rs): " + r.amt);
		}
	}
}
