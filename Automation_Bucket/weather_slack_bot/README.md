# Weather Notice Slack Bot
A slack bot that tells you the weather when you ask the bot "weather ???"

## Prerequisites
* python-dotenv - Library for managing environment variables
* requests - library for sending http get and post requests (used here to send get request to OpenWeatherMap API)
* slackbot - Library for interacting with bots

## How to run the script
Python 3.8

you can use install first with pip install -r requirements.txt

and then run with command python run.py

## Start with creating a new app in slack as a bot
**First You create a workspace and click "add app".**

<img src="./image/addApp.png" title="addApp">

**You search "hubot" and click "add".**

<img src="./image/searchHubot1.png" title="searchHubot1">
<img src="./image/searchHubot2.png" title="searchHubot2">

**Redirect to slack settings page and get API token.**

<img src="./image/settingHubot1.png" title="settingHubot1">
<img src="./image/settingHubot2.png" title="settingHubot2">

**You set the API Token in .env.**

<img src="./image/settingEnv1.png" title="settingEnv1">

**Then get the API Key for the OpenWeather API**

<img src="./image/getAPIKey1.png" title="getAPIKey1">
<img src="./image/getAPIKey2.png" title="getAPIKey2">
<img src="./image/getAPIKey3.png" title="getAPIKey3">
<img src="./image/getAPIKey4.png" title="getAPIKey4">

**Setting API Key .env in the same way as Hubot API Token.**

**Now that you’ve done this your app should be ready.**

**Running run.py and ask hubot the weather.**

<img src="./image/demo1.png" title="demo1">
<img src="./image/demo2.png" title="demo2">


## *Author Name*
@kazuyoshi-tech
https://github.com/kazuyoshi-tech