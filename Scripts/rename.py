#! python3
import time
import ssl
import os
import datetime
import urllib.request
import json
import requests
from bs4 import BeautifulSoup
import re
import subprocess
import psutil
from subprocess import check_output


PROCNAME = "ApexDC-x64.exe"

for proc in psutil.process_iter():
    if proc.name() == PROCNAME:
        p=proc.pid

pp = psutil.Process(p)
pp.terminate()

paths='C:\DC Downloads'
for path, subdirs, file in os.walk(paths):
    for name in file:
        if(name[-1:]=="_"):
            oldname=path+'\\'+name
            newname=oldname[:-1]
            print(newname)
            print(oldname)
            print()
            os.rename(oldname,newname)
