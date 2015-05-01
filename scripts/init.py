#!/usr/bin/python
import sqlite3
con = sqlite3.connect('ss')
cursor = con.cursor()
cursor.execute("CREATE TABLE p3 (Month text, Date text, Time text, File text)")
con.commit()
print "Lets (t)roll!"
