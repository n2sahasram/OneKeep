#!/usr/bin/python
import sqlite3
conn = sqlite3.connect('ss')
curso = conn.cursor()
for x in curso.execute("SELECT * FROM p3 WHERE File = 'p2.py'"):
	print x[3] 

