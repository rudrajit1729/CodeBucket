'''
A script to automate facebook login using selenium
To install selenium using pip use this command: pip install selenium
Chrome Driver is also needed for this automation. To download latest version
of chrome driver visit: https://sites.google.com/a/chromium.org/chromedriver/
After installing, now in the path variable mention the exact path of your chromedriver.exe file
and in the username and password variable, mention your own username and password of facebook.
That's it. Now just run the script and enjoy ;)
'''

from selenium import webdriver

path = "your chromedriver.exe path like D:/chromedriver/chromedriver"
username = "your username or email id"
password = "your password"

driver = webdriver.Chrome(path)

driver.get("https://www.facebook.com/")
driver.find_element_by_id("email").send_keys(username)
driver.find_element_by_id("pass").send_keys(password)
driver.find_element_by_name("login").click()

print("Log in successful")
