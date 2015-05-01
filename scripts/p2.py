#!/usr/bin/python
import sqlite3
import subprocess
ls_lines = subprocess.check_output(['ls', '-l'])
l = ls_lines.split('\n')
del l[0], l[-1]
con = sqlite3.connect('ss')
cursor = con.cursor()
t = ()
for i,s in enumerate(l):
   t = l[i].split(' ')[-4:]
   cursor.execute("INSERT INTO p3 values (?, ?, ?, ?)", (t[0], t[1], t[2], t[3]))
con.commit()

