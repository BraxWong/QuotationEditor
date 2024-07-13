"""

Change Log

* ** Version 1.0.0 (5/7/2024):
   * Added: Allow users to choose where the excel file will be saved 
   
* ** Version 1.0.1 (6/7/2024):
   * Changed: Separated database related functions from DatabaseScreen.py as it 
              allows these functions to be used globally without triggering the database screen
* ** Version 1.1.0 (7/7/2024):
   * Added: When an unregistered item has been added to the spreadsheet, it will be added to the database for 
            future usage.
* ** Version 1.2.0 (8/7/2024):
   * Added: When an unregistered customer has been added to the spreadsheet, it will be added to the database for 
            future usage.
* ** Version 1.3.0 (8/7/2024):
   * Added: Customer's detail will be automatically filled if it exists within the database when editing a spreadsheet
            
* ** Version 1.3.1 (9/7/2024):
   * Added: Implemented PopUpWindow class that can be used to display error messages
   
* ** Version 1.4.0 (11/7/2024):
   * Added: PopUpWindow is now used to display error message.

* ** Version 1.4.1 (13/7/2024):
   * Modified: Doing self.show() in PopUpWindow's constructor to avoid calling show() in other places.
               Added more pop up messages to indicate whether an operation was performed successfully.

"""