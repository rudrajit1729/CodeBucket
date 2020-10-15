'''
A script to automate Youtube using selenium
To install selenium : pip install selenium
We  also need to install the latest version of Chromedriver for this automation.
Link-https://chromedriver.chromium.org/
After installing, now in the path variable mention the exact path of your chromedriver.exe file
To search for something on Youtube, just type in the query and the script will play the first suggested video for you.
That's it. Now just run the script and enjoy ;)
'''

from selenium import webdriver
from selenium.webdriver.common.keys import Keys

print("Enter your Youtube query")
s = input()

PATH = "C:\Program Files (x86)\chromedriver.exe"

driver = webdriver.Chrome(PATH)
driver.get("https://youtube.com")


search = driver.find_element_by_name('search_query')
search.send_keys(s)

searchButton = driver.find_element_by_xpath('//*[@id="search-icon-legacy"]')
searchButton.click()

