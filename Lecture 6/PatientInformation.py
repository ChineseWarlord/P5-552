class Admin:
    def __init__(self, ID, Password, AccessLevel):
        self.ID = ID
        self.Password = Password
        self.AccessLevel = AccessLevel
        
    def __repr__(self):
        return "ID: {} \nPassword: {} \nAccess Level: {}".format(
        self.ID,
        self.Password,
        self.AccessLevel)
        
    def GeneratePatient(self, PatientName, PatientLastName, PatientAge, PatientGender, PatientAddr, PatientCPR, Medical_Record, Financial_Record):
        self.PatientName = PatientName
        self.PatientLastName = PatientLastName
        self.PatientAge = PatientAge
        self.PatientGender = PatientGender
        self._PatientAddr = PatientAddr
        self.__PatientCPR = PatientCPR
        self.__MedicalRecord = Medical_Record
        self.__FinancialRecord = Financial_Record
        
    def ViewFinancialRecord(self):
        return Patient.FinancialRecord

class Patient:
    def __init__(self, PatientName, PatientLastName, PatientAge, PatientGender, PatientAddr, PatientCPR, MedicalRecord, FinancialRecord):
        self.PatientName = PatientName
        self.PatientLastName = PatientLastName
        self.PatientAge = PatientAge
        self.PatientGender = PatientGender
        self._PatientAddr = PatientAddr
        self.__PatientCPR = PatientCPR
        self.__MedicalRecord = MedicalRecord
        self.__FinancialRecord = FinancialRecord
        
    def __repr__(self):
        return "\nPatient Name: {} \nPatient Last Name: {} \nPatient Age: {} years \nPatient Gender: {}\nPatient Address: {}\nPatient CPR no.: {}".format(
        self.PatientName,
        self.PatientLastName,
        self.PatientAge,
        self.PatientGender,
        self._PatientAddr,
        self.__PatientCPR)
        

class MedicalRecord:
    Prescriptions = []
    Notes = []

    def add_Prescription(self, prescription):
        self.Prescriptions.append(prescription)

    def get_Pre(self):
        return self.Prescriptions
    
    def add_Notes(self, Notes):
        self.Notes.append(Notes)
        
    def get_Notes(self):
        return self.Notes
    
class FinancialRecord:
    
    def CardInfo(self, CardNo):
        self.CardNo = "4571 9999 9999 9999"
        
    def get_CardInfo(self):
        return self.CardInfo
        
    def Balance(self,Balance):
        self.Balance = 99999999   
    
    def get_Bal(self):
        return self.Balance

if __name__=="__main__":
    admin = Admin("Ben", "Dover", 9001)
    print(admin)
    
    admin.GeneratePatient("lol", "PatientLastName", 99, "PatientGender", "PatientAddr", "PatientCPR", MedicalRecord, FinancialRecord)
    
    patient1 = Patient("lol", "PatientLastName", 99, "PatientGender", "PatientAddr", "PatientCPR", MedicalRecord, FinancialRecord)
    print(patient1)
    
       
    
     