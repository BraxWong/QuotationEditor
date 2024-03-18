import xlsxwriter

class XlsxWriter:
    def __init__(self, entry, orderDetails) -> None:
        self.entry = entry
        self.orderDetails = orderDetails

    def writeToXlsx(self):
        workbook = xlsxwriter.Workbook(self.orderDetails.fileName)
        worksheet = workbook.add_worksheet()
        worksheet.write('A1', 'hello World')
        workbook.close()
