import xlsxwriter
from datetime import date

class XlsxWriter:
    def __init__(self, entry, orderDetails) -> None:
        self.entry = entry
        self.orderDetails = orderDetails
        self.total = 0
        self.totalDiscount = 0
        self.totalMJHR = 0
        self.row = 0
        self.itemCount = 1 

    def writeToXlsx(self):
        workbook = xlsxwriter.Workbook(self.orderDetails.fileName)
        worksheet = workbook.add_worksheet()
        worksheet.set_paper(9)
        merge_format = self.createFormat(workbook, 22, '標楷體', True)
        merge_format2 = self.createFormat(workbook, 14, 'Times New Roman', True) 
        merge_format3 = self.createFormat(workbook, 12, '標楷體', False)
        url_format = workbook.add_format({'font_color': 'blue',
                                          'underline': True,
                                          'align': 'center'
                                          })
        url_format.set_align('vcenter')
        merge_format4 = self.createFormat(workbook, 16, '新細明體', True)
        merge_format4.set_underline(True)
        merge_format5 = self.createFormat(workbook, 11, 'Calibri (Body)', False)
        merge_format5.set_align("left")
        underline_format = workbook.add_format({
        'bottom': 1,  # Set a bottom border
        'bottom_color': 'black',  # Set the bottom border color to black
        'align': 'center'
        })
        underline_format.set_bottom(2)  # Set the bottom border style to underline
        underline_format.set_align("vcenter")
        underline_format2 = workbook.add_format({
        'bottom': 1,  # Set a bottom border
        'bottom_color': 'black',  # Set the bottom border color to black
        })
        underline_format2.set_bottom(2)  # Set the bottom border style to underline
        underline_format2.set_align("left")


        worksheet.set_column('B:B', 38)
        worksheet.set_column('C:C', 4)
        worksheet.set_column('D:D', 14)
        worksheet.set_column('E:E', 14)
        worksheet.set_column('F:F', 14)
        worksheet.set_row(0, 30)
        worksheet.merge_range(self.row, 0, self.row, 6, '中天廚房設備有限公司', merge_format)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, 'CHUNG TIN KITCHEN WARES COMPANY LIMITED', merge_format2)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, '香港九龍馬頭角道105號地下', merge_format3)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, 'G/F., 105 Ma Tau Kok Road, Kowloon, Hong Kong', merge_format3)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, '電話: (852) 2363 1482  傳真: (852) 2766 1415', merge_format3)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, '機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)', merge_format3)
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, '', url_format)
        worksheet.write_url(self.row, 0, 'chungtinkitchen@netvigator.com', url_format, 'E-mail: chungtinkitchen@netvigator.com')
        self.row += 1
        worksheet.merge_range(self.row, 0, self.row, 6, '報價單', merge_format4)
        self.row += 1
        worksheet.write_string(self.row, 0,'客戶名稱:', merge_format5)
        worksheet.write_string(self.row, 1, self.orderDetails.customerName, merge_format5)
        worksheet.write_string(self.row, 4, '報價單號碼： ', merge_format5)
        worksheet.write_string(self.row, 5, self.orderDetails.quotationID, merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 0, '客戶地址:', merge_format5)
        worksheet.write_string(self.row, 1, self.orderDetails.customerAddr, merge_format5)
        worksheet.write_string(self.row, 4, 'Staff: ', merge_format5)
        worksheet.write_string(self.row, 5, self.orderDetails.staffName, merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 0, '負責人:', merge_format5)
        worksheet.write_string(self.row, 1, self.orderDetails.supervisor, merge_format5)
        worksheet.write_string(self.row, 4, '日期：', merge_format5)
        worksheet.write_string(self.row, 5, str(date.today()), merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 0, '電話 :', merge_format5)
        worksheet.write_number(self.row, 1, self.orderDetails.customerTel, merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 0, '客戶編號:', merge_format5)
        worksheet.write_string(self.row, 1, self.orderDetails.customerID, merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 0, '項目', underline_format)
        worksheet.write_string(self.row, 1, '內容', underline_format)
        worksheet.write_string(self.row, 2, '數量', underline_format)
        worksheet.write_string(self.row, 3, '單價', underline_format)
        worksheet.write_string(self.row, 4, '金額', underline_format)
        worksheet.write_string(self.row, 5, '兆焦耳(MJ/HR)', underline_format)

        self.printEntries(worksheet, workbook, self.entry)
        self.row += 2
        self.printEndOfFile(worksheet,workbook)
        workbook.close()

    def createFormat(self, workbook: xlsxwriter.Workbook, font_size, font_name, bold):
        
        merge_format = workbook.add_format({'align': 'center',
                                            'bold': bold,
                                          })
        merge_format.set_align('vcenter')
        merge_format.set_font_size(font_size)
        merge_format.set_font_name(font_name)
        return merge_format
        

    def printEntries(self,worksheet, workbook, entries):
        self.row += 2
        merge_format = self.createFormat(workbook, 12, 'Calibri (Body)', False)
        merge_format.set_align("left")
        merge_format2 = self.createFormat(workbook, 12, 'Calibri (Body)', False)
        merge_format3 = self.createFormat(workbook, 12, 'Calibri (Body)', False)
        merge_format3.set_align("right")
        currency_format = workbook.add_format({'num_format': '$#,##0.00'})
        discount_currency_format = workbook.add_format({'num_format': '-$#,##0.00'})

        for entry in entries:
            totalPrice = int(entry.price) * int(entry.quantity)
            self.total = self.total + totalPrice
            worksheet.write_number(self.row, 0, self.itemCount, merge_format2)
            worksheet.write_string(self.row, 1, entry.productName, merge_format)
            worksheet.write_number(self.row, 2, int(entry.quantity), merge_format2)
            worksheet.write_number(self.row, 3, int(entry.price), currency_format)
            worksheet.write_number(self.row, 4, totalPrice, currency_format)
            worksheet.write_string(self.row, 5, str(entry.MJHR) + "MJ/HR", merge_format3)
            self.totalMJHR = self.totalMJHR + entry.MJHR
            self.row += 1
            worksheet.write_string(self.row, 1, "型號:" + entry.modelName + ",批核編號(" + entry.approveNumber + ")", merge_format)
            self.row += 1
            worksheet.write_string(self.row, 1, entry.dimensionX + "X" + entry.dimensionY + "X" + entry.dimensionZ + "H", merge_format)
            if entry.discount:
                self.row += 1
                worksheet.write_string(self.row, 1, "香港中華煤氣有限公司(尊貴客戶)優惠", merge_format)
                worksheet.write_number(self.row , 2, int(entry.quantity), merge_format2)
                worksheet.write_number(self.row, 3, int(entry.price), discount_currency_format)
                worksheet.write_number(self.row, 4, totalPrice, discount_currency_format)
                self.totalDiscount = self.totalDiscount + totalPrice
            self.row += 2
            self.itemCount += 1

    def printEndOfFile(self, worksheet, workbook):
        currency_format = workbook.add_format({'num_format': '$#,##0.00'})
        currency_format.set_top(2)
        discount_currency_format = workbook.add_format({'num_format': '-$#,##0.00'})
        total_currency_format = self.createFormat(workbook, 14, '新細明體', True)
        total_currency_format = workbook.add_format({'num_format': '$#,##0.00'})
        total_currency_format.set_bottom(6)
        total_currency_format.set_top(2)
        merge_format = self.createFormat(workbook, 13, '新細明體', True)
        merge_format.set_align("right")
        merge_format2 = self.createFormat(workbook, 13, 'Calibri (Body)', True)
        merge_format2.set_align("left")
        merge_format3 = self.createFormat(workbook, 12, '新細明體', False)
        merge_format3.set_align("right")
        merge_format5 = self.createFormat(workbook, 12, '新細明體', True)
        merge_format5.set_align("left")
        merge_format5.set_underline(1)
        merge_format6 = self.createFormat(workbook, 12, '新細明體', False)
        merge_format6.set_align("left")
        mjhr_format = self.createFormat(workbook, 13, 'Calibri (Body)', True)
        mjhr_format.set_align("right")
        worksheet.write_string(self.row, 0, '*', merge_format)
        worksheet.write_string(self.row, 1, '以上報價不包括煤氣錶按金及街喉費用', merge_format2)
        self.row += 2
        worksheet.write_string(self.row, 3, '合共金額 : ', merge_format3)
        worksheet.write_number(self.row, 4, self.total, currency_format)
        self.row += 1
        worksheet.merge_range(self.row, 1, self.row, 3, '香港中華煤氣有限公司『尊貴客戶』優惠 - 合共金額 : ', merge_format3)
        worksheet.write_number(self.row, 4, self.totalDiscount, discount_currency_format)
        self.row += 1
        worksheet.merge_range(self.row, 2, self.row, 3, '客人應付金額 : ', merge_format)
        final = self.total - self.totalDiscount
        worksheet.write_number(self.row, 4, int(final), total_currency_format)
        self.row += 1
        worksheet.merge_range(self.row, 2, self.row, 3, '合共兆焦耳(MJ/HR):',merge_format)
        worksheet.write_string(self.row, 4, str(self.totalMJHR) + "MJ/HR", mjhr_format)
        self.row += 2
        worksheet.write_string(self.row, 0, '*備注 : ', merge_format3)
        worksheet.merge_range(self.row, 1, self.row, 4, '1)上述 (尊貴客戶) 爐具優惠以香港中華煤氣有限公司最後批核作準。', merge_format5)
        self.row += 1
        worksheet.merge_range(self.row, 1, self.row, 4, '2)上述兆焦耳(MJ/HR) 以最後現場已完成之爐具批核作準, 如超過1150MJ/HR, ', merge_format5)
        self.row += 1
        worksheet.write_string(self.row, 1, '客人需自行申報環保。', merge_format5)
        self.row += 1
        worksheet.merge_range(self.row, 1, self.row, 3, '上述所有由香港中華煤氣有限公司提供(尊貴客戶)優惠', merge_format6)
        self.row += 1
        worksheet.merge_range(self.row, 1, self.row, 3, '之爐具已包括本公司首年之免費維修保養及零件更換.', merge_format6)
        self.row += 2
        worksheet.write_string(self.row, 1, '客戶簽署及蓋印', merge_format6)
        worksheet.merge_range(self.row, 4, self.row, 5, '中天廚房設備有限公司')
        self.row += 5
        underline_format2 = workbook.add_format({
                            'bottom': 1,  # Set a bottom border
                            'bottom_color': 'black',  # Set the bottom border color to black
                            })
        underline_format2.set_bottom(2)  # Set the bottom border style to underline
        worksheet.write_string(self.row, 1, '', underline_format2)
        worksheet.merge_range(self.row, 4, self.row, 5, '', underline_format2)


