import tkinter as tk
from tkinter import messagebox

class QuizGame:
    def __init__(self, master):
        self.master = master
        self.master.title("Quiz Game")
        self.score = 0
        self.question_index = 0
        self.questions = [
            {
                "question": "What is the capital of France?",
                "options": ["Berlin", "Madrid", "Paris", "Lisbon"],
                "answer": "Paris"
            },
            {
                "question": "What is the largest ocean on Earth?",
                "options": ["Indian Ocean", "Atlantic Ocean", "Arctic Ocean", "Pacific Ocean"],
                "answer": "Pacific Ocean"
            },
            {
                "question": "Which planet is known as the Red Planet?",
                "options": ["Earth", "Mars", "Jupiter", "Saturn"],
                "answer": "Mars"
            },
            {
                "question": "What is the chemical symbol for water?",
                "options": ["O2", "H2O", "CO2", "H2"],
                "answer": "H2O"
            },
            {
                "question": "Who wrote 'To Kill a Mockingbird'?",
                "options": ["Harper Lee", "Mark Twain", "F. Scott Fitzgerald", "Ernest Hemingway"],
                "answer": "Harper Lee"
            }
        ]

        self.question_label = tk.Label(self.master, text="", wraplength=300)
        self.question_label.pack(pady=20)

        self.var = tk.StringVar()
        self.option_buttons = []

        for i in range(4):
            button = tk.Radiobutton(self.master, text="", variable=self.var, value="", wraplength=250)
            button.pack(anchor='w')
            self.option_buttons.append(button)

        self.submit_button = tk.Button(self.master, text="Submit", command=self.submit_answer)
        self.submit_button.pack(pady=20)

        self.load_question()

    def load_question(self):
        if self.question_index < len(self.questions):
            question_data = self.questions[self.question_index]
            self.question_label.config(text=question_data["question"])

            for i, option in enumerate(question_data["options"]):
                self.option_buttons[i].config(text=option, value=option)

            self.var.set(None)  # Clear the previous selection
        else:
            self.show_score()

    def submit_answer(self):
        selected_answer = self.var.get()
        correct_answer = self.questions[self.question_index]["answer"]

        if selected_answer == correct_answer:
            self.score += 1

        self.question_index += 1
        self.load_question()

    def show_score(self):
        messagebox.showinfo("Quiz Complete", f"Your score: {self.score}/{len(self.questions)}")
        self.master.quit()  # Exit the application

if __name__ == "__main__":
    root = tk.Tk()
    game = QuizGame(root)
    root.mainloop()
