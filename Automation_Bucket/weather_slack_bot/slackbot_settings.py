import os
from os.path import join, dirname
from dotenv import load_dotenv

dotenv_path = join(dirname(__file__), '.env')
load_dotenv(dotenv_path)

# set bot acount token
API_TOKEN = os.environ['SLACK_TOKEN']

DEFAULT_REPLY = "Hello!!"

# extend return mesage
PLUGINS = ['plugins']