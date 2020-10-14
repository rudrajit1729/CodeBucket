require 'set'
require 'yaml'

class Game
	attr_reader :n_guesses, :guessed_chars, :revealed_word	

	def initialize
		File.open("data/dict.txt", "r") do |dict|
			text = dict.read.split
			@word = text[Random.rand(text.size - 1)] # get a random word
			@word.upcase!			
		end
		Dir.mkdir("saves") unless Dir.exists?("saves")
		@n_guesses = 6
		@guessed_chars = Set.new
		@revealed_word = "_" * @word.length 
		@won = false
		@game_over = false		
	end

	def draw_hangman
		hang = File.open("data/hang#{@n_guesses}.txt", "r")
		puts hang.read
	end

	def cleanup_saves
		File.delete("saves/savedata.yml") if File.exists?("saves/savedata.yml")
	end			

	def already_guessed?(ch)
		return @guessed_chars.include?(ch)
	end

	def show_progress
		puts ""
		puts @revealed_word.chars.join(" ")
	end

	def reveal_char(index_list, ch) #take in character and indices where it occurs, then reveal those
		index_list.each do |i|			
			@revealed_word[i] = ch
		end
		show_progress
	end

	def eval_guess(ch)
		index_list = []
		@word.each_char.with_index do |w_ch, ind|
			index_list << ind if w_ch == ch
			@guessed_chars.add(ch)
		end
		if index_list.length != 0 # guessed character present in word
			# modify state of guessed word and display
			reveal_char(index_list, ch)
			if @revealed_word == @word
				@game_over = true
				@won = true
			end
		else
			# display number of guesses left & warning
			@n_guesses -= 1			
			draw_hangman
			if @n_guesses == 0 # run out of guesses
				@game_over = true
			else				
				show_progress
			end
		end
	end

	def parse_input(str)
		str.upcase!
		if str == "QUIT"
			puts "\nQuitting..."
			exit
		elsif str == "SAVE"
			# save
			File.open("saves/savedata.yml", "w") do |file|
				yml_content = YAML.dump(self)
				file.puts(yml_content)
			end
			puts "\nProgress saved!"			
		elsif str.length != 1
			puts "\nGuess must be a single letter or a valid command!"			
		else
			unless already_guessed?(str)
				eval_guess(str)				
			else
				puts "\nYou already guessed this letter! Try another one."								
			end
		end		
	end

	def play
		puts "\nYou are now playing Hangman!"
		draw_hangman		
		show_progress
		
		puts "\nEnter a letter to guess, otherwise enter SAVE or QUIT."
		until @game_over						
			puts "\nEnter your guess or a command:"
			cmd = gets.chomp
			#byebug
			parse_input(cmd)			
		end

		if @won
			puts "\nYou won!"
			cleanup_saves
		else
			puts "\nYou lost! The word was #{@word}!"
			cleanup_saves
		end
	end
end

