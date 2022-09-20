class Dog: # A simple attempt to model a dog.
    def __init__(self, name, age):#Initialize name and age attributes
        self.name = name
        self.age = age
        self.friends = set()
    def play_dead(self):#Simulate playing dead
        print(f"{self.name} is playing dead, take a picture!")
    def get_name(self):
        return self.name
    def bark(self, other_dog):
        if other_dog.name not in self.friends:
            print("{}: vov vov to {}".format(self.name,other_dog.name))
            other_dog.bark_back(self)
    def bark_back(self, other_dog):
        if other_dog.name not in self.friends:
            self.friends.add(other_dog.name)
            print("{}: vov vov, {} is now my friend".format(self.name, other_dog.name))
            other_dog.bark_back(self)
            




if __name__=="__main__":

    my_dog = Dog("Scoobert", 8) # Create old Scoobert of age 8
    a = my_dog.get_name()
    print(f"My dog’s name is {a}.")
    print(f"My dog’s age is {my_dog.age} years.")
    my_dog.play_dead()

    your_dog = Dog("Miles", 3) 
    b = your_dog.get_name()
    print(f"Your dog’s name is {b}.")
    print(f"Your dog’s age is {your_dog.age} years.")
    your_dog.play_dead()

    ###### Dog pack
    print("\n%%%%%%  Dog pack %%%%%%")
    my_dog.bark(your_dog)