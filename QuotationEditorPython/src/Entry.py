import math

class Entry:
    def __init__(self, ao, pName, modelName, pDimensionsX, pDimensionsY, pDimensionsZ, approveNum, quant, price, MH, D):
        self.addOn = ao
        self.productName = pName
        self.modelName = modelName
        self.dimensionX = pDimensionsX
        self.dimensionY = pDimensionsY
        self.dimensionZ = pDimensionsZ
        self.approveNumber = approveNum
        self.quantity = quant
        self.price = price
        self.MJHR = math.floor(MH * 100) / 100;
        self.discount = D

