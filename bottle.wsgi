import os

os.chdir('C:\SignalAnalysis') # the directory where your py files are, use the full linux system path
from DTW_WSGI import app # I assume appone.py is your main application

application = app