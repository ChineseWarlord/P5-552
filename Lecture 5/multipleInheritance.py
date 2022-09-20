class BaseClass:
    num_base_calls = 0
    def call_me(self):
        print("Method on Base Class called")
        self.num_base_calls += 1
        print("Method on Base Class finished")
    def method(self):
        print("Method on Base Class implemented")

class LeftSubclass(BaseClass):
    num_left_calls = 0
    def call_me(self):
        print("Method on Left Subclass called")
        super().call_me()
        self.num_left_calls += 1
        print("Method on Left Subclass finished")
    def method(self):
        print("Method on Left Subclass implemented")

class RightSubclass(BaseClass):
    num_right_calls = 0
    def call_me(self):
        print("Method on Right Subclass called")
        super().call_me()
        self.num_right_calls += 1
        print("Method on Right Subclass finished")
    def method(self):
        print("Method on Right Subclass implemented")

class SubClass(LeftSubclass, RightSubclass):
    num_sub_calls = 0
    def call_me(self):
        print("Method on Subclass called")
        super().call_me()
        self.num_sub_calls += 1
        print("Method on Subclass finished")

if __name__=="__main__":
    s = SubClass()
    s.call_me()
    print("\n%%%%%%%%%%\n")
    s.method()
