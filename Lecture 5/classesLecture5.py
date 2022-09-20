import time

def timer(method):
    def wrapper(*args, **kwargs):
        start_time = time.perf_counter()
        value = method(*args, **kwargs)
        end_time = time.perf_counter()
        exec_time = end_time - start_time
        print("Execution time of method {} is {}".format(method.__name__,exec_time))
        return value
    return wrapper  

class Human:
    def __init__(self, name, lastname, age, address, cpr_no = 123456-7891):
        self.name = name
        self.lastname = lastname
        self.age = age
        self._address = address 
        self.__cpr = cpr_no
        
    def __repr__(self):
        return "Name: {} {}\nAge: {} years\nAddress: {}\nCPR no.: {}".format(
        self.name,
        self.lastname,
        self.age,
        self._address,
        self.__cpr)

class Student(Human):
    def __init__(self, name, lastname, age, address, cpr_no = 0):
        super().__init__(name, lastname, age, address, cpr_no)
        self.semester = []
        self.email = "{}{}@student.aau.dk".format(name[0],lastname[0:2])
        self.courses = []
        
    def __repr__(self):
        return "Name: {} {}\nAge: {} years\nAddress: {}\nCPR no.: {} Semester: {} Email: {}".format(
        self.name,
        self.lastname,
        self.age,
        self._address,
        self.__cpr,
        self.semester,
        self.email)
        
    def enrol_in_semester(self,semester):
        self.semester = semester
    def get_semester(self):
        return self.semester
    def get_email(self):
        return self.email
    def enrol_in_group(self,group):
        group.enrol_student(self)
    

class StudentGroup():
    def __init__(self, education, semester, number = 156):
        self.education = education
        self.group_id = f"{education}-{semester}-{number}"
        self.students_in_group = []
    def __repr__(self):
        if self.students_in_group==[]:
            return "Group ID: {} is empty".format(self.group_id)
        else:
            return "The students in Group ID: {} are\n {}".format(
            self.group_id, 
            self.students_in_group)
    def enrol_student(self,self_proclaimed_student):
        if isinstance(self_proclaimed_student,Student) and self_proclaimed_student.semester[:-1]==self.education:
            self.students_in_group.append(self_proclaimed_student)


class StudentList(list):
    def search(self, name):
        matching_students = []
        for student in self:
            if name in student.name:
                matching_students.append(student)
        return matching_students


class Colors(list):    
    def __iter__(self):
        return Iterator(self)

class Iterator(object):
    def __init__(self, collection):
        self.collection = collection
        self.i = -1
    def __next__(self):
        self.i+=1
        if self.i>len(self.collection):
            raise StopIteration
        return self.collection[self.i]
    def __iter__(self):
        return self       
     




if __name__=="__main__":
    human = Human("John", "Doe", 19, "211 Baker Street")
    print(human)    

    student =Student("John", "Doe", 19, "211 Baker Street")
    print(student)
    print(student.get_email())
    student.enrol_in_semester("COMTEK5")
    student.get_semester()

    print(dir(human))
    group = StudentGroup("COMTEK",5)
    print(group)
    student.enrol_in_group(group)

    print(group)
    other_student = Student("Roger", "Waters", 21, "Boulevarden 1")

    st_list = StudentList([student, other_student])

    print(st_list.search("Roger"))

    colorlist = Colors(["blue", "white", "black"])
    it = iter(colorlist)
    print(next(it))
    print(next(it))
    

