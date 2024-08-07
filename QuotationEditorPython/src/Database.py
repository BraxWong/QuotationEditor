import json
import Entry
import OrderDetails

class Database:

    def __init__(self):
        self.productDatabasePath = 'Database/database.json'
        self.customerDatabasePath = 'Database/customer.json'

    """
    Product Database Section
    """

    """
    @Function: updateItemInDatabase()
    @Param: Entry entry 
    @Description: If the entry's product name was found within the database itself, 
                  The data regarding that product will be updated within the database.
                  If not, do nothing.
    """

    def updateItemInDatabase(self, entry):
        with open(self.productDatabasePath, "r", encoding='utf-8') as file:
            file_data = json.load(file)
            for item in file_data["items"]:
                if item["product name"] == entry.productName:
                    item["price per unit"] = entry.price
                    item["MJ/HR"] = float(entry.MJHR)
                    item["model"] = entry.modelName
                    item["approval number"] = entry.approveNumber
                    item["dimension x"] = entry.dimensionX
                    item["dimension y"] = entry.dimensionY
                    item["dimension z"] = entry.dimensionZ
        
        with open(self.productDatabasePath, 'w', encoding='utf-8') as file:
                json.dump(file_data, file, indent = 2, ensure_ascii=False)
    

    def checkItemInDatabase(self, entry):
        with open(self.productDatabasePath, "r", encoding='utf-8') as file:
            file_data = json.load(file)
            for item in file_data["items"]:
                if item["product name"] == entry.productName:
                    return True
        return False
    

    def addItemToDatabase(self, entry):
        with open(self.productDatabasePath, 'r+', encoding='utf-8') as file:
            file_data = json.load(file)
            file_data["items"].append({"product name": entry.productName , 
                                    "price per unit": entry.price, 
                                    "MJ/HR": float(entry.MJHR), 
                                    "model": entry.modelName, 
                                    "approval number": entry.approveNumber,
                                    "dimension x": entry.dimensionX,
                                    "dimension y": entry.dimensionY,
                                    "dimension z": entry.dimensionZ})
            file.seek(0)
            json.dump(file_data, file, indent = 2, ensure_ascii=False)   


    def getEntryByProductName(self, productName):     
        with open(self.productDatabasePath, "+r", encoding="utf-8") as file:
            file_data = json.load(file)
            for item in file_data["items"]:
                if productName == item["product name"]:
                    entry = Entry.Entry(None, "", item["model"], item["dimension x"],
                                        item["dimension y"], item["dimension z"],
                                        item["approval number"], None, item["price per unit"],
                                        item["MJ/HR"], False, False, False)
                    file.seek(0)
                    return entry
        return None
    

    """
    Customer Database Section
    """
        
    def customerInDatabase(self, customer):
        with open(self.customerDatabasePath, "r", encoding='utf-8') as file:
            file_data = json.load(file)
            for entry in file_data["customers"]:
                if entry["customer name"] == customer.customerName:
                    return True
        return False

    
    def addCustomerToDatabase(self, customer):
        with open(self.customerDatabasePath, "r+", encoding='utf-8') as file:
            file_data = json.load(file)
            file_data["customers"].append({"customer name": customer.customerName,
                                           "address": customer.customerAddr,
                                           "supervisor": customer.supervisor,
                                           "telephone number": customer.customerTel,
                                           "customer id": customer.customerID})
            file.seek(0)
            json.dump(file_data, file, indent=2, ensure_ascii=False)
    

    def updateCustomerInDatabase(self, customer):
        with open(self.customerDatabasePath, "r", encoding='utf-8') as file:
            file_data = json.load(file)
            for item in file_data["customers"]:
                if item["customer name"] == customer.customerName:
                    item["address"] = customer.customerAddr
                    item["supervisor"] = customer.supervisor
                    item["telephone number"] = customer.customerTel
                    item["customer id"] = customer.customerID
        
        with open(self.customerDatabasePath, 'w', encoding='utf-8') as file:
                json.dump(file_data, file, indent = 2, ensure_ascii=False)

    def getCustomerByCustomerName(self, customerName):     
        with open(self.customerDatabasePath, "+r", encoding="utf-8") as file:
            file_data = json.load(file)
            for entry in file_data["customers"]:
                if customerName == entry["customer name"]:
                    customer = OrderDetails.OrderDetails(entry["customer name"], entry["address"],
                                                         entry["supervisor"], None,
                                                         None, None,
                                                         entry["telephone number"], entry["customer id"]
                    )
                    file.seek(0)
                    return customer
        return None

