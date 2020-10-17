from tkinter import *
import numpy as np

# Variables used in the game

size= 500
dots = 5
symbol_size = (size/ 3 - size/ 8) / 2
symbol_thickness = 40
dot_color = 'green2'
P1_col = 'RoyalBlue3'
P1_col_light = 'RoyalBlue2'
P2_col = 'DeepPink3'
P2_col_light = 'DeepPink2'
Green_col = 'green2'
dot_width = 0.25*size/dots
edge_width = 0.1*size/dots
dist = size/ (dots)

class Dots_and_Boxes():
    def __init__(self):
        self.window = Tk()
        self.window.title('Dots and Boxes')
        self.canvas = Canvas(self.window, width=size, height=size)
        self.canvas.pack()
        self.window.bind('<Button-1>', self.click)
        self.player1_starts = True
        self.refresh_board()
        self.play_again()

    def play_again(self):
        self.refresh_board()
        self.board_status = np.zeros(shape=(dots - 1, dots - 1))
        self.row_status = np.zeros(shape=(dots, dots - 1))
        self.col_status = np.zeros(shape=(dots - 1, dots))
        
        self.player1_starts = not self.player1_starts
        self.player1_turn = not self.player1_starts
        self.reset_board = False
        self.turntext_handle = []

        self.already_marked_boxes = []
        self.display_turn_text()

    def mainloop(self):
        self.window.mainloop()

    # Modules that execute the game logic

    def click(self, event):
        if (not self.reset_board):
            grid_position = [event.x, event.y]
            logical_position, valid_input = self.convert_grid_to_logical_position(grid_position)
            if (valid_input) and (not self.is_grid_occupied(logical_position, valid_input)):
                self.update_board(valid_input, logical_position)
                self.make_edge(valid_input, logical_position)
                self.mark_box()
                self.refresh_board()
                self.player1_turn = not self.player1_turn

                if (self.is_gameover()):
                    self.display_gameover()
                else:
                    self.display_turn_text()
        else:
            self.canvas.delete("all")
            self.play_again()
            self.reset_board = False

    def mark_box(self):
        boxes = np.argwhere(self.board_status == -4)

        for box in boxes:
            if (list(box) not in self.already_marked_boxes) and (list(box) !=[]):
                self.already_marked_boxes.append(list(box))
                color = P1_col_light
                self.shade_box(box, color)

        boxes = np.argwhere(self.board_status == 4)

        for box in boxes:
            if (list(box) not in self.already_marked_boxes) and (list(box) !=[]):
                self.already_marked_boxes.append(list(box))
                color = P2_col_light
                self.shade_box(box, color)            

    def is_grid_occupied(self, logical_position, type):
        r = logical_position[0]
        c = logical_position[1]
        occupied = True

        if (type == 'row') and (self.row_status[c][r] == 0):
            occupied = False

        if (type == 'col') and (self.col_status[c][r] == 0):
            occupied = False

        return occupied

    def convert_grid_to_logical_position(self, grid_position):
        grid_position = np.array(grid_position)
        pos = (grid_position-dist/4)//(dist/2)
        
        type = False
        logical_position = []
        if (pos[1] % 2 == 0) and ((pos[0] - 1) % 2 == 0):
            r = int((pos[0]-1)//2)
            c = int(pos[1]//2)
            logical_position = [r, c]
            type = 'row'
            
        elif (pos[0] % 2 == 0) and ((pos[1] - 1) % 2 == 0):
            r = int(pos[0] // 2)
            c = int((pos[1] - 1) // 2)
            logical_position = [r, c]
            type = 'col'
            
        return logical_position, type

    def update_board(self, type, logical_position):
        r = logical_position[0]
        c = logical_position[1]
        val = 1

        if self.player1_turn:
            val =- 1

        if c < (dots-1) and r < (dots-1):
            self.board_status[c][r] += val

        if type == 'row':
            self.row_status[c][r] = 1
            if c >= 1:
                self.board_status[c-1][r] += val

        elif type == 'col':
            self.col_status[c][r] = 1
            if r >= 1:
                self.board_status[c][r-1] += val

    def is_gameover(self):
        return (self.row_status == 1).all() and (self.col_status == 1).all()

    # Modules to draw edges and boxes on the canvas

    def make_edge(self, type, logical_position):

        if (type == 'row'):
            start_x = dist/2 + logical_position[0]*dist
            end_x = start_x+dist
            start_y = dist/2 + logical_position[1]*dist
            end_y = start_y
        elif type == 'col':
            start_y = dist / 2 + logical_position[1]*dist
            end_y = start_y + dist
            start_x = dist / 2 + logical_position[0]*dist
            end_x = start_x

        if (self.player1_turn):
            color = P1_col
        else:
            color = P2_col

        self.canvas.create_line(start_x, start_y, end_x, end_y, fill=color, width=edge_width)

    def display_gameover(self):
        P1 = len(np.argwhere(self.board_status == -4))
        P2 = len(np.argwhere(self.board_status == 4))

        if (P1 > P2):
            text = 'WINNER: Player 1 '
            color = P1_col
        elif (P2 > P1):
            text = 'WINNER: Player 2 '
            color = P2_col
        else:
            text = 'Its a tie'
            color = 'gray'

        self.canvas.delete("all")

        self.canvas.create_text(size/ 2, size/ 3, font="cmr 35 bold", fill=color, text=text)

        disp = 'SCORES \n'

        self.canvas.create_text(size/ 2, 5 * size/ 8, font="cmr 30 bold", fill=Green_col,
                                text=disp)

        disp = 'Player 1 : ' + str(P1) + '\n'

        disp += 'Player 2 : ' + str(P2) + '\n'

        self.canvas.create_text(size/ 2, 3 * size/ 4, font="cmr 25 bold", fill=Green_col,
                                text=disp)

        self.reset_board = True

        disp = 'Play again \n'
        self.canvas.create_text(size/ 2, 15 * size/ 16, font="cmr 30 bold", fill="gray",
                                text=disp)

    def refresh_board(self):
        for i in range(dots):
            x = i*dist+dist/2
            self.canvas.create_line(x, dist/2, x,
                                    size-dist/2,
                                    fill='gray', dash = (2, 2))
            self.canvas.create_line(dist/2, x,
                                    size-dist/2, x,
                                    fill='gray', dash=(2, 2))

        for i in range(dots):
            for j in range(dots):
                start_x = i*dist+dist/2
                end_x = j*dist+dist/2
                self.canvas.create_oval(start_x-dot_width/2, end_x-dot_width/2, start_x+dot_width/2,
                                        end_x+dot_width/2, fill=dot_color,
                                        outline=dot_color)

    def shade_box(self, box, color):
        start_x = dist / 2 + box[1] * dist + edge_width/2
        start_y = dist / 2 + box[0] * dist + edge_width/2
        end_x = start_x + dist - edge_width
        end_y = start_y + dist - edge_width
        self.canvas.create_rectangle(start_x, start_y, end_x, end_y, fill=color, outline='')

    def display_turn_text(self):
        if (self.player1_turn):
            text = 'Player 1'
            color = P1_col
        else:
            text = 'Player 2'
            color = P2_col
        text += '’s turn : Click on an edge'

        self.canvas.delete(self.turntext_handle)
        self.turntext_handle = self.canvas.create_text(size- 5*len(text),
                                                       size-dist/8,
                                                       font="cmr 15 bold", text=text, fill=color)
        
game_instance = Dots_and_Boxes()
game_instance.mainloop()
