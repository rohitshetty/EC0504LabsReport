from Tkinter import *
import serial 
import serial.tools.list_ports
from time import sleep
portList = serial.tools.list_ports.comports()

for port in portList:
 if(not port[2]=='n/a'):
  portLine = port[0]
  connection = serial.Serial(portLine,115200)
  print "Connected over",connection.name


root  = Tk()
entryVar = StringVar()

Recived = StringVar()
Label(root,textvariable = Recived).pack()
you =  StringVar()
Label(root,textvariable=you).pack()

def get(data="null"):
 data = entryVar.get()
 connection.write(" ".join((data,"\n")))
 entryVar.set('')
 you.set(" ".join(("You :",data)))

entry = Entry(root,textvariable=entryVar).pack()
button = Button(root,text = "press ",command= get).pack()

def call():
 if(connection.inWaiting()>0):
  sent = connection.readline()
  Recived.set(" ".join(("Sender :",sent.replace("\n",""))))
 root.after(100,call)



root.bind("<Return>",get)
root.after(100,call)
root.mainloop()



