class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        
        def play_dead(self):
            print(f"{self.name} is playing dead, take a picture!")
            
test_dog = Dog("Simon", 22)
my_dog = Dog("Scoobert", 8)

print(f"{test_dog.name} is {test_dog.age} yrs old")
print(f"{my_dog.name} is {my_dog.age} yrs old")
#print(dir(test_dog))
#print(dir(my_dog))
#print(test_dog)
#print(my_dog)