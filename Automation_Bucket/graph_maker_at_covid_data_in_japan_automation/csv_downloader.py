from selenium import webdriver
import chromedriver_binary

import os
import shutil
import time

 # Set the download folder path
csv_download_dir = './csv_download'

def csvDownloader():
    driver = webdriver.Chrome()

    try:
        # If the previous result remains in the folder Delete the folder
        if os.path.isdir(csv_download_dir):
            shutil.rmtree(csv_download_dir)
        
        # Make download folder
        os.mkdir(csv_download_dir)

        # Change download destination in Chrome option settings
        options = webdriver.ChromeOptions()
        prefs = {'download.default_directory' : csv_download_dir }
        options.add_experimental_option('prefs',prefs)

        # Set to start in a secret window
        options.add_experimental_option("useAutomationExtension", False)
        options.add_argument("--ignore-certificate-errors")
        options.add_argument("--headless")

        # Apply options and launch Google Chrome
        driver = webdriver.Chrome(chrome_options = options)

        # Open WEB page
        url = "https://www.mhlw.go.jp/stf/covid-19/open-data.html"
        driver.get(url)

        # Wait 5 seconds for the information to be available in the browser
        time.sleep(5)

        # Click after getting all CSV download links
        CSVs = driver.find_elements_by_class_name('m-link')
        for CSV in CSVs:
            CSV.click()
        
        # Wait 10 seconds for the download to complete
        time.sleep(10)
    
    except:
        raise Exception


if __name__ == "__main__":
    csvDownloader()
