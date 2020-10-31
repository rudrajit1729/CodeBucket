from slackbot.bot import respond_to

import requests
import json
import os
from os.path import join, dirname
from dotenv import load_dotenv

dotenv_path = join(dirname(__file__), '../.env')
load_dotenv(dotenv_path)

def get_weather(city):
    try:
        WHEATHER_KEY = os.environ['WHEATHER_KEY']
        url = f"http://api.openweathermap.org/data/2.5/weather?units=metric&q={city}&appid={WHEATHER_KEY}"
        response = requests.get(url)
        return response.json()
    except:
        return None


# Test execution function
# if __name__ == "__main__":
#     get_weather('Tokyo')


@respond_to('weather\s[a-zA-Z]')
def whetherNotice(message):
    respond = message.body['text'].split()
    city = respond[1]
    data = get_weather(city)

    try:
        attachments = [
        {
            "color": "#3104B4",
            "fields": [
                {
                    "title": "city",
                    "value": data['name']
                },
                {
                    "title": "weather",
                    "value": data['weather'][0]['main']
                },
                {
                    "title": "temp",
                    "value": f"{data['main']['temp']}°C"
                },
            ],
            "footer": "!",
            "footer_icon": "https://pics.prcm.jp/db36726f85742/67433428/jpeg/67433428.jpeg"
        }
        ]
        message.send_webapi('Infomation', json.dumps(attachments))
    except:
        message.reply('There was no city')