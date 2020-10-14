'''
A script to automate Whatsapp using selenium
To install selenium : pip install selenium
We  also need to install the latest version of Chromedriver for this automation.
Link-https://chromedriver.chromium.org/
After installing, now in the path variable mention the exact path of your chromedriver.exe file
To send a message enter the name of the recipient and the message you want to send.
That's it. Now just run the script and enjoy ;)
'''
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
path=r"C:\Users\HP\Downloads\chromedriver_win32\chromedriver"
driver=webdriver.Chrome(path)
driver.get("https://web.whatsapp.com/")
wait=WebDriverWait(driver,600)
target='"Recipient Name"'#Enter friends name here
string='hello!!'#message that needs to be sent
x_arg="//span[contains(@title,"+target+")]"
target=wait.until(EC.presence_of_element_located((By.XPATH,x_arg)))
target.click()

input_box=driver.find_element_by_class_name("_3uMse")
for i in range(10):
    input_box.send_keys(string+Keys.ENTER)

