import numpy as np

class Dice:
    def __init__(self, sides=6):
        self.sides = sides
        self.value = np.random.randint(1,self.sides)

    def roll(self):
        self.value = np.random.randint(1,self.sides)

    def get_value(self):
        return self.value

    def __repr__(self):
        return "This is a {}-sided dice. The last throw gave a {}\n".format(
        self.sides,
        self.value)


class Dice_Collection:
    def __init__(self):
        self.dice = []

    def add_dice(self, dice):
        self.dice.append(dice)

    def throw(self):
        for i in self.dice:
            i.roll()

    def __repr__(self):
        values = []
        for i in self.dice:
            values.append(i.get_value())
        return f"The dice collection contains {len(self.dice)} dice. The Values of the dice are: {values}"


if __name__=="__main__":
    n_sides = 6
    dice1 = Dice(n_sides)
    dice2 = Dice(n_sides)
    dice = Dice_Collection()
    dice.add_dice(dice1)
    dice.add_dice(dice2)
    dice.throw()
    print(dice)
