#!/usr/bin/env python

import getpass
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

fromaddr = "kabascolby@gmail.com"
passwd = getpass.getpass('your email server password : ')
toaddr = raw_input("ADDRESS YOU WANT TO SEND TO:")
subj = raw_input("SUBJECT OF MAIL:")
message = raw_input("MESSAGE OF EMAIL:")
msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = subj

body = message
msg.attach(MIMEText(body, 'plain'))

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, passwd)
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
print "Email sent with success!"
server.quit()