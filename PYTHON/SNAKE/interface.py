from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import re  # Importujemy moduł re do wyrażeń regularnych

difficulty_level = None  # Zmienna globalna do przechowywania poziomu trudności

class SnakeLogin:
    def __init__(self, master):
        self.master = master
        master.title('Login')
        master.geometry('250x210')
        self.create_widgets()

    def create_widgets(self):
        # Pole do nazwy
        self.nick_text = ttk.Label(self.master, text='Nick: ')
        self.nick_text.pack()
        self.nick = Entry(self.master, justify='center')
        self.nick.pack()

        # Pole do maila
        self.mail_text = ttk.Label(self.master, text='E-Mail: ')
        self.mail_text.pack()
        self.mail = Entry(self.master, justify='center')
        self.mail.pack()

        # Pole do poziomu trudności
        self.difficulty_label = ttk.Label(self.master, text='Difficulty: ')
        self.difficulty_label.pack()
        self.difficulty_text = StringVar(self.master)
        self.difficulty_text.set("Choose difficulty")
        levels = ["Easy", "Normal", "Hard"]
        self.difficulty = ttk.OptionMenu(self.master, self.difficulty_text, *levels)
        self.difficulty.pack()

        # Przycisk zatwierdzający
        self.button = Button(self.master, text='Submit', width=10, height=2, bg='white', fg='black', command=self.save_to_file)
        self.button.pack()

        # Funkcja wywoływana podczas zamykania okna
        self.master.protocol("WM_DELETE_WINDOW", self.on_closing)

    def is_valid_email(self, email):
        # Sprawdza, czy adres e-mail kończy się na @gmail.com
        pattern = r'^[a-zA-Z0-9._%+-]+@gmail\.com$'
        return re.match(pattern, email) is not None

    # Funkcja zapisująca dane do pliku i zamykająca okno
    def save_to_file(self):
        global difficulty_level
        nick_value = self.nick.get()
        mail_value = self.mail.get()
        difficulty_value = self.difficulty_text.get()

        if nick_value and mail_value and difficulty_value != "Choose difficulty":
            if self.is_valid_email(mail_value):
                with open('login.txt', 'a') as file:
                    file.write(f"Nick: {nick_value}, E-Mail: {mail_value}, Poziom Trudnosci: {difficulty_value}, ")
                    messagebox.showinfo("Saved Successfully", "Saved Successfully")
                difficulty_level = difficulty_value  # Ustaw poziom trudności
                # Zamknij okno po zapisaniu danych i uruchom grę
                self.master.destroy()
                self.start_game()
            else:
                messagebox.showwarning("Warning", "Invalid email address. Please use a valid @gmail.com address.")
        else:
            messagebox.showwarning("Warning", "Please fill in all fields")

    # Funkcja wywoływana podczas zamykania okna
    def on_closing(self):
        self.master.destroy()

    # Funkcja uruchamiająca grę
    def start_game(self):
        import main
        main.start_game()

def main():
    root = Tk()
    app = SnakeLogin(root)
    root.mainloop()

if __name__ == "__main__":
    main()
