import json
import Entry

class Database:

    def __init__(self):
        self.databasePath = 'database.json'

    """
    @Function: updateItemInDatabase()
    @Param: Entry entry 
    @Description: If the entry's product name was found within the database itself, 
                  The data regarding that product will be updated within the database.
                  If not, do nothing.
    """

    def updateItemInDatabase(self, entry):
        with open(self.databasePath, "r", encoding='utf-8') as file:
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
        
        with open(self.databasePath, 'w', encoding='utf-8') as file:
                json.dump(file_data, file, indent = 2, ensure_ascii=False)
    
    def checkItemInDatabase(self, entry):
        with open(self.databasePath, "r", encoding='utf-8') as file:
            file_data = json.load(file)
            for item in file_data["items"]:
                if item["product name"] == entry.productName:
                    return True
        return False
    
    def addItemToDatabase(self, entry):
        with open(self.databasePath, 'r+', encoding='utf-8') as file:
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
        with open("database.json", "+r", encoding="utf-8") as file:
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