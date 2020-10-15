require 'yaml'
require 'set'
require_relative 'meta.rb'

puts "Welcome to the ultimate Hangman!"
save_location = "saves/savedata.yml"
game_obj = nil
if File.exists?(save_location)
	loop do
		puts "Load your last save(0) or start a new game(1)?"
		choice = gets.chomp
		if choice == "0"			
			game_obj = YAML.parse_file(save_location).to_ruby			
			break
		elsif choice == "1"
			game_obj = Game.new
			break
		else
			puts "Please enter a valid choice!"
		end
	end
else
	puts "No save found, starting a new game..."	
	game_obj = Game.new
end

game_obj.play
