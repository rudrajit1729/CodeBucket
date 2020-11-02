from slackbot.bot import respond_to
from slackbot.bot import default_reply
import slackbot_settings


@respond_to('Hi')
def greeting(message):
    message.reply('Have a nice day!!')

@respond_to("I'm\s(.*)")
def hello(message, something):
    message.reply(f'Hi {something}!!')

@default_reply
def my_default_handler(message):
    message.send(slackbot_settings.DEFAULT_REPLY)