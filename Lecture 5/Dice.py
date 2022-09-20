import numpy as np

class Dice:
    def __init__(self, sides):
        self.sides = sides
        self.value = np.random.randint(1,self.sides)

    def roll(self):
        self.value = np.random.randint(1,self.sides)

    def __repr__(self):
        return "This is a {}-sided dice. The last throw gave a {}\n".format(
        self.sides,
        self.value)

if __name__=="__main__":
    n_sides = 6
    dice = Dice(n_sides)
    dice.roll()
    print(dice)