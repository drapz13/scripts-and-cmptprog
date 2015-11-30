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
'''
p = subprocess.Popen(["C:\Program Files\ApexDC++\ApexDC-x64.exe"])
time.sleep(5)

child = subprocess.Popen(['pgrep','C:\Program Files\ApexDC++\ApexDC-x64.exe'], stdout=subprocess.PIPE, shell=False)
result = child.communicate()[0]
#m=int(check_output(["pidof","-s","C:\Program Files\ApexDC++\ApexDC-x64.exe"]))
#m=psutil.Process(os.getpid("C:\Program Files\ApexDC++\ApexDC-x64.exe"))
print(result)
#p.terminate()
'''
'''
ch=input()
if ch=="y":
    p = subprocess.Popen(["C:\Program Files\ApexDC++\ApexDC-x64.exe"])
    time.sleep(5)
    p.terminate()
else:
    print("arre")
'''
