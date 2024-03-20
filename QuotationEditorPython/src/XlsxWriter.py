import xlsxwriter
from datetime import date

class XlsxWriter:
    def __init__(self, entry, orderDetails) -> None:
        self.entry = entry
        self.orderDetails = orderDetails

    def writeToXlsx(self):
        workbook = xlsxwriter.Workbook(self.orderDetails.fileName)
        worksheet = workbook.add_worksheet()
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
        worksheet.set_column('B:B', 38)
        worksheet.set_column('C:C', 4)
        worksheet.set_column('E:E', 12)
        worksheet.set_row(0, 30)
        worksheet.merge_range('A1:F1', '中天廚房設備有限公司', merge_format)
        worksheet.merge_range('A2:F2', 'CHUNG TIN KITCHEN WARES COMPANY LIMITED', merge_format2)
        worksheet.merge_range('A3:F3', '香港九龍馬頭角道105號地下', merge_format3)
        worksheet.merge_range('A4:F4', 'G/F., 105 Ma Tau Kok Road, Kowloon, Hong Kong', merge_format3)
        worksheet.merge_range('A5:F5', '電話: (852) 2363 1482  傳真: (852) 2766 1415', merge_format3)
        worksheet.merge_range('A6:F6', '機電處註冊氣體工程承辦商號碼 RGC NO.-(682-06)', merge_format3)
        worksheet.merge_range('A7:F7', '', url_format)
        worksheet.write_url('A7', 'chungtinkitchen@netvigator.com', url_format, 'E-mail: chungtinkitchen@netvigator.com')
        worksheet.merge_range('A8:F8', '報價單', merge_format4)
        worksheet.write_string(9, 0,'客戶名稱:', merge_format5)
        worksheet.write_string(9, 4, '報價單號碼： ', merge_format5)
        worksheet.write_string(9, 5, self.orderDetails.quotationID, merge_format5)
        worksheet.write_string(10, 0, '客戶地址:', merge_format5)
        worksheet.write_string(10, 4, 'Staff: ', merge_format5)
        worksheet.write_string(10, 5, self.orderDetails.staffName, merge_format5)
        worksheet.write_string(11, 0, '負責人:', merge_format5)
        worksheet.write_string(11, 4, '日期：', merge_format5)
        worksheet.write_string(11, 5, str(date.today()), merge_format5)
        workbook.close()

    def createFormat(self, workbook: xlsxwriter.Workbook, font_size, font_name, bold):
        
        merge_format = workbook.add_format({'align': 'center',
                                            'bold': bold,
                                          })
        merge_format.set_align('vcenter')
        merge_format.set_font_size(font_size)
        merge_format.set_font_name(font_name)
        return merge_format
        
