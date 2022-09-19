from flask import Flask, Response
from flask import send_from_directory
import serial
import time
import cv2
import json, os, signal

camera = cv2.VideoCapture(0)
# arduino = serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=.1)

app = Flask(__name__)

def gen_frames():  
    while True:
        success, frame = camera.read()  # read the camera frame
        if not success:
            break
        else:
            ret, buffer = cv2.imencode('.jpg', frame)
            frame = buffer.tobytes()
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

# def write_read(x):
#     arduino.write(bytes(x, 'utf-8'))
#     time.sleep(0.05)

@app.route('/kill')
def stopServer():
    os.kill(os.getpid(), signal.SIGINT)
    return 'killed'

# @app.route('/movement/<num>')
# def number_handler(num):
#     write_read(num)
#     return 'good'

@app.route('/movement/')
def movement_handler():
    return send_from_directory(path='static', filename='movement.html')

@app.route('/webcam/')
def videostream_handler():
    return send_from_directory(path='static', filename='video.html')

@app.route('/video_feed')
def video_feed():
    return Response(gen_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80, debug=False)