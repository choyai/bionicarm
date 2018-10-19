import serial
import numpy as np
import time
import datetime as dt
import matplotlib.pyplot as plt
import matplotlib.animation as animation

BAUDRATE = int(input("Enter baud rate: "))
PORT = input("Enter COM port: ")

# initiate coms with device
ser = serial.Serial()
ser.baudrate = BAUDRATE
ser.port = PORT
ser.timeout = 1
ser.dtr = 0
ser.rts = 0
while True:
    try:
        ser.open()
        print("connected to: " + ser.portstr)
        start = time.time()
        break
    except:
        print("cannot access " + PORT)

        # Parameters
x_len = 200         # Number of points to display
y_range = [0, 1023]  # Range of possible Y values to display

# Create figure for plotting
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
xs = list(range(0, 200))
ys = [0] * x_len
ax.set_ylim(y_range)

# Create a blank line. We will update the line in animate
line, = ax.plot(xs, ys)

# Add labels
plt.title('ADC reading')
plt.xlabel('Samples')
plt.ylabel('ADC')

# This function is called periodically from FuncAnimation

adc_reading = 0


def animate(i, ys):

    # Read adc
    message = ser.readline().decode('utf-8')
    print(message)

    if message is not '':
        #
        adc_reading = int(message.split(",")[0])
    #
    # Add y to list
    ys.append(adc_reading)

    # Limit y list to set number of items
    ys = ys[-x_len:]

    # Update line with new Y values
    line.set_ydata(ys)

    return line,


# Set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig,
                              animate,
                              fargs=(ys,),
                              interval=50,
                              blit=True)
plt.show()
ser.close()
