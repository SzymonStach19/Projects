from turtle import Turtle

ALIGNMENT = 'center'
FONT = ('Arial', 24, 'normal')

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.score = 0
        self.color('white')
        self.penup()
        self.hideturtle()
        self.goto(0, 260)
        self.update()

    def update(self):
        self.clear()
        self.write(f'Score: {self.score}', align=ALIGNMENT, font=FONT)

    def game_over(self):
        self.goto(0, 0)
        self.write("GAME OVER", align=ALIGNMENT, font=FONT)
        self.save_score_to_file()

    def increase_score(self):
        self.score += 1
        self.update()

    def save_score_to_file(self):
        with open("login.txt", "a") as file:
            file.write(f"Wynik: {self.score}, ")
