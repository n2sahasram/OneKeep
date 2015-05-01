#!/usr/bin/python
import os
import datetime
def modification_date(filename):
    t = 0; q = 0;
    t = os.path.getmtime(filename)
    q = os.path.getctime(filename)
    a = [datetime.datetime.fromtimestamp(t), datetime.datetime.fromtimestamp(q)]
    return a
    
get = modification_date('mytxt')
print get[0], get[1]

