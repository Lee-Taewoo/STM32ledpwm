import serial as s
import time
import tkinter as tk
import tkinter as ttk

ser = s.Serial("COM3", 115200)

def red_function():
     ser.write("G000R100B000\n".encode())
     print("적색 버튼을 눌렀습니다.")
def green_function():
     ser.write("G100R000B000\n".encode())
     print("녹색 버튼을 눌렀습니다.")
def blue_function():
    ser.write("G000R000B100\n".encode())
    print("청색 버튼을 눌렀습니다.")

root = tk.Tk()
root.title('RGB 슬라이더 프로그램')
root.geometry('600x300+100+100')
root.resizable(False, False)

g_value = tk.IntVar(value=0)
r_value = tk.IntVar(value=0)
b_value = tk.IntVar(value=0)
def on_slider_change(event=None):
    data = f'G{g_value.get():03d}R{r_value.get():03d}B{b_value.get():03d}\n'
    ser.write(data.encode())


redButton = tk.Button(root, text='적색 LED 켜기', command = red_function())
greenButton = tk.Button(root, text='녹색 LED 켜기', command= green_function())
blueButton = tk.Button(root, text='청색 LED 켜기', command=blue_function())
g_slider = ttk.Scale(root, from_=0, to = 100, orient = "horizontal", variable=g_value,command=on_slider_change)
r_slider = ttk.Scale(root, from_=0, to = 100, orient = "horizontal", variable=r_value,command=on_slider_change)
b_slider = ttk.Scale(root, from_=0, to = 100, orient = "horizontal", variable=b_value,command=on_slider_change)

redButton.pack()
greenButton.pack()
blueButton.pack()
g_slider.pack()
r_slider.pack()
b_slider.pack()

root.mainloop()




