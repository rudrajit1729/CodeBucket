card_on_table = input()
card_hand = input().split()
rank = card_on_table[0]
suit = card_on_table[1]
def solve():
	for card in card_hand:
		if card[0] == rank or card[1] == suit:
			print("YES")
			return 
	print("NO")

solve()


